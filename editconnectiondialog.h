#ifndef EDITCONNECTIONDIALOG_H
#define EDITCONNECTIONDIALOG_H
#include "listworker.h"
#include "linker.h"

#include <QDialog>

namespace Ui {
class EditConnectionDialog;
}

class EditConnectionDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditConnectionDialog(QWidget *parent = 0);
    ~EditConnectionDialog();
    void prepare(Linker elink);

private slots:
    void on_list_computers_clicked(const QModelIndex &index);

    void on_list_scientists_clicked(const QModelIndex &index);

private:
    Ui::EditConnectionDialog *ui;
    ListWorker elist;
    int currentId = 0;
    bool clickedScientist = false;
    bool clickedComputer = false;
};

#endif // EDITCONNECTIONDIALOG_H
