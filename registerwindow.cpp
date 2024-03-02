#include "registerwindow.h"
#include "ui_registerwindow.h"

RegisterWindow::RegisterWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::RegisterWindow)
{
    ui->setupUi(this);
    ui-> message -> setVisible(false);
    ui->message2->setVisible(false) ;
    ui->label_9->setVisible(false) ;
    ui->label_12->setVisible(false) ;



}

RegisterWindow::~RegisterWindow()
{
    delete ui;
}

void RegisterWindow::on_register_2_clicked()
{
    QString username = ui->username1->text() ;
    QString password = ui->password1->text() ;
    QString repassword = ui->repassword->text() ;
    QString day1 =ui->day->text() ;
    QString year1 = ui->year->text() ;
    QString  month =ui-> monthcombo ->currentText() ;

    Qstring gender ;
    if(ui->male->isChecked())
    {
        gender = "Male" ;
    } else if(ui->female->isChecked())
    {
        gender="Female" ;
    }

    QString account ;
    if(ui->user->isChecked())
    {
        account = "User" ;
    }
    else if(ui->admin->isChecked())
    {
        account = "Admin" ;
    }
}

