#include "SDockWidget.h"
#include <QCloseEvent>
#include <QHBoxLayout>

static const QString s_floatStyle =
        "QPushButton{ border:none; image:url(\":/image/icon/float.png\"); }"
        "QPushButton:hover{ image:url(\":/image/icon/float_hover.png\"); }"
        "QPushButton:pressed:hover{ image:url(\":/image/icon/float_hover.png\"); }";

static const QString s_autoHideStyle =
        "QPushButton{ border:none; image:url(\":/image/icon/hide.png\"); }"
        "QPushButton:hover{ image:url(\":/image/icon/hide_hover.png\"); }"
        "QPushButton:pressed:hover{ image:url(\":/image/icon/hide_hover.png\"); }";

SDockWidget::SDockWidget(QWidget *parent) :
    QDockWidget(parent),
    m_float(false)
{
    m_titleBarWgt = new SDockTitleBarWgt(this);
    connect(m_titleBarWgt->m_tieleBarIcon, SIGNAL(clicked(bool)), this, SLOT(floatBtnClickedSlot(bool)));
    setTitleBarWidget(m_titleBarWgt);

    m_floatToolBtn = new QToolButton();
}

void SDockWidget::setTitleBarText(const QString &a_text)
{
    setWindowTitle(a_text);
    m_titleBarWgt->m_tieleBarText->setText(a_text);
}

void SDockWidget::setTitleBarIcon(const QIcon &a_icon)
{
    setWindowIcon(a_icon);
}

void SDockWidget::setEnableFloat(bool a_enable)
{
    m_float = a_enable;
    m_float ? m_titleBarWgt->m_tieleBarIcon->setStyleSheet(s_floatStyle):
              m_titleBarWgt->m_tieleBarIcon->setStyleSheet(s_autoHideStyle);
}

void SDockWidget::floatBtnClickedSlot(bool)
{
    m_float = !m_float;
    m_float ? m_titleBarWgt->m_tieleBarIcon->setStyleSheet(s_floatStyle):
              m_titleBarWgt->m_tieleBarIcon->setStyleSheet(s_autoHideStyle);
    emit isAnimation(m_float);
}

SDockTitleBarWgt::SDockTitleBarWgt(QWidget *parent) :
    QWidget(parent)
{

    QHBoxLayout* hLayout = new QHBoxLayout(this);
    hLayout->setContentsMargins(10, 2, 5, 2);
    hLayout->setSpacing(0);
    m_tieleBarText = new QLabel();
    hLayout->addWidget(m_tieleBarText);
    hLayout->addStretch();
    m_tieleBarIcon = new QPushButton();
    m_tieleBarIcon->setFixedSize(22, 20);
    m_tieleBarIcon->setIconSize(QSize(22, 20));
    m_tieleBarIcon->setStyleSheet(s_autoHideStyle);
    m_tieleBarIcon->setToolTip("Auto hide");
    hLayout->addWidget(m_tieleBarIcon);

    QPalette palette = this->palette();
    palette.setBrush(backgroundRole(), QBrush(Qt::darkCyan));
    setPalette(palette);
    setAutoFillBackground(true);
}

bool SDockTitleBarWgt::event(QEvent *event)
{
    if(event->type() == QEvent::Enter)
    {
        QPalette palette = this->palette();
        palette.setBrush(backgroundRole(), QBrush(Qt::cyan));
        setPalette(palette);
    }else if(event->type() == QEvent::Leave)
    {
        QPalette palette = this->palette();
        palette.setBrush(backgroundRole(), QBrush(Qt::darkCyan));
        setPalette(palette);
    }
    return QWidget::event(event);
}
