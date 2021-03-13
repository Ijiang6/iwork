#ifndef CUSTOMGRAPHICSVIEW_H
#define CUSTOMGRAPHICSVIEW_H

#include<QGraphicsView>
#include<QWheelEvent>
#include<QScrollBar>
#include<QVariantAnimation>
class CustomGraphicsView :public QGraphicsView
{
    Q_OBJECT
public:
    CustomGraphicsView(QGraphicsView * parent = nullptr);

 void  wheelEvent(QWheelEvent *event);
 void mousePressEvent(QMouseEvent *event) override;

private:
 class PrivateData;
    PrivateData *d_data;
};

#endif // CUSTOMGRAPHICSVIEW_H
