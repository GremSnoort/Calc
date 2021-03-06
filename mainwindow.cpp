#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::Do_1(int number, int i)
{
    Mr="";
    Ml="";

    right=i+1;
    left=i-1;
    int y = data_flow.length();
    while(right<y && data_flow.at(right)!="*" && data_flow.at(right)!="/" && data_flow.at(right)!="%" && data_flow.at(right)!="+" && data_flow.at(right)!="-")
    {
        Mr+=data_flow.at(right);
        right++;
    }
    while(left>=0 && data_flow.at(left)!="*" && data_flow.at(left)!="/" && data_flow.at(left)!="%" && data_flow.at(left)!="+" && data_flow.at(left)!="-")
    {
        Ml=data_flow.at(left)+Ml;
        left--;
    }

    Dr = QStringToDouble(Mr);
    Dl = QStringToDouble(Ml);

    QTextStream out(stdout);
    out<<Dr<<"~~~"<<Dl<<endl;


    if(data_flow.at(i)=="*" || data_flow.at(i)=="/" || data_flow.at(i)=="%")
    {
        if((pVSm.at(number)=="-" && pVSm.at(number-1)=="+")||(pVSm.at(number)=="+" && pVSm.at(number-1)=="-"))
        {pVSm.replace(number-1, 2, "-");}
        else
        {pVSm.replace(number-1, 2, "+");}
    }

}

int MainWindow::DoSumm(int number, int i)
{

    Do_1(number, i);
    if(pVSm.at(number-1)=="-") Dl=0-Dl;
    if(pVSm.at(number)=="-") Dr=0-Dr;
    double RES = Dr+Dl;
    if(RES<0) {pVSm.replace(number-1, 2, "-");RES=0-RES;}
    else {pVSm.replace(number-1, 2, "+");}

    data_flow.replace(left+1, right-(left+1), QString::number(RES));

    return left+((QString::number(RES)).length())+1;
}

int MainWindow::DoDiff(int number, int i)
{

    Do_1(number, i);
    if(pVSm.at(number-1)=="-") Dl=0-Dl;
    if(pVSm.at(number)=="-") Dr=0-Dr;
    double RES = Dl-Dr;
    if(RES<0) {pVSm.replace(number-1, 2, "-");RES=0-RES;}
    else {pVSm.replace(number-1, 2, "+");}

    data_flow.replace(left+1, right-(left+1), QString::number(RES));

    return left+((QString::number(RES)).length())+1;
}


int MainWindow::DoMultiply(int number, int i)
{

    Do_1(number, i);
    double RES = Dr*Dl;
    data_flow.replace(left+1, right-(left+1), QString::number(RES));

    return left+((QString::number(RES)).length())+1;
}

int MainWindow::DoDiv(int number, int i)
{

    Do_1(number, i);
    if(Dr==0)
    {
        ClearAll();
        ui->Display->setText("Division by zero");
        return 20;

    }else{
    double RES = Dl/Dr;
    data_flow.replace(left+1, right-(left+1), QString::number(RES));

    return left+((QString::number(RES)).length())+1;
    }
}

int MainWindow::DoMod(int number, int i)
{

    Do_1(number, i);
    if(Dr==0)
    {
        ClearAll();
        ui->Display->setText("Division by zero");
        return 20;

    }else{
    int RES1;
    double RES;
    if(Dl-int(Dl)==0 && Dr-int(Dr)==0){RES1 = int(Dl)%int(Dr);RES=RES1;}else {RES=Dl/Dr;ui->WARN->setText("Warning: non-integer values. Changed % to /.");}

    data_flow.replace(left+1, right-(left+1), QString::number(RES));

    return left+((QString::number(RES)).length())+1;
    }
}

void MainWindow::OutOfRange()
{
    ClearAll();
    ui->Display->setText("Out of range");
    ui->WARN->setText("Values 123e+4567 no computing.");
}

