#include "registerwindow.h"
#include "ui_registerwindow.h"
#include "Users.h"
#include "welcomewindow.h"

RegisterWindow::RegisterWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::RegisterWindow)
{
    ui->setupUi(this);
    ui-> message -> setVisible(false);
    ui->message2->setVisible(false) ;
    ui->year1->setVisible(false) ;
    ui->message10->setVisible(false) ;



}

RegisterWindow::~RegisterWindow()
{
    delete ui;
}

void RegisterWindow::on_register_2_clicked()
{
    QString username = ui->username1->text();
    QString password = ui->password1->text();
    QString repassword = ui->repassword->text();
    QString day1 = ui->day->text();
    QString year1 = ui->year->text();
    QString month1 =ui->monthcombo->currentText() ;
    bool gender1 = ui-> male-> isChecked() ;
    bool gender2 =ui-> female-> isChecked() ;
    bool user1 = ui-> user-> isChecked() ;
    bool user2 = ui-> admin -> isChecked();
    bool action1 = ui->action -> isChecked() ;
    bool drama1 =ui ->drama -> isChecked() ;
    bool horror1 = ui->horror->isChecked() ;
    bool comedy1 =ui->comedy->isChecked() ;
    bool romance1=ui->romance->isChecked() ;
    bool other1 =ui->other->isChecked()  ;
    ui->message->setText("") ;
    ui->message2->setText("") ;
    ui-> year1->setText("") ;
    ui->message10->setText("") ;




    bool ok;
    int year = ui->year->text().toInt(&ok);
    if (username.isEmpty() || password.isEmpty() || repassword.isEmpty() || day1.isEmpty() || year1.isEmpty())
    {
        ui->message10->setVisible(true);
        ui->message10->setText(" Please fill all ");
        return;
    }

    for (int i = 0; i < usersCount; i++)
    {
        if (usernames[i] == username)
        {
            ui->message->setVisible(true);
            ui->message->setText(" username already exists");
            return;
        }
    }
    if (password != repassword)
    {
        ui->message2->setVisible(true);
        ui->message2->setText("Passwords do not match");
        return;
    }

    int currentYear = 2024;
    int age = currentYear - year;
    if (age < 12)
    {
        ui->year1->setVisible(true);
        ui->year1->setText(" you must be at least 12 years old");
        return;
    }

    if (usersCount < 100)
    {
        usernames[usersCount] = username;
        passwords[usersCount] = password;
        ages[usersCount] = age;
        ++usersCount;
        WelcomeWindow* welc = new WelcomeWindow(username, age, this);

        hide();
        welc->show();
    }
    else
    {
        ui->message10->setVisible(true);
        ui->message10->setText(" Maximum number reached");
    }

}
