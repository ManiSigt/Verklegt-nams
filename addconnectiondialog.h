#ifndef ADDCONNECTIONDIALOG_H
#define ADDCONNECTIONDIALOG_H

#include <QDialog>

#include "listworker.h"
#include "linker.h"

namespace Ui {
class AddConnectionDialog;
}

class AddConnectionDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddConnectionDialog(QWidget *parent = 0);
    ~AddConnectionDialog();
    void prepare();

private slots:
    void on_list_scientists_clicked();                              // A function that dictates what happens when the user presses a specific button.
    void on_list_computers_clicked();                               // A function that dictates what happens when the user presses a specific button.
    void on_button_edit_connection_cancel_clicked();                // A function that dictates what happens when the user presses a specific button.
    void on_button_add_connection_clicked();                        // A function that dictates what happens when the user presses a specific button.

private:
    Ui::AddConnectionDialog *ui;
    ListWorker elist;
    bool clickedScientist;                                          // Checks if the a scientist was picked from a list.
    bool clickedComputer;                                           // Checks if a computer was picked from a list.
};

#endif // ADDCONNECTIONDIALOG_H
