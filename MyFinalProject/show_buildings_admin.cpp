#include "show_buildings_admin.h"
#include "ui_show_buildings_admin.h"
#include <edit_building.h>
#include <mainpage.h>
show_buildings_admin::show_buildings_admin(Person* _myuser,QVector<rent> r1,QVector<sell> s1,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::show_buildings_admin)
{
    this_user=_myuser;
    myrent=r1;
    mysell=s1;
    RAND =973581;
    sabad=984581;
    ui->setupUi(this);
}

show_buildings_admin::~show_buildings_admin()
{
    delete ui;
}

void show_buildings_admin::on_pushButton_2_clicked()
{
    ui->label_7->clear();
    qDebug()<<"hoih";
    bool NV=ui->chekckNV->isChecked();
    bool SV=ui->checksv->isChecked();
    bool AP=ui->checkap->isChecked();
    bool renti=ui->checkrent->isChecked();
    bool mortgage=ui->checkmortgage->isChecked();
    ui->listWidget->clear();
    QString mainstring="",fieldstring="",space="                ";
    int jj=0,kk=0;
    qDebug()<<NV;
    if(renti){
        if(NV){
            int sss=0;
             for(int i=0;i<myrent.size();i++){
                 qDebug()<<myrent[i].get_buildingtype();
                 if(myrent[i].get_buildingtype()=="NV"){
                     if(!sss){
                         mainstring="  ID             Type          Case    Tot-area    cons-area    Room-No    Front-yard    Back-yard    Owner    Base-Price    Final-Price     Rent    Rahn    duration(months)";
                         ui->listWidget->addItem(mainstring);
                         sss++;
                     }
                   qDebug()<<"ERGDSFGSDFGSDFGSDFG";
                   qDebug()<<"pouya "<<myrent[i].get_final_price();
             fieldstring=QString::number(RAND+i)+space+"Nvilla"+space+"sell"+space+myrent[i].get_nvilla()->get_tot_area()+space;
             fieldstring+=myrent[i].get_nvilla()->get_cons_area()+space+myrent[i].get_nvilla()->get_room()+space+myrent[i].get_nvilla()->get_fontyard()+space+myrent[i].get_nvilla()->get_backyard();
             fieldstring+=space+myrent[i].get_nvilla()->get_ower()+space+myrent[i].get_nvilla()->get_base_price()+space+myrent[i].get_final_price();
             fieldstring+=space+myrent[i].get_rent_amount()+space+myrent[i].get_rahn()+space+myrent[i].get_rent_duraion();
              ui->listWidget->addItem(fieldstring);
                 }
             }
        }
        if(SV){
            int sss=0;
        for(int i=0;i<myrent.size();i++){
            if(myrent[i].get_buildingtype()=="SV"){
                if(!sss){
                    mainstring="  ID                 Type         Case    Tot-area    cons-area    Room-No    Yard    Parking    Owner    Base-Price    Final-Price     Rent    Rahn   duratoin(months)";
                    ui->listWidget->addItem(mainstring);
                    sss++;
                }
                qDebug()<<"12231321";
        fieldstring=QString::number(RAND+i)+space+"Svilla"+space+"sell"+space+myrent[i].get_svilla()->get_tot_area()+space;
        fieldstring+=myrent[i].get_svilla()->get_cons_area()+space+myrent[i].get_svilla()->get_room()+space+myrent[i].get_svilla()->get_yard()+space+myrent[i].get_svilla()->get_parking();
        fieldstring+=space+myrent[i].get_svilla()->get_ower()+space+myrent[i].get_svilla()->get_base_price()+space+myrent[i].get_final_price();
        fieldstring+=space+myrent[i].get_rent_amount()+space+myrent[i].get_rahn()+space+myrent[i].get_rent_duraion();
            ui->listWidget->addItem(fieldstring);
            }
            }
        }
        if(AP){
            int sss=0;
            for(int i=0;i<myrent.size();i++){qDebug()<<"lllllllllllllllllllllllllllllllllllllllllll";
                if(myrent[i].get_buildingtype()=="AP"){
                    qDebug()<<"lllllllllllllllllllllllllllllllllllllllllll";
                    if(!sss){
                        mainstring="  ID               Type            Case    Tot-Area     Cons-Area      Elevator    Floor     Room-No    Base-Price    Owner    Address    Final-Price    Rent    Rahn   duration(months)     usage";
                        ui->listWidget->addItem(mainstring);
                        sss++;
                    }
            fieldstring=QString::number(RAND+i)+space+"AP"+space+"sell"+space+myrent[i].get_tiny()->get_tot_area()+space;
            fieldstring+=myrent[i].get_tiny()->get_cons_area()+space+myrent[i].get_tiny()->get_nest()->get_elevator()+space+myrent[i].get_tiny()->get_floor();
            fieldstring+=space+myrent[i].get_tiny()->get_room()+space+myrent[i].get_tiny()->get_base_price()+space+myrent[i].get_tiny()->get_ower();
            fieldstring+=space+myrent[i].get_tiny()->get_address()+space+myrent[i].get_final_price()+myrent[i].get_rent_amount()+space+myrent[i].get_rahn()+space;
            fieldstring+=myrent[i].get_rent_duraion()+space+myrent[i].get_tiny()->get_usage();
              ui->listWidget->addItem(fieldstring);
                }
        }
    }
    }
     if(mortgage){
        if(NV){
            int sss=0;
            for(int i=0;i<mysell.size();i++){
                if(mysell[i].get_vuildingtype()=="NV"){
                    if(!sss){
                        mainstring="  ID             Type          Case    Tot-area    cons-area    Room-No    Front-yard    Back-yard    Owner    Base-Price    Final-Price     Selling-cond";
                        ui->listWidget->addItem(mainstring);
                        sss++;
                    }
            fieldstring=QString::number(sabad+i)+space+"Nvilla"+space+"rent"+space+mysell[i].get_nvilla()->get_tot_area()+space;
            fieldstring+=mysell[i].get_nvilla()->get_cons_area()+space+mysell[i].get_nvilla()->get_room()+space+mysell[i].get_nvilla()->get_fontyard()+space+mysell[i].get_nvilla()->get_backyard();
            fieldstring+=space+mysell[i].get_nvilla()->get_ower()+space+mysell[i].get_nvilla()->get_base_price()+space+mysell[i].get_final_price();
            fieldstring+=space+mysell[i].get_cond();
             ui->listWidget->addItem(fieldstring);
                }
            }
        }
        if(SV){
            int sss=0;
            for(int i=0;i<mysell.size();i++){
                if(mysell[i].get_vuildingtype()=="SV"){
                    if(!sss){
                        mainstring="  ID                 Type         Case    Tot-area    cons-area   Room-No    Yard    Parking    Owner    Base-Price    Final-Price     Selling-cond";
                        ui->listWidget->addItem(mainstring);
                        sss++;
                    }
            fieldstring=QString::number(sabad+i)+space+"Svilla"+space+"rent"+space+mysell[i].get_svilla()->get_tot_area()+space;
            fieldstring+=mysell[i].get_svilla()->get_cons_area()+mysell[i].get_svilla()->get_room()+space+mysell[i].get_svilla()->get_yard()+space+mysell[i].get_svilla()->get_parking();
            fieldstring+=space+mysell[i].get_svilla()->get_ower()+space+mysell[i].get_svilla()->get_base_price()+space+mysell[i].get_final_price();
            fieldstring+=space+mysell[i].get_cond();
                ui->listWidget->addItem(fieldstring);
                }
                }
        }
        if(AP){
            int sss=0;
            for(int i=0;i<mysell.size();i++){
                if(mysell[i].get_vuildingtype()=="AP"){
                    qDebug()<<"lllllllllllllllllllllllllllllllllllllllllll";
                    if(!sss){
                        mainstring="  ID               Type            Case    Tot-Area     Cons-Area      Elevator    Floor     Room-No    Base-Price    Owner    Address    Final-Price    Selling-cond     usage";
                        ui->listWidget->addItem(mainstring);
                        sss++;
                    }
            fieldstring=QString::number(sabad+i)+space+"AP"+space+"rent"+space+mysell[i].get_tiny()->get_tot_area()+space;
            fieldstring+=mysell[i].get_tiny()->get_cons_area()+space+mysell[i].get_tiny()->get_nest()->get_elevator()+space+mysell[i].get_tiny()->get_floor();
            fieldstring+=space+mysell[i].get_tiny()->get_room()+space+mysell[i].get_tiny()->get_base_price()+space+mysell[i].get_tiny()->get_ower();
            fieldstring+=space+mysell[i].get_tiny()->get_address()+space+mysell[i].get_final_price()+space+mysell[i].get_cond()+space;
            fieldstring+=mysell[i].get_tiny()->get_usage();
              ui->listWidget->addItem(fieldstring);
                }
        }
        }
    }


}

