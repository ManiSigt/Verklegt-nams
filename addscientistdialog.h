#ifndef ADDSCIENTISTDIALOG_H
#define ADDSCIENTISTDIALOG_H

#include <QDialog>


#include "mainwindow.h"

#include "listworker.h"


namespace Ui {
class AddScientistDialog;
}

class AddScientistDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddScientistDialog(QWidget *parent = 0);
    ~AddScientistDialog();

private slots:
    void on_button_addScientist_clicked();

private:
    Ui::AddScientistDialog *ui;
    //ListWorker list2;




};

#endif // ADDSCIENTISTDIALOG_H
