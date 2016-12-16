#include "infoscientistdialog.h"
#include "ui_infoscientistdialog.h"

infoScientistDialog::infoScientistDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::infoScientistDialog)
{
    ui->setupUi(this);
}

infoScientistDialog::~infoScientistDialog()
{
    delete ui;
}
