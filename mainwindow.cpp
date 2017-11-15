#include "mainwindow.h"
#include "ui_mainwindow.h"


void MainWindow::TypeZero()
{
    QString s = ui->Display->toPlainText();

    s+="0";
    ui->Display->setText(s);
    data_flow->append("0");
ui->WIIMemory->append(data_flow->last());
    ui->N_zero->setChecked(false);
    SIGN=0;
}
void MainWindow::TypeOne()
{
    QString s = ui->Display->toPlainText();
    s+="1";
    ui->Display->setText(s);
    data_flow->append("1");
ui->WIIMemory->append(data_flow->last());
    ui->N_one->setChecked(false);
    SIGN=0;
}
void MainWindow::TypeTwo()
{
    QString s = ui->Display->toPlainText();
    s+="2";
    ui->Display->setText(s);
    data_flow->append("2");
ui->WIIMemory->append(data_flow->last());
    ui->N_two->setChecked(false);
    SIGN=0;
}
void MainWindow::TypeThree()
{
    QString s = ui->Display->toPlainText();
    s+="3";
    ui->Display->setText(s);
    data_flow->append("3");
ui->WIIMemory->append(data_flow->last());
    ui->N_three->setChecked(false);
    SIGN=0;
}
void MainWindow::TypeFour()
{
    QString s = ui->Display->toPlainText();
    s+="4";
    ui->Display->setText(s);
    data_flow->append("4");
ui->WIIMemory->append(data_flow->last());
    ui->N_four->setChecked(false);
    SIGN=0;
}
void MainWindow::TypeFive()
{
    QString s = ui->Display->toPlainText();
    s+="5";
    ui->Display->setText(s);
    data_flow->append("5");
ui->WIIMemory->append(data_flow->last());
    ui->N_five->setChecked(false);
    SIGN=0;
}
void MainWindow::TypeSix()
{
    QString s = ui->Display->toPlainText();
    s+="6";
    ui->Display->setText(s);
    data_flow->append("6");
ui->WIIMemory->append(data_flow->last());
    ui->N_six->setChecked(false);
    SIGN=0;
}
void MainWindow::TypeSeven()
{
    QString s = ui->Display->toPlainText();
    s+="7";
    ui->Display->setText(s);
    data_flow->append("7");
ui->WIIMemory->append(data_flow->last());
    ui->N_seven->setChecked(false);
    SIGN=0;
}
void MainWindow::TypeEight()
{
    QString s = ui->Display->toPlainText();
    s+="8";
    ui->Display->setText(s);
    data_flow->append("8");
ui->WIIMemory->append(data_flow->last());
    ui->N_eight->setChecked(false);
    SIGN=0;
}
void MainWindow::TypeNine()
{
    QString s = ui->Display->toPlainText();
    s+="9";
    ui->Display->setText(s);
    data_flow->append("9");
ui->WIIMemory->append(data_flow->last());
    ui->N_nine->setChecked(false);
    SIGN=0;
}


void MainWindow::TypePoint()
{
    if(POINT==0){
    QString s = ui->Display->toPlainText();
    if(s!=""){
    s+=",";
    ui->Display->setText(s);
    data_flow->append(",");
ui->WIIMemory->append(data_flow->last());
    POINT=1;
    }
    ui->Point->setChecked(false);
    }
}
void MainWindow::TypePlus()
{
    if(SIGN==0 && !data_flow->empty()){
        //QString s = ui->Display->toPlainText();
        //s+="+";
        ui->Display->clear();
        data_flow->append("+");
    ui->WIIMemory->append(data_flow->last());
        ui->Plus->setChecked(false);
        SIGN=1;
        POINT=0;
    }
}
void MainWindow::TypeMinus()
{
    if(SIGN==0 && !data_flow->empty()){
        //QString s = ui->Display->toPlainText();
        //s+="-";
        ui->Display->clear();
        data_flow->append("-");
    ui->WIIMemory->append(data_flow->last());
        ui->Minus->setChecked(false);
        SIGN=1;
        POINT=0;
    }
}
void MainWindow::TypeStar()
{
    if(SIGN==0 && !data_flow->empty()){
        //QString s = ui->Display->toPlainText();
        //s+="*";
        ui->Display->clear();
        data_flow->append("*");
    ui->WIIMemory->append(data_flow->last());
        ui->Multiply->setChecked(false);
        SIGN=1;
        POINT=0;
    }
}
void MainWindow::TypeDiv()
{
    if(SIGN==0 && !data_flow->empty()){
        //QString s = ui->Display->toPlainText();
        //s+="/";
        ui->Display->clear();
        data_flow->append("/");
    ui->WIIMemory->append(data_flow->last());
        ui->Div_div->setChecked(false);
        SIGN=1;
        POINT=0;
    }
}
void MainWindow::TypeMod()
{
    if(SIGN==0 && !data_flow->empty()){
        //QString s = ui->Display->toPlainText();
        //s+="%";
        ui->Display->clear();
        data_flow->append("%");
    ui->WIIMemory->append(data_flow->last());
        ui->Div_mod->setChecked(false);
        SIGN=1;
        POINT=0;
    }
}
void MainWindow::TypeSqrt()
{
    if(SIGN==0 &&!data_flow->empty()){
        //QString s = ui->Display->toPlainText();
        //s+="√";
        ui->Display->clear();
        data_flow->append("√");
    ui->WIIMemory->append(data_flow->last());
        ui->Sqrt_->setChecked(false);
        SIGN=1;
        POINT=0;
    }
}


void MainWindow::ClearAll()
{
    ui->Display->clear();

    data_flow->clear();
ui->WIIMemory->append(QString(data_flow->size()));
SIGN=0;
POINT=0;

}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QTextStream cout(stdout);
    in_memory = new QVector<QString> {};
    data_flow = new QVector<QString> {};


connect(ui->N_zero, SIGNAL(released()), this, SLOT(TypeZero()));
connect(ui->N_one, SIGNAL(released()), this, SLOT(TypeOne()));
connect(ui->N_two, SIGNAL(released()), this, SLOT(TypeTwo()));
connect(ui->N_three, SIGNAL(released()), this, SLOT(TypeThree()));
connect(ui->N_four, SIGNAL(released()), this, SLOT(TypeFour()));
connect(ui->N_five, SIGNAL(released()), this, SLOT(TypeFive()));
connect(ui->N_six, SIGNAL(released()), this, SLOT(TypeSix()));
connect(ui->N_seven, SIGNAL(released()), this, SLOT(TypeSeven()));
connect(ui->N_eight, SIGNAL(released()), this, SLOT(TypeEight()));
connect(ui->N_nine, SIGNAL(released()), this, SLOT(TypeNine()));

connect(ui->Point, SIGNAL(released()), this, SLOT(TypePoint()));
connect(ui->Plus, SIGNAL(released()), this, SLOT(TypePlus()));
connect(ui->Minus, SIGNAL(released()), this, SLOT(TypeMinus()));
connect(ui->Div_div, SIGNAL(released()), this, SLOT(TypeDiv()));
connect(ui->Div_mod, SIGNAL(released()), this, SLOT(TypeMod()));
connect(ui->Multiply, SIGNAL(released()), this, SLOT(TypeStar()));
connect(ui->Sqrt_, SIGNAL(released()), this, SLOT(TypeSqrt()));



connect(ui->C, SIGNAL(released()), this, SLOT(ClearAll()));












}

MainWindow::~MainWindow()
{
    delete ui;
}
