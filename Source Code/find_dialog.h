#ifndef FIND_DIALOG_H
#define FIND_DIALOG_H

#include <QDialog>

namespace Ui {
class find_dialog;
}

class find_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit find_dialog(QWidget *parent = nullptr);
    QString user_direction;
    ~find_dialog();

    QString getUser_find() const;

private slots:
    void on_cancelbutton_clicked();

private:
    Ui::find_dialog *ui;
    QString user_find;
};

#endif // FIND_DIALOG_H
