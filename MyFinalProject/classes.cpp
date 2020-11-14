#include "classes.h"
#include <QDebug>
     QString Person::get_username() { return User_name; }
     QString Person::get_birthday() { return Birthday; }
     QString Person::get_user_status() { return User_status; }
     QString Person::get_password() { return Password; }
     QString Person::get_credit() { return Credit; }
     QString Person::get_fullname() { return Full_name; }
     void Person::set_username(QString temp) { User_name = temp; }
     void Person::set_birthday(QString temp) { Birthday = temp; }
     void Person::set_user_stat(QString temp) { User_status = temp; }
     void Person::set_password(QString temp) { Password = temp; }
     void Person::set_credit(QString temp) { Credit = temp; }
     void Person::set_fullname(QString temp) { Full_name = temp; }
     

     void Building::set_owner(QString temp ){owner=temp;}
     void Building::set_address(QString temp){address=temp;}
     void Building::set_base_price(QString temp){base_price=temp;}
     void Building::set_room(QString temp){room=temp;}
     void Building::set_tot_price(QString temp){tot_price=temp;}
     void Building::set_cons_area(QString temp){cons_area=temp;}
     void Building::set_tot_area(QString temp){tot_area=temp;}
     QString Building::get_ower(){return owner;}
     QString Building::get_address(){return address;}
     QString Building::get_base_price(){return base_price;}
     QString Building::get_room(){return  room;}
     QString Building::get_tot_price(){return tot_price;}
     QString Building::get_cons_area(){return cons_area;}
     QString Building::get_tot_area(){return  tot_area;}

     void Nvila::set_backyard(QString temp){backyard=temp;}
     void Nvila::set_frontyard(QString temp){frontyard=temp;}
     QString Nvila::get_backyard(){return backyard;}
     QString Nvila::get_fontyard(){return frontyard;}

     void Svilla::set_yard(QString temp){yard=temp;};
     void Svilla::set_parking(QString temp){parking=temp;}
     QString Svilla::get_yard(){return yard;}
     QString Svilla::get_parking(){return parking;}


     void apartment::set_elevator(QString temp){elevator=temp.toInt();}
     void apartment::set_floor(QString temp){floor=temp;}
     void apartment::set_house(QString temp){house=temp;}
     QString apartment::get_floor(){return floor;}
     QString apartment::get_house(){return house;}
     QString apartment::get_elevator(){return QString::number(elevator);}


     void cases::set_commision(QString temp){commision=temp;}
     void cases::set_final_price(){}
     QString cases::get_final_price(){return final_price;}
     QString cases::get_commision(){return commision;}


     void tiny::set_floor(QString temp){floor=temp;}
     void tiny::set_usage(QString temp){usage=temp;}
     void tiny::set_nest(apartment* temp){nest=temp;}
     QString tiny::get_floor(){return floor;}
     QString tiny::get_usage(){return usage;}
     apartment* tiny::get_nest(){return nest;}



     void rent::set_tent_amount(QString temp){rent_amount=temp;}
     void rent::set_rent_duration(QString temp){rent_duration=temp;}
     void rent::set_rahn(QString temp){rahn=temp;}
     QString rent::get_rent_amount(){return rent_amount;}
     QString rent::get_rahn(){return rahn;}
     QString rent::get_rent_duraion(){return rent_duration;}
     tiny* rent:: get_tiny(){return home;}
     Nvila* rent::get_nvilla(){return vila;}
     Svilla* rent::get_svilla(){return villa;}
     void rent::set_building(QString temp){
         if(temp=="NV")
             vila=new Nvila();
         if(temp=="SV")
             villa=new Svilla();
         else {
             home=new tiny();
         }
     }



     tiny* sell::get_tiny(){return home;}
     Nvila* sell::get_nvilla(){return vila;}
     Svilla* sell::get_svilla(){return villa;}
     void sell::set_condition(QString temp){condition=temp;}
     QString sell::get_cond(){return condition;}
     void sell::set_vuilding(QString temp){
         if(temp=="NV")
             vila=new Nvila();
         if(temp=="SV")
             villa=new Svilla();
         else {
             home=new tiny();
         }
     }

     void rent::set_final_price(){
         final_price=QString::number(rent_amount.toDouble()*rent_duration.toDouble()+rahn.toDouble()+rahn.toDouble()*0.03);
         qDebug()<<"ammmu"<<final_price;
     }
     void sell::set_final_price(){
         if(building_type=="NV")
             final_price=QString::number(get_nvilla()->get_tot_price().toDouble()+get_nvilla()->get_tot_price().toDouble()*0.8);
         if(building_type=="SV")
             final_price=QString::number(get_svilla()->get_tot_price().toDouble()+get_svilla()->get_tot_price().toDouble()*0.8);
         if(building_type=="AP")
             final_price=QString::number(get_tiny()->get_tot_price().toDouble()+get_tiny()->get_tot_price().toDouble()*0.8);

     }








