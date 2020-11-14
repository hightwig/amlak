#include "add_building.h"
#include "ui_add_building.h"
#include <QDebug>
#include <QFile>
#include <mainpage.h>
#include <QMessageBox>
Add_building::Add_building(Person* _myuser,QVector <rent> r1,QVector <sell> s1,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Add_building)
{
    myuser=_myuser;
    myrent=r1;
    mysell=s1;
    I_HOUSES=0;
    ui->setupUi(this);
    ui->case_type->addItem("Rent");
    ui->case_type->addItem("Sell");
    ui->comboBox->addItem("northern villa");
    ui->comboBox->addItem("southern villa");
    ui->comboBox->addItem("apartemnt");
    ui->Lbackyard->setValidator(new QIntValidator(10,900,this));
    ui->Lfrontyard->setValidator(new QIntValidator(10,900,this));
    ui->Lbaseprice->setValidator(new QIntValidator(10,9000,this));
    ui->Lconstructionarea->setValidator(new QIntValidator(10,900,this));
    ui->tottall->setValidator(new QIntValidator(10,900,this));
    ui->base->setValidator(new QIntValidator(10,9000,this));
    ui->constructionarea->setValidator(new QIntValidator(10,900,this));
    ui->floornum->setValidator(new QIntValidator(10,900,this));
    ui->roomnum->setValidator(new QIntValidator(10,900,this));
    ui->_Lconstrucion->setValidator(new QIntValidator(10,900,this));
    ui->_Lyardarea->setValidator(new QIntValidator(10,900,this));
    ui->_Lparkingarea->setValidator(new QIntValidator(10,900,this));
    ui->_Lyardarea->setValidator(new QIntValidator(10,900,this));

}

Add_building::~Add_building()
{
    delete ui;
}

void Add_building::on_comboBox_currentIndexChanged(int index)
{
    if(index==0){
        ui->southernvilla->hide();
        ui->apartment->hide();
        ui->northernvilla->show();
    }
    else if(index==1){
    ui->apartment->hide();
    ui->northernvilla->hide();
    ui->southernvilla->show();
    }
    else{
    ui->southernvilla->hide();
    ui->apartment->show();
    ui->northernvilla->hide();
    }

}

void Add_building::on_case_type_currentIndexChanged(int index)
{
    if(index==0){
        ui->Rent_case->show();
        ui->sell_case->hide();
    }
    else{
        ui->Rent_case->hide();
        ui->sell_case->show();
    }
}

