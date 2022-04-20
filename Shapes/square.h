#ifndef SQUARE_H
#define SQUARE_H

#include <QObject>
#include <QGraphicsItem>
#include "figure.h"

class Square : public Figure
{
    Q_OBJECT

public:
    explicit Square(GlobParams *gl, QPointF point, QObject *parent = 0);
    ~Square();

    Figure* Copy(QPointF point) override;

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

#endif // SQUARE_H
