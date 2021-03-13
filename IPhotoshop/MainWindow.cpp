#include "MainWindow.h"
#include "ui_MainWindow.h"
#include"ImageRotationForm.h"
#include"SDockWidget.h"
#include"ImageCroppingForm.h"
#include<QPropertyAnimation>
#include"CustomGraphicsView.h"
#include"CustomGraphicsScene.h"
#include"CustomGraphicsItem.h"
#include"rulebar.h"
#include"BrightnessContrastForm.h"
#include"CGlobal.h"
#include<QFileDialog>
#include"WarpAffineForm.h"
#define GetDockWgt(w)       (reinterpret_cast<SDockWidget*>(w->parentWidget()))
#define GetDockWgtBtn(w)    (GetDockWgt(w)->getToolButton())
class MainWindow::PrivateData
{
public:
    CustomGraphicsView *pView;
    CustomGraphicsScene *pScene;
    CustomGraphicsItem *pItem;
    QtRuleBar *pHorbar;
    QList<QWidget*> listWgts;

};
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    pData = new PrivateData;
    initDocWgt();
    initConnection();
    initScene();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::initScene()
{
    pData->pView = new CustomGraphicsView;

    pData->pScene = new CustomGraphicsScene;
    pData->pScene->setSceneRect(0,0,1000,700);
    pData->pView->setScene(pData->pScene);
    pData->pItem = new CustomGraphicsItem;
    QString img = "D:/Works/code/QtProject/IPhotoshop/image/test.png";
    pData->pItem->setImagePath(img);
    pData->pScene->addItem(pData->pItem);
    CGlobal::getInstance()->g_MatSrc = cv::imread(img.toStdString(),1);

    this->setCentralWidget(pData->pView);
}
void MainWindow::initDocWgt()
{
    QWidget *pWgt = new ImageRotationForm;
    pWgt->setWindowTitle(QStringLiteral("旋\n转"));//"R\no\nt\na\nt\ni\no\nn"
    pData->listWgts << pWgt;

    pWgt = new ImageCroppingForm;
    pWgt->setWindowTitle(QStringLiteral("选\n择"));//"C\nu\nt"
    pData->listWgts << pWgt;

    pWgt = new BrightnessContrastForm;
    pWgt->setWindowTitle(QStringLiteral("亮\n度/\n对\n比\n度"));//B\nr\ni\ng\nh\nt\nn\ne\ns\ns\nu\n
    pData->listWgts << pWgt;
    connect((BrightnessContrastForm*)pWgt,&BrightnessContrastForm::sig_updateImg,this,&MainWindow::slot_updateImg);

    pWgt = new WarpAffineForm;
    pWgt->setWindowTitle(QStringLiteral("仿射变换"));
    pData->listWgts << pWgt;
    connect((WarpAffineForm*)pWgt,&WarpAffineForm::sig_updateImg,this,&MainWindow::slot_updateImg);

    for(int index =0 ; index < pData->listWgts.size() ; ++ index)
    {
        pWgt = pData->listWgts[index];
        SDockWidget *doc =  new SDockWidget;
        connect(doc, SIGNAL(isAnimation(bool)), this, SLOT(floatAnimationSlot(bool)));
        doc->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
        doc->setTitleBarText(pWgt->windowTitle().remove('\n'));
        doc->setWidget(pWgt);
        addDockWidget(Qt::LeftDockWidgetArea, doc);
        doc->raise();
    }
    ui->leftFrameTool->setWindowTitle(QStringLiteral("左侧工具栏"));
    ui->leftFrameTool->setStyleSheet("QToolBar{background-color:rgb(255,255,255);}"
                                     "QToolButton{font:12px;}");
    ui->leftFrameTool->setVisible(false);
    foreach(QWidget* wgt,pData->listWgts )
    {
        QToolButton* toolBtn = GetDockWgtBtn(wgt);
        toolBtn->setFixedSize(30, 100);
        toolBtn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        toolBtn->setIcon(wgt->windowIcon());
        toolBtn->setText(wgt->windowTitle());
        ui->leftFrameTool->addWidget(toolBtn);

    }
    this->addToolBar(Qt::LeftToolBarArea, ui->leftFrameTool);
}

