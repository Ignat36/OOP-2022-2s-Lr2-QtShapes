#include "elipse.h"
#include <QPainter>

Elipse::Elipse(GlobParams *gl, QPointF point, QObject *parent) :
    Figure(gl,point,parent)
{
    Q_UNUSED(point)
}

Elipse::~Elipse()
{

}

Figure* Elipse::Copy(QPointF point)
{
    return new Elipse(globs, point);
}

// Реализуем метод отрисовки
void Elipse::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(lineColor, lineWidth));
    if(brushFlag) painter->setBrush(QBrush(brushColor));

    QRectF rect(endPoint().x() > startPoint().x() ? startPoint().x() : endPoint().x(),
                endPoint().y() > startPoint().y() ? startPoint().y() : endPoint().y(),
                qAbs(endPoint().x() - startPoint().x()),
                qAbs(endPoint().y() - startPoint().y()));

    painter->drawEllipse(rect);

    Q_UNUSED(option)
    Q_UNUSED(widget)
}
