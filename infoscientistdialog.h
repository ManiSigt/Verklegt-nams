#ifndef INFOSCIENTISTDIALOG_H
#define INFOSCIENTISTDIALOG_H

#include <QDialog>

namespace Ui {
class infoScientistDialog;
}

class infoScientistDialog : public QDialog
{
    Q_OBJECT

public:
    explicit infoScientistDialog(QWidget *parent = 0);
    ~infoScientistDialog();

private:
    Ui::infoScientistDialog *ui;
};

#endif // INFOSCIENTISTDIALOG_H
