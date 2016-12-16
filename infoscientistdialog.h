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
     void prepareShowSci(Person infoSci);
private:
    Ui::infoScientistDialog *ui;
    ListWorker ilist;
    int currentID;
    Person person;
};

#endif // INFOSCIENTISTDIALOG_H
