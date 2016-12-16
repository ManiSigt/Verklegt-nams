#ifndef ADDCOMPUTERDIALOG_H
#define ADDCOMPUTERDIALOG_H

//#include "mainwindow.h"
#include "listworker.h"
#include <QDialog>

namespace Ui {
class addComputerDialog;
}

class addComputerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit addComputerDialog(QWidget *parent = 0);
    ~addComputerDialog();

    void themeChanger(int changer);
private slots:
    void on_add_computer_button_clicked();              // A function that dictates what happens when the user presses a specific button.

    void on_button_add_picture_clicked();               // A function dat dictates what happens when the user presses a specific button.

private:
    Ui::addComputerDialog *ui;
    ListWorker list;
    QString fileName = "0";
};

#endif // ADDCOMPUTERDIALOG_H
