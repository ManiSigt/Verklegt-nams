#ifndef EDITSCIENTISTDIALOG_H
#define EDITSCIENTISTDIALOG_H
#include <person.h>
#include "listworker.h"

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

private slots:

    void on_button_scientist_edit_cancel_clicked();

    void on_button_scientist_edit_clicked();

    void on_button_file_open_clicked();

    void on_button_file_save_clicked();

private:
    Ui::EditScientistDialog *ui;
    ListWorker elist;
    int currentId;
};

#endif // EDITSCIENTISTDIALOG_H
