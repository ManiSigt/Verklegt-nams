#ifndef EDITCOMPUTERDIALOG_H
#define EDITCOMPUTERDIALOG_H
#include "computer.h"
#include "listworker.h"

#include <QDialog>

namespace Ui {
class EditComputerDialog;
}

class EditComputerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditComputerDialog(QWidget *parent = 0);
    ~EditComputerDialog();
    void prepare(Computer ecom);

private slots:
    void on_button_computer_edit_clicked();

    void on_button_computer_edit_cancel_clicked();

private:
    Ui::EditComputerDialog *ui;
    ListWorker elist;
    int currentId = 0;
};

#endif // EDITCOMPUTERDIALOG_H
