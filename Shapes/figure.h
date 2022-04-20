#ifndef FIGURE_H
#define FIGURE_H

#include <QObject>
#include <QGraphicsItem>
#include <QDebug>
#include <QCursor>
#include <QPainter>
#include <QTimer>
#include <QGraphicsSceneMouseEvent>

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
    explicit Figure(QPointF point, QObject *parent = 0);
    ~Figure();

    QPointF startPoint() const;
    QPointF endPoint() const;

    void setStartPoint(const QPointF point);
    void setEndPoint(const QPointF point);

    virtual Figure* Copy(QPointF point) = 0;

signals:
    void pointChanged();

public:
    QColor lineColor;
    QColor brushColor;
    int lineWidth;
    bool brushFlag;

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
};                                                                                                                                                                                                                                                                                                                                                                                                                                                                  extern Figure *tmpFigure; extern bool FlagCopy; extern bool FlagRotate; extern bool FlagChange; extern bool FlagMove; extern bool FlagDelete; extern bool FlagBrush; extern void setAllFlagsFalse(); extern void setDefaultPen(); extern QPen pen; extern QColor CurColor; extern QColor CurBrushColor; extern int CurPenWidth;

#endif // FIGURE_H
