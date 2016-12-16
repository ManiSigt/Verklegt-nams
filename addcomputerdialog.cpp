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
        ui->error_name->setText("<span style='color: #FF1100'>No name in input!</span>");
        return;
    }
    QString type = ui->input_computer_type->text();
    if(type.isEmpty())
    {
        ui->error_type->setText("<span style='color: #FF1100'>No type name in input!</span>");
        return;
    }
    QString date = ui->input_computer_date->text();
    int date1 = ui->input_computer_date->text().toUInt();
    if (date.isEmpty())
    {
        ui->error_date->setText("<span style='color: #FF1100'>No date in input!</span>");
        return;
    }
    if(date1 > 2016)
    {
       ui->error_date->setText("<span style='color: #FF1100'>Not a valid date!</span>");
       return;
    }
    if(date < 0)
    {
      ui->error_date->setText("<span style='color: #FF1100'>Not a valid date!</span>");
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
        this->done(1);
    }
    else
    {
        this->done(-1);
    }
}
