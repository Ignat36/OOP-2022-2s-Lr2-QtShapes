#ifndef PAINTSCENE_H
#define PAINTSCENE_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsSceneMouseEvent>
#include <QMouseEvent>
#include <QListView>
#include <QTextBrowser>
#include <QFileDialog>
#include <QVector>
#include <QCursor>
#include <qmath.h>
#include <vector>
#include "figure.h"
#include "romb.h"
#include "triangle.h"
#include "square.h"
#include "elipse.h"

class PaintScene : public QGraphicsScene
{
    Q_OBJECT

public:
    explicit PaintScene(QObject *parent = 0);
    ~PaintScene();

    void setTypeFigure(Figure *NewFigureSpawner);     // Установка текущего типа
    void RedoFigure();
    void UndoFigure();
    void updateFiguresList();
    void saveToFile();
    GlobParams *globs;
    QTextBrowser *FiguresView;

    void addFigsList(std::vector<Figure*> list);

private:
    int m_typeFigure;   // текущий тип фигуры
    Figure *tempFigure;
    std::vector<Figure*> undo, redo;
    Figure *CurFigureSpawner;


private:
    // Для рисования используем события мыши
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
};

#endif // PAINTSCENE_H
