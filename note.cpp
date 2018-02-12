#include "note.h"
#include "ui_note.h"

Note::Note(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Note)
{
    ui->setupUi(this);
}

Note::~Note()
{
    delete ui;
}

void Note::on_actionNew_triggered()
{
    ui -> lineEdit -> setText("");
    ui -> textEdit -> setText("");
    CurrentFile = "";
}

void Note::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open the file");
    QFile file(fileName);
    CurrentFile = fileName;
    if (!file.open(QIODevice::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, "..", "File not opened.");
        return;
    }
    QTextStream in(&file);
    QString text = in.readAll();
    ui -> lineEdit -> setText(fileName);
    ui -> textEdit -> setText(text);
    file.close();
}

void Note::on_actionSave_triggered()
{
    QFile file(CurrentFile);
    if (!file.open(QIODevice::WriteOnly | QFile::Text)) {
        on_actionSave_As_triggered();
        return;
    }
    QTextStream out(&file);

    out << (ui -> lineEdit -> text()) << endl;
    for (int i=0 ; i<(ui->lineEdit->text()).length() ; ++i)
        out << "=";
    out << endl << endl << (ui -> textEdit -> toPlainText()) << endl;

    file.flush();
    file.close();
}

void Note::on_actionSave_As_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save as");
    QFile file(fileName);
    CurrentFile = fileName;
    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this,"..","File not opened.");
        return;
    }
    QTextStream out(&file);

    out << (ui -> lineEdit -> text()) << endl;
    for (int i=0 ; i<(ui->lineEdit->text()).length() ; ++i)
        out << "=";
    out << endl << endl << (ui -> textEdit -> toPlainText()) << endl;

    file.flush();
    file.close();
}

void Note::on_actionExit_triggered()
{
    this -> ~Note();
}

void Note::on_pushButton_clicked()
{
    on_actionSave_triggered();
}
