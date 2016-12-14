#include "addcomputerdialog.h"
#include "ui_addcomputerdialog.h"

addComputerDialog::addComputerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addComputerDialog)
{
    ui->setupUi(this);
}

addComputerDialog::~addComputerDialog()
{
    delete ui;
}

void addComputerDialog::on_add_computer_button_clicked()
{
    string yesNo;
    QString name = ui->input_computer_name->text();
    if(name.isEmpty())
    {
        ui->error_name->setText("No name in input!");
        return;
    }
    QString type = ui->input_computer_type->text();
    if(type.isEmpty())
    {
        ui->error_type->setText("No type name in input!");
        return;
    }
    QString date = ui->input_computer_date->text();
    if (date.isEmpty())
    {
        ui->error_date->setText("No date in input!");
        return;
    }
    if(ui->radioButton_Yes->isChecked())
    {
        yesNo = "Yes";
    }
    if(ui->radioButton_Yes->isChecked())
    {
        yesNo = "No";
    }

    bool success = list.addNewComputer(name.toStdString(), type.toStdString(), date.toInt(), yesNo);
    if (success)
    {
        this->done(0);
    }
    else
    {
        this->done(1);
    }
}
