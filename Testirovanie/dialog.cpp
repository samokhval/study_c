#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(ChangeAnswer()));
    connect(ui->pushButton, SIGNAL(pressed()), this, SLOT(next_q()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(GetDataBase()));
    connect(ui->lineEdit,SIGNAL(returnPressed()),this ,SLOT(ChangeAnswer()));
    ui->lineEdit->setValidator(new QIntValidator(0, 81, this));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_3_clicked()
{
    close();
}