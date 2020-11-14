#ifndef SEARCH_USER_H
#define SEARCH_USER_H
#include <classes.h>
#include <QDialog>

namespace Ui {
class Search_user;
}

class Search_user : public QDialog
{
    Q_OBJECT

public:
    explicit Search_user(Person*,QVector<rent>,QVector<sell>,QWidget *parent = nullptr);
    ~Search_user();

private slots:
    void on_pushButton_clicked();

    void on_comboBox_currentIndexChanged(int);

private:
    QVector<rent> myrent;
      QVector<rent> myrent1;
    QVector<sell> mysell;
    Person* this_user;
    long long int RAND;
    Ui::Search_user *ui;
};

#endif // SEARCH_USER_H
