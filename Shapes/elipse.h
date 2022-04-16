#ifndef ELIPSE_H
#define ELIPSE_H

#include <QObject>
#include <QGraphicsItem>
#include "figure.h"

class Elipse : public Figure
{
    Q_OBJECT

public:
    explicit Elipse(QPointF point, QObject *parent = 0);
    ~Elipse();

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // ELIPSE_H
