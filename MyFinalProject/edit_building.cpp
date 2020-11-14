#include "edit_building.h"
#include "ui_edit_building.h"
#include <show_buildings_admin.h>
Edit_building::Edit_building(QString itstype,QString inin,QVector<rent> myrent,QVector<sell> mysell,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Edit_building)
{
    t1=itstype;
    t2=inin;
    msell=mysell;
    mrent=myrent;
    ui->setupUi(this);
    if(itstype=="rent"){
        ui->groupBox->show();
        ui->groupBox_2->hide();
        if(myrent[inin.toInt()].get_buildingtype()=="NV"){
            ui->nvnvnv->show();
            ui->southern->hide();
            ui->cur_n_cons->setText(myrent[inin.toInt()].get_nvilla()->get_cons_area());
            ui->cur_n_base->setText(myrent[inin.toInt()].get_nvilla()->get_base_price());
            ui->cur_n_room->setText(myrent[inin.toInt()].get_nvilla()->get_room());
            ui->cur_n_front->setText(myrent[inin.toInt()].get_nvilla()->get_fontyard());
            ui->cur_n_address->setText(myrent[inin.toInt()].get_nvilla()->get_address());
            ui->cur_n_backyard->setText(myrent[inin.toInt()].get_nvilla()->get_backyard());
            ui->current->setText(myrent[inin.toInt()].get_rent_duraion());
        }
        if(myrent[inin.toInt()].get_buildingtype()=="SV"){
            ui->nvnvnv->hide();
            ui->southern->show();
            ui->cur_s_cons->setText(myrent[inin.toInt()].get_svilla()->get_cons_area());
            ui->cur_s_room->setText(myrent[inin.toInt()].get_svilla()->get_room());
            ui->cur_s_yard->setText(myrent[inin.toInt()].get_svilla()->get_yard());
            ui->cur_s_basae->setText(myrent[inin.toInt()].get_svilla()->get_base_price());
            ui->cur_s_adress->setText(myrent[inin.toInt()].get_svilla()->get_address());
            ui->cur_s_parking->setText(myrent[inin.toInt()].get_svilla()->get_parking());
            ui->current->setText(myrent[inin.toInt()].get_rent_duraion());
        }
    }
    if(itstype=="sell"){
        ui->groupBox->hide();
        ui->groupBox_2->show();
        if(mysell[inin.toInt()].get_vuildingtype()=="NV"){
            ui->nvnvnv->show();
            ui->southern->hide();
            ui->cur_n_cons->setText(mysell[inin.toInt()].get_nvilla()->get_cons_area());
            ui->cur_n_base->setText(mysell[inin.toInt()].get_nvilla()->get_base_price());
            ui->cur_n_room->setText(mysell[inin.toInt()].get_nvilla()->get_room());
            ui->cur_n_front->setText(mysell[inin.toInt()].get_nvilla()->get_fontyard());
            ui->cur_n_address->setText(mysell[inin.toInt()].get_nvilla()->get_address());
            ui->cur_n_backyard->setText(mysell[inin.toInt()].get_nvilla()->get_backyard());
            ui->current->setText(mysell[inin.toInt()].get_cond());
        }
        if(mysell[inin.toInt()].get_vuildingtype()=="SV"){
            ui->nvnvnv->hide();
            ui->southern->show();
            ui->cur_s_cons->setText(mysell[inin.toInt()].get_svilla()->get_cons_area());
            ui->cur_s_room->setText(mysell[inin.toInt()].get_svilla()->get_room());
            ui->cur_s_yard->setText(mysell[inin.toInt()].get_svilla()->get_yard());
            ui->cur_s_basae->setText(mysell[inin.toInt()].get_svilla()->get_base_price());
            ui->cur_s_adress->setText(mysell[inin.toInt()].get_svilla()->get_address());
            ui->cur_s_parking->setText(mysell[inin.toInt()].get_svilla()->get_parking());
            ui->current->setText(mysell[inin.toInt()].get_cond());
        }
    }
}

Edit_building::~Edit_building()
{
    delete ui;
}

void Edit_building::on_cancel_clicked()
{
    Person *d=new Person();
    d->set_username("ADMIN");
    show_buildings_admin *vfv=new show_buildings_admin(d,mrent,msell);
    this->close();
}

