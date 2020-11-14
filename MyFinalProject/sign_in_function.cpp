#include "sign_in_function.h"
#include "ui_sign_in_function.h"

using namespace std;
Sign_in_function::Sign_in_function(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Sign_in_function)
{
    ui->setupUi(this);
    statuus=new QStatusBar(this);
    I_VECTOR=0;

}

Sign_in_function::~Sign_in_function()
{
    delete ui;
}

void Sign_in_function::on_Login_clicked()
{
    vector <Building> VEC_BUILDING;
    Person *new_user;
    statuus=new QStatusBar();
    QString _username,_pass,_birthday,_credit,_name,_status,temp="s";
    int i,stat=-1;
    QString username=ui->username->text();
    QString password=ui->password->text();
    QString temp1="",temp2="";
    QFile MyFile(":/new/prefix1/users.txt");
    if(!MyFile.open(QFile::ReadOnly | QFile::Text))
        QMessageBox::information(this,"not found","problem");
    if(!MyFile.exists())
            qDebug() << "NO existe el archivo ";
    QTextStream in(&MyFile);
    in>>_username>>_pass>>_credit>>_birthday>>_name>>_status;
    stat=-1;
    while(temp!="") {
        //qDebug()<<"hoy1";
        if(_username==username){
          //  qDebug()<<"hoy2";
            if(_pass==password){
            //    qDebug()<<"hoy";
                stat=1;
                break;
            }
            else {
                stat=0;
             //   qDebug()<<"hoy3";
            }
        }
        in>>_username>>_pass>>_credit>>_birthday>>_name>>_status;
        temp=_username;
    }
    MyFile.close();
    if(stat==0)
    ui->label_3->setText("Wrong Password");
    else if(stat==-1)
        ui->label_3->setText("Wrong Username");
    else if(stat==1){
        QString _type,_case,tempp="S",_rentn,_selln;
        new_user=new Person();
        ui->label_3->setText("successfull");
        new_user->set_credit(_credit);
        new_user->set_birthday(_birthday);
        new_user->set_fullname(_name);
        new_user->set_password(_pass);
        new_user->set_username(_username);
        new_user->set_user_stat(_status);
        QFile ireadit(":/new/prefix2/FLATS.txt");
        ireadit.open(QIODevice::ReadOnly);
        if(MyFile.exists())
                qDebug() << "test";
        QTextStream tushe(&ireadit);
        tushe>>_rentn>>_selln;
        qDebug()<<"RENTI="<<_rentn;
        qDebug()<<"sELLI="<<_selln;

        for(int i=0;i<_rentn.toInt();i++){
            tushe>>_type;

            if(_type=="NV"){
                // qDebug()<<"ERGDjhgjhSDFG";
                QString _CONS_AREA,_FRONT,_BACK,_ROOMNO,_BASE_PRICE,_ADDRESS,RENT_DURATION,_PERSON;
                tushe>>_CONS_AREA>>_FRONT>>_BACK>>_ROOMNO>>_BASE_PRICE>>_ADDRESS>>RENT_DURATION>>_PERSON;
                rent *temp=new rent();
                temp->set_building("NV");
                temp->set_buildingtype("NV");
                temp->get_nvilla()->set_backyard(_BACK);
                temp->get_nvilla()->set_frontyard(_FRONT);
                temp->get_nvilla()->set_room(_ROOMNO);
                temp->get_nvilla()->set_owner(_PERSON);
                temp->get_nvilla()->set_address(_ADDRESS);
                QString faas=QString::number(_BACK.toDouble()+_FRONT.toDouble()+_CONS_AREA.toDouble());
                temp->get_nvilla()->set_tot_area(faas);
                temp->get_nvilla()->set_cons_area(_CONS_AREA);
                temp->get_nvilla()->set_base_price(_BASE_PRICE);
                double temppp=_BACK.toDouble()*_BASE_PRICE.toDouble()*0.15+_FRONT.toDouble()*_BASE_PRICE.toDouble()*0.3+_CONS_AREA.toDouble()*_BASE_PRICE.toDouble();
                temp->get_nvilla()->set_tot_price(QString::number(temppp));
                temp->set_rent_duration(RENT_DURATION);
                temp->set_rahn(QString::number(temppp*0.05));
                temp->set_tent_amount(QString::number(temppp*0.01));
                temp->set_commision("0.03");
                temp->set_final_price();
                myrent.push_back(*temp);
                 qDebug()<<"NV added";
            }
            if(_type=="SV"){
                 qDebug()<<"46646";
                QString _CONS_AREA,_YARD,_PARKING,_ROOMNO,_BASE_PRICE,_ADDRESS,_DURATION,_PERSON;
                tushe>>_CONS_AREA>>_YARD>>_PARKING>>_ROOMNO>>_BASE_PRICE>>_ADDRESS>>_DURATION>>_PERSON;
                rent temp;
                temp.set_building("SV");
                temp.set_buildingtype("SV");
                temp.get_svilla()->set_yard(_YARD);
                temp.get_svilla()->set_parking(_PARKING);
                temp.get_svilla()->set_room(_ROOMNO);
                temp.get_svilla()->set_owner(_PERSON);
                temp.get_svilla()->set_address(_ADDRESS);
                QString faas=QString::number(_YARD.toDouble()+_PARKING.toDouble()+_CONS_AREA.toDouble());
                temp.get_svilla()->set_tot_area(faas);
                temp.get_svilla()->set_cons_area(_CONS_AREA);
                temp.get_svilla()->set_base_price(_BASE_PRICE);
                double temppp=_YARD.toDouble()*_BASE_PRICE.toDouble()*0.3+_PARKING.toDouble()*_BASE_PRICE.toDouble()*0.15+_CONS_AREA.toDouble()*_BASE_PRICE.toDouble();
                temp.get_svilla()->set_tot_price(QString::number(temppp));
                temp.set_rent_duration(_DURATION);
                temp.set_rahn(QString::number(temppp*0.05));
                temp.set_tent_amount(QString::number(temppp*0.01));
                temp.set_commision("0.03");
                temp.set_final_price();
                myrent.push_back(temp);
                 qDebug()<<"SV added";
            }
            if(_type=="AP"){
                QString _FLOOR,_TOT_AREA,ELEVATOR,ADDRESS,_BASE_PRICE,_II,_SELLING;
                tushe>>_TOT_AREA>>_BASE_PRICE>>ELEVATOR>>_FLOOR>>ADDRESS>>_II;
                 apartment* yohu=new apartment();
                 yohu->set_floor(_FLOOR);
                 yohu->set_house(_II);
                 yohu->set_elevator(ELEVATOR);
                 for(int i=0;i<_II.toInt();i++){
                     QString __cons,__room,__floor,__person,__usage,duru;
                     tushe>>__floor>>__room>>__cons>>__person>>__usage>>duru;
                     rent germ;
                     germ.set_building("AP");
                     germ.set_buildingtype("AP");
                     germ.set_rent_duration(duru);
                     germ.set_commision("0.03");
                     germ.set_rahn(QString::number(__cons.toDouble()*_BASE_PRICE.toDouble()*0.05));
                     germ.set_tent_amount(QString::number(__cons.toDouble()*_BASE_PRICE.toDouble()*0.01));
                     germ.get_tiny()->set_nest(yohu);
                     germ.get_tiny()->set_floor(__floor);
                     germ.get_tiny()->set_usage(__usage);
                     germ.get_tiny()->set_room(__room);
                     germ.get_tiny()->set_owner(__person);
                     germ.get_tiny()->set_address(ADDRESS);
                     germ.get_tiny()->set_tot_area(_TOT_AREA);
                     germ.get_tiny()->set_cons_area(__cons);
                     germ.get_tiny()->set_base_price(_BASE_PRICE);
                     germ.get_tiny()->set_tot_price(QString::number(__cons.toDouble()*_BASE_PRICE.toDouble()));
                     germ.set_final_price();
                     myrent.push_back(germ);
                      qDebug()<<"AP added";
                 }
            }
        }
        for(int i=0;i<_selln.toInt();i++){
            tushe>>_type;
            qDebug()<<"sexi="<<_type;
            if(_type=="NV"){
                QString _CONS_AREA,_FRONT,_BACK,_ROOMNO,_BASE_PRICE,_ADDRESS,SELLING,_PERSON;
                tushe>>_CONS_AREA>>_FRONT>>_BACK>>_ROOMNO>>_BASE_PRICE>>_ADDRESS>>SELLING>>_PERSON;
                sell temp;temp.set_vuilding("NV");
                temp.set_buildingtype("NV");
                temp.get_nvilla()->set_backyard(_BACK);
                temp.get_nvilla()->set_frontyard(_FRONT);
                temp.get_nvilla()->set_room(_ROOMNO);
                temp.get_nvilla()->set_owner(_PERSON);
                temp.get_nvilla()->set_address(_ADDRESS);
                QString faas=QString::number(_BACK.toDouble()+_FRONT.toDouble()+_CONS_AREA.toDouble());
                temp.get_nvilla()->set_tot_area(faas);
                temp.get_nvilla()->set_cons_area(_CONS_AREA);
                temp.get_nvilla()->set_base_price(_BASE_PRICE);
                double temppp=_BACK.toDouble()*_BASE_PRICE.toDouble()*0.15+_FRONT.toDouble()*_BASE_PRICE.toDouble()*0.3+_CONS_AREA.toDouble()*_BASE_PRICE.toDouble();
                temp.get_nvilla()->set_tot_price(QString::number(temppp));
                temp.set_condition(SELLING);
                temp.set_commision("0.03");
                temp.set_final_price();
                mysell.push_back(temp);
                 qDebug()<<"NV added";
            }
            if(_type=="SV"){
                QString _CONS_AREA,_YARD,_PARKING,_ROOMNO,_BASE_PRICE,_ADDRESS,_DURATION,_PERSON;
                tushe>>_CONS_AREA>>_YARD>>_PARKING>>_ROOMNO>>_BASE_PRICE>>_ADDRESS>>_DURATION>>_PERSON;
                sell temp;
                temp.set_vuilding("SV");
                temp.set_buildingtype("SV");
                temp.get_svilla()->set_yard(_YARD);
                temp.get_svilla()->set_parking(_PARKING);
                temp.get_svilla()->set_room(_ROOMNO);
                temp.get_svilla()->set_owner(_PERSON);
                temp.get_svilla()->set_address(_ADDRESS);
                QString faas=QString::number(_YARD.toDouble()+_PARKING.toDouble()+_CONS_AREA.toDouble());
                temp.get_svilla()->set_tot_area(faas);
                temp.get_svilla()->set_cons_area(_CONS_AREA);
                temp.get_svilla()->set_base_price(_BASE_PRICE);
                double temppp=_YARD.toDouble()*_BASE_PRICE.toDouble()*0.3+_PARKING.toDouble()*_BASE_PRICE.toDouble()*0.15+_CONS_AREA.toDouble()*_BASE_PRICE.toDouble();
                temp.get_svilla()->set_tot_price(QString::number(temppp));
                temp.set_condition(_DURATION);
                temp.set_commision("0.03");
                temp.set_final_price();
                mysell.push_back(temp);
                 qDebug()<<"SV added";
            }
            if(_type=="AP"){
                QString _FLOOR,_TOT_AREA,ELEVATOR,ADDRESS,_BASE_PRICE,_II,_SELLING;
                tushe>>_TOT_AREA>>_BASE_PRICE>>ELEVATOR>>_FLOOR>>ADDRESS>>_II;
                 apartment* yohu=new apartment();
                 yohu->set_floor(_FLOOR);
                 yohu->set_house(_II);
                 yohu->set_elevator(ELEVATOR);
                 for(int i=0;i<_II.toInt();i++){
                     QString __cons,__room,__floor,__person,__usage,duru;
                     tushe>>__floor>>__room>>__cons>>__person>>__usage>>duru;
                     sell germ;
                     germ.set_vuilding("AP");
                     germ.set_buildingtype("AP");
                     germ.set_condition(_SELLING);
                     germ.set_commision("0.03");
                     germ.get_tiny()->set_nest(yohu);
                     germ.get_tiny()->set_floor(__floor);
                     germ.get_tiny()->set_usage(__usage);
                     germ.get_tiny()->set_room(__room);
                     germ.get_tiny()->set_owner(__person);
                     germ.get_tiny()->set_address(ADDRESS);
                     germ.get_tiny()->set_tot_area(_TOT_AREA);
                     germ.get_tiny()->set_cons_area(__cons);
                     germ.get_tiny()->set_base_price(_BASE_PRICE);
                     germ.get_tiny()->set_tot_price(QString::number(__cons.toDouble()*_BASE_PRICE.toDouble()));
                     germ.set_final_price();
                     mysell.push_back(germ);
                      qDebug()<<"ap added";
                 }
            }
        }
        ireadit.close();
        hide();
       _Mainpage=new MainPage(new_user,myrent,mysell);
       _Mainpage->exec();
    }
    }











