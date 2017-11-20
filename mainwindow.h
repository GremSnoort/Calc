#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QTextBrowser>
#include <QVector>
#include <QString>
#include <QTextStream>
#include <QFont>
#include <QtMath>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QString in_memory="";
    QString data_flow="";
    QVector<QString> *pVSm;

int POINT = 0;
int SIGN = 0;
int forSIGN=0;
int SQRT=0;

QString pvsm="+";

void tmp();
void TypeDIGIT(QString Arg);
void TypeSIGN(QString Arg);

public slots:
    //DIGITS________________
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
    //DIGITS________________




    void TypePoint();
    void changePtoM();

    //SIMPLE_SIGN_____________
    void TypePlus();
    void TypeMinus();
    void TypeStar();
    void TypeDiv();
    void TypeMod();
    //SIMPLE_SIGN_____________



    //MEMORY__________________
    void TypeMemorySave();
    void TypeMemoryRead();
    void TypeMemoryClear();
    //MEMORY__________________




    //COMPLICATED_SIGN________
    void TypeSqrt();
    //COMPLICATED_SIGN________


    //C_CE_->____________
    void CE();
    void ClearAll();
    void Arrow();
    //C_CE_->____________

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
