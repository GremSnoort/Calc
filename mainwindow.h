#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QTextBrowser>
#include <QVector>
#include <QString>
#include <QTextStream>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QVector<QString> *in_memory;
    QVector<QString> *data_flow;

int POINT = 0;
int SIGN = 0;


public slots:
    void TypeZero();
    void TypeOne();
    void TypeTwo();
    void TypeThree();
    void TypeFour();
    void TypeFive();
    void TypeSix();
    void TypeSeven();
    void TypeEight();
    void TypeNine();

    void TypePoint();
    void TypePlus();
    void TypeMinus();
    void TypeStar();
    void TypeDiv();
    void TypeMod();
    void TypeSqrt();


    void ClearAll();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H