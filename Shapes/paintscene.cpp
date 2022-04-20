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
    {
        undo.push_back(tempFigure);
        tempFigure = nullptr;
        redo.clear();
    }
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

        if(FlagCopy)
        {
            FlagCopy = false;
            FlagMove = true;

            tempFigure = tmpFigure;
            tmpFigure = nullptr;
            this->addItem(tempFigure);
        }
    }
}

void PaintScene::RedoFigure()
{
    if(!redo.empty())
    {
        Figure* tmp = redo.back(); redo.pop_back();
        this->addItem(tmp);
        undo.push_back(tmp);
    }
}

void PaintScene::UndoFigure()
{
    if(!undo.empty())
    {
        Figure* tmp = undo.back(); undo.pop_back();
        this->removeItem(tmp);
        redo.push_back(tmp);
    }
}

