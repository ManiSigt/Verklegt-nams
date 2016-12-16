#ifndef INFOCOMPUTERDIALOG_H
#define INFOCOMPUTERDIALOG_H

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

private:
    Ui::infoComputerDialog *ui;
};

#endif // INFOCOMPUTERDIALOG_H
