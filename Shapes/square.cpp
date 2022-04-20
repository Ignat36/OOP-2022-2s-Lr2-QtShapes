#include "square.h"
#include <QPainter>

Square::Square(GlobParams *gl, QPointF point, QObject *parent) :
    Figure(gl,point,parent)
{
    Q_UNUSED(point)
}

Square::~Square()
{

}

Figure* Square::Copy(QPointF point)
{
    return new Square(globs, point);
}

void Square::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(lineColor, lineWidth));
    if(brushFlag) painter->setBrush(QBrush(brushColor));

    QRectF rect(endPoint().x() > startPoint().x() ? startPoint().x() : endPoint().x(),
                endPoint().y() > startPoint().y() ? startPoint().y() : endPoint().y(),
                qAbs(endPoint().x() - startPoint().x()),
                qAbs(endPoint().y() - startPoint().y()));
    painter->drawRect(rect);

    Q_UNUSED(option)
    Q_UNUSED(widget)
}

