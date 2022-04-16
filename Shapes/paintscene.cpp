#include "paintscene.h"

PaintScene::PaintScene(QObject *parent) : QGraphicsScene(parent)
{
    tempFigure = CurFigureSpawner = nullptr;
}

PaintScene::~PaintScene()
{

}

void PaintScene::setTypeFigure(Figure *NewFigureSpawner)
{
    CurFigureSpawner = NewFigureSpawner;
}

void PaintScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if(CurFigureSpawner != nullptr)
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
    if(CurFigureSpawner != nullptr)
        tempFigure = nullptr;
    else
    {
        QGraphicsScene::mouseReleaseEvent(event);
    }
}

void PaintScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(CurFigureSpawner != nullptr)
    {
        Figure *item = CurFigureSpawner->Copy(event->scenePos());
        item->setPos(event->pos());
        tempFigure = item;
        this->addItem(tempFigure);
    }
    else
    {
        QGraphicsScene::mousePressEvent(event);
    }
}

