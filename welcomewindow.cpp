#include "welcomewindow.h"
#include "ui_welcomewindow.h"
#include "loginwindow.h"

WelcomeWindow::WelcomeWindow(const QString& username, int age, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::WelcomeWindow)
{
    ui->setupUi(this);

    QPixmap pix("C:\\Users\\dell\\Desktop\\istockphoto-1396162151-612x612.jpg");
    int w = ui->image->width();
    int l = ui->image->height();
    ui->image->setPixmap(pix.scaled(w, l, Qt::KeepAspectRatio));

    QString ageString = QString::number(age);
    QString greeting = "hello " + username + " " + ageString;
    ui->hello->setText(greeting);
}

WelcomeWindow::~WelcomeWindow()
{
    delete ui;
}

void WelcomeWindow::on_Logout_clicked()
{
    hide();

    // Show the login window
    LoginWindow *loginWindow = new LoginWindow();
    loginWindow->show();
}

