#ifndef SIGN_IN_FUNCTION_H
#define SIGN_IN_FUNCTION_H

#include <QDialog>
#include <QMessageBox>
#include <QMap>
#include <QDebug>
#include <QIODevice>
#include <QFile>
#include <QWidget>
#include <QStatusBar>
#include <fstream>
#include <iostream>
#include <QTextEdit>
#include <QVector>
#include <mainpage.h>
#include <classes.h>
using namespace std;
namespace Ui {
class Sign_in_function;
}

class Sign_in_function : public QDialog
{
    Q_OBJECT

public:
    explicit Sign_in_function(QWidget *parent = nullptr);
    ~Sign_in_function();

private slots:
    void on_Login_clicked();

private:

    int I_VECTOR;
    QVector<rent> myrent;
    QVector<sell> mysell;
    Ui::Sign_in_function *ui;
    QMap<QString,QString> MYMap;
    QStatusBar *statuus;
    MainPage *_Mainpage;
};

#endif // SIGN_IN_FUNCTION_H
