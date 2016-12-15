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
    void on_list_scientists_clicked(const QModelIndex &index);

    void on_list_computers_clicked(const QModelIndex &index);

    void on_button_edit_connection_cancel_clicked();

    void on_button_add_connection_clicked();

private:
    Ui::AddConnectionDialog *ui;
    ListWorker elist;
    bool clickedScientist;
    bool clickedComputer;
};

#endif // ADDCONNECTIONDIALOG_H
