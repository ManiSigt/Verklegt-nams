#ifndef INFOCOMPUTERDIALOG_H
#define INFOCOMPUTERDIALOG_H
#include "listworker.h"

#include <QDialog>

namespace Ui {
class infoComputerDialog;
}

class infoComputerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit infoComputerDialog(QWidget *parent = 0);
    ~infoComputerDialog();
    void test();

private slots:
    void on_button_close_clicked();

private:
    Ui::infoComputerDialog *ui;

    ListWorker elist;
};

#endif // INFOCOMPUTERDIALOG_H
