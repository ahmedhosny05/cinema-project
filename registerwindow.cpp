#include "registerwindow.h"
#include "ui_registerwindow.h"
#include "Users.h"

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
    bool gender1 = ui-> gender->isChecked() ;
    bool account1 =ui->account->isChecked() ;
    bool genre = ui -> genrebox-> isChecked() ;
    QString selectedOption = ui->monthcombo->currentText();

    bool ok;
    int year = ui->year->text().toInt(&ok);
    if(username.isEmpty()||password.isEmpty()||repassword.isEmpty()||day1.isEmpty()||year1.isEmpty())
    {
        ui->message10->setVisible(true) ;
        ui->message10->setText(" Please fill all ") ;
        return ;
    }

    for( int i =0 ;i<usersCount;i++)
    {
        if(usernames[i]==username)
        {
            ui->message->setVisible(true) ;
            ui->message->setText(" username already exists") ;
            return ;
        }
    }
    if (password != repassword) {
        ui->message2->setVisible(true);
        ui->message2->setText("Passwords do not match");
        return;
    }


    if((2024-year)<12)
    {
        ui->year1->setVisible(true);
        ui-> year1->setText(" you must be atleast 12 years old");
    }

    for(int i=0 ;i<usersCount;i++)
    {
         usernames[usersCount] = username;
    }

}


