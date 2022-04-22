#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <QObject>
#include <QGraphicsItem>
#include "figure.h"

class Triangle : public Figure
{
    Q_OBJECT

public:
    explicit Triangle(GlobParams *gl, QPointF point, QObject *parent = 0);
    ~Triangle();

    Figure* Copy(QPointF point) override;
    QString getName() override;

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

#endif // TRIANGLE_H
