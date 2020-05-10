#ifndef REPLACEDIALOG_H
#define REPLACEDIALOG_H

#include <QDialog>
#include <QDebug>

namespace Ui {
class replacedialog;
}

class replacedialog : public QDialog
{
    Q_OBJECT

public:
    explicit replacedialog(QWidget *parent = nullptr);
    ~replacedialog();

    QString user_find;
    QString user_replace;
    QString user_action;

private slots:
    void on_findnextbutton_5_clicked();

    void on_replacebutton_clicked();

    void on_replaceallbutton_clicked();

private:
    Ui::replacedialog *ui;

};

#endif // REPLACEDIALOG_H
