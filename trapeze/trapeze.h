#ifndef TRAPEZE_H
#define TRAPEZE_H

#include "trapeze_global.h"

#include "trapeze_global.h"
#include "../Shapes/figure.h"

class TRAPEZE_EXPORT Trapeze : public Figure
{
    Q_OBJECT
public:
    explicit Trapeze(GlobParams *gl, QPointF point, QObject *parent = 0);
    ~Trapeze();

    Figure* Copy(QPointF point) override;
    QString getName() override;

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

};

extern "C" TRAPEZE_EXPORT Figure* getShape();

#endif // TRAPEZE_H
