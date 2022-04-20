#ifndef ELIPSE_H
#define ELIPSE_H

#include <QObject>
#include <QGraphicsItem>
#include "figure.h"

class Elipse : public Figure
{
    Q_OBJECT

public:
    explicit Elipse(GlobParams *gl, QPointF point, QObject *parent = 0);
    ~Elipse();

    Figure* Copy(QPointF point) override;

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

#endif // ELIPSE_H
