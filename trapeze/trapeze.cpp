#include "trapeze.h"

Trapeze::Trapeze(GlobParams *gl, QPointF point, QObject *parent) :
    Figure(gl,point,parent)
{
    Q_UNUSED(point)
}

Trapeze::~Trapeze()
{

}

Figure* Trapeze::Copy(QPointF point)
{
    return new Trapeze(globs, point);
}

void Trapeze::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(lineColor, lineWidth));
    if(brushFlag) painter->setBrush(QBrush(brushColor));

    QPolygonF polygon;

    int quot = (endPoint().x() - startPoint().x()) / 4;

    polygon << QPointF(startPoint().x(),
                       startPoint().y())
            << QPointF(endPoint().x(),
                       startPoint().y())
            << QPointF(endPoint().x() - quot,
                       endPoint().y())
            << QPointF(startPoint().x() + quot,
                       endPoint().y());

    painter->drawPolygon(polygon);

    Q_UNUSED(option)
    Q_UNUSED(widget)
}

QString Trapeze::getName()
{
    return "Трапеция";
}

Figure* getShape()
{
    Figure* tmp = new Trapeze(new GlobParams(), QPointF());
    return tmp;
}
