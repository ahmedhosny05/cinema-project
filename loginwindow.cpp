#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "welcomewindow.h"
#include "Users.h"
#include "registerwindow.h"

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
    for(int i =0 ;i<100 ; i++)
    {
        if((ui->username->text())==usernames[i]&&(ui->password->text())==passwords[i])
        {
            hide() ;
            WelcomeWindow *p = new WelcomeWindow(usernames[i], ages[i], this);

            p-> show() ;
        }
        else
        {
            ui->error -> setVisible(true);
            ui-> error-> setText( " Wrong username or password ");
        }
    }
}
void LoginWindow::on_register_2_clicked()
{
    hide() ;
    RegisterWindow*R = new RegisterWindow(this) ;
    R->show() ;
}
