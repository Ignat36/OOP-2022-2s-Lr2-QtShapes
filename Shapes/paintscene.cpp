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
        if(globs->FlagChange || globs->FlagRotate || globs->FlagMove)
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
        tempFigure->id = globs->ID; globs->ID++;
        this->addItem(tempFigure);
    }
    else
    {
        QGraphicsScene::mousePressEvent(event);

        if(globs->FlagCopy)
        {
            globs->FlagCopy = false;
            globs->FlagMove = true;

            tempFigure = globs->tmpFigure;
            globs->tmpFigure = nullptr;
            tempFigure->id = globs->ID; globs->ID++;
            this->addItem(tempFigure);
            undo.push_back(tempFigure);
        }

        if(globs->FlagDelete && globs->tmpFigure)
        {
            this->removeItem(globs->tmpFigure);
            undo.push_back(globs->tmpFigure);
            globs->tmpFigure = nullptr;
        }
    }
}

void PaintScene::RedoFigure()
{
    if(!redo.empty())
    {
        Figure* tmp = redo.back(); redo.pop_back();
        if(this->items().contains(tmp))
            this->removeItem(tmp);
        else
            this->addItem(tmp);
        undo.push_back(tmp);
    }
}

void PaintScene::UndoFigure()
{
    if(!undo.empty())
    {
        Figure* tmp = undo.back(); undo.pop_back();
        if(this->items().contains(tmp))
            this->removeItem(tmp);
        else
            this->addItem(tmp);
        redo.push_back(tmp);
    }
}

void PaintScene::updateFiguresList()
{
    QString text = "";
    for(Figure* i : undo)
    {
        if(!this->items().contains(i))
            continue;
        text += i->getName() + ". Creation id: " + QString::number(i->id) +
                ". Shape location: " + QString::number(i->startPoint().x()) + " " + QString::number(i->startPoint().y()) +
                ", " + QString::number(i->endPoint().x()) + " " + QString::number(i->endPoint().y());
        text += "\n";
    }
    FiguresView->clear();
    FiguresView->setText(text);
}

void PaintScene::saveToFile()
{
    QString fileName;
    fileName = QFileDialog::getOpenFileName();

    if(fileName.isNull())
        return;

    QFile file(fileName);
    file.open(QIODevice::ReadWrite);
    file.resize(0);

    QTextStream out(&file);
    for(Figure *i: undo)
    {
        out << i->getName() + " " +
               QString::number(i->startPoint().x()) + " " +
               QString::number(i->startPoint().y()) + " " +
               QString::number(i->endPoint().x()) + " " +
               QString::number(i->endPoint().y()) + " " +
               QString::number(i->RotationAngle) + " " +
               QString::number(i->lineWidth) + " " +
               QString::number(i->brushFlag ? 1 : 0) + " " +

               QString::number(i->lineColor.red()) + " " +
               QString::number(i->lineColor.green()) + " " +
               QString::number(i->lineColor.blue()) + " " +

               QString::number(i->brushColor.red()) + " " +
               QString::number(i->brushColor.green()) + " " +
               QString::number(i->brushColor.blue()) + " " +

               QString::number(i->id) + "\n";
    }
}

void PaintScene::addFigsList(std::vector<Figure *> list)
{
    for(auto i: list)
    {
        this->addItem(i);
        undo.push_back(i);
    }
}
