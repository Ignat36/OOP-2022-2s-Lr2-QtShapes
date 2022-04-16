#include "figure.h"

Figure::Figure(QPointF point, QObject *parent) :
    QObject(parent), QGraphicsItem()
{
    this->setStartPoint(mapFromScene(point));
    this->setEndPoint(mapFromScene(point));
    RotationAngle = 0;

    timer = new QTimer();
    PressedButton = -1;
    connect(timer, &QTimer::timeout, this, &Figure::slotTimer);
    connect(this, &Figure::pointChanged, this, &Figure::updateRomb);
}

void Figure::slotTimer()
{
    if(PressedButton == 0)
    {
        RotationAngle++;
    }
    if(PressedButton == 1)
    {
        RotationAngle--;
    }
    this->setRotation(RotationAngle);
}

Figure::~Figure()
{

}

QRectF Figure::boundingRect() const
{
    return QRectF((endPoint().x() > startPoint().x() ? startPoint().x() : endPoint().x()) - 5,
                  (endPoint().y() > startPoint().y() ? startPoint().y() : endPoint().y()) - 5,
                  qAbs(endPoint().x() - startPoint().x()) + 10,
                  qAbs(endPoint().y() - startPoint().y()) + 10);
}

void Figure::updateRomb()
{
    this->update((endPoint().x() > startPoint().x() ? startPoint().x() : endPoint().x()) - 5,
                 (endPoint().y() > startPoint().y() ? startPoint().y() : endPoint().y()) - 5,
                 qAbs(endPoint().x() - startPoint().x()) + 10,
                 qAbs(endPoint().y() - startPoint().y()) + 10);
}

void Figure::setStartPoint(const QPointF point)
{
    m_startPoint = mapFromScene(point);
    emit pointChanged();
}

void Figure::setEndPoint(const QPointF point)
{
    m_endPoint = mapFromScene(point);
    emit pointChanged();
}

QPointF Figure::startPoint() const
{
    return m_startPoint;
}

QPointF Figure::endPoint() const
{
    return m_endPoint;
}

void Figure::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if(FlagMove)
    {
        bool tmp = false;
        if(RotationAngle)
        {
            setRotationPoint();
            this->setRotation(0);
            tmp = true;
        }
        if(m_startPoint.x() < m_endPoint.x())
        {
            if(m_startPoint.y() < m_endPoint.y())
            {
                QPointF tempS = m_startPoint;
                QPointF tempE = m_endPoint;
                this->setStartPoint(event->scenePos() - (tempE - tempS) / 2);
                this->setEndPoint(event->scenePos() + (tempE - tempS) / 2);
            }
            else
            {
                QPointF tempS(m_startPoint.x(), m_endPoint.y());
                QPointF tempE(m_endPoint.x(), m_startPoint.y());
                this->setStartPoint(event->scenePos() + (tempE - tempS) / 2);
                this->setEndPoint(event->scenePos() - (tempE - tempS) / 2);
            }
        }
        else
        {
            if(m_startPoint.y() < m_endPoint.y())
            {
                QPointF tempS(m_endPoint.x(), m_startPoint.y());
                QPointF tempE(m_startPoint.x(), m_endPoint.y());
                this->setStartPoint(event->scenePos() + (tempE - tempS) / 2);
                this->setEndPoint(event->scenePos() - (tempE - tempS) / 2);
            }
            else
            {
                QPointF tempS = m_endPoint;
                QPointF tempE = m_startPoint;
                this->setStartPoint(event->scenePos() + (tempE - tempS) / 2);
                this->setEndPoint(event->scenePos() - (tempE - tempS) / 2);
            }
        }
        if(tmp)
        {
            setRotationPoint();
            this->setRotation(RotationAngle);
        }
    }
    if(FlagChange)
    {
        this->setEndPoint(event->scenePos());
    }
    if(FlagRotate)
    {

    }
}

void Figure::setRotationPoint()
{
    if(m_startPoint.x() < m_endPoint.x())
    {
        if(m_startPoint.y() < m_endPoint.y())
            this->setTransformOriginPoint(m_startPoint + (m_endPoint - m_startPoint) / 2);
        else
        {
            QPointF tempS(m_startPoint.x(), m_endPoint.y());
            QPointF tempE(m_endPoint.x(), m_startPoint.y());
            this->setTransformOriginPoint(tempS + (tempE - tempS) / 2);
        }
    }
    else
    {
        if(m_startPoint.y() < m_endPoint.y())
        {
            QPointF tempS(m_endPoint.x(), m_startPoint.y());
            QPointF tempE(m_startPoint.x(), m_endPoint.y());
            this->setTransformOriginPoint(tempS + (tempE - tempS) / 2);
        }
        else
        {
            QPointF tempS = m_endPoint;
            QPointF tempE = m_startPoint;
            this->setTransformOriginPoint(tempS + (tempE - tempS) / 2);
        }
    }
}

void Figure::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(FlagMove)
    {

    }
    if(FlagDelete)
    {
        this->deleteLater();
    }
    if(FlagChange)
    {

    }
    if(FlagRotate)
    {
        if(event->buttons() == Qt::RightButton)
        {
            PressedButton = 0;
        }
        if(event-> buttons() == Qt::LeftButton)
        {
            PressedButton = 1;;
        }

        setRotationPoint();

        timer->start(12);

    }
    Q_UNUSED(event);
}

void Figure::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if(FlagMove)
    {

    }
    if(FlagChange)
    {

    }
    if(FlagRotate)
    {
        timer->stop();
    }
    Q_UNUSED(event);
}
