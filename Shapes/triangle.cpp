#include "triangle.h"
#include <QPainter>

Triangle::Triangle(GlobParams *gl, QPointF point, QObject *parent) :
    Figure(gl,point,parent)
{
    Q_UNUSED(point)

}

Triangle::~Triangle()
{

}

Figure* Triangle::Copy(QPointF point)
{
    return new Triangle(globs, point);
}

void Triangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(lineColor, lineWidth));
    if(brushFlag) painter->setBrush(QBrush(brushColor));

    QPolygonF polygon;

    polygon << QPointF(startPoint().x() + (endPoint().x() > startPoint().x() ? + 1 : - 1)*
                           abs((endPoint().x() - startPoint().x())/2), startPoint().y())
                << QPointF((endPoint().x() > startPoint().x()) ? endPoint().x() : startPoint().x(),
                           endPoint().y())
                << QPointF((endPoint().x() > startPoint().x()) ? startPoint().x() : endPoint().x(),
                           endPoint().y());

    painter->drawPolygon(polygon);

    Q_UNUSED(option)
    Q_UNUSED(widget)
}

QString Triangle::getName()
{
    return "Треугольник";
}
