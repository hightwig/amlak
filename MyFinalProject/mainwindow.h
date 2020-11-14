#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMainWindow>
#include <sign_in_function.h>
#include <QStatusBar>
#include <sign_up_function.h>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private slots:
    void signin_clicked();
    void signup_clicked();
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QPushButton *Sign_in;
    QPushButton *Sign_up;
    Sign_in_function *signin_window;
    sign_up_function *signup_window;

};

#endif // MAINWINDOW_H
