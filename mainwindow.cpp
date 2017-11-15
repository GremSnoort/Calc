#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::TypeMemorySave()
{
    in_memory->clear();
    QString s = ui->Display->toPlainText();
    ui->WIIMemory->setText(s);
    for(int i=0; i<s.size(); i++)
    {
        in_memory->append(s.at(i));

    }

    QTextStream cout(stdout);
    for(int i=0; i<data_flow->size(); i++)
    {
       cout<<data_flow->at(i);

    }
}

void MainWindow::TypeMemoryRead()
{
    if(!in_memory->empty()){
    QString s = ui->Display->toPlainText();
    int y=data_flow->size()-1;
    for(int i=y; i>=y+1-s.size(); i--)
    {
        data_flow->removeAt(i);
    }
    QString ss="";
    for(int i=0; i<in_memory->size(); i++)
    {
        data_flow->append(in_memory->at(i));
        ss+=in_memory->at(i);

    }
    ui->Display->setText(ss);
    QTextStream cout(stdout);
    for(int i=0; i<data_flow->size(); i++)
    {
       cout<<data_flow->at(i);

    }
}

}


void MainWindow::TypeMemoryClear()
{
    in_memory->clear();
    ui->WIIMemory->clear();
    QTextStream cout(stdout);
    for(int i=0; i<data_flow->size(); i++)
    {
       cout<<data_flow->at(i);

    }
}


void MainWindow::TypeDIGIT(QString Arg)
{
    QString s = ui->Display->toPlainText();
    s+=Arg;
    ui->Display->setText(s);
    data_flow->append(Arg);
    SIGN=0;
    forSIGN=0;


//QTextStream cout(stdout);
//cout<<data_flow->last();
}


void MainWindow::TypeZero()
{
    TypeDIGIT("0");
    ui->N_zero->setChecked(false);

}
void MainWindow::TypeOne()
{
    TypeDIGIT("1");
    ui->N_one->setChecked(false);

}
void MainWindow::TypeTwo()
{
    TypeDIGIT("2");
    ui->N_two->setChecked(false);

}
void MainWindow::TypeThree()
{
    TypeDIGIT("3");
    ui->N_three->setChecked(false);

}
void MainWindow::TypeFour()
{
    TypeDIGIT("4");
    ui->N_four->setChecked(false);

}
void MainWindow::TypeFive()
{
    TypeDIGIT("5");
    ui->N_five->setChecked(false);

}
void MainWindow::TypeSix()
{
    TypeDIGIT("6");
    ui->N_six->setChecked(false);

}
void MainWindow::TypeSeven()
{
    TypeDIGIT("7");
    ui->N_seven->setChecked(false);

}
void MainWindow::TypeEight()
{
    TypeDIGIT("8");
    ui->N_eight->setChecked(false);

}
void MainWindow::TypeNine()
{
    TypeDIGIT("9");
    ui->N_nine->setChecked(false);

}


void MainWindow::TypePoint()
{
    if(POINT==0){
    QString s = ui->Display->toPlainText();
    if(s!=""){
    s+=",";
    ui->Display->setText(s);
    data_flow->append(",");
    POINT=1;
    forSIGN=1;


    QTextStream cout(stdout);
    cout<<data_flow->last();
    }
    ui->Point->setChecked(false);
    }
}
void MainWindow::TypePlus()
{
    if(SIGN==0 && forSIGN==0 && !data_flow->empty()){
        //QString s = ui->Display->toPlainText();
        //s+="+";
        ui->Display->clear();
        data_flow->append("+");
        ui->Plus->setChecked(false);
        SIGN=1;
        POINT=0;

        QTextStream cout(stdout);
        cout<<data_flow->last();
    }
}
void MainWindow::TypeMinus()
{
    if(SIGN==0 && forSIGN==0 && !data_flow->empty()){
        //QString s = ui->Display->toPlainText();
        //s+="-";
        ui->Display->clear();
        data_flow->append("-");
        ui->Minus->setChecked(false);
        SIGN=1;
        POINT=0;

        QTextStream cout(stdout);
        cout<<data_flow->last();
    }
}
void MainWindow::TypeStar()
{
    if(SIGN==0 && forSIGN==0 && !data_flow->empty()){
        //QString s = ui->Display->toPlainText();
        //s+="*";
        ui->Display->clear();
        data_flow->append("*");
        ui->Multiply->setChecked(false);
        SIGN=1;
        POINT=0;

        QTextStream cout(stdout);
        cout<<data_flow->last();
    }
}
void MainWindow::TypeDiv()
{
    if(SIGN==0 && forSIGN==0 && !data_flow->empty()){
        //QString s = ui->Display->toPlainText();
        //s+="/";
        ui->Display->clear();
        data_flow->append("/");
        ui->Div_div->setChecked(false);
        SIGN=1;
        POINT=0;

        QTextStream cout(stdout);
        cout<<data_flow->last();
    }
}
void MainWindow::TypeMod()
{
    if(SIGN==0 && forSIGN==0 && !data_flow->empty()){
        //QString s = ui->Display->toPlainText();
        //s+="%";
        ui->Display->clear();
        data_flow->append("%");
        ui->Div_mod->setChecked(false);
        SIGN=1;
        POINT=0;

        QTextStream cout(stdout);
        cout<<data_flow->last();
    }
}
/*void MainWindow::TypeSqrt()
{
    if(SIGN==0 && forSIGN==0 &&!data_flow->empty()){
        //QString s = ui->Display->toPlainText();
        //s+="√";
        ui->Display->clear();
        data_flow->append("√");
    ui->WIIMemory->append(data_flow->last());
        ui->Sqrt_->setChecked(false);
        SIGN=1;
        POINT=0;
    }
}*/


void MainWindow::ClearAll()
{
    ui->Display->clear();

    data_flow->clear();

SIGN=0;
POINT=0;
forSIGN=0;

QTextStream cout(stdout);
cout<<data_flow->size();

}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

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
//connect(ui->Sqrt_, SIGNAL(released()), this, SLOT(TypeSqrt()));

connect(ui->MSave, SIGNAL(released()), this, SLOT(TypeMemorySave()));
connect(ui->MRead, SIGNAL(released()), this, SLOT(TypeMemoryRead()));
connect(ui->MClear, SIGNAL(released()), this, SLOT(TypeMemoryClear()));

connect(ui->C, SIGNAL(released()), this, SLOT(ClearAll()));












}

MainWindow::~MainWindow()
{
    delete ui;
}
