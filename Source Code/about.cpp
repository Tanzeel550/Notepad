#include "about.h"
#include "ui_about.h"

about::about(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::about)
{
    ui->setupUi(this);

    this->setFixedSize(400,300);

    this->setWindowTitle("About TanPad");

}

about::~about()
{
    delete ui;
}

void about::on_pushButton_clicked()
{
    accept();
}
