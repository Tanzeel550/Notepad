#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "find_dialog.h"
#include "replacedialog.h"
#include "about.h"
#include "help_dialog.h"

#include <QMainWindow>
#include <QTreeWidgetItem>
#include <QThread>
#include <QDirModel>
#include <QFileSystemModel>
#include <QInputDialog>
#include <QMessageBox>
#include <QDebug>
#include <QTextOption>
#include <QFileDialog>
#include <QTextStream>
#include <QApplication>
#include <QFontDialog>
#include <QTime>
#include <QDateTime>
#include <string.h>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_actionUndo_triggered();

    void on_actionCopy_triggered();

    void on_actionPaste_triggered();

    void on_actionCut_triggered();

    void on_actionFind_triggered();

    void on_actionWord_Wrap_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_as_triggered();

    void on_actionSave_triggered();

    void on_actionclose_triggered();

    void on_actionRedo_triggered();

    void on_actionFont_triggered();

    void on_actionFind_next_triggered();

    void on_actionSelect_all_triggered();

    void on_actionTime_Date_triggered();

    void on_textEdit_textChanged();

    void on_actionReplace_triggered();

    void on_actionAbout_tanzeel_pad_triggered();

    void on_actionView_help_triggered();

private:
    Ui::MainWindow *ui;
    int ret;
    find_dialog finddialog;
    QString filename = "no";
    void findAndReplaceAll(std::string & data, std::string toSearch, std::string replaceStr);
};

#endif // MAINWINDOW_H
