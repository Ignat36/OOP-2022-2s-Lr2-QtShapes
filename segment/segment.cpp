#include "segment.h"
#include <QPainter>
#include <QChar>

Segment::Segment(GlobParams *gl, QPointF point, QObject *parent) :
    Figure(gl,point,parent)
{
    Q_UNUSED(point)
}

Segment::~Segment()
{

}

Figure* Segment::Copy(QPointF point)
{
    return new Segment(globs, point);
}

void Segment::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(lineColor, lineWidth));
    if(brushFlag) painter->setBrush(QBrush(brushColor));

    QPolygonF polygon;

    polygon << QPointF(startPoint().x(),
                       startPoint().y())
                << QPointF(endPoint().x(),
                           endPoint().y());

    painter->drawPolygon(polygon);

    Q_UNUSED(option)
    Q_UNUSED(widget)
}

Figure* getShape()
{
    Figure* tmp = new Segment(new GlobParams(), QPointF());
    return tmp;
}

char* getName()
{
    QString str1 = "Segment";
    QByteArray ba = str1.toLocal8Bit();
    char *name = ba.data();
    return name;
}
