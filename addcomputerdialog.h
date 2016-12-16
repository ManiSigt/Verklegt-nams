#ifndef ADDCOMPUTERDIALOG_H
#define ADDCOMPUTERDIALOG_H

#include "mainwindow.h"
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

private slots:
    void on_add_computer_button_clicked();

    void on_button_add_picture_clicked();

private:
    Ui::addComputerDialog *ui;
    ListWorker list;
    QString fileName = "0";
};

#endif // ADDCOMPUTERDIALOG_H