void MainWindow::ANSWER()                                                                           //ANSWER!!!!!!!!!!!!!!!!!!!
{QTextStream out(stdout);
tmp();

    if(pVSm.size()>0){
    if (data_flow.contains("e+") || data_flow.contains("e-")){OutOfRange();}else
    {


    ui->WARN->clear();
pVSm+=pvsm;
    if(SIGN==0 && forSIGN==0  && !data_flow.isEmpty())
    {
        int j = data_flow.length();
        int i = 0;
        int number = 0;

        while(i<j)
        {

            if(data_flow.at(i)=="*" || data_flow.at(i)=="/" || data_flow.at(i)=="%" || data_flow.at(i)=="+" || data_flow.at(i)=="-"){  number+=1;    }

            if(data_flow.at(i)=="*"){i=DoMultiply(number, i);number-=1;}else
            if(data_flow.at(i)=="%"){i=DoMod(number, i);number-=1;}else
            if(data_flow.at(i)=="/"){i=DoDiv(number, i);number-=1;}else i++;

            if (data_flow.contains("e+") || data_flow.contains("e-")){OutOfRange();}

            j = data_flow.length();           
        }

        number =0;
        i=0;
        j=data_flow.length();
         while(i<j)
         {
                if(data_flow.at(i)=="+" || data_flow.at(i)=="-"){  number+=1;    }

                if(data_flow.at(i)=="+"){i=DoSumm(number, i);number-=1;}else
                if(data_flow.at(i)=="-"){i=DoDiff(number, i);number-=1;}else i++;

                if (data_flow.contains("e+") || data_flow.contains("e-")){OutOfRange();}
                j = data_flow.length();
          }


         if(pVSm.size()==1 && !data_flow.isEmpty())
         {
            if(pVSm.at(0)=="-")ui->Display->setText("-"+data_flow);else ui->Display->setText(data_flow);
                pvsm=pVSm.at(0);
                pVSm.clear();

                SIGN=0;
                forSIGN=0;


                FLAG=0;
                ANS=1;


         }


         out<<"~~~~~~~~~~~~~~~~~~~`"<<pVSm.size()<<endl;
         tmp();

    }
    }
}
}


//_____________________________________

void MainWindow::tmp()
{
    QTextStream cout(stdout);
    cout<<data_flow<<endl;

    for(int i=0; i<pVSm.length(); i++){cout<<pVSm.at(i);}

}


//_____________________________________

double MainWindow::QStringToDouble(QString s)
{
    const char* ch = s.toStdString().c_str();
    return atof (ch);
}


//MEMORY_______________________________________________________________________________________________________________________begin~~~~

void MainWindow::TypeMemorySave()               //SAVE
{
    in_memory.clear();
    QString s = ui->Display->toPlainText();
    if(s=="-" || s=="+" || s=="*" || s=="/" || s=="%"){s="";}
    in_memory = s;
    if(pvsm=="-"){in_memory.remove(0,1);}
    MEMORYSIGN=pvsm;
    if(MEMORYSIGN=="-"){ui->WIIMemory->setText(MEMORYSIGN+in_memory);}else{ui->WIIMemory->setText(in_memory);}
ui->WARN->clear();
tmp();

}



void MainWindow::MemoryPLUS()
{
    if(SIGN==0 && forSIGN==0 && !data_flow.isEmpty() && !in_memory.isEmpty())
    {

        QString s = ui->Display->toPlainText();

        double D = QStringToDouble(s);
        double Dm = QStringToDouble(in_memory);
        if(MEMORYSIGN=="-"){Dm=0-Dm;}

        D=D+Dm;
        if(D<0){D=0-D; pvsmn ="-";}else{pvsmn ="+";}

        vspm(D);

        FLAG=1;
    }
ui->WARN->clear();
tmp();

}

void MainWindow::MemoryMINUS()
{
    if(SIGN==0 && forSIGN==0 && !data_flow.isEmpty() && !in_memory.isEmpty())
    {

        QString s = ui->Display->toPlainText();

        double D = QStringToDouble(s);
        double Dm = QStringToDouble(in_memory);
        if(MEMORYSIGN=="-"){Dm=0-Dm;}

        D=D-Dm;
        if(D<0){D=0-D; pvsmn="-";}else{pvsmn="+";}

        vspm(D);

        FLAG=1;
    }
ui->WARN->clear();
tmp();
}




