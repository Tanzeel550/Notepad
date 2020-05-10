#include "help_dialog.h"
#include "ui_help_dialog.h"

help_dialog::help_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::help_dialog)
{
    ui->setupUi(this);

    this->setWindowTitle("Help");

    this->setFixedSize(226, 193);
}

help_dialog::~help_dialog()
{
    delete ui;
}

void help_dialog::on_buttonBox_accepted()
{
    accept();
}