void MainWindow::initConnection()
{
    connect(this, SIGNAL(hoverEnter(QObject*)), this, SLOT(hoverEnterSlot(QObject*)));
    connect(this, SIGNAL(hoverLeave(QObject*)), this, SLOT(hoverLeaveSlot(QObject*)));
    connect(ui->actionOpen,&QAction::triggered,this,&MainWindow::slot_openImg);

}
void MainWindow::floatAnimationSlot(bool a_enable)
{
    SDockWidget *pDoc = qobject_cast<SDockWidget*> (sender());
    if(pDoc ==nullptr)
    {
        return ;
    }

    pDoc->setEnableFloat(a_enable);

    //安装按钮事件过滤器
    for(QWidget* wgt : pData->listWgts) {
        setEnableDockWgtAnimation(GetDockWgt(wgt), a_enable);
    }
    if(a_enable) {
        ui->leftFrameTool->show();
        for(QWidget* wgt : pData->listWgts) {
            removeDockWidget(GetDockWgt(wgt));
        }
    }else {
        ui->leftFrameTool->hide();
        for(QWidget* wgt : pData->listWgts) {
            addDockWidget(Qt::LeftDockWidgetArea, GetDockWgt(wgt));
        }
    }

}
void MainWindow::setEnableDockWgtAnimation(QWidget *a_Wgt, bool a_enable)
{
    SDockWidget *pDoc = qobject_cast<SDockWidget*>(a_Wgt);
    if(pDoc == nullptr)
    {
        return ;
    }
    if(a_enable)
    {
        pDoc->hide();
        pDoc->setFloating(false);
        pDoc->setFeatures(QDockWidget::NoDockWidgetFeatures);
        pDoc->getToolButton()->installEventFilter(this);
    }else
    {
        pDoc->getToolButton()->removeEventFilter(this);
        pDoc->removeEventFilter(this);
        pDoc->setFloating(false);
        pDoc->setFeatures(QDockWidget::AllDockWidgetFeatures);
        pDoc->show();
    }
}
void MainWindow::hideAnimationFinishSlot()
{
    //动画显示成功，安装按钮事件过滤器
    QPropertyAnimation* animation = qobject_cast<QPropertyAnimation*>(QObject::sender());
    if(!animation)
    {
        return;
    }

    SDockWidget* wgt = qobject_cast<SDockWidget*>(animation->targetObject());
    if(!wgt)
    {
        return;
    }
    wgt->hide();

    if(isDockWidget(wgt))
    {
        wgt->getToolButton()->installEventFilter(this);
    }
}
void MainWindow::hideWgtAnimation(QWidget *a_wgt, MainWindow::ANIMATION_DIRECTION a_direction, int a_timeout)
{
    QPropertyAnimation* animation = new QPropertyAnimation(a_wgt, "pos");
    connect(animation, SIGNAL(finished()), this, SLOT(hideAnimationFinishSlot()));

    if(a_direction == RIGHT_TO_LEFT)
    {
        animation->setStartValue(QPoint(ui->leftFrameTool->width() + 1, ui->toolBar->height()));
        animation->setEndValue(QPoint(0 - a_wgt->width(), ui->toolBar->height()));
    }else if(a_direction == LEFT_TO_RIGHT)
    {
        animation->setStartValue(QPoint(this->width() - a_wgt->width() - ui->leftFrameTool->width() - 1, ui->toolBar->height()));
        animation->setEndValue(QPoint(this->width(), ui->toolBar->height()));
    }/*else if(a_direction == TOP_TO_BOOTM)
    {
        int x = ui->leftFrameTool->isHidden() ? 0 : ui->leftFrameTool->width();
        int y = ui->statusBar->isVisible() ? this->height() - ui->bottomFrameTool->height() - ui->statusBar->height() - a_wgt->height():
                                             this->height() - ui->bottomFrameTool->height() - a_wgt->height();
        animation->setStartValue(QPoint(x + 1, y));
        animation->setEndValue(QPoint(x + 1, this->height()));
    }*/
    animation->setDuration(a_timeout);
    animation->setEasingCurve(QEasingCurve::OutInExpo);
    animation->start(QAbstractAnimation::DeleteWhenStopped);
}
void MainWindow::hoverLeaveSlot(QObject *obj)
{

    //left toolbar

    QWidget* dockWgt = dynamic_cast<QWidget*>(obj);
    if(!dockWgt) {
        return;
    }
    dockWgt->removeEventFilter(this);
    hideWgtAnimation(dockWgt, RIGHT_TO_LEFT);

}
void MainWindow::hoverEnterSlot(QObject *obj)
{
    QWidget* absWgt = nullptr;
    for(int index = 0; index < pData->listWgts.size() ;++index)
    {
        absWgt = pData->listWgts[index];
        if(obj == GetDockWgtBtn(absWgt))
        {
            break;
        }
    }
    //如果当前有其他浮动窗口显示，则将浮动窗口关闭，并移除事件过滤器
    removeDockWgtEventFilter(pData->listWgts, absWgt);

    int y = ui->leftFrameTool->isHidden() ? this->height() - ui->toolBar->height() - ui->statusBar->height() :
                                            this->height() - ui->toolBar->height() - ui->statusBar->height() - ui->leftFrameTool->height();
    if(!ui->statusBar->isVisible()) {
        y += ui->statusBar->height();
    }
    this->isMaximized() ? GetDockWgt(absWgt)->resize(550, y):
                          GetDockWgt(absWgt)->resize(500, y);

    //移除当前按钮事件过滤器, 动画显示界面
    GetDockWgtBtn(absWgt)->removeEventFilter(this);
    showWgtAnimation(GetDockWgt(absWgt), LEFT_TO_RIGHT);

}
void MainWindow::showWgtAnimation(QWidget *a_wgt, MainWindow::ANIMATION_DIRECTION a_direction, int a_timeout)
{
    QPropertyAnimation* animation = new QPropertyAnimation(a_wgt, "pos");
    connect(animation, SIGNAL(finished()), this, SLOT(showAnimationFinishSlot()));
    a_wgt->show();
    a_wgt->raise();

    if(a_direction == LEFT_TO_RIGHT)
    {
        animation->setStartValue(QPoint(0 - a_wgt->width(), ui->toolBar->height()+10));
        animation->setEndValue(QPoint(ui->leftFrameTool->width() + 1,  ui->toolBar->height()+10));
    }else if(a_direction == RIGHT_TO_LEFT)
    {
        animation->setStartValue(QPoint(this->width(),  ui->toolBar->height()+10));
        animation->setEndValue(QPoint(this->width() - a_wgt->width() - ui->leftFrameTool->width() - 1,  ui->toolBar->height()+10));
    }/*else if(a_direction == BOOTM_TO_TOP)
    {
        int x = ui->leftFrameTool->isHidden() ? 0 : ui->leftFrameTool->width();
        int y = ui->statusBar->isVisible() ? this->height() - ui->bottomFrameTool->height() - ui->statusBar->height() - a_wgt->height():
                                             this->height() - ui->bottomFrameTool->height() - a_wgt->height();
        animation->setStartValue(QPoint(x + 1, this->height()));
        animation->setEndValue(QPoint(x + 1, y));
    }*/
    animation->setDuration(a_timeout);
    animation->setEasingCurve(QEasingCurve::OutInExpo);
    animation->start(QAbstractAnimation::DeleteWhenStopped);
}
void MainWindow::removeDockWgtEventFilter(QList<QWidget*> &wgtList, QWidget *diffWgt)
{
    for(QWidget* wgt : wgtList)
    {
        if(wgt == diffWgt) {
            continue;
        }

        if(!GetDockWgt(wgt)->isHidden()) {
            GetDockWgt(wgt)->hide();
            GetDockWgt(wgt)->removeEventFilter(this);
            GetDockWgtBtn(wgt)->installEventFilter(this);
        }
    }
}
bool MainWindow::isDockWidget(QObject *obj)
{
    bool isDock = false;
    for(QWidget* wgt : pData->listWgts)
    {
        if(GetDockWgt(wgt) == obj) {
            isDock = true;
            break;
        }
    }
    return isDock;
}
bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
    static bool isEnter = false;
    if(event->type() == QEvent::HoverEnter) {

        if(isDockButton(obj)) {
            emit hoverEnter(obj);
        }
    }else if(event->type() == QEvent::Enter) {

        if(isDockWidget(obj)) {
            isEnter = true;
        }
    }else if(event->type() == QEvent::Leave) {

        if(isDockWidget(obj) && isEnter) {
            isEnter = false;
            emit hoverLeave(obj);
        }
    }

    return QMainWindow::eventFilter(obj, event);
}
bool MainWindow::isDockButton(QObject *obj)
{
    bool isDock = false;
    for(QWidget* wgt : pData->listWgts)
    {
        if(GetDockWgtBtn(wgt) == obj) {
            isDock = true;
            break;
        }
    }

    return isDock;
}
void MainWindow::showAnimationFinishSlot()
{
    //动画显示成功，安装界面事件过滤器
    QPropertyAnimation* animation = qobject_cast<QPropertyAnimation*>(QObject::sender());
    if(!animation)
    {
        return;
    }

    SDockWidget* wgt = qobject_cast<SDockWidget*>(animation->targetObject());
    if(!wgt)
    {
        return;
    }
    wgt->installEventFilter(this);
}
/**
 * @brief MainWindow::slot_openImg
 */
void MainWindow::slot_openImg()
{
    QString path= "D:/Works/code/QtProject/IPhotoshop/image";
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                     path,
                                                     tr("Images (*.png *.xpm *.jpg)"));

    if(fileName.isEmpty())
    {
        return ;
    }
    pData->pItem->setImagePath(fileName);
    CGlobal::getInstance()->g_MatSrc = cv::imread(fileName.toStdString(),1);

}
/**
 * @brief MainWindow::slot_updateImg
 */
void MainWindow::slot_updateImg()
{
    QImage dst;
    OpencvConvertFun::matToImage(CGlobal::getInstance()->g_MatDst,dst);
    QPixmap pix= QPixmap::fromImage(dst);
    pData->pItem->setPIxmapDispaly(pix);

}
