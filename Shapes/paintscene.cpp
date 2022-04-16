#include "paintscene.h"
#include "romb.h"
#include "triangle.h"
#include "square.h"
#include "elipse.h"

PaintScene::PaintScene(QObject *parent) : QGraphicsScene(parent)
{
    tempFigure = nullptr;
}

PaintScene::~PaintScene()
{

}

int PaintScene::typeFigure() const
{
    return m_typeFigure;
}

void PaintScene::setTypeFigure(const int type)
{
    m_typeFigure = type;
}

void PaintScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if(m_typeFigure != Non)
    {
        if(tempFigure != nullptr)
        {
            tempFigure->setEndPoint(event->scenePos());
            this->update(QRectF(0,0,this->width(), this->height()));
        }
    }
    else
    {
        QGraphicsScene::mouseMoveEvent(event);
        if(FlagChange || FlagRotate || FlagMove)
        {
            this->update(QRectF(0,0,this->width(), this->height()));
        }
    }
}

void PaintScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if(m_typeFigure != Non)
        tempFigure = nullptr;
    else
    {
        QGraphicsScene::mouseReleaseEvent(event);
    }
}

void PaintScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    switch (m_typeFigure) {
    case SquareType: {
        Square *item = new Square(event->scenePos());
        item->setPos(event->pos());
        tempFigure = item;
        break;
    }
    case RombType: {
        Romb *item = new Romb(event->scenePos());
        item->setPos(event->pos());
        tempFigure = item;
        break;
    }
    case TriangleType: {
        Triangle *item = new Triangle(event->scenePos());
        item->setPos(event->pos());
        tempFigure = item;
        break;
    }
    case ElipseTtype: {
        Elipse *item = new Elipse(event->scenePos());
        item->setPos(event->pos());
        tempFigure = item;
        break;
    }
    default:{
        QGraphicsScene::mousePressEvent(event);
        break;
    }
    }
    if(m_typeFigure != Non)
        this->addItem(tempFigure);
}

