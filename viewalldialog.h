#ifndef VIEWALLDIALOG_H
#define VIEWALLDIALOG_H

#include <QDialog>
#include "listworker.h"

namespace Ui {
class ViewAllDialog;
}

class ViewAllDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ViewAllDialog(QWidget *parent = 0);
    ~ViewAllDialog();

private slots:
    void on_button_view_scientist_clicked();

private:
    Ui::ViewAllDialog *ui;
    ListWorker listWorker;
    void viewScientist();
};

#endif // VIEWALLDIALOG_H
