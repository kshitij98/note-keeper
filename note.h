#ifndef NOTE_H
#define NOTE_H

#include <QMainWindow>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>

namespace Ui {
class Note;
}

class Note : public QMainWindow
{
    Q_OBJECT

public:
    explicit Note(QWidget *parent = 0);
    ~Note();

private slots:
    void on_actionNew_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_actionSave_As_triggered();

    void on_actionExit_triggered();

    void on_pushButton_clicked();

private:
    Ui::Note *ui;
    QString CurrentFile;
};

#endif // NOTE_H
