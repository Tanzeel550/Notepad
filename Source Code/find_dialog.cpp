#include "find_dialog.h"
#include "ui_find_dialog.h"
#include "mainwindow.h"
#include <QDebug>

find_dialog::find_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::find_dialog)
{
    ui->setupUi(this);

    setFixedSize(364, 111);

    connect(ui->findnextbutton, &QPushButton::clicked, [=] {
        user_find = ui->lineEdit->text();

        if(ui->radioButton->isChecked())
            user_direction = "up";
        if(ui->radioButton_2->isChecked())
            user_direction = "down";

        accept();
    });

}

find_dialog::~find_dialog()
{
    delete ui;
}


void find_dialog::on_cancelbutton_clicked()
{
    reject();
}

QString find_dialog::getUser_find() const
{
    return user_find;
}

