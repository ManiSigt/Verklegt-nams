#ifndef EDITCONNECTIONSDIALOG_H
#define EDITCONNECTIONSDIALOG_H

#include "listworker.h"
#include "linker.h"

#include <QDialog>

namespace Ui {
class EditConnectionsDialog;
}

class EditConnectionsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditConnectionsDialog(QWidget *parent = 0);
    ~EditConnectionsDialog();
    void prepare(Linker elink);

private slots:
    void on_list_computers_clicked();                                   // A function that dictates what happens when the user presses a specific button.
    void on_list_scientists_clicked();                                  // A function that dictates what happens when the user presses a specific button.
    void on_button_edit_connection_cancel_clicked();                    // A function that dictates what happens when the user presses a specific button.
    void on_button_edit_connection_clicked();                           // A function that dictates what happens when the user presses a specific button.

private:
    Ui::EditConnectionsDialog *ui;
    ListWorker elist;
    int currentId = 0;
    bool clickedScientist = false;                                       // Checks if the a scientist was picked from a list.
    bool clickedComputer = false;                                        // Checks if the a computer was picked from a list.
};

#endif // EDITCONNECTIONSDIALOG_H
