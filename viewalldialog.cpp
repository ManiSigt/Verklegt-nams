#include "viewalldialog.h"
#include "ui_viewalldialog.h"
#include "listworker.h"
#include <iostream>
#include <vector>

using namespace std;

ViewAllDialog::ViewAllDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ViewAllDialog)
{
    ui->setupUi(this);
}

ViewAllDialog::~ViewAllDialog()
{
    delete ui;
}

void ViewAllDialog::on_button_view_scientist_clicked()
{
    viewScientist();
}

void ViewAllDialog::viewScientist()
{
    ui->tableViewAll->rowAt(7);
    ui->tableViewAll->columnAt(3);

    for(unsigned int i = 0; i < 10; i++)
    {

    }
}
