#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->textEdit->setWordWrapMode(QTextOption::NoWrap);

    QColor color(0,0,0);
    ui->textEdit->setTextColor(color);
    this->setCentralWidget(ui->textEdit);
    this->setWindowTitle("Untitled.txt");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}

void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}

void MainWindow::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}

void MainWindow::on_actionCut_triggered()
{
    ui->textEdit->cut();
}

void MainWindow::on_actionclose_triggered()
{
    QApplication::quit();
}

void MainWindow::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}

void MainWindow::on_actionSelect_all_triggered()
{
    ui->textEdit->selectAll();
}

void MainWindow::on_actionFind_triggered()
{
    ret = finddialog.exec();
    if(ret == finddialog.Accepted){
        if(finddialog.user_direction == "down")
            ui->textEdit->find(finddialog.getUser_find(),QTextDocument::FindBackward);
        if(finddialog.user_direction == "up")
            ui->textEdit->find(finddialog.getUser_find());
    }
}

void MainWindow::on_actionFind_next_triggered()
{
    if(ret == 1){
        if(finddialog.user_direction == "down")
            ui->textEdit->find(finddialog.getUser_find(),QTextDocument::FindBackward);
        if(finddialog.user_direction == "up")
            ui->textEdit->find(finddialog.getUser_find());
    }
}

void MainWindow::on_actionWord_Wrap_triggered()
{
    if(ui->actionWord_Wrap->isChecked())
        ui->textEdit->setWordWrapMode(QTextOption::WrapAtWordBoundaryOrAnywhere);
    else
        ui->textEdit->setWordWrapMode(QTextOption::NoWrap);
}

void MainWindow::on_actionOpen_triggered()
{
    //Make a variable to store the data of the file in the variable
    QString wholefile;
    //Open a dialog to select the file to read
    filename = QFileDialog::getOpenFileName(this, tr("Open File"), "tanzeel", "Text(*txt);;html(*html);;css(*css)");

    this->setWindowTitle(filename);
    //Check if the file is empty
    if(filename.isEmpty())
        return;
    //Open the file
    QFile file(filename);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;
    //Set a in-stream to the file
    QTextStream in(&file);
    //Read the whole file
    QString line = in.readLine();
    while(!line.isNull()){
        wholefile.append(line);
        line = in.readLine();
    }
    file.close();
    ui->textEdit->clear();
    ui->textEdit->setText(wholefile);
}

void MainWindow::on_actionSave_triggered()
{
    if(filename=="no"){
        filename = QFileDialog::getSaveFileName(this, "Save as");
        //A dialog to
        if(filename.isEmpty())
            return;
        //Open the file
        QFile file(filename);

        if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
            return;

        //Open the file in textstream (like filestreams in C++)
        QTextStream out(&file);
        out << ui->textEdit->toPlainText() << "\n";

        file.close();
    }
    else{
        QFile file(filename);

        if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
            return;

        //Open the file in textstream (like filestreams in C++)
        QTextStream out(&file);
        out << ui->textEdit->toPlainText() << "\n";

        file.close();
    }
}

void MainWindow::on_actionSave_as_triggered()
{
    filename = QFileDialog::getSaveFileName(this, "Save as");
    //A dialog to
    if(filename.isEmpty())
        return;
    //Open the file
    QFile file(filename);

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;

    //Open the file in textstream (like filestreams in C++)
    QTextStream out(&file);
    out << ui->textEdit->toPlainText() << "\n";

    file.close();
}

void MainWindow::on_actionFont_triggered()
{
    bool ok;
    QFont font = QFontDialog::getFont(
                &ok, QFont("Helvetica [Cronyx]", 10), this);
    if (ok)
        ui->textEdit->setFont(font);
}

void MainWindow::on_actionTime_Date_triggered()
{
    QDateTime set(QDateTime::currentDateTime());
    QString time = set.toString();
    ui->textEdit->append(time);
}

void MainWindow::on_textEdit_textChanged()
{
    if(ui->actionStatus_Bar->isChecked()){
        QString wholetext = ui->textEdit->toPlainText();
        int column = 0, row = 1;
        for(int i = 0; i < wholetext.count(); i++){
            if(wholetext.at(i)=="\n"){
                row++;
                column = 1;
            }
            else
                column++;
        }
        QString status = QString("Row : %1, Column : %2").arg(row).arg(column);
        statusBar()->showMessage(status);
    }
}

void MainWindow::on_actionReplace_triggered()
{
    replacedialog replacedialog;
    replacedialog.exec();

    if(replacedialog.user_action == "find"){
        ui->textEdit->find(replacedialog.user_find);
    }
    if(replacedialog.user_action == "replace"){
        QString wholetext = ui->textEdit->toPlainText();
        int user_replace_location = wholetext.indexOf(replacedialog.user_find);
        wholetext.remove(user_replace_location, replacedialog.user_find.length());
        wholetext.insert(user_replace_location, replacedialog.user_replace);
        ui->textEdit->setPlainText(wholetext);
    }
    if(replacedialog.user_action == "replaceall"){
        QString wholetext = ui->textEdit->toPlainText();
        std::string std_wholetext = wholetext.toStdString();
        std::string std_user_find = replacedialog.user_find.toStdString();
        std::string std_user_replace = replacedialog.user_replace.toStdString();

        findAndReplaceAll(std_wholetext, std_user_find, std_user_replace);

        ui->textEdit->setPlainText(QString::fromStdString(std_wholetext));
    }
}

void MainWindow::findAndReplaceAll(std::string &data, std::string toSearch, std::string replaceStr)
{
    // Get the first occurrence
    size_t pos = data.find(toSearch);

    // Repeat till end is reached
        while( pos != std::string::npos){
        // Replace this occurrence of Sub String
        data.replace(pos, toSearch.size(), replaceStr);
        // Get the next occurrence from the current position
        pos = data.find(toSearch, pos + replaceStr.size());
    }
}

void MainWindow::on_actionAbout_tanzeel_pad_triggered()
{
    about * aboutdialoag = new about(this);
    aboutdialoag->exec();
}

void MainWindow::on_actionView_help_triggered()
{
    help_dialog helpdialog;
    helpdialog.exec();
}
