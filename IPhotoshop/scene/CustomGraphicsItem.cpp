#include "CustomGraphicsItem.h"
#include<QPixmap>

CustomGraphicsItem::CustomGraphicsItem(QGraphicsPixmapItem *parent) : QGraphicsPixmapItem(parent)
{

}

void CustomGraphicsItem::setImagePath(const QString &path)
{
    if(path.isEmpty())
    {
        return ;
    }
     QPixmap pixmap(path);
     setPixmap(pixmap);

}

void CustomGraphicsItem::setPIxmapDispaly(const QPixmap &pixmap)
{
     setPixmap(pixmap);
}
