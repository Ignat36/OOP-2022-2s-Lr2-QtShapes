#ifndef SEGMENT_H
#define SEGMENT_H

#include <QObject>
#include <QGraphicsItem>
#include "figure.h"

class Segment : public Figure
{
    Q_OBJECT

public:
    explicit Segment(QPointF point, QObject *parent = 0);
    ~Segment();

    Figure* Copy(QPointF point) override;

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

#endif // SEGMENT_H
