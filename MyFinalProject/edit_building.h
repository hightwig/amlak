#ifndef EDIT_BUILDING_H
#define EDIT_BUILDING_H
#include <classes.h>
#include <QDialog>

namespace Ui {
class Edit_building;
}

class Edit_building : public QDialog
{
    Q_OBJECT

public:
    explicit Edit_building(QString,QString,QVector<rent>,QVector<sell>,QWidget *parent = nullptr);
    ~Edit_building();

private slots:
    void on_cancel_clicked();

    void on_apply_clicked();

private:
    QString t1,t2;
    QVector <sell>  msell;
    QVector <rent>  mrent;
    Ui::Edit_building *ui;
};

#endif // EDIT_BUILDING_H
