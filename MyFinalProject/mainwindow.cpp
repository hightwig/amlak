#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent)
{
    Sign_in=new QPushButton("Sign in");
    Sign_up=new QPushButton("Sign up");
    QHBoxLayout *Horizontal=new QHBoxLayout();
    Horizontal->addWidget(Sign_in);
    Horizontal->addWidget(Sign_up);

    connect(Sign_in,SIGNAL(clicked()),this,SLOT(signin_clicked()));
    connect(Sign_up,SIGNAL(clicked()),this,SLOT(signup_clicked()));

    QWidget *centeral=new QWidget;
    centeral->setLayout(Horizontal);
    setCentralWidget(centeral);
}

MainWindow::~MainWindow()
{

}
void MainWindow::signin_clicked(){
    hide();
    signin_window=new Sign_in_function();
    signin_window->show();
}
void MainWindow::signup_clicked(){
    hide();
    signup_window=new sign_up_function();
    signup_window->show();

}
