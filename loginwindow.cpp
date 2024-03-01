#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "welcomewindow.h"
#include "Users.h"

LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    ui ->error->setVisible(false);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}




void LoginWindow::on_login_clicked()
{
    QString enteredUsername = ui->username->text();
    QString enteredPassword = ui->password->text();

    bool found = false;
    for(int i = 0; i < 100; i++) {
        if(usernames[i] == enteredUsername && passwords[i] == enteredPassword) {
            found = true;
            break;
        }
    }

    if(found) {
        hide();
        WelcomeWindow *welcomeWindow = new WelcomeWindow(this);
        welcomeWindow->show();
    } else {
        ui->error->setVisible(true);
        ui->error->setText("Wrong username or password");
    }
}
