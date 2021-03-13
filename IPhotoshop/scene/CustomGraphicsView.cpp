#include "CustomGraphicsView.h"
#include"WaterDrop.h"
class CustomGraphicsView::PrivateData
{
public:
    PrivateData(int radiusVar =10,
                QColor colorVar=Qt::darkCyan,
                bool bShowVar = true)
    {
        iRadius =radiusVar;
        color =colorVar;
        bShow = bShowVar;
        waterDrop =nullptr;
    }
    int iRadius;
    QColor color;
    bool bShow;
    QVariantAnimation *waterDrop;
};

CustomGraphicsView::CustomGraphicsView(QGraphicsView * parent)
    :QGraphicsView(parent)
{
    d_data = new PrivateData;
    // 控件显示完关闭后自动删除;
       this->setAttribute(Qt::WA_DeleteOnClose);
    d_data->waterDrop = new QVariantAnimation(this);
}

void CustomGraphicsView::wheelEvent(QWheelEvent *event)
{

        // 获取当前鼠标相对于view的位置;
        QPointF cursorPoint = event->pos();
        // 获取当前鼠标相对于scene的位置;
        QPointF scenePos = this->mapToScene(QPoint(cursorPoint.x(), cursorPoint.y()));

        // 获取view的宽高;
        qreal viewWidth = this->viewport()->width();
        qreal viewHeight = this->viewport()->height();

        // 获取当前鼠标位置相当于view大小的横纵比例;
        qreal hScale = cursorPoint.x() / viewWidth;
        qreal vScale = cursorPoint.y() / viewHeight;

        // 当前放缩倍数;
        qreal scaleFactor = this->matrix().m11();
        int wheelDeltaValue = event->delta();
        // 向上滚动，放大;
        if (wheelDeltaValue > 0)
        {
            this->scale(1.2, 1.2);
        }
        // 向下滚动，缩小;
        else
        {
            this->scale(1.0 / 1.2, 1.0 / 1.2);
        }

        // 将scene坐标转换为放大缩小后的坐标;
        QPointF viewPoint = this->matrix().map(scenePos);
        // 通过滚动条控制view放大缩小后的展示scene的位置;
        horizontalScrollBar()->setValue(int(viewPoint.x() - viewWidth * hScale));
        verticalScrollBar()->setValue(int(viewPoint.y() - viewHeight * vScale));


}

/**
 * @brief CustomGraphicsView::mousePressEvent
 * @param event
 */
void CustomGraphicsView::mousePressEvent(QMouseEvent *event)
{
    QPoint cursorPos = event->pos();

        WaterDrop* waterDrop = new WaterDrop();
        waterDrop->move(this->mapToGlobal(cursorPos));
        waterDrop->setColor(Qt::darkCyan);
        waterDrop->show();
}


