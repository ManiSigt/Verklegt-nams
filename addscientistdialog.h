#ifndef ADDSCIENTISTDIALOG_H
#define ADDSCIENTISTDIALOG_H

#include "mainwindow.h"
#include "listworker.h"
#include <QDialog>

namespace Ui {
class addScientistDialog;
}

class addScientistDialog : public QDialog
{
    Q_OBJECT

public:
    explicit addScientistDialog(QWidget *parent = 0);
    ~addScientistDialog();

private slots:
    void on_button_add_scientist_clicked();                 // a function that dictates what happens when the user presses a specific button

private:
    Ui::addScientistDialog *ui;
    ListWorker list;
};

#endif // ADDSCIENTISTDIALOG_H
