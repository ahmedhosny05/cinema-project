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
