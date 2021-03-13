#ifndef CUSTOMGRAPHICSITEM_H
#define CUSTOMGRAPHICSITEM_H

#include <QGraphicsPixmapItem>
#include<QPainter>
#include<QStyleOptionGraphicsItem>
#include<QPixmap>
#include<QRectF>
class CustomGraphicsItem : public QGraphicsPixmapItem
{

public:
    explicit CustomGraphicsItem(QGraphicsPixmapItem *parent = nullptr);
    void  setImagePath(const QString & path);
    void setPIxmapDispaly(const QPixmap &pixmap);
signals:

};

#endif // CUSTOMGRAPHICSITEM_H
