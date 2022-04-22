#ifndef FIGURE_H
#define FIGURE_H

#include <QObject>
#include <QGraphicsItem>
#include <QDebug>
#include <QCursor>
#include <QPainter>
#include <QTimer>
#include <QGraphicsSceneMouseEvent>

class GlobParams;

class Figure : public QObject, public QGraphicsItem
{
    Q_OBJECT

    Q_PROPERTY(QPointF startPoint
               READ startPoint WRITE setStartPoint
               NOTIFY pointChanged)

    Q_PROPERTY(QPointF endPoint
               READ endPoint WRITE setEndPoint
               NOTIFY pointChanged)
public:
    explicit Figure(GlobParams *gl, QPointF point, QObject *parent = 0);
    ~Figure();

    QPointF startPoint() const;
    QPointF endPoint() const;

    void setStartPoint(const QPointF point);
    void setEndPoint(const QPointF point);

    virtual Figure* Copy(QPointF point) = 0;
    virtual QString getName() = 0;

signals:
    void pointChanged();

public:
    QColor lineColor;
    QColor brushColor;
    int lineWidth;
    bool brushFlag;
    GlobParams *globs;
    int id;

public:
    QPointF m_startPoint;
    QPointF m_endPoint;
    double RotationAngle;
    void setRotationPoint();

    QTimer *timer;
    void slotTimer();
    int PressedButton;
    QPointF MoveSaveShape;

    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

    QRectF boundingRect() const;

    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) = 0;

public slots:
    void updateRomb();
};

class GlobParams
{

public:
    GlobParams();
    bool FlagMove;
    bool FlagDelete;
    bool FlagChange;
    bool FlagRotate;
    bool FlagBrush;
    bool FlagCopy;

    QPen pen;
    QColor CurColor;
    QColor CurBrushColor;
    int CurPenWidth;
    Figure* tmpFigure;

    int ID;

    void setAllFlagsFalse();
    void setDefaultPen();

};

#endif // FIGURE_H
