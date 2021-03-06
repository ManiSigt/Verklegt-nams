#ifndef INFOSCIENTISTDIALOG_H
#define INFOSCIENTISTDIALOG_H
#include <person.h>
#include "listworker.h"

#include <QDialog>

namespace Ui {
class infoScientistDialog;
}

class infoScientistDialog : public QDialog
{
    Q_OBJECT

public:
    explicit infoScientistDialog(QWidget *parent = 0);
    ~infoScientistDialog();
    void prepareShowSci(Person infoSci);           // Takes one Scientist out of the vector and shows it.

private slots:
     void on_button_close_clicked();

private:
    Ui::infoScientistDialog *ui;
    ListWorker ilist;
    int currentID;
    Person person;
};

#endif // INFOSCIENTISTDIALOG_H
