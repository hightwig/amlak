#ifndef ADD_BUILDING_H
#define ADD_BUILDING_H
#include <classes.h>
#include <QDialog>

namespace Ui {
class Add_building;
}

class Add_building : public QDialog
{
    Q_OBJECT

public:
    explicit Add_building(Person* _myuser,QVector<rent>,QVector<sell>,QWidget *parent=nullptr);
    ~Add_building();

private slots:
    void on_comboBox_currentIndexChanged(int index);


    void on_case_type_currentIndexChanged(int index);

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    //QVector<manager> *ser;
    QVector <rent> myrent;
    QVector <sell>mysell;
    Person *myuser;
    Ui::Add_building *ui;
    //tiny_home MYHOUSES[24];
    int I_HOUSES;
};

#endif // ADD_BUILDING_H
