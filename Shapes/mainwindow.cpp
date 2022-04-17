#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new PaintScene();
    scene->setTypeFigure(nullptr);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setCacheMode(QGraphicsView::CacheBackground);
    ui->graphicsView->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    ui->graphicsView->setCursor(Qt::ArrowCursor);
    setAllFlagsFalse();
    setDefaultPen();
    CurBrushColor = QColor(255, 255, 255);
    r = g = b = "0";
    r1 = g1 = b1 = "255";

    timer = new QTimer();
    connect(timer, &QTimer::timeout, this, &MainWindow::slotTimer);
    timer->start(100);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slotTimer()
{
    timer->stop();
    scene->setSceneRect(0,0, ui->graphicsView->width() - 20, ui->graphicsView->height() - 20);
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    timer->start(100);
    QMainWindow::resizeEvent(event);
}

void MainWindow::on_pushButton_clicked()
{
    ui->graphicsView->setCursor(Qt::ArrowCursor);
    scene->setTypeFigure(new Romb(QPointF()));
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->graphicsView->setCursor(Qt::ArrowCursor);
    scene->setTypeFigure(new Square(QPointF()));
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->graphicsView->setCursor(Qt::ArrowCursor);
    scene->setTypeFigure(new Triangle(QPointF()));
}

void MainWindow::on_pushButton_4_clicked()
{
    ui->graphicsView->setCursor(Qt::ArrowCursor);
    scene->setTypeFigure(new Elipse(QPointF()));
}

void MainWindow::on_pushButton_5_clicked()
{
    scene = new PaintScene();
    scene->setTypeFigure(nullptr);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setCacheMode(QGraphicsView::CacheBackground);
    ui->graphicsView->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    ui->graphicsView->setCursor(Qt::ArrowCursor);
    setAllFlagsFalse();

    timer = new QTimer();
    connect(timer, &QTimer::timeout, this, &MainWindow::slotTimer);
    timer->start(100);
}

void MainWindow::on_pushButton_6_clicked()
{
    scene->setTypeFigure(nullptr);
    setAllFlagsFalse();
    FlagDelete = true;
    ui->graphicsView->setCursor(Qt::ForbiddenCursor);
}

void MainWindow::on_pushButton_7_clicked()
{
    ui->graphicsView->setCursor(Qt::ClosedHandCursor);
    scene->setTypeFigure(nullptr);
    setAllFlagsFalse();
    FlagMove = true;
}

void MainWindow::on_pushButton_8_clicked()
{
    ui->graphicsView->setCursor(Qt::SizeAllCursor);
    scene->setTypeFigure(nullptr);
    setAllFlagsFalse();
    FlagChange = true;
}

void MainWindow::on_pushButton_9_clicked()
{
    ui->graphicsView->setCursor(Qt::ClosedHandCursor);
    scene->setTypeFigure(nullptr);
    setAllFlagsFalse();
    FlagRotate = true;
}

void MainWindow::on_pushButton_10_clicked()
{
    scene->UndoFigure();
}


void MainWindow::on_pushButton_11_clicked()
{
    scene->RedoFigure();
}


void MainWindow::on_redSlider_valueChanged(int value)
{
    r = QString::number(value);

    ui->UsedColor->setStyleSheet("border: 2px solid red; background-color: rgb("+r+", "+g+", "+b+");");

    CurColor = QColor(r.toInt(), g.toInt(), b.toInt());
    pen.setColor(CurColor);
}


void MainWindow::on_greenSlider_valueChanged(int value)
{
    g = QString::number(value);

    ui->UsedColor->setStyleSheet("border: 2px solid red; background-color: rgb("+r+", "+g+", "+b+");");

    CurColor = QColor(r.toInt(), g.toInt(), b.toInt());
    pen.setColor(CurColor);
}


void MainWindow::on_blueSlider_valueChanged(int value)
{
    b = QString::number(value);

    ui->UsedColor->setStyleSheet("border: 2px solid red; background-color: rgb("+r+", "+g+", "+b+");");

    CurColor = QColor(r.toInt(), g.toInt(), b.toInt());
    pen.setColor(CurColor);

}


void MainWindow::on_redSlider_2_valueChanged(int value)
{
    r1 = QString::number(value);

    ui->UsedColor_2->setStyleSheet("border: 2px solid red; background-color: rgb("+r1+", "+g1+", "+b1+");");

    CurBrushColor = QColor(r1.toInt(), g1.toInt(), b1.toInt());
}


void MainWindow::on_greenSlider_2_valueChanged(int value)
{
    g1 = QString::number(value);

    ui->UsedColor_2->setStyleSheet("border: 2px solid red; background-color: rgb("+r1+", "+g1+", "+b1+");");

    CurBrushColor = QColor(r1.toInt(), g1.toInt(), b1.toInt());
}


void MainWindow::on_blueSlider_2_valueChanged(int value)
{
    b1 = QString::number(value);

    ui->UsedColor_2->setStyleSheet("border: 2px solid red; background-color: rgb("+r1+", "+g1+", "+b1+");");

    CurBrushColor = QColor(r1.toInt(), g1.toInt(), b1.toInt());
}


void MainWindow::on_spinBox_valueChanged(int arg1)
{
    CurPenWidth = arg1;
    pen.setWidth(arg1);
}

