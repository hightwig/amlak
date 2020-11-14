#ifndef SIGN_UP_FUNCTION_H
#define SIGN_UP_FUNCTION_H

#include <QDialog>

namespace Ui {
class sign_up_function;
}

class sign_up_function : public QDialog
{
    Q_OBJECT

public:
    explicit sign_up_function(QWidget *parent = nullptr);
    ~sign_up_function();

private:
    Ui::sign_up_function *ui;
};

#endif // SIGN_UP_FUNCTION_H
