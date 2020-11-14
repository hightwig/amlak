#include "search_user.h"
#include "ui_search_user.h"
#include <QDebug>
Search_user::Search_user(Person* _myuser,QVector<rent> r1,QVector<sell> s1,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Search_user)
{
    this_user=_myuser;
    myrent=r1;
    myrent1=r1;
    mysell=s1;
    RAND =973581;
    ui->setupUi(this);
    ui->label->hide();
    ui->label_2->hide();
    ui->label_3->hide();
    ui->label_4->hide();
    ui->label_5->hide();
    ui->label_6->hide();
    ui->lineEdit->hide();
    ui->lineEditbm->hide();
    ui->lineEditbm2->hide();
    ui->lineEditaddres->hide();
    ui->lineEditroomno->hide();
}

Search_user::~Search_user()
{
    delete ui;
}

void Search_user::on_pushButton_clicked()
{ui->listWidget->clear();

    QString mainstring="",fieldstring="",space="                ";
       int jj=0;
    if(ui->comboBox->currentText()=="address"){
        ui->lineEditaddres->show();
 QString aa=ui->lineEditaddres->text();
 if(aa!=""){
int df=0;

        for(int i=0;i<myrent.size();i++){

            if(myrent[i].get_buildingtype()=="NV"){

                qDebug() <<myrent[i].get_nvilla()->get_address();
                if(myrent[i].get_nvilla()->get_address().contains(aa)==1){

                    if(df==0){df++;

                       mainstring="  ID             Type          Case    Tot-area    Room-No    Front-yard    Back-yard    Owner    Base-Price    Final-Price     Rent    Rahn    duration(months)";
                       ui->listWidget->addItem(mainstring);
                    }


        fieldstring=QString::number(RAND+jj++)+space+"Nvilla"+space+"rent"+space+myrent[i].get_nvilla()->get_tot_area()+space;
        fieldstring+=myrent[i].get_nvilla()->get_room()+space+myrent[i].get_nvilla()->get_fontyard()+space+myrent[i].get_nvilla()->get_backyard();
        fieldstring+=space+myrent[i].get_nvilla()->get_ower()+space+myrent[i].get_nvilla()->get_base_price()+space+myrent[i].get_final_price();
        fieldstring+=space+myrent[i].get_rent_amount()+space+myrent[i].get_rahn()+space+myrent[i].get_rent_duraion();
         ui->listWidget->addItem(fieldstring);
            }
        }
        }
            df=0;

            for(int i=0;i<myrent.size();i++){
                if(myrent[i].get_buildingtype()=="SV"){
                    qDebug() <<myrent[i].get_svilla()->get_address();

                    if(myrent[i].get_svilla()->get_address().contains(aa)==1){
                          qDebug()<<"salamm";
                        if(df==0){df++;

                            mainstring="  ID                 Type         Case    Tot-area    Room-No    Yard    Parking    Owner    Base-Price    Final-Price     Rent    Rahn   duratoin(months)";
                            ui->listWidget->addItem(mainstring);
                        }



            fieldstring=QString::number(RAND+jj++)+space+"Svilla"+space+"rent"+space+myrent[i].get_svilla()->get_tot_area()+space;
            fieldstring+=myrent[i].get_svilla()->get_room()+space+myrent[i].get_svilla()->get_yard()+space+myrent[i].get_svilla()->get_parking();
            fieldstring+=space+myrent[i].get_svilla()->get_ower()+space+myrent[i].get_svilla()->get_base_price()+space+myrent[i].get_final_price();
            fieldstring+=space+myrent[i].get_rent_amount()+space+myrent[i].get_rahn()+space+myrent[i].get_rent_duraion();
                ui->listWidget->addItem(fieldstring);
                }
                }
        }
            df=0;


            for(int i=0;i<myrent.size();i++){
                if(myrent[i].get_buildingtype()=="AP"){
                    if(myrent[i].get_tiny()->get_address().contains(aa)){
                    if(df==1){df++;
                    mainstring="  ID               Type            Case    Tot-Area     Cons-Area      Elevator    Floor     Room-No    Base-Price    Owner    Address    Final-Price    Rent    Rahn   duration(months)     usage";
                    ui->listWidget->addItem(mainstring);
                    }
            fieldstring=QString::number(RAND+jj++)+space+"AP"+space+"rent"+space+myrent[i].get_tiny()->get_tot_area()+space;
            fieldstring+=myrent[i].get_tiny()->get_cons_area()+space+myrent[i].get_tiny()->get_nest()->get_elevator()+space+myrent[i].get_tiny()->get_floor();
            fieldstring+=space+myrent[i].get_tiny()->get_room()+space+myrent[i].get_tiny()->get_base_price()+space+myrent[i].get_tiny()->get_ower();
            fieldstring+=space+myrent[i].get_tiny()->get_address()+space+myrent[i].get_final_price()+myrent[i].get_rent_amount()+space+myrent[i].get_rahn()+space;
            fieldstring+=myrent[i].get_rent_duraion()+space+myrent[i].get_tiny()->get_usage();
              ui->listWidget->addItem(fieldstring);
                    }
                }


        }
            df=0;
            for(int i=0;i<mysell.size();i++){
                if(mysell[i].get_vuildingtype()=="NV"){

                    if(mysell[i].get_nvilla()->get_address().contains(aa)){
                        if(df==0) {
                    mainstring="  ID             Type          Case    Tot-area    Room-No    Front-yard    Back-yard    Owner    Base-Price    Final-Price     Selling-cond";
                    ui->listWidget->addItem(mainstring);
                        }
            fieldstring=QString::number(RAND+jj++)+space+"Nvilla"+space+"sell"+space+mysell[i].get_nvilla()->get_tot_area()+space;
            fieldstring+=mysell[i].get_nvilla()->get_room()+space+mysell[i].get_nvilla()->get_fontyard()+space+mysell[i].get_nvilla()->get_backyard();
            fieldstring+=space+mysell[i].get_nvilla()->get_ower()+space+mysell[i].get_nvilla()->get_base_price()+space+mysell[i].get_final_price();
            fieldstring+=space+mysell[i].get_cond();
             ui->listWidget->addItem(fieldstring);
                    }

                }
            }


            df=0;


            for(int i=0;i<mysell.size();i++){
                if(mysell[i].get_vuildingtype()=="SV"){
                    if(mysell[i].get_svilla()->get_address().contains(aa)){

                    if(df==0){df++;
                    mainstring="  ID                 Type         Case    Tot-area    Room-No    Yard    Parking    Owner    Base-Price    Final-Price     Selling-cond";
                    ui->listWidget->addItem(mainstring);
                    }
            fieldstring=QString::number(RAND+jj++)+space+"Svilla"+space+"sell"+space+mysell[i].get_svilla()->get_tot_area()+space;
            fieldstring+=mysell[i].get_svilla()->get_room()+space+mysell[i].get_svilla()->get_yard()+space+mysell[i].get_svilla()->get_parking();
            fieldstring+=space+mysell[i].get_svilla()->get_ower()+space+mysell[i].get_svilla()->get_base_price()+space+mysell[i].get_final_price();
            fieldstring+=space+mysell[i].get_cond();
                ui->listWidget->addItem(fieldstring);
                }
                }
            }

            df=0;

            for(int i=0;i<mysell.size();i++){
                if(mysell[i].get_vuildingtype()=="AP"){
                    if(mysell[i].get_tiny()->get_address().contains(aa)){

                    if(df==0){df++;
                    mainstring="  ID               Type            Case    Tot-Area     Cons-Area      Elevator    Floor     Room-No    Base-Price    Owner    Address    Final-Price    Selling-cond     usage";
                    ui->listWidget->addItem(mainstring);
                    }
            fieldstring=QString::number(RAND+jj++)+space+"AP"+space+"SELL"+space+mysell[i].get_tiny()->get_tot_area()+space;
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
    else {

    }

    if(ui->comboBox->currentText()=="base price&meter"){

        int df=0;

        int pricee=ui->lineEditbm->text().toInt();

        int meter=ui->lineEditbm2->text().toInt();

        for(int i=0;i<myrent.size();i++){

            if(myrent[i].get_buildingtype()=="NV"){

                qDebug() <<myrent[i].get_nvilla()->get_address();
                if(myrent[i].get_nvilla()->get_tot_area().toInt()>meter&&myrent[i].get_nvilla()->get_base_price().toInt()>pricee){

                    if(df==0){df++;

                       mainstring="  ID             Type          Case    Tot-area    Room-No    Front-yard    Back-yard    Owner    Base-Price    Final-Price     Rent    Rahn    duration(months)";
                       ui->listWidget->addItem(mainstring);
                    }


        fieldstring=QString::number(RAND+jj++)+space+"Nvilla"+space+"rent"+space+myrent[i].get_nvilla()->get_tot_area()+space;
        fieldstring+=myrent[i].get_nvilla()->get_room()+space+myrent[i].get_nvilla()->get_fontyard()+space+myrent[i].get_nvilla()->get_backyard();
        fieldstring+=space+myrent[i].get_nvilla()->get_ower()+space+myrent[i].get_nvilla()->get_base_price()+space+myrent[i].get_final_price();
        fieldstring+=space+myrent[i].get_rent_amount()+space+myrent[i].get_rahn()+space+myrent[i].get_rent_duraion();
         ui->listWidget->addItem(fieldstring);
            }
        }
        }

        df=0;

        for(int i=0;i<myrent.size();i++){
            if(myrent[i].get_buildingtype()=="SV"){
                qDebug() <<myrent[i].get_svilla()->get_address();

                if(myrent[i].get_svilla()->get_tot_area().toInt()>meter&&myrent[i].get_svilla()->get_base_price().toInt()>pricee){
                      qDebug()<<"salamm";
                    if(df==0){df++;

                        mainstring="  ID                 Type         Case    Tot-area    Room-No    Yard    Parking    Owner    Base-Price    Final-Price     Rent    Rahn   duratoin(months)";
                        ui->listWidget->addItem(mainstring);
                    }



        fieldstring=QString::number(RAND+jj++)+space+"Svilla"+space+"rent"+space+myrent[i].get_svilla()->get_tot_area()+space;
        fieldstring+=myrent[i].get_svilla()->get_room()+space+myrent[i].get_svilla()->get_yard()+space+myrent[i].get_svilla()->get_parking();
        fieldstring+=space+myrent[i].get_svilla()->get_ower()+space+myrent[i].get_svilla()->get_base_price()+space+myrent[i].get_final_price();
        fieldstring+=space+myrent[i].get_rent_amount()+space+myrent[i].get_rahn()+space+myrent[i].get_rent_duraion();
            ui->listWidget->addItem(fieldstring);
            }
            }
    }
        df=0;


        for(int i=0;i<myrent.size();i++){
            if(myrent[i].get_buildingtype()=="AP"){
                if(myrent[i].get_tiny()->get_tot_area().toInt()>meter&&myrent[i].get_tiny()->get_base_price().toInt()>pricee){
                if(df==0){df++;
                mainstring="  ID               Type            Case    Tot-Area     Cons-Area      Elevator    Floor     Room-No    Base-Price    Owner    Address    Final-Price    Rent    Rahn   duration(months)     usage";
                ui->listWidget->addItem(mainstring);
                }
        fieldstring=QString::number(RAND+jj++)+space+"AP"+space+"rent"+space+myrent[i].get_tiny()->get_tot_area()+space;
        fieldstring+=myrent[i].get_tiny()->get_cons_area()+space+myrent[i].get_tiny()->get_nest()->get_elevator()+space+myrent[i].get_tiny()->get_floor();
        fieldstring+=space+myrent[i].get_tiny()->get_room()+space+myrent[i].get_tiny()->get_base_price()+space+myrent[i].get_tiny()->get_ower();
        fieldstring+=space+myrent[i].get_tiny()->get_address()+space+myrent[i].get_final_price()+myrent[i].get_rent_amount()+space+myrent[i].get_rahn()+space;
        fieldstring+=myrent[i].get_rent_duraion()+space+myrent[i].get_tiny()->get_usage();
          ui->listWidget->addItem(fieldstring);
                }
            }


    }
        df=0;
        for(int i=0;i<mysell.size();i++){
            if(mysell[i].get_vuildingtype()=="NV"){

                if(mysell[i].get_nvilla()->get_tot_area().toInt()>meter&&mysell[i].get_nvilla()->get_base_price().toInt()>pricee){
                    if(df==0) {
                mainstring="  ID             Type          Case    Tot-area    Room-No    Front-yard    Back-yard    Owner    Base-Price    Final-Price     Selling-cond";
                ui->listWidget->addItem(mainstring);
                    }
        fieldstring=QString::number(RAND+jj++)+space+"Nvilla"+space+"sell"+space+mysell[i].get_nvilla()->get_tot_area()+space;
        fieldstring+=mysell[i].get_nvilla()->get_room()+space+mysell[i].get_nvilla()->get_fontyard()+space+mysell[i].get_nvilla()->get_backyard();
        fieldstring+=space+mysell[i].get_nvilla()->get_ower()+space+mysell[i].get_nvilla()->get_base_price()+space+mysell[i].get_final_price();
        fieldstring+=space+mysell[i].get_cond();
         ui->listWidget->addItem(fieldstring);
                }

            }
        }


        df=0;


        for(int i=0;i<mysell.size();i++){
            if(mysell[i].get_vuildingtype()=="SV"){
                if(mysell[i].get_svilla()->get_tot_area().toInt()>meter&&mysell[i].get_svilla()->get_base_price().toInt()>pricee){

                if(df==0){df++;
                mainstring="  ID                 Type         Case    Tot-area    Room-No    Yard    Parking    Owner    Base-Price    Final-Price     Selling-cond";
                ui->listWidget->addItem(mainstring);
                }
        fieldstring=QString::number(RAND+jj++)+space+"Svilla"+space+"sell"+space+mysell[i].get_svilla()->get_tot_area()+space;
        fieldstring+=mysell[i].get_svilla()->get_room()+space+mysell[i].get_svilla()->get_yard()+space+mysell[i].get_svilla()->get_parking();
        fieldstring+=space+mysell[i].get_svilla()->get_ower()+space+mysell[i].get_svilla()->get_base_price()+space+mysell[i].get_final_price();
        fieldstring+=space+mysell[i].get_cond();
            ui->listWidget->addItem(fieldstring);
            }
            }
        }

        df=0;

        for(int i=0;i<mysell.size();i++){
            if(mysell[i].get_vuildingtype()=="AP"){
                if(mysell[i].get_tiny()->get_base_price().toInt()>pricee&&mysell[i].get_tiny()->get_tot_area().toInt()>meter){

                if(df==0){df++;
                mainstring="  ID               Type            Case    Tot-Area     Cons-Area      Elevator    Floor     Room-No    Base-Price    Owner    Address    Final-Price    Selling-cond     usage";
                ui->listWidget->addItem(mainstring);
                }
        fieldstring=QString::number(RAND+jj++)+space+"AP"+space+"SELL"+space+mysell[i].get_tiny()->get_tot_area()+space;
        fieldstring+=mysell[i].get_tiny()->get_cons_area()+space+mysell[i].get_tiny()->get_nest()->get_elevator()+space+mysell[i].get_tiny()->get_floor();
        fieldstring+=space+mysell[i].get_tiny()->get_room()+space+mysell[i].get_tiny()->get_base_price()+space+mysell[i].get_tiny()->get_ower();
        fieldstring+=space+mysell[i].get_tiny()->get_address()+space+mysell[i].get_final_price()+space+mysell[i].get_cond()+space;
        fieldstring+=mysell[i].get_tiny()->get_usage();
          ui->listWidget->addItem(fieldstring);
            }
    }
        }

}
    if(ui->comboBox->currentText()=="apt&room"){


        int df=0;
        int num=ui->lineEditroomno->text().toInt();


        for(int i=0;i<mysell.size();i++){
            if(mysell[i].get_vuildingtype()=="AP"){
                if(mysell[i].get_tiny()->get_room().toInt()>num){

                if(df==0){df++;
                mainstring="  ID               Type            Case    Tot-Area     Cons-Area      Elevator    Floor     Room-No    Base-Price    Owner    Address    Final-Price    Selling-cond     usage";
                ui->listWidget->addItem(mainstring);
                }
        fieldstring=QString::number(RAND+jj++)+space+"AP"+space+"SELL"+space+mysell[i].get_tiny()->get_tot_area()+space;
        fieldstring+=mysell[i].get_tiny()->get_cons_area()+space+mysell[i].get_tiny()->get_nest()->get_elevator()+space+mysell[i].get_tiny()->get_floor();
        fieldstring+=space+mysell[i].get_tiny()->get_room()+space+mysell[i].get_tiny()->get_base_price()+space+mysell[i].get_tiny()->get_ower();
        fieldstring+=space+mysell[i].get_tiny()->get_address()+space+mysell[i].get_final_price()+space+mysell[i].get_cond()+space;
        fieldstring+=mysell[i].get_tiny()->get_usage();
          ui->listWidget->addItem(fieldstring);
            }
    }
        }

    }
    if(ui->comboBox->currentText()=="separate"){
        int df=0;

                for(int i=0;i<myrent.size();i++){

                    if(myrent[i].get_buildingtype()=="NV"){

                        qDebug() <<myrent[i].get_nvilla()->get_address();
                       {

                            if(df==0){df++;

                               mainstring="  ID             Type          Case    Tot-area    Room-No    Front-yard    Back-yard    Owner    Base-Price    Final-Price     Rent    Rahn    duration(months)";
                               ui->listWidget->addItem(mainstring);
                            }


                fieldstring=QString::number(RAND+jj++)+space+"Nvilla"+space+"rent"+space+myrent[i].get_nvilla()->get_tot_area()+space;
                fieldstring+=myrent[i].get_nvilla()->get_room()+space+myrent[i].get_nvilla()->get_fontyard()+space+myrent[i].get_nvilla()->get_backyard();
                fieldstring+=space+myrent[i].get_nvilla()->get_ower()+space+myrent[i].get_nvilla()->get_base_price()+space+myrent[i].get_final_price();
                fieldstring+=space+myrent[i].get_rent_amount()+space+myrent[i].get_rahn()+space+myrent[i].get_rent_duraion();
                 ui->listWidget->addItem(fieldstring);
                    }
                }
                }
                    df=0;

                    for(int i=0;i<myrent.size();i++){
                        if(myrent[i].get_buildingtype()=="SV"){
                            qDebug() <<myrent[i].get_svilla()->get_address();

                           {
                                  qDebug()<<"salamm";
                                if(df==0){df++;

                                    mainstring="  ID                 Type         Case    Tot-area    Room-No    Yard    Parking    Owner    Base-Price    Final-Price     Rent    Rahn   duratoin(months)";
                                    ui->listWidget->addItem(mainstring);
                                }



                    fieldstring=QString::number(RAND+jj++)+space+"Svilla"+space+"rent"+space+myrent[i].get_svilla()->get_tot_area()+space;
                    fieldstring+=myrent[i].get_svilla()->get_room()+space+myrent[i].get_svilla()->get_yard()+space+myrent[i].get_svilla()->get_parking();
                    fieldstring+=space+myrent[i].get_svilla()->get_ower()+space+myrent[i].get_svilla()->get_base_price()+space+myrent[i].get_final_price();
                    fieldstring+=space+myrent[i].get_rent_amount()+space+myrent[i].get_rahn()+space+myrent[i].get_rent_duraion();
                        ui->listWidget->addItem(fieldstring);
                        }
                        }
                }
                    df=0;


                    for(int i=0;i<myrent.size();i++){
                        if(myrent[i].get_buildingtype()=="AP"){
                           {
                            if(df==1){df++;
                            mainstring="  ID               Type            Case    Tot-Area     Cons-Area      Elevator    Floor     Room-No    Base-Price    Owner    Address    Final-Price    Rent    Rahn   duration(months)     usage";
                            ui->listWidget->addItem(mainstring);
                            }
                    fieldstring=QString::number(RAND+jj++)+space+"AP"+space+"rent"+space+myrent[i].get_tiny()->get_tot_area()+space;
                    fieldstring+=myrent[i].get_tiny()->get_cons_area()+space+myrent[i].get_tiny()->get_nest()->get_elevator()+space+myrent[i].get_tiny()->get_floor();
                    fieldstring+=space+myrent[i].get_tiny()->get_room()+space+myrent[i].get_tiny()->get_base_price()+space+myrent[i].get_tiny()->get_ower();
                    fieldstring+=space+myrent[i].get_tiny()->get_address()+space+myrent[i].get_final_price()+myrent[i].get_rent_amount()+space+myrent[i].get_rahn()+space;
                    fieldstring+=myrent[i].get_rent_duraion()+space+myrent[i].get_tiny()->get_usage();
                      ui->listWidget->addItem(fieldstring);
                            }
                        }


                }
                    df=0;
                    for(int i=0;i<mysell.size();i++){
                        if(mysell[i].get_vuildingtype()=="NV"){

                         {
                                if(df==0) {
                            mainstring="  ID             Type          Case    Tot-area    Room-No    Front-yard    Back-yard    Owner    Base-Price    Final-Price     Selling-cond";
                            ui->listWidget->addItem(mainstring);
                                }
                    fieldstring=QString::number(RAND+jj++)+space+"Nvilla"+space+"sell"+space+mysell[i].get_nvilla()->get_tot_area()+space;
                    fieldstring+=mysell[i].get_nvilla()->get_room()+space+mysell[i].get_nvilla()->get_fontyard()+space+mysell[i].get_nvilla()->get_backyard();
                    fieldstring+=space+mysell[i].get_nvilla()->get_ower()+space+mysell[i].get_nvilla()->get_base_price()+space+mysell[i].get_final_price();
                    fieldstring+=space+mysell[i].get_cond();
                     ui->listWidget->addItem(fieldstring);
                            }

                        }
                    }


                    df=0;


                    for(int i=0;i<mysell.size();i++){
                        if(mysell[i].get_vuildingtype()=="SV"){
                           {

                            if(df==0){df++;
                            mainstring="  ID                 Type         Case    Tot-area    Room-No    Yard    Parking    Owner    Base-Price    Final-Price     Selling-cond";
                            ui->listWidget->addItem(mainstring);
                            }
                    fieldstring=QString::number(RAND+jj++)+space+"Svilla"+space+"sell"+space+mysell[i].get_svilla()->get_tot_area()+space;
                    fieldstring+=mysell[i].get_svilla()->get_room()+space+mysell[i].get_svilla()->get_yard()+space+mysell[i].get_svilla()->get_parking();
                    fieldstring+=space+mysell[i].get_svilla()->get_ower()+space+mysell[i].get_svilla()->get_base_price()+space+mysell[i].get_final_price();
                    fieldstring+=space+mysell[i].get_cond();
                        ui->listWidget->addItem(fieldstring);
                        }
                        }
                    }

                    df=0;

                    for(int i=0;i<mysell.size();i++){
                        if(mysell[i].get_vuildingtype()=="AP"){
                           {

                            if(df==0){df++;
                            mainstring="  ID               Type            Case    Tot-Area     Cons-Area      Elevator    Floor     Room-No    Base-Price    Owner    Address    Final-Price    Selling-cond     usage";
                            ui->listWidget->addItem(mainstring);
                            }
                    fieldstring=QString::number(RAND+jj++)+space+"AP"+space+"SELL"+space+mysell[i].get_tiny()->get_tot_area()+space;
                    fieldstring+=mysell[i].get_tiny()->get_cons_area()+space+mysell[i].get_tiny()->get_nest()->get_elevator()+space+mysell[i].get_tiny()->get_floor();
                    fieldstring+=space+mysell[i].get_tiny()->get_room()+space+mysell[i].get_tiny()->get_base_price()+space+mysell[i].get_tiny()->get_ower();
                    fieldstring+=space+mysell[i].get_tiny()->get_address()+space+mysell[i].get_final_price()+space+mysell[i].get_cond()+space;
                    fieldstring+=mysell[i].get_tiny()->get_usage();
                      ui->listWidget->addItem(fieldstring);
                        }
                }
                    }



    }

    if(ui->comboBox->currentText()=="price"){

        qDebug()<<"tof";
        for(int i=0;i<mysell.size();i++){
            for(int i=0;i<mysell.size()-1;i++){if(  mysell[i].get_final_price().toDouble()>mysell[i+1].get_final_price().toDouble()){std::swap(mysell[i],mysell[i+1]);}
        }}
        for(int i=0;i<myrent.size();i++){
            for(int i=0;i<myrent.size()-1;i++){if(  myrent[i].get_final_price().toDouble()>myrent[i+1].get_final_price().toDouble()){qDebug()<<"salammmm";  myrent[i]=myrent1[i+1]; myrent[i+1]=myrent1[i];qDebug()<<myrent1[i].get_final_price();}
        }}

        int df=0;

                for(int i=0;i<myrent.size();i++){

                    if(myrent[i].get_buildingtype()=="NV"){

                        qDebug() <<myrent[i].get_nvilla()->get_address();
                       {

                            if(df==0){df++;

                               mainstring="  ID             Type          Case    Tot-area    Room-No    Front-yard    Back-yard    Owner    Base-Price    Final-Price     Rent    Rahn    duration(months)";
                               ui->listWidget->addItem(mainstring);
                            }

                    QString aa=  myrent[i].get_nvilla()->get_base_price();

                fieldstring=QString::number(RAND+jj++)+space+"Nvilla"+space+"rent"+space+myrent[i].get_nvilla()->get_tot_area()+space;
                fieldstring+=myrent[i].get_nvilla()->get_room()+space+myrent[i].get_nvilla()->get_fontyard()+space+myrent[i].get_nvilla()->get_backyard();
                fieldstring+=space+myrent[i].get_nvilla()->get_ower()+space+myrent[i].get_nvilla()->get_base_price()+space+myrent[i].get_final_price();
                fieldstring+=space+myrent[i].get_rent_amount()+space+myrent[i].get_rahn()+space+myrent[i].get_rent_duraion();
                 ui->listWidget->addItem(fieldstring);
                    }
                }
                }
                    df=0;

                    for(int i=0;i<myrent.size();i++){
                        if(myrent[i].get_buildingtype()=="SV"){
                            qDebug() <<myrent[i].get_svilla()->get_address();

                           {
                                  qDebug()<<"salamm";
                                if(df==0){df++;

                                    mainstring="  ID                 Type         Case    Tot-area    Room-No    Yard    Parking    Owner    Base-Price    Final-Price     Rent    Rahn   duratoin(months)";
                                    ui->listWidget->addItem(mainstring);
                                }



                    fieldstring=QString::number(RAND+jj++)+space+"Svilla"+space+"rent"+space+myrent[i].get_svilla()->get_tot_area()+space;
                    fieldstring+=myrent[i].get_svilla()->get_room()+space+myrent[i].get_svilla()->get_yard()+space+myrent[i].get_svilla()->get_parking();
                    fieldstring+=space+myrent[i].get_svilla()->get_ower()+space+myrent[i].get_svilla()->get_base_price()+space+myrent[i].get_final_price();
                    fieldstring+=space+myrent[i].get_rent_amount()+space+myrent[i].get_rahn()+space+myrent[i].get_rent_duraion();
                        ui->listWidget->addItem(fieldstring);
                        }
                        }
                }
                    df=0;


                    for(int i=0;i<myrent.size();i++){
                        if(myrent[i].get_buildingtype()=="AP"){
                           {
                            if(df==1){df++;
                            mainstring="  ID               Type            Case    Tot-Area     Cons-Area      Elevator    Floor     Room-No    Base-Price    Owner    Address    Final-Price    Rent    Rahn   duration(months)     usage";
                            ui->listWidget->addItem(mainstring);
                            }
                    fieldstring=QString::number(RAND+jj++)+space+"AP"+space+"rent"+space+myrent[i].get_tiny()->get_tot_area()+space;
                    fieldstring+=myrent[i].get_tiny()->get_cons_area()+space+myrent[i].get_tiny()->get_nest()->get_elevator()+space+myrent[i].get_tiny()->get_floor();
                    fieldstring+=space+myrent[i].get_tiny()->get_room()+space+myrent[i].get_tiny()->get_base_price()+space+myrent[i].get_tiny()->get_ower();
                    fieldstring+=space+myrent[i].get_tiny()->get_address()+space+myrent[i].get_final_price()+myrent[i].get_rent_amount()+space+myrent[i].get_rahn()+space;
                    fieldstring+=myrent[i].get_rent_duraion()+space+myrent[i].get_tiny()->get_usage();
                      ui->listWidget->addItem(fieldstring);
                            }
                        }


                }
                    df=0;
                    for(int i=0;i<mysell.size();i++){
                        if(mysell[i].get_vuildingtype()=="NV"){

                         {
                                if(df==0) {
                            mainstring="  ID             Type          Case    Tot-area    Room-No    Front-yard    Back-yard    Owner    Base-Price    Final-Price     Selling-cond";
                            ui->listWidget->addItem(mainstring);
                                }
                    fieldstring=QString::number(RAND+jj++)+space+"Nvilla"+space+"sell"+space+mysell[i].get_nvilla()->get_tot_area()+space;
                    fieldstring+=mysell[i].get_nvilla()->get_room()+space+mysell[i].get_nvilla()->get_fontyard()+space+mysell[i].get_nvilla()->get_backyard();
                    fieldstring+=space+mysell[i].get_nvilla()->get_ower()+space+mysell[i].get_nvilla()->get_base_price()+space+mysell[i].get_final_price();
                    fieldstring+=space+mysell[i].get_cond();
                     ui->listWidget->addItem(fieldstring);
                            }

                        }
                    }


                    df=0;


                    for(int i=0;i<mysell.size();i++){
                        if(mysell[i].get_vuildingtype()=="SV"){
                           {

                            if(df==0){df++;
                            mainstring="  ID                 Type         Case    Tot-area    Room-No    Yard    Parking    Owner    Base-Price    Final-Price     Selling-cond";
                            ui->listWidget->addItem(mainstring);
                            }
                    fieldstring=QString::number(RAND+jj++)+space+"Svilla"+space+"sell"+space+mysell[i].get_svilla()->get_tot_area()+space;
                    fieldstring+=mysell[i].get_svilla()->get_room()+space+mysell[i].get_svilla()->get_yard()+space+mysell[i].get_svilla()->get_parking();
                    fieldstring+=space+mysell[i].get_svilla()->get_ower()+space+mysell[i].get_svilla()->get_base_price()+space+mysell[i].get_final_price();
                    fieldstring+=space+mysell[i].get_cond();
                        ui->listWidget->addItem(fieldstring);
                        }
                        }
                    }

                    df=0;

                    for(int i=0;i<mysell.size();i++){
                        if(mysell[i].get_vuildingtype()=="AP"){
                           {

                            if(df==0){df++;
                            mainstring="  ID               Type            Case    Tot-Area     Cons-Area      Elevator    Floor     Room-No    Base-Price    Owner    Address    Final-Price    Selling-cond     usage";
                            ui->listWidget->addItem(mainstring);
                            }
                    fieldstring=QString::number(RAND+jj++)+space+"AP"+space+"SELL"+space+mysell[i].get_tiny()->get_tot_area()+space;
                    fieldstring+=mysell[i].get_tiny()->get_cons_area()+space+mysell[i].get_tiny()->get_nest()->get_elevator()+space+mysell[i].get_tiny()->get_floor();
                    fieldstring+=space+mysell[i].get_tiny()->get_room()+space+mysell[i].get_tiny()->get_base_price()+space+mysell[i].get_tiny()->get_ower();
                    fieldstring+=space+mysell[i].get_tiny()->get_address()+space+mysell[i].get_final_price()+space+mysell[i].get_cond()+space;
                    fieldstring+=mysell[i].get_tiny()->get_usage();
                      ui->listWidget->addItem(fieldstring);
                        }
                }
                    }






    }
    if(ui->comboBox->currentText()=="apr&home meter")
    {int df=0;
        int cek=0;
        int qq=ui->lineEdit->text().toInt();
        for(int i=0;i<myrent.size();i++){
            if(myrent[i].get_buildingtype()=="AP"){
                if(myrent[i].get_tiny()->get_tot_area()>qq)cek++;

                if(df==1){df++;
                mainstring="  ID               Type            Case    Tot-Area     Cons-Area      Elevator    Floor     Room-No    Base-Price    Owner    Address    Final-Price    Rent    Rahn   duration(months)     usage";
                ui->listWidget->addItem(mainstring);
                }
        fieldstring=QString::number(RAND+jj++)+space+"AP"+space+"rent"+space+myrent[i].get_tiny()->get_tot_area()+space;
        fieldstring+=myrent[i].get_tiny()->get_cons_area()+space+myrent[i].get_tiny()->get_nest()->get_elevator()+space+myrent[i].get_tiny()->get_floor();
        fieldstring+=space+myrent[i].get_tiny()->get_room()+space+myrent[i].get_tiny()->get_base_price()+space+myrent[i].get_tiny()->get_ower();
        fieldstring+=space+myrent[i].get_tiny()->get_address()+space+myrent[i].get_final_price()+myrent[i].get_rent_amount()+space+myrent[i].get_rahn()+space;
        fieldstring+=myrent[i].get_rent_duraion()+space+myrent[i].get_tiny()->get_usage();
          ui->listWidget->addItem(fieldstring);
                }
            }

        if(cek==0)ui->listWidget->clear();
        cek=0;
        df=0;

        for(int i=0;i<mysell.size();i++){
            if(mysell[i].get_vuildingtype()=="AP"){

                    if(mysell[i].get_tiny()->get_tot_area().toInt()>qq)cek++;

                if(df==0){df++;
                mainstring="  ID               Type            Case    Tot-Area     Cons-Area      Elevator    Floor     Room-No    Base-Price    Owner    Address    Final-Price    Selling-cond     usage";
                ui->listWidget->addItem(mainstring);
                }
        fieldstring=QString::number(RAND+jj++)+space+"AP"+space+"SELL"+space+mysell[i].get_tiny()->get_tot_area()+space;
        fieldstring+=mysell[i].get_tiny()->get_cons_area()+space+mysell[i].get_tiny()->get_nest()->get_elevator()+space+mysell[i].get_tiny()->get_floor();
        fieldstring+=space+mysell[i].get_tiny()->get_room()+space+mysell[i].get_tiny()->get_base_price()+space+mysell[i].get_tiny()->get_ower();
        fieldstring+=space+mysell[i].get_tiny()->get_address()+space+mysell[i].get_final_price()+space+mysell[i].get_cond()+space;
        fieldstring+=mysell[i].get_tiny()->get_usage();
          ui->listWidget->addItem(fieldstring);
            }
    }
             if(cek==0)ui->listWidget->clear();

}





}
void Search_user::on_comboBox_currentIndexChanged(int index)
{
    if(index==0){


        ui->label_2->hide();
        ui->label_3->hide();
        ui->label_4->hide();
        ui->label_5->hide();
        ui->label_6->hide();
        ui->lineEdit->hide();
        ui->lineEditbm->hide();
        ui->lineEditbm2->hide();

        ui->lineEditroomno->hide();
        ui->lineEditaddres->show();
        ui->label->show();
    }
    else if(index==1){

        ui->label->hide();

        ui->label_4->hide();
        ui->label_5->hide();
        ui->label_6->hide();
        ui->lineEdit->hide();


        ui->lineEditaddres->hide();
        ui->lineEditroomno->hide();
        ui->label_2->show();
        ui->label_3->show();
        ui->lineEditbm->show();
        ui->lineEditbm2->show();
    }

    else if(index==2){

        ui->label->hide();
        ui->label_2->hide();
        ui->label_3->hide();
        ui->label_4->show();
        ui->label_5->hide();
        ui->label_6->hide();
        ui->lineEdit->hide();
        ui->lineEditbm->hide();
        ui->lineEditbm2->hide();
        ui->lineEditaddres->hide();
        ui->lineEditroomno->show();
    }
    if(index==3){

        ui->label->hide();
        ui->label_2->hide();
        ui->label_3->hide();
        ui->label_4->hide();
        ui->label_5->show();
        ui->label_6->hide();
        ui->lineEdit->show();
        ui->lineEditbm->hide();
        ui->lineEditbm2->hide();
        ui->lineEditaddres->hide();
        ui->lineEditroomno->hide();
    }
    if(index==4){

        ui->label->hide();
        ui->label_2->hide();
        ui->label_3->hide();
        ui->label_4->hide();
        ui->label_5->hide();
        ui->label_6->hide();
        ui->lineEdit->hide();
        ui->lineEditbm->hide();
        ui->lineEditbm2->hide();
        ui->lineEditaddres->hide();
        ui->lineEditroomno->hide();
    }
    if(index==5){

        ui->label->hide();
        ui->label_2->hide();
        ui->label_3->hide();
        ui->label_4->hide();
        ui->label_5->hide();
        ui->label_6->hide();
        ui->lineEdit->hide();
        ui->lineEditbm->hide();
        ui->lineEditbm2->hide();
        ui->lineEditaddres->hide();
        ui->lineEditroomno->hide();
    }
}
