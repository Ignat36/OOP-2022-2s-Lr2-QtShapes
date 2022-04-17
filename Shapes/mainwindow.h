#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QResizeEvent>

#include "paintscene.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:

    Ui::MainWindow *ui;
    PaintScene *scene;
    QTimer *timer;
    QString r, g, b;
    QString r1, g1, b1;

private:
    /* Переопределяем событие изменения размера окна
     * для пересчёта размеров графической сцены
     * */
    void resizeEvent(QResizeEvent * event);

private slots:
    // Таймер для изменения размеров сцены при изменении размеров Окна приложения
    void slotTimer();
    void on_pushButton_clicked();       // Включаем отрисовку Ромба
    void on_pushButton_2_clicked();     // Включаем отрисовку Квадрата
    void on_pushButton_3_clicked();     // Включаем отрисовку Треугольника
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_9_clicked();
    void on_pushButton_10_clicked();
    void on_pushButton_11_clicked();
    void on_redSlider_valueChanged(int value);
    void on_greenSlider_valueChanged(int value);
    void on_blueSlider_valueChanged(int value);
    void on_redSlider_2_valueChanged(int value);
    void on_greenSlider_2_valueChanged(int value);
    void on_blueSlider_2_valueChanged(int value);
    void on_spinBox_valueChanged(int arg1);
};

#endif // MAINWINDOW_H
