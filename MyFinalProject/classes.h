#ifndef BUILDING_H
#define BUILDING_H
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <QString>
#include <QVector>
#include <sstream>
using namespace std;
class Person {
   QString Full_name;
   QString Birthday;
   QString User_status;
   QString User_name;
   QString Password;
   QString Credit;
public:
    QString get_username();
    QString get_birthday() ;
    QString get_user_status();
    QString get_password();
    QString get_credit() ;
    QString get_fullname();
    void set_username(QString) ;
    void set_birthday(QString) ;
    void set_user_stat(QString );
    void set_password(QString );
    void set_credit(QString );
    void set_fullname(QString);

};

class Building {
protected:
    QString owner;
    QString address;
    QString base_price;
    QString room;
    QString tot_price;
    QString cons_area;
    QString tot_area;
public:
    void set_owner(QString);
    void set_address(QString);
    void set_base_price(QString);
    void set_room(QString);
    void set_tot_price(QString);
    void set_cons_area(QString);
    void set_tot_area(QString);
    QString get_ower();
    QString get_address();
    QString get_base_price();
    QString get_room();
    QString get_tot_price();
    QString get_cons_area();
    QString get_tot_area();
};

class Nvila :public Building{
    QString backyard;
    QString frontyard;
public:
    void set_backyard(QString);
    void set_frontyard(QString);
    QString get_backyard();
    QString get_fontyard();
};
class Svilla :public Building{
    QString yard;
    QString parking;
public:
    void set_yard(QString);
    void set_parking(QString);
    QString get_yard();
    QString get_parking();
};
class apartment {
    bool elevator;
    QString floor;
    QString house;
public:
    void set_elevator(QString);
    void set_floor(QString);
    void set_house(QString);
    QString get_floor();
    QString get_house();
    QString get_elevator();
};
class tiny :public Building{
   QString floor;
   QString usage;
   apartment* nest;
public:
   void set_floor(QString);
   void set_usage(QString);
   void set_nest(apartment*);
   QString get_floor();
   QString get_usage();
   apartment* get_nest();

};
class cases{
protected:
    QString commision;
    QString final_price;
public:
    cases(){}
    void set_commision(QString);
    virtual void set_final_price();
    QString get_final_price();
    QString get_commision();
    virtual ~cases(){}
};
class rent : public cases{
    QString rent_amount;
    QString rent_duration;
    QString rahn;
    QString building_type;
    tiny* home;
    Nvila* vila;
    Svilla* villa;
public:
    void set_final_price();
    void set_tent_amount(QString);
    void set_rent_duration(QString);
    void set_rahn(QString);
    QString get_rent_amount();
    QString get_rahn();
    QString get_rent_duraion();
    tiny* get_tiny();
    Nvila* get_nvilla();
    Svilla* get_svilla();
    void set_building(QString);
    QString get_buildingtype(){return building_type;}
    void set_buildingtype(QString tekp){building_type=tekp;}
};
class sell : public cases {
    QString condition;
    QString building_type;
    tiny* home;
    Nvila* vila;
    Svilla* villa;
public:
    void set_final_price();
    tiny* get_tiny();
    Nvila* get_nvilla();
    Svilla* get_svilla();
    void set_condition(QString);
    QString get_cond();
    void set_vuilding(QString);
    void set_buildingtype(QString tekp){building_type=tekp;}
    QString get_vuildingtype(){return building_type;}
};

#endif // BUILDING_H
