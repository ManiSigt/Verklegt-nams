#include "infocomputerdialog.h"
#include "ui_infocomputerdialog.h"

infoComputerDialog::infoComputerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::infoComputerDialog)
{
    ui->setupUi(this);
}

infoComputerDialog::~infoComputerDialog()
{
    delete ui;
}
