#ifndef MAINPAGE_H
#define MAINPAGE_H
#include <classes.h>
#include <QDialog>
#include "show_buildings_admin.h"
#include <add_building.h>
#include "search_user.h"
//#include "mainwindow.h"
namespace Ui {
class MainPage;
}

class MainPage : public QDialog
{
    Q_OBJECT

public:
    explicit MainPage(Person*,QVector<rent>,QVector<sell>,QWidget *parent = nullptr);
    ~MainPage();

private slots:
    void on_signout_clicked();

    void on_signout_2_clicked();

    void on_addbuilding_clicked();

    void on_viewbuilding_clicked();

    void on_search_clicked();

private:
    Add_building *wind_s;
    show_buildings_admin *mypage;
    //QVector <manager> myvect;
    QVector<sell> mysell;
    QVector<rent> myrent;
    Search_user *usersc;
    Person *myuser;
    Ui::MainPage *ui;
   // MainWindow *page_1;
};

#endif // MAINPAGE_H