void MainWindow::TypeMemoryRead()               //READ
{

    if(!in_memory.isEmpty()){

    QString s = ui->Display->toPlainText();
    if(s=="-" || s=="+" || s=="*" || s=="/" || s=="%"){ui->Display->clear();s="";SIGN=1;}
    if(s!=in_memory && !s.isEmpty()){
        int y = data_flow.size()-s.size();
        if(pvsm=="-"){y+=1;}
        data_flow.truncate(y);
        SIGN=1;

    }
    if(SIGN==1 || data_flow.isEmpty()){
    data_flow+=in_memory;
    }

    if(MEMORYSIGN=="-"){ui->Display->setText("-"+in_memory);}else{ui->Display->setText(in_memory);}

    SIGN=0;
    forSIGN=0;
    pvsm=MEMORYSIGN;

ui->WARN->clear();
    tmp();
}

}


void MainWindow::TypeMemoryClear()                  //CLEAR
{
    in_memory.clear();
    ui->WIIMemory->clear();
    MEMORYSIGN="+";
    ui->WARN->clear();
   tmp();
}

//MEMORY_______________________________________________________________________________________________________________________end~~~~




//DIGITS_ONLY__________________________________________________________________________________________________________________begin~~~~

void MainWindow::TypeDIGIT(QString Arg)
{
    if(FLAG==1){CE(); FLAG=0;}
    if(ANS==1){ClearAll();ANS=0;}

    QString s = ui->Display->toPlainText();
    if(data_flow.isEmpty() && !s.isEmpty()){ui->Display->clear();s="";}

    if(s=="-" || s=="+" || s=="*" || s=="/" || s=="%"){ui->Display->clear();s="";}
    if(s.size()<12){
    s+=Arg;
    ui->Display->setText(s);
    data_flow+=Arg;
    SIGN=0;
    forSIGN=0;
ui->WARN->clear();
}

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

//DIGITS_ONLY__________________________________________________________________________________________________________________end~~~~




//SIMPLE_SIGN_ONLY___________________________________________________________________________________________________________________begin~~~~

void MainWindow::TypeSIGN(QString Arg)
{
        if(SIGN==0 && forSIGN==0 && !data_flow.isEmpty()){
        ui->Display->setText(Arg);
        data_flow+=Arg;
        pVSm+=pvsm;
        pvsm="+";

        SIGN=1;

        FLAG=0;
        ANS=0;
ui->WARN->clear();


    }else if(forSIGN==0 && SIGN==1 && !data_flow.isEmpty())
    {
        ui->Display->setText(Arg);
        data_flow.truncate(data_flow.size()-1);
        data_flow+=Arg;

        SIGN=1;


        FLAG=0;
        ANS=0;
ui->WARN->clear();

    }
 tmp();

}


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

//~SIGN_ONLY___________________________________________________________________________________________________________________


//MORE_COMPLICATED_SIGNS_____________________________________________________________________________________________________________


void MainWindow::TypeSqrt()
{
    if(pvsm=="+" && SIGN==0 && forSIGN==0 &&!data_flow.isEmpty()){
        QString s = ui->Display->toPlainText();

        double D = QStringToDouble(s);
        D=sqrt(D);
        pvsmn=pvsm;
        vspm(D);

        FLAG=1;

        ui->WARN->clear();

    }else if(pvsm=="-"){ui->WARN->setText("Exception: sqrt of negative value. No computing.");}
    tmp();
}


void MainWindow::XandX()
{
    if(SIGN==0 && forSIGN==0 && !data_flow.isEmpty())
    {
        QString s = ui->Display->toPlainText();
        if(pvsm=="-"){s.remove(0,1);}
        double D = QStringToDouble(s);
        D=D*D;
        pvsmn="+";
        vspm(D);

        FLAG=1;

        ui->WARN->clear();

    }
    tmp();
}


void MainWindow::OneDivX()
{
    if(SIGN==0 && forSIGN==0 && !data_flow.isEmpty())
    {
        QString s = ui->Display->toPlainText();

        if(pvsm=="-"){s.remove(0,1);}
        double D = QStringToDouble(s);
        if(D!=0.000000000)
        {
            D=1/D;
            pvsmn=pvsm;
            vspm(D);

            FLAG=1;

            ui->WARN->clear();

        }else
        {
            ui->WARN->setText("Exception: division by zero. No computing.");

        }




    }
    tmp();

}


void MainWindow::vspm(double D)
{
    QString out = QString::number(D);


    CE();
    pvsm=pvsmn;
    if(pvsm=="-"){ui->Display->setText("-"+out);}else
   { ui->Display->setText(out);}
    data_flow+=out;
    SIGN=0; forSIGN=0;
}

//~MORE_COMPLICATED_SIGNS______________________________________________________________________________________________________________

//RANKS______________________________________________________________



void MainWindow::Sinus()
{
    if(SIGN==0 && forSIGN==0 && !data_flow.isEmpty())
    {        
        QString s = ui->Display->toPlainText();
        double D = QStringToDouble(s);
        double RES;
        D=D-(360*int(D/360));
        if(D==0 || D==180){RES=0;}else{
        D=D*3.1415926535897932384626433832795/180;
        RES = sin(D);}
        if(RES<0){pvsmn="-";RES=-RES;}else if(RES>=0){pvsmn="+";}
        vspm(RES);
        FLAG=1;
        ui->WARN->setText("Arg in grad.");
    }

}

void MainWindow::Cosinus()
{
    if(SIGN==0 && forSIGN==0 && !data_flow.isEmpty())
    {
        QString s = ui->Display->toPlainText();
        double D = QStringToDouble(s);
        double RES;
        D=D-(360*int(D/360));
        if(D==90 || D==270){RES=0;}else{
        D=D*3.1415926535897932384626433832795/180;
        RES = cos(D);}
        if(RES<0){pvsmn="-";RES=-RES;}else if(RES>=0){pvsmn="+";}
        vspm(RES);
        FLAG=1;
        ui->WARN->setText("Arg in grad.");
    }

}

void MainWindow::Tangens()
{
    if(SIGN==0 && forSIGN==0 && !data_flow.isEmpty())
    {
    QString s = ui->Display->toPlainText();
    double D = QStringToDouble(s);
    double RES;
    D=D-(360*int(D/360));
    if(D==90 || D==270){ui->WARN->setText("Non exist.");}else{
    D=D*3.1415926535897932384626433832795/180;
    RES = tan(D);

    if(RES<0){pvsmn="-";RES=-RES;}else {pvsmn="+";}
    vspm(RES);
    FLAG=1;
    ui->WARN->setText("Arg in grad.");
    }

}
}

void MainWindow::Cotangens()
{
    if(SIGN==0 && forSIGN==0 && !data_flow.isEmpty())
    {
    QString s = ui->Display->toPlainText();
    double D = QStringToDouble(s);
    double RES;
    D=D-(360*int(D/360));
    if(D==0 || D==180){ui->WARN->setText("Non exist.");}else{
    D=D*3.1415926535897932384626433832795/180;
    RES = 1/tan(D);

    if(RES<0){pvsmn="-";RES=-RES;}else {pvsmn="+";}
    vspm(RES);
    FLAG=1;
    ui->WARN->setText("Arg in grad.");
    }
}
}


void MainWindow::Arcsinus()
{
    if(SIGN==0 && forSIGN==0 && !data_flow.isEmpty())
    {
        QString s = ui->Display->toPlainText();
        double D = QStringToDouble(s);

        if(D>=-1 && D<=1){

        long double RES = asin(D);

        if(RES<0){pvsmn="-";RES=-RES;}else {pvsmn="+";}
        vspm(RES);
        FLAG=1;
        ui->WARN->setText("Answer in rad.");
        }else {ui->WARN->setText("x should be in range [-1; 1].");}
}
}

void MainWindow::Arccosinus()
{
    if(SIGN==0 && forSIGN==0 && !data_flow.isEmpty())
    {
        QString s = ui->Display->toPlainText();
        double D = QStringToDouble(s);

        if(D>=-1 && D<=1){

        long double RES = acos(D);

        if(RES<0){pvsmn="-";RES=-RES;}else {pvsmn="+";}
        vspm(RES);
        FLAG=1;
        ui->WARN->setText("Answer in rad.");
        }else {ui->WARN->setText("x should be in range [-1; 1].");}

}
}

void MainWindow::Arctangens()
{
    if(SIGN==0 && forSIGN==0 && !data_flow.isEmpty())
    {
        QString s = ui->Display->toPlainText();
        double D = QStringToDouble(s);

        double RES = atan(D);

        if(RES<0){pvsmn="-";RES=-RES;}else {pvsmn="+";}
        vspm(RES);
        FLAG=1;
        ui->WARN->setText("Answer in rad.");
    }
}

void MainWindow::RadTOgrad()
{
    if(SIGN==0 && forSIGN==0 && !data_flow.isEmpty())
    {
        QString s = ui->Display->toPlainText();
        double D = QStringToDouble(s);
        D = D*180/3.1415926535897932384626433832795;
        if(D<0){pvsmn="-";D=-D;}else {pvsmn="+";}
        vspm(D);
        FLAG=1;
    }

}

void MainWindow::Ln_X()
{
    if(SIGN==0 && forSIGN==0 && !data_flow.isEmpty())
    {
        QString s = ui->Display->toPlainText();
        double D = QStringToDouble(s);


        if(D>0)
        {
            double RES = log(D);
            if(RES<0){pvsmn="-";RES=-RES;}else if(RES>=0){pvsmn="+";}
            vspm(RES);
            FLAG=1;
            ui->WARN->clear();
        }else {
            ui->WARN->setText("Negative value!");
        }
}
}

void MainWindow::Exp_X()
{
    if(SIGN==0 && forSIGN==0 && !data_flow.isEmpty())
    {
        QString s = ui->Display->toPlainText();
        double D = QStringToDouble(s);
        double D1=D;
        double F=1;
        double RES=1;
        for(int i=1; i<72; i++)
        {
            F*=i;
            RES+=D/F;
            D*=D1;
        }


        if(RES<0){pvsmn="-";RES=-RES;}else if(RES>=0){pvsmn="+";}
        vspm(RES);
        FLAG=1;
        ui->WARN->clear();
    }
}


//~RANKS_____________________________________________________________


//C_CE_->____________________________________________________________________________________________________________________
void MainWindow::ClearAll()             //C
{
    ui->Display->clear();

    data_flow.clear();
    pVSm.clear();
    pvsm="+";


SIGN=0;

forSIGN=0;

FLAG=0;

ui->WARN->clear();
tmp();

}

void MainWindow::CE()                   //CE
{
    QString s = ui->Display->toPlainText();
    if(!(s=="-" || s=="+" || s=="*" || s=="/" || s=="%")){
    int y = data_flow.size()-s.size();
    if(pvsm=="-"){y+=1;}
    if(!s.isEmpty()){
    data_flow.truncate(y);
    ui->Display->clear();
    SIGN=1;

    pvsm="+";

    ui->WARN->clear();
    }

    }
    tmp();
}


void MainWindow::Arrow()                //->
{
    QString s = ui->Display->toPlainText();
    if(!(s=="-" || s=="+" || s=="*" || s=="/" || s=="%" || s=="")){
        if(s.length()>2 && s.at(s.length()-2)=="."){forSIGN=1;}
        if(s.at(s.length()-1)=="."){forSIGN=0;}
        s.remove(s.length()-1, 1);
        data_flow.remove(data_flow.length()-1, 1);
        if(s=="-"){s="";pvsm="+";}
        if(s==""){SIGN=1;}

        ui->Display->setText(s);

        ui->WARN->clear();
    }
tmp();
}

//~C_CE_->_____________________________________________________________________________________________________________________






void MainWindow::TypePoint()
{

    if(forSIGN==0 && ANS==0){
    QString s = ui->Display->toPlainText();
    if(!(s=="-" || s=="+" || s=="*" || s=="/" || s=="%")){
    if(s!="" && s.size()<14){
    s+=".";
    ui->Display->setText(s);
    data_flow+=".";

    forSIGN=1;


ui->WARN->clear();
    }

    }
    }
ui->Point->setChecked(false);
}


void MainWindow::changePtoM()
{
    QString s = ui->Display->toPlainText();
    if(s!="" && s!="/" && s!="%" && s!="+" && s!="-" && s!="*"){
    if(pvsm=="+")
    {
        pvsm="-";
        QString s = ui->Display->toPlainText();
        ui->Display->setText("-"+s);

        ui->WARN->clear();
    }
    else
    {
        pvsm="+";
        QString s = ui->Display->toPlainText();
        if(s.at(0)=="-")
        {
            s.remove(0, 1);
            ui->Display->setText(s);

            ui->WARN->clear();
        }
    }
    }
}




MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);



    //STYLE______________________________________________________________________

    QFont MFont("Times", 29, QFont::Bold);
    QFont lFont("Misc Fixed", 11, QFont::Bold);
    QFont memoryFont("Times", 16, QFont::Bold);
    ui->Display->setFont(MFont);
    ui->WIIMemory->setFont(memoryFont);
    ui->WARN->setFont(lFont);
    ui->Display->setTextColor(QColor(0, 255, 0));
    ui->WIIMemory->setTextColor(QColor(0, 255, 0));
    ui->WARN->setTextColor(QColor(255, 0, 0));
    QString lstyle = "background-color: rgb(0, 40, 40);";
    ui->Display->setStyleSheet(lstyle);
    ui->WIIMemory->setStyleSheet(lstyle);
    QString style = "color: rgb(0, 255, 0);\n"
                     "font: 87 16pt 'Misc Fixed';\n"
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
    ui->XinSquare->setStyleSheet(style);
    ui->SinusX->setStyleSheet(style);
    ui->CosinusX->setStyleSheet(style);
    ui->TgX->setStyleSheet(style);
    ui->CtgX->setStyleSheet(style);
    ui->LnX->setStyleSheet(style);
    ui->ExpX->setStyleSheet(style);
    ui->ArccosX->setStyleSheet(style);
    ui->ArcsinX->setStyleSheet(style);
    ui->ArctgX->setStyleSheet(style);
    ui->radTOgrad->setStyleSheet(style);

    //~STYLE________________________________________________________________________


