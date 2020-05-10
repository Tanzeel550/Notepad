#include "replacedialog.h"
#include "ui_replacedialog.h"



replacedialog::replacedialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::replacedialog)
{
    ui->setupUi(this);

    this->setWindowTitle("Replace");
}

replacedialog::~replacedialog()
{
    delete ui;
}

void replacedialog::on_findnextbutton_5_clicked()
{
    user_find = ui->findlineedit->text();
    user_action = "find";
    accept();
}

void replacedialog::on_replacebutton_clicked()
{
    user_action = "replace";
    user_find = ui->findlineedit->text();
    user_replace = ui->replacelineedit->text();
    accept();
}

void replacedialog::on_replaceallbutton_clicked()
{
    user_action = "replaceall";
    user_find = ui->findlineedit->text();
    user_replace = ui->replacelineedit->text();
    accept();
}
