#include "CustomGraphicsScene.h"

CustomGraphicsScene::CustomGraphicsScene(QGraphicsScene *parent) : QGraphicsScene(parent)
{

}
void CustomGraphicsScene::drawBackground(QPainter *painter, const QRectF &rect)
{

    const int gridSize = 20;

        const int realLeft = static_cast<int>(std::floor(rect.left()));
        const int realRight = static_cast<int>(std::ceil(rect.right()));
        const int realTop = static_cast<int>(std::floor(rect.top()));
        const int realBottom = static_cast<int>(std::ceil(rect.bottom()));

        // Draw grid.
        const int firstLeftGridLine = realLeft - (realLeft % gridSize);
        const int firstTopGridLine = realTop - (realTop % gridSize);

        QVarLengthArray<QLine, 100> lines;

        for (qreal x = firstLeftGridLine; x <= realRight; x += gridSize)
            lines.append(QLine(x, realTop, x, realBottom));
        for (qreal y = firstTopGridLine; y <= realBottom; y += gridSize)
            lines.append(QLine(realLeft, y, realRight, y));

        //painter->setRenderHint(QPainter::Antialiasing);
        painter->setPen(QPen(QColor(220, 220, 220), 0.0));
        painter->drawLines(lines.data(), lines.size());

        // Draw axes.
        painter->setPen(QPen(Qt::red, 1.5));
        painter->drawLine(0, realTop, 0, realBottom);
        painter->drawLine(realLeft, 0, realRight, 0);

}
