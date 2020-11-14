#ifndef SHOW_BUILDINGS_ADMIN_H
#define SHOW_BUILDINGS_ADMIN_H
#include <classes.h>
#include <QDialog>
#include <QDebug>
namespace Ui {
class show_buildings_admin;
}

class show_buildings_admin : public QDialog
{
    Q_OBJECT

public:
    explicit show_buildings_admin(Person*,QVector<rent>,QVector<sell>,QWidget *parent = nullptr);
    ~show_buildings_admin();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_cancel_clicked();

private:
    QVector<rent> myrent;
    QVector<sell> mysell;
    Person* this_user;
    long long int RAND;
    long long int sabad;
    Ui::show_buildings_admin *ui;
};

#endif // SHOW_BUILDINGS_ADMIN_H
