#ifndef SEGMENT_H
#define SEGMENT_H

#include "segment_global.h"
#include "../Shapes/figure.h"

class SEGMENT_EXPORT Segment : public Figure
{
    Q_OBJECT
public:
    explicit Segment(QPointF point, QObject *parent = 0);
    ~Segment();

    Figure* Copy(QPointF point) override;

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

};

std::pair<Figure*, QString> getShape();

#endif // SEGMENT_H
