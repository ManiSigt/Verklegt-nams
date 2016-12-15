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
    void on_list_computers_clicked(const QModelIndex &index);

    void on_list_scientists_clicked(const QModelIndex &index);

    void on_button_edit_connection_cancel_clicked();

    void on_button_edit_connection_clicked();

private:
    Ui::EditConnectionsDialog *ui;
    ListWorker elist;
    int currentId = 0;
    bool clickedScientist = false;
    bool clickedComputer = false;
};

#endif // EDITCONNECTIONSDIALOG_H
