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
    QString type = ui->input_computer_type->text();
    QString date = ui->input_computer_date->text();

    if(ui->radioButton_Yes->isChecked())
    {
        yesNo = "Yes";
    }
    if(ui->radioButton_Yes->isChecked())
    {
        yesNo = "No";
    }

    list.addNewComputer(name.toStdString(), type.toStdString(), date.toInt(), yesNo);

}
