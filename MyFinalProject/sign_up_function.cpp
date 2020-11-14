#include "sign_up_function.h"
#include "ui_sign_up_function.h"

sign_up_function::sign_up_function(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sign_up_function)
{
    ui->setupUi(this);
}

sign_up_function::~sign_up_function()
{
    delete ui;
}