connect(ui->GET_ANSWER, SIGNAL(released()), this, SLOT(ANSWER()));




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
connect(ui->One_div_X, SIGNAL(released()), this, SLOT(OneDivX()));
connect(ui->XinSquare, SIGNAL(released()), this, SLOT(XandX()));



connect(ui->SinusX, SIGNAL(released()), this, SLOT(Sinus()));
connect(ui->CosinusX, SIGNAL(released()), this, SLOT(Cosinus()));
connect(ui->TgX, SIGNAL(released()), this, SLOT(Tangens()));
connect(ui->CtgX, SIGNAL(released()), this, SLOT(Cotangens()));
connect(ui->ArcsinX, SIGNAL(released()), this, SLOT(Arcsinus()));
connect(ui->ArccosX, SIGNAL(released()), this, SLOT(Arccosinus()));
connect(ui->ArctgX, SIGNAL(released()), this, SLOT(Arctangens()));

connect(ui->LnX, SIGNAL(released()), this, SLOT(Ln_X()));
connect(ui->ExpX, SIGNAL(released()), this, SLOT(Exp_X()));

connect(ui->radTOgrad, SIGNAL(released()), this, SLOT(RadTOgrad()));



connect(ui->MSave, SIGNAL(released()), this, SLOT(TypeMemorySave()));
connect(ui->MPlus, SIGNAL(released()), this, SLOT(MemoryPLUS()));
connect(ui->MMinus, SIGNAL(released()), this, SLOT(MemoryMINUS()));
connect(ui->MRead, SIGNAL(released()), this, SLOT(TypeMemoryRead()));
connect(ui->MClear, SIGNAL(released()), this, SLOT(TypeMemoryClear()));


connect(ui->C, SIGNAL(released()), this, SLOT(ClearAll()));
connect(ui->CE, SIGNAL(released()), this, SLOT(CE()));
connect(ui->Delete_the_last, SIGNAL(released()), this, SLOT(Arrow()));



connect(ui->Change_plus_minus, SIGNAL(released()), this, SLOT(changePtoM()));








}

MainWindow::~MainWindow()
{
    delete ui;
}
