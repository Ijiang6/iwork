#ifndef CUSTOMGRAPHICSSCENE_H
#define CUSTOMGRAPHICSSCENE_H

#include <QObject>
#include <QGraphicsScene>
#include<QPainter>
class CustomGraphicsScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit CustomGraphicsScene(QGraphicsScene *parent = nullptr);
void drawBackground(QPainter *painter, const QRectF &rect) Q_DECL_OVERRIDE;
signals:

};

#endif // CUSTOMGRAPHICSSCENE_H
