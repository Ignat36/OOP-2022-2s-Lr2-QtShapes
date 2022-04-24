#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    globs = new GlobParams();
    scene = new PaintScene();
    scene->setTypeFigure(nullptr);
    scene->globs = globs;
    scene->FiguresView = ui->textBrowser;
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setCacheMode(QGraphicsView::CacheBackground);
    ui->graphicsView->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    ui->graphicsView->setCursor(Qt::ArrowCursor);


    r = g = b = "0";
    r1 = g1 = b1 = "255";

    timer = new QTimer();
    connect(timer, &QTimer::timeout, this, &MainWindow::slotTimer);
    timer->start(100);

    ui->comboBox->addItem("");
    shapes[""] = nullptr;
    shapes["Треугольник"] = new Triangle(globs, QPointF()); ui->comboBox->addItem("Треугольник");
    shapes["Прямоугольник"] = new Square(globs, QPointF()); ui->comboBox->addItem("Прямоугольник");
    shapes["Ромб"] = new Romb(globs, QPointF()); ui->comboBox->addItem("Ромб");
    shapes["Элипс"] = new Elipse(globs, QPointF()); ui->comboBox->addItem("Элипс");

    QFile libs("additionalFigures\\LibrariesPathes.txt");

    if(!libs.open(QIODevice::ReadOnly))
    {
        qDebug() << "Can not open libs pathes file";
        return;
    }

    QTextStream in(&libs);
    while(!in.atEnd())
    {
        QString path = in.readLine();

        QLibrary lib(path);

        if (!lib.load())
        {
            qDebug() << lib.errorString();
            continue;
        }
        typedef Figure* (*Prototype)();
        Prototype  func = (Prototype) lib.resolve("getShape");

        if(func)
        {
            Figure* tmp = func();
            tmp->globs = globs;
            shapes[tmp->getName()] = tmp;
            ui->comboBox->addItem(tmp->getName());
        }
    }
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
    scene->setTypeFigure(new Romb(globs, QPointF()));
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->graphicsView->setCursor(Qt::ArrowCursor);
    scene->setTypeFigure(new Square(globs, QPointF()));
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->graphicsView->setCursor(Qt::ArrowCursor);
    scene->setTypeFigure(new Triangle(globs, QPointF()));
}

void MainWindow::on_pushButton_4_clicked()
{
    ui->graphicsView->setCursor(Qt::ArrowCursor);
    scene->setTypeFigure(new Elipse(globs, QPointF()));
}

void MainWindow::on_pushButton_5_clicked()
{
    scene = new PaintScene();
    scene->setTypeFigure(nullptr);
    scene->globs = globs;
    scene->FiguresView = ui->textBrowser;
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setCacheMode(QGraphicsView::CacheBackground);
    ui->graphicsView->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    ui->graphicsView->setCursor(Qt::ArrowCursor);
    globs->setAllFlagsFalse();
    ui->comboBox->setCurrentIndex(0);

    timer = new QTimer();
    connect(timer, &QTimer::timeout, this, &MainWindow::slotTimer);
    timer->start(100);
}

void MainWindow::on_pushButton_6_clicked()
{
    ui->comboBox->setCurrentIndex(0);
    scene->setTypeFigure(nullptr);
    globs->setAllFlagsFalse();
    globs->FlagDelete = true;
    ui->graphicsView->setCursor(Qt::ForbiddenCursor);
}

void MainWindow::on_pushButton_7_clicked()
{
    ui->comboBox->setCurrentIndex(0);
    ui->graphicsView->setCursor(Qt::ClosedHandCursor);
    scene->setTypeFigure(nullptr);
    globs->setAllFlagsFalse();
    globs->FlagMove = true;
}

void MainWindow::on_pushButton_8_clicked()
{
    ui->comboBox->setCurrentIndex(0);
    ui->graphicsView->setCursor(Qt::SizeAllCursor);
    scene->setTypeFigure(nullptr);
    globs->setAllFlagsFalse();
    globs->FlagChange = true;
}

void MainWindow::on_pushButton_9_clicked()
{
    ui->comboBox->setCurrentIndex(0);
    ui->graphicsView->setCursor(Qt::ClosedHandCursor);
    scene->setTypeFigure(nullptr);
    globs->setAllFlagsFalse();
    globs->FlagRotate = true;
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

    globs->CurColor = QColor(r.toInt(), g.toInt(), b.toInt());
    globs->pen.setColor(globs->CurColor);
}


void MainWindow::on_greenSlider_valueChanged(int value)
{
    g = QString::number(value);

    ui->UsedColor->setStyleSheet("border: 2px solid red; background-color: rgb("+r+", "+g+", "+b+");");

    globs->CurColor = QColor(r.toInt(), g.toInt(), b.toInt());
    globs->pen.setColor(globs->CurColor);
}


void MainWindow::on_blueSlider_valueChanged(int value)
{
    b = QString::number(value);

    ui->UsedColor->setStyleSheet("border: 2px solid red; background-color: rgb("+r+", "+g+", "+b+");");

    globs->CurColor = QColor(r.toInt(), g.toInt(), b.toInt());
    globs->pen.setColor(globs->CurColor);

}


void MainWindow::on_redSlider_2_valueChanged(int value)
{
    r1 = QString::number(value);

    ui->UsedColor_2->setStyleSheet("border: 2px solid red; background-color: rgb("+r1+", "+g1+", "+b1+");");

    globs->CurBrushColor = QColor(r1.toInt(), g1.toInt(), b1.toInt());
}


void MainWindow::on_greenSlider_2_valueChanged(int value)
{
    g1 = QString::number(value);

    ui->UsedColor_2->setStyleSheet("border: 2px solid red; background-color: rgb("+r1+", "+g1+", "+b1+");");

    globs->CurBrushColor = QColor(r1.toInt(), g1.toInt(), b1.toInt());
}


void MainWindow::on_blueSlider_2_valueChanged(int value)
{
    b1 = QString::number(value);

    ui->UsedColor_2->setStyleSheet("border: 2px solid red; background-color: rgb("+r1+", "+g1+", "+b1+");");

    globs->CurBrushColor = QColor(r1.toInt(), g1.toInt(), b1.toInt());
}


void MainWindow::on_spinBox_valueChanged(int arg1)
{
    globs->CurPenWidth = arg1;
    globs->pen.setWidth(arg1);
}


void MainWindow::on_checkBox_clicked(bool checked)
{
    globs->FlagBrush = checked;
}


void MainWindow::on_pushButton_13_clicked()
{
    ui->comboBox->setCurrentIndex(0);
    ui->graphicsView->setCursor(Qt::WhatsThisCursor);
    scene->setTypeFigure(nullptr);
    globs->setAllFlagsFalse();
    globs->FlagCopy = true;
}

void MainWindow::on_pushButton_12_clicked()
{
    scene->updateFiguresList();
}




void MainWindow::on_comboBox_currentTextChanged(const QString &arg1)
{
    ui->graphicsView->setCursor(Qt::ArrowCursor);
    scene->setTypeFigure(shapes[arg1]);
}


void MainWindow::on_comboBox_textActivated(const QString &arg1)
{
    ui->graphicsView->setCursor(Qt::ArrowCursor);
    scene->setTypeFigure(shapes[arg1]);
}

