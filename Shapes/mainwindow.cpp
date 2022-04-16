#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new PaintScene();
    scene->setTypeFigure(PaintScene::Non);
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
    scene->setTypeFigure(PaintScene::RombType);
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->graphicsView->setCursor(Qt::ArrowCursor);
    scene->setTypeFigure(PaintScene::SquareType);
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->graphicsView->setCursor(Qt::ArrowCursor);
    scene->setTypeFigure(PaintScene::TriangleType);
}

void MainWindow::on_pushButton_4_clicked()
{
    ui->graphicsView->setCursor(Qt::ArrowCursor);
    scene->setTypeFigure(PaintScene::ElipseTtype);
}

void MainWindow::on_pushButton_5_clicked()
{
    scene = new PaintScene();
    scene->setTypeFigure(PaintScene::Non);
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
    scene->setTypeFigure(PaintScene::Non);
    setAllFlagsFalse();
    FlagDelete = true;
    ui->graphicsView->setCursor(Qt::ForbiddenCursor);
}

void MainWindow::on_pushButton_7_clicked()
{
    ui->graphicsView->setCursor(Qt::ClosedHandCursor);
    scene->setTypeFigure(PaintScene::Non);
    setAllFlagsFalse();
    FlagMove = true;
}

void MainWindow::on_pushButton_8_clicked()
{
    ui->graphicsView->setCursor(Qt::SizeAllCursor);
    scene->setTypeFigure(PaintScene::Non);
    setAllFlagsFalse();
    FlagChange = true;
}

void MainWindow::on_pushButton_9_clicked()
{
    ui->graphicsView->setCursor(Qt::ClosedHandCursor);
    scene->setTypeFigure(PaintScene::Non);
    setAllFlagsFalse();
    FlagRotate = true;
}