void show_buildings_admin::on_pushButton_clicked()
{
    ui->label_7->clear();
    if(ui->listWidget->currentItem()->text()[0]==" " || ui->listWidget->currentItem()->text()==""){
        ui->label_7->setText("no building selected");
        return;
    }
    else if(ui->listWidget->currentItem()->text()!=""){
     QString remp=ui->listWidget->currentItem()->text();
     QString number;int stat=0;
     for(int i=0;i<remp.size();i++){
         if(remp[i]==" ")
             break;
         else
          number+=remp[i];
     }
     qDebug()<<"-----------------------------------------------------";
     qDebug()<<"number="<<number;
     bool isrent=remp.contains("Nvilla");
     bool issell=remp.contains("Svilla");
     bool isap=remp.contains("AP");
     QString typl;
     int index1=remp.indexOf("97");
     int index2=remp.indexOf("98");
     if(remp[1]=='7'){
         typl="rent";
         int nin=number.toInt()-973581;
         qDebug()<<"type="<<typl;
         qDebug()<<"index="<<nin;
         Edit_building *bnb=new Edit_building(typl,QString::number(nin),myrent,mysell);
         hide();
         //bnb->setModal(true);
         bnb->show();
     }
     if(remp[1]=='8'){
         typl="sell";
         int nin=number.toInt()-984581;
         qDebug()<<"type="<<typl;
         qDebug()<<"index="<<nin;
         hide();
         Edit_building *bnb=new Edit_building(typl,QString::number(nin),myrent,mysell);
         //bnb->setModal(true);
         bnb->show();
     }


    }
    else {
        ui->label_7->setText("no building selected");
        return;
    }
}

void show_buildings_admin::on_cancel_clicked()
{
    //Person *g=new Person();
    //g->set_username("ADMIN");
    MainPage *fd=new MainPage(this_user,myrent,mysell);
    close();
    fd->show();
}
