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
#include <math.h>

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
    QString pVSm = "";


int SIGN = 0;
int forSIGN=0;


int FLAG=0;
int ANS=0;

QString Mr="";
QString Ml="";
double Dr;
double Dl;
int right;
int left;

QString pvsm="+";
QString pvsmn="+";
QString MEMORYSIGN="+";

void tmp();
void TypeDIGIT(QString Arg);
void TypeSIGN(QString Arg);
double QStringToDouble(QString s);
void vspm(double D);

void Do_1(int number, int i);


void OutOfRange();

int DoMultiply(int number, int i);
int DoDiv(int number, int i);
int DoMod(int number, int i);

int DoSumm(int number, int i);
int DoDiff(int number, int i);

double functions(QString v);
double Arc(double D);

public slots:

    void ANSWER();


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
    void MemoryPLUS();
    void MemoryMINUS();
    //MEMORY__________________




    //COMPLICATED_SIGN________
    void TypeSqrt();
    void OneDivX();
    void XandX();
    //COMPLICATED_SIGN________


    //RANKS__________________
    void Sinus();
    void Cosinus();
    void Tangens();
    void Cotangens();
    void Arcsinus();
    void Arccosinus();
    void Arctangens();

    void Ln_X();
    void Exp_X();

    //RANKS__________________


    //C_CE_->____________
    void CE();
    void ClearAll();
    void Arrow();
    //C_CE_->____________

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
