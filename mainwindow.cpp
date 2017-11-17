#include "mainwindow.h"
#include "ui_mainwindow.h"

//_____________________________________

void MainWindow::tmp()
{
    QTextStream cout(stdout);
    cout<<data_flow;

}


//_____________________________________


void MainWindow::TypeMemorySave()
{
    in_memory.clear();
    QString s = ui->Display->toPlainText();
    if(s=="-" || s=="+" || s=="*" || s=="/" || s=="%"){s="";}
    in_memory = s;
    ui->WIIMemory->setText(in_memory);

tmp();

}
void MainWindow::CE()
{
    QString s = ui->Display->toPlainText();
    int y = data_flow.size()-s.size();
    if(!s.isEmpty()){
    data_flow.truncate(y);
    ui->Display->clear();
    SIGN=1;
    }


    tmp();
}

void MainWindow::TypeMemoryRead()
{

    if(!in_memory.isEmpty()){

    QString s = ui->Display->toPlainText();
    if(s=="-" || s=="+" || s=="*" || s=="/" || s=="%"){ui->Display->clear();s="";SIGN=1;}
    if(s!=in_memory && !s.isEmpty()){
        int y = data_flow.size()-s.size();
        data_flow.truncate(y);
        SIGN=1;

    }
    if(SIGN==1 || data_flow.isEmpty()){
    data_flow+=in_memory;
    }

    ui->Display->setText(in_memory);

    SIGN=0;
    forSIGN=0;

    tmp();
}

}


void MainWindow::TypeMemoryClear()
{
    in_memory.clear();
    ui->WIIMemory->clear();
   tmp();
}


void MainWindow::TypeDIGIT(QString Arg)
{
    QString s = ui->Display->toPlainText();
    if(s=="-" || s=="+" || s=="*" || s=="/" || s=="%"){ui->Display->clear();s="";}
    if(s.size()<15){
    s+=Arg;
    ui->Display->setText(s);
    data_flow+=Arg;
    SIGN=0;
    forSIGN=0;

}
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
    if(!(s=="-" || s=="+" || s=="*" || s=="/" || s=="%")){
    if(s!="" && s.size()<14){
    s+=".";
    ui->Display->setText(s);
    data_flow+=".";
    POINT=1;
    forSIGN=1;



    }

    }
    }
ui->Point->setChecked(false);
}

//__________

void MainWindow::TypeSIGN(QString Arg)
{
    if(SIGN==0 && forSIGN==0 && !data_flow.isEmpty()){
        ui->Display->setText(Arg);
        data_flow+=Arg;

        SIGN=1;
        POINT=0;


    }else if(forSIGN==0 && SIGN==1 && !data_flow.isEmpty())
    {
        ui->Display->setText(Arg);
        data_flow.truncate(data_flow.size()-1);
        data_flow+=Arg;

        SIGN=1;
        POINT=0;

    }
 tmp();

}

//__________

void MainWindow::TypePlus()
{
    TypeSIGN("+");
    ui->Plus->setChecked(false);
}
void MainWindow::TypeMinus()
{
    TypeSIGN("-");
    ui->Minus->setChecked(false);
}
void MainWindow::TypeStar()
{    
    TypeSIGN("*");
    ui->Multiply->setChecked(false);
}
void MainWindow::TypeDiv()
{
    TypeSIGN("/");
    ui->Div_div->setChecked(false);
}
void MainWindow::TypeMod()
{
    TypeSIGN("%");
    ui->Div_mod->setChecked(false);
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

    data_flow.clear();


SIGN=0;
POINT=0;
forSIGN=0;

tmp();

}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    QFont MFont("Times", 29, QFont::Bold);
    QFont lFont("Times", 16, QFont::Bold);
    ui->Display->setFont(MFont);
    ui->WIIMemory->setFont(lFont);
    ui->Display->setTextColor(QColor(0, 255, 0));
    ui->WIIMemory->setTextColor(QColor(0, 255, 0));
    QString lstyle = "background-color: rgb(0, 40, 40);";
    ui->Display->setStyleSheet(lstyle);
    ui->WIIMemory->setStyleSheet(lstyle);
    QString style = "color: rgb(0, 255, 0);\n"
                     "font: 87 16pt 'Misc Fixed Wide';\n"
                     "background-color: qconicalgradient(cx:0, cy:0, angle:135, stop:0 rgba(0, 70, 0, 69), stop:0.375 rgba(0, 70, 0, 69), stop:0.423533 rgba(0, 70, 0, 145), stop:0.45 rgba(0, 70, 0, 208), stop:0.477581 rgba(0, 55, 71, 130), stop:0.518717 rgba(0, 40, 71, 130), stop:0.55 rgba(0, 70, 0, 255), stop:0.57754 rgba(0, 50, 0, 130), stop:0.625 rgba(0, 70, 0, 69), stop:1 rgba(0, 70, 0, 69))";

    ui->N_zero->setStyleSheet(style);
    ui->N_one->setStyleSheet(style);
    ui->N_two->setStyleSheet(style);
    ui->N_three->setStyleSheet(style);
    ui->N_four->setStyleSheet(style);
    ui->N_five->setStyleSheet(style);
    ui->N_six->setStyleSheet(style);
    ui->N_seven->setStyleSheet(style);
    ui->N_eight->setStyleSheet(style);
    ui->N_nine->setStyleSheet(style);
    ui->C->setStyleSheet(style);
    ui->CE->setStyleSheet(style);
    ui->Change_plus_minus->setStyleSheet(style);
    ui->Delete_the_last->setStyleSheet(style);
    ui->Div_div->setStyleSheet(style);
    ui->Div_mod->setStyleSheet(style);
    ui->GET_ANSWER->setStyleSheet(style);
    ui->Minus->setStyleSheet(style);
    ui->Sqrt_->setStyleSheet(style);
    ui->MClear->setStyleSheet(style);
    ui->Multiply->setStyleSheet(style);
    ui->MMinus->setStyleSheet(style);
    ui->MPlus->setStyleSheet(style);
    ui->MRead->setStyleSheet(style);
    ui->MSave->setStyleSheet(style);
    ui->Plus->setStyleSheet(style);
    ui->Point->setStyleSheet(style);
    ui->One_div_X->setStyleSheet(style);


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
connect(ui->CE, SIGNAL(released()), this, SLOT(CE()));









}

MainWindow::~MainWindow()
{
    delete ui;
}