void Edit_building::on_apply_clicked()
{
    if(t1=="rent"){
        if(mrent[t2.toInt()].get_buildingtype()=="NV"){
            qDebug()<<"tuye rent va nv";
            QString l1,l2,l3,l4,l5,l6,l7;
            l1=ui->cons->text();
            l2=ui->back->text();
            l3=ui->front->text();
            l4=ui->lineEdit->text();
            l5=ui->roomo->text();
            l6=ui->adderes->toPlainText();
            l7=ui->linerent->text();
            if(l1!="")
                mrent[t2.toInt()].get_nvilla()->set_cons_area(l1);
            if(l2!="")
                mrent[t2.toInt()].get_nvilla()->set_backyard(l2);
            if(l3!="")
                mrent[t2.toInt()].get_nvilla()->set_frontyard(l3);
            if(l4!="")
                mrent[t2.toInt()].get_nvilla()->set_base_price(l4);
            if(l5!="")
                mrent[t2.toInt()].get_nvilla()->set_room(l5);
            if(l6!="")
                mrent[t2.toInt()].get_nvilla()->set_address(l6);
            if(l7!="")
                    mrent[t2.toInt()].set_rent_duration(l7);
            double area=mrent[t2.toInt()].get_nvilla()->get_backyard().toDouble()+mrent[t2.toInt()].get_nvilla()->get_fontyard().toDouble()+mrent[t2.toInt()].get_nvilla()->get_cons_area().toDouble();
            mrent[t2.toInt()].get_nvilla()->set_tot_area(QString::number(area));
            double pp=mrent[t2.toInt()].get_nvilla()->get_backyard().toDouble()*mrent[t2.toInt()].get_nvilla()->get_base_price().toDouble()*0.15;
            pp+=mrent[t2.toInt()].get_nvilla()->get_fontyard().toDouble()*mrent[t2.toInt()].get_nvilla()->get_base_price().toDouble()*0.3;
            pp+=mrent[t2.toInt()].get_nvilla()->get_cons_area().toDouble()*mrent[t2.toInt()].get_nvilla()->get_base_price().toDouble();
            mrent[t2.toInt()].get_nvilla()->set_tot_price(QString::number(pp));
            mrent[t2.toInt()].set_rahn(QString::number(pp*0.05));
            mrent[t2.toInt()].set_tent_amount(QString::number(pp*0.01));
            mrent[t2.toInt()].set_final_price();
            Person *d=new Person();
            d->set_username("ADMIN");
            show_buildings_admin *vfv=new show_buildings_admin(d,mrent,msell);
            close();
            vfv->show();

        }
        if(mrent[t2.toInt()].get_buildingtype()=="SV"){
            qDebug()<<"tuye rent va sv";
            QString l1,l2,l3,l4,l5,l6,l7;
            l1=ui->baseprice->text();
            l2=ui->conss->text();
            l3=ui->parking->text();
            l4=ui->roomrooomo_2->text();
            l5=ui->yard->text();
            l6=ui->plainTextEdit->toPlainText();
            l7=ui->linerent->text();
            if(l1!="")
                mrent[t2.toInt()].get_svilla()->set_cons_area(l2);
            if(l2!="")
                mrent[t2.toInt()].get_svilla()->set_yard(l5);
            if(l3!="")
                mrent[t2.toInt()].get_svilla()->set_parking(l3);
            if(l4!="")
                mrent[t2.toInt()].get_svilla()->set_base_price(l1);
            if(l5!="")
                mrent[t2.toInt()].get_svilla()->set_room(l4);
            if(l6!="")
                mrent[t2.toInt()].get_svilla()->set_address(l6);
            if(l7!="")
                    mrent[t2.toInt()].set_rent_duration(l7);
            double area=mrent[t2.toInt()].get_svilla()->get_yard().toDouble()+mrent[t2.toInt()].get_svilla()->get_parking().toDouble()+mrent[t2.toInt()].get_svilla()->get_cons_area().toDouble();
            mrent[t2.toInt()].get_svilla()->set_tot_area(QString::number(area));
            double pp=mrent[t2.toInt()].get_svilla()->get_yard().toDouble()*mrent[t2.toInt()].get_svilla()->get_base_price().toDouble()*0.3;
            pp+=mrent[t2.toInt()].get_svilla()->get_parking().toDouble()*mrent[t2.toInt()].get_svilla()->get_base_price().toDouble()*0.15;
            pp+=mrent[t2.toInt()].get_svilla()->get_cons_area().toDouble()*mrent[t2.toInt()].get_svilla()->get_base_price().toDouble();
            mrent[t2.toInt()].get_svilla()->set_tot_price(QString::number(pp));
            mrent[t2.toInt()].set_rahn(QString::number(pp*0.05));
            mrent[t2.toInt()].set_tent_amount(QString::number(pp*0.01));
            mrent[t2.toInt()].set_final_price();
            Person *d=new Person();
            d->set_username("ADMIN");
            show_buildings_admin *vfv=new show_buildings_admin(d,mrent,msell);
            close();
            vfv->show();
        }
    }
   if(t1=="sell"){
       if(msell[t2.toInt()].get_vuildingtype()=="NV"){
           QString l1,l2,l3,l4,l5,l6,l7;
           l1=ui->cons->text();
           l2=ui->back->text();
           l3=ui->front->text();
           l4=ui->lineEdit->text();
           l5=ui->roomo->text();
           l6=ui->adderes->toPlainText();
           l7=ui->sellingcond->toPlainText();
           if(l1!="")
               msell[t2.toInt()].get_nvilla()->set_cons_area(l1);
           if(l2!="")
               msell[t2.toInt()].get_nvilla()->set_backyard(l2);
           if(l3!="")
               msell[t2.toInt()].get_nvilla()->set_frontyard(l3);
           if(l4!="")
               msell[t2.toInt()].get_nvilla()->set_base_price(l4);
           if(l5!="")
               msell[t2.toInt()].get_nvilla()->set_room(l5);
           if(l6!="")
               msell[t2.toInt()].get_nvilla()->set_address(l6);
           if(l7!="")
                   msell[t2.toInt()].set_condition(l7);
           double area=msell[t2.toInt()].get_nvilla()->get_backyard().toDouble()+msell[t2.toInt()].get_nvilla()->get_fontyard().toDouble()+msell[t2.toInt()].get_nvilla()->get_cons_area().toDouble();
           msell[t2.toInt()].get_nvilla()->set_tot_area(QString::number(area));
           double pp=msell[t2.toInt()].get_nvilla()->get_backyard().toDouble()*msell[t2.toInt()].get_nvilla()->get_base_price().toDouble()*0.15;
           pp+=msell[t2.toInt()].get_nvilla()->get_fontyard().toDouble()*msell[t2.toInt()].get_nvilla()->get_base_price().toDouble()*0.3;
           pp+=msell[t2.toInt()].get_nvilla()->get_cons_area().toDouble()*msell[t2.toInt()].get_nvilla()->get_base_price().toDouble();
           msell[t2.toInt()].get_nvilla()->set_tot_price(QString::number(pp));
           msell[t2.toInt()].set_final_price();
           Person *d=new Person();
           d->set_username("ADMIN");
           show_buildings_admin *vfv=new show_buildings_admin(d,mrent,msell);
           close();
           vfv->show();
       }
       if(msell[t2.toInt()].get_vuildingtype()=="SV"){
           QString l1,l2,l3,l4,l5,l6,l7;
           l1=ui->baseprice->text();
           l2=ui->conss->text();
           l3=ui->parking->text();
           l4=ui->roomrooomo_2->text();
           l5=ui->yard->text();
           l6=ui->plainTextEdit->toPlainText();
           l7=ui->sellingcond->toPlainText();
           if(l1!="")
               msell[t2.toInt()].get_svilla()->set_cons_area(l2);
           if(l2!="")
               msell[t2.toInt()].get_svilla()->set_yard(l5);
           if(l3!="")
               msell[t2.toInt()].get_svilla()->set_parking(l3);
           if(l4!="")
               msell[t2.toInt()].get_svilla()->set_base_price(l1);
           if(l5!="")
               msell[t2.toInt()].get_svilla()->set_room(l4);
           if(l6!="")
               msell[t2.toInt()].get_svilla()->set_address(l6);
           if(l7!="")
                   msell[t2.toInt()].set_condition(l7);
           double area=msell[t2.toInt()].get_svilla()->get_yard().toDouble()+msell[t2.toInt()].get_svilla()->get_parking().toDouble()+msell[t2.toInt()].get_svilla()->get_cons_area().toDouble();
           msell[t2.toInt()].get_svilla()->set_tot_area(QString::number(area));
           double pp=msell[t2.toInt()].get_svilla()->get_yard().toDouble()*msell[t2.toInt()].get_svilla()->get_base_price().toDouble()*0.3;
           pp+=msell[t2.toInt()].get_svilla()->get_parking().toDouble()*msell[t2.toInt()].get_svilla()->get_base_price().toDouble()*0.15;
           pp+=msell[t2.toInt()].get_svilla()->get_cons_area().toDouble()*msell[t2.toInt()].get_svilla()->get_base_price().toDouble();
           msell[t2.toInt()].get_svilla()->set_tot_price(QString::number(pp));
           msell[t2.toInt()].set_final_price();
           Person *d=new Person();
           d->set_username("ADMIN");
           show_buildings_admin *vfv=new show_buildings_admin(d,mrent,msell);
           close();
           vfv->show();
       }
}
}