void Add_building::on_pushButton_2_clicked(){

    if(ui->comboBox->currentText()=="northern villa"&&ui->case_type->currentText()=="Sell"){


        sell temp;
        temp.set_vuilding("NV");
        temp.set_buildingtype("NV");
        temp.set_commision("0.03");
        temp.set_condition(ui->plainTextEdit_3->toPlainText());
        temp.get_nvilla()->set_backyard(ui->Lbackyard->text());
        temp.get_nvilla()->set_frontyard(ui->Lfrontyard->text());
        temp.get_nvilla()->set_room(ui->RoomNo->text());
        temp.get_nvilla()->set_owner(ui->lineEdit->text());
        temp.get_nvilla()->set_address(ui->Ladress->toPlainText());
        temp.get_nvilla()->set_tot_area(QString::number(ui->Lbackyard->text().toDouble()+ui->Lbackyard->text().toDouble()+ui->Lconstructionarea->text().toDouble()));
        temp.get_nvilla()->set_cons_area(ui->Lconstructionarea->text());
        QString rrr=QString::number(ui->Lbackyard->text().toDouble()*ui->Lbaseprice->text().toDouble()*0.15+ui->Lfrontyard->text().toDouble()*ui->Lbaseprice->text().toDouble()*0.3+ui->Lconstructionarea->text().toDouble()*ui->Lbaseprice->text().toDouble());
        temp.get_nvilla()->set_tot_price(rrr);
        temp.get_nvilla()->set_base_price(ui->Lbaseprice->text());
        temp.set_final_price();
        mysell.push_back(temp);
    }

 if(ui->comboBox->currentText()=="northern villa"&&ui->case_type->currentText()=="Rent"){
     rent temp;
     temp.set_building("NV");
     temp.set_buildingtype("NV");
     temp.set_commision("0.03");
     temp.get_nvilla()->set_backyard(ui->Lbackyard->text());
     temp.get_nvilla()->set_frontyard(ui->Lfrontyard->text());
     temp.get_nvilla()->set_room(ui->RoomNo->text());
     temp.get_nvilla()->set_owner(ui->lineEdit->text());
     temp.get_nvilla()->set_address(ui->Ladress->toPlainText());
     temp.get_nvilla()->set_tot_area(QString::number(ui->Lbackyard->text().toDouble()+ui->Lfrontyard->text().toDouble()+ui->Lconstructionarea->text().toDouble()));
     temp.get_nvilla()->set_cons_area(ui->Lconstructionarea->text());
     QString rrr=QString::number(ui->Lbackyard->text().toDouble()*ui->Lbaseprice->text().toDouble()*0.15+ui->Lfrontyard->text().toDouble()*ui->Lbaseprice->text().toDouble()*0.3+ui->Lconstructionarea->text().toDouble()*ui->Lbaseprice->text().toDouble());
     temp.get_nvilla()->set_tot_price(rrr);
     temp.get_nvilla()->set_base_price(ui->Lbaseprice->text());
     temp.set_rahn(QString::number(rrr.toDouble()*0.05));
     temp.set_tent_amount(QString::number(rrr.toDouble()*0.01));
     temp.set_rent_duration(QString::number(ui->spinBox_2->value()));
     temp.set_final_price();
     myrent.push_back(temp);

 }
 if(ui->comboBox->currentText()=="sorthern villa"&&ui->case_type->currentText()=="Sell"){
     sell temp;
     temp.set_vuilding("SV");
     temp.set_buildingtype("SV");
     temp.set_commision("0.03");
     temp.set_condition(ui->plainTextEdit_3->toPlainText());
     temp.get_svilla()->set_yard(ui->_Lyardarea->text());
     temp.get_svilla()->set_parking(ui->_Lparkingarea->text());
     temp.get_svilla()->set_room(ui->_RoomNo->text());
     temp.get_svilla()->set_owner(ui->lineEdit->text());
     temp.get_svilla()->set_address(ui->plainTextEdit->toPlainText());
     temp.get_svilla()->set_tot_area(QString::number(ui->_Lyardarea->text().toDouble()+ui->_Lparkingarea->text().toDouble()+ui->_Lconstrucion->text().toDouble()));
     temp.get_svilla()->set_cons_area(ui->_Lconstrucion->text());
     QString rrr=QString::number(ui->_Lparkingarea->text().toDouble()*ui->_Lbaseprice->text().toDouble()*0.15+ui->_Lyardarea->text().toDouble()*ui->_Lbaseprice->text().toDouble()*0.3+ui->_Lconstrucion->text().toDouble()*ui->_Lbaseprice->text().toDouble());
     temp.get_svilla()->set_tot_price(rrr);
     temp.get_svilla()->set_base_price(ui->_Lbaseprice->text());
     temp.set_final_price();
     mysell.push_back(temp);


 }
 if(ui->comboBox->currentText()=="sorthern villa"&&ui->case_type->currentText()=="Rent"){

     rent temp;
     temp.set_building("SV");
     temp.set_buildingtype("SV");
     temp.set_commision("0.03");
     temp.get_svilla()->set_yard(ui->_Lyardarea->text());
     temp.get_svilla()->set_parking(ui->_Lparkingarea->text());
     temp.get_svilla()->set_room(ui->_RoomNo->text());
     temp.get_svilla()->set_owner(ui->lineEdit->text());
     temp.get_svilla()->set_address(ui->plainTextEdit->toPlainText());
     temp.get_svilla()->set_tot_area(QString::number(ui->_Lyardarea->text().toDouble()+ui->_Lparkingarea->text().toDouble()+ui->_Lconstrucion->text().toDouble()));
     temp.get_svilla()->set_cons_area(ui->_Lconstrucion->text());
     QString rrr=QString::number(ui->_Lparkingarea->text().toDouble()*ui->_Lbaseprice->text().toDouble()*0.15+ui->_Lyardarea->text().toDouble()*ui->_Lbaseprice->text().toDouble()*0.3+ui->_Lconstrucion->text().toDouble()*ui->_Lbaseprice->text().toDouble());
     temp.get_svilla()->set_tot_price(rrr);
     temp.get_svilla()->set_base_price(ui->_Lbaseprice->text());
     temp.set_rahn(QString::number(rrr.toDouble()*0.05));
     temp.set_tent_amount(QString::number(rrr.toDouble()*0.01));
     temp.set_rent_duration(QString::number(ui->spinBox_2->value()));
     temp.set_final_price();
     myrent.push_back(temp);

 }
/* if(ui->comboBox->currentText()=="apartemnt" && ui->case_type->currentText()=="Rent"){

        apartment *apa=new apartment();
        apa->set_floor(QString::number(ui->spinBox->value()));
        apa->set_house(QString::number(I_HOUSES));
        apa->set_elevator(QString::number(ui->checkBox->isChecked()));
        for(int i=0;i<I_HOUSES;i++){
        rent temp;
        temp.set_building("AP");
        temp.set_buildingtype("AP");
        temp.set_commision("0.03");
        //temp.set_tent_amount();
        }




       }*/
    QMessageBox::information(this,"status","add shod");
    hide();
    MainPage *re=new MainPage(myuser,myrent,mysell);
    re->show();

}
void Add_building::on_pushButton_clicked()
{
 /*   if(ui->base->text()==""){
        ui->Warning->setText("at least one house is nesseccary");
        return;
    }
    MYHOUSES[I_HOUSES].set_cons(ui->constructionarea->text());
    MYHOUSES[I_HOUSES].set_room(ui->roomnum->text());
    MYHOUSES[I_HOUSES].set_floor(ui->floornum->text());
    //MYHOUSES[I_HOUSES].set_total_price(ui->base->text(),ui->usage->currentText(),ui->checkBox->isTristate());
    ui->constructionarea->clear();
    ui->roomnum->clear();
    ui->floornum->clear();
    ui->minihouse->setText("house has been added");
    I_HOUSES++;*/
}

