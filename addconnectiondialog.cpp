#include "addconnectiondialog.h"
#include "ui_addconnectiondialog.h"

AddConnectionDialog::AddConnectionDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddConnectionDialog)
{
    ui->setupUi(this);
    prepare();
}
void AddConnectionDialog::prepare()
{
    for(unsigned int i = 0; i < elist.computerSize();i++)
    {
        ui->list_computers->insertItem(i,QString::fromStdString(elist.getComputerName(i)));
    }
    for(unsigned int i = 0; i < elist.personsSize();i++)
    {
        ui->list_scientists->insertItem(i,QString::fromStdString(elist.getScientistName(i)));
    }

}

AddConnectionDialog::~AddConnectionDialog()
{
    delete ui;
}

void AddConnectionDialog::on_list_scientists_clicked(const QModelIndex &index)
{
    ui->input_current_scientist->clear();
    int row = ui->list_scientists->currentRow();
    QString sciName = QString::fromStdString(elist.getScientistName(row));
    ui->input_current_scientist->insert(sciName);

    clickedScientist = true;
    if(clickedComputer == true && clickedScientist == true)
    {
        ui->button_add_connection->setEnabled(true);
    }
}

void AddConnectionDialog::on_list_computers_clicked(const QModelIndex &index)
{
    ui->input_current_computer->clear();
    int row = ui->list_computers->currentRow();
    QString comName = QString::fromStdString(elist.getComputerName(row));
    ui->input_current_computer->insert(comName);

    clickedComputer = true;
    if(clickedComputer == true && clickedScientist == true)
    {
        ui->button_add_connection->setEnabled(true);
    }
}

void AddConnectionDialog::on_button_edit_connection_cancel_clicked()
{
    this->close();
}

void AddConnectionDialog::on_button_add_connection_clicked()
{
    string comName = ui->input_current_computer->text().toStdString();
    string sciName = ui->input_current_scientist->text().toStdString();

    int sciId = elist.getScientistIdFromName(sciName);
    int comId = elist.getComputerIdFromName(comName);

    elist.addNewConnection(comId,sciId);
    this->close();
}
