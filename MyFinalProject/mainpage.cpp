#include "mainpage.h"
#include "ui_mainpage.h"
#include<mainwindow.h>

MainPage::MainPage(Person *new_user,QVector<rent> r1,QVector<sell> s1,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainPage)
{
    ui->setupUi(this);
    mysell=s1;
    myrent=r1;
    myuser=new_user;
    if(new_user->get_username()=="ADMIN")
      ui->ordinary_users->hide();
    else {
      ui->ADMIN->hide();
    }
}

MainPage::~MainPage()
{
    delete ui;
}

void MainPage::on_signout_clicked()
{
    remove(":/new/prefix2/FLATS.txt");
    QFile 
    
    
    
    
    
    
    
    
    
    
       hide();
       MainWindow *asli=new MainWindow();
       asli->show();
}   

void MainPage::on_signout_2_clicked()
{
    hide();
    MainWindow *asli=new MainWindow();
    asli->show();
}

void MainPage::on_addbuilding_clicked()
{
    hide();
    wind_s=new Add_building(myuser,myrent,mysell);
    wind_s->show();
}

void MainPage::on_viewbuilding_clicked()
{
    hide();
    mypage=new show_buildings_admin(myuser,myrent,mysell);
    mypage->exec();
}

void MainPage::on_search_clicked()
{
    hide();
       usersc=new Search_user(myuser,myrent,mysell);
       usersc->show();
}
