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
int onedivx=0;
int MPLUS=0;
int MMINUS=0;

QString pvsm="+";
QString pvsmn="+";
QString MEMORYSIGN="+";

void tmp();
void TypeDIGIT(QString Arg);
void TypeSIGN(QString Arg);
double QStringToDouble(QString s);
void vspm(double D);


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
    void MemoryPLUS();
    void MemoryMINUS();
    //MEMORY__________________




    //COMPLICATED_SIGN________
    void TypeSqrt();
    void OneDivX();
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
