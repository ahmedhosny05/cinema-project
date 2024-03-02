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
    QString username = ui->username1->text();
    QString password = ui->password1->text();
    QString repassword = ui->repassword->text();
    QString day1 = ui->day->text();
    QString year1 = ui->year->text();
    bool gender1 = ui-> gender->isChecked() ;
    bool account1 =ui->account->isChecked() ;
    bool genre = ui -> genrebox-> isChecked() ;

    bool ok;
    int year = ui->year->text().toInt(&ok);

    if(username.isEmpty()||password.isEmpty()||repassword.isEmpty()||day1.isEmpty()||year1.isEmpty())
    {
        ui->message->setVisible(true) ;
        ui->message->setText(" Please fill all ") ;
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
        ui->message->setVisible(true);
        ui->message->setText("Passwords do not match");
        return;
    }


    bool ok;
    int year = year1.toInt(&ok);
    if (!ok) {
        ui->message->setVisible(true);
        ui->message->setText("Invalid birth year");
        return;
    }


    QDate currentDate = QDate::currentDate();
    int currentYear = currentDate.year();
    int age = currentYear - year;
    if (age < 12) {
        ui->message->setVisible(true);
        ui->message->setText("You must be at least 12 years old");
        return;.
    }


}


