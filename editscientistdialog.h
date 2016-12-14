#ifndef EDITSCIENTISTDIALOG_H
#define EDITSCIENTISTDIALOG_H
#include <person.h>

#include <QDialog>

namespace Ui {
class EditScientistDialog;
}

class EditScientistDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditScientistDialog(QWidget *parent = 0);
    ~EditScientistDialog();
    void prepare(Person esci);

private:
    Ui::EditScientistDialog *ui;
};

#endif // EDITSCIENTISTDIALOG_H
