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
    void on_button_scientist_edit_cancel_clicked();                     // A function that dictates what happens when the user presses a specific button.
    void on_button_scientist_edit_clicked();                            // A function that dictates what happens when the user presses a specific button.
    void on_button_edit_picture_clicked();                              // A function that dictates what happens when the user presses a specific button.

private:
    Ui::EditScientistDialog *ui;
    ListWorker elist;
    int currentId;
    QString fileName;
};

#endif // EDITSCIENTISTDIALOG_H
