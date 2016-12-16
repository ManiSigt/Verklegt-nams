#include "editconnectionsdialog.h"
#include "ui_editconnectionsdialog.h"
#include <QDebug>
#include <QTableWidget>
using namespace std;

EditConnectionsDialog::EditConnectionsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditConnectionsDialog)
{
    ui->setupUi(this);
}
EditConnectionsDialog::~EditConnectionsDialog()
{
    delete ui;
}
void EditConnectionsDialog::prepare(Linker elink)
{
    int comId = elink.getComId();
    int sciId = elink.getSciId();
    currentId = elink.getId();

    for(int i = 0; i < elist.computerSize(); i++)
    {
        ui->list_computers->insertItem(i,QString::fromStdString(elist.getComputerName(i)));
    }

    for(int i = 0; i < elist.personsSize(); i++)
    {
        ui->list_scientists->insertItem(i,QString::fromStdString(elist.getScientistName(i)));
    }
    ui->input_current_computer->insert(QString::fromStdString(elist.getComputerNameFromId(comId)));
    ui->input_current_scientist->insert(QString::fromStdString(elist.getScientistNameFromId(sciId)));
}
void EditConnectionsDialog::on_list_computers_clicked()
{
    ui->input_current_computer->clear();
    int row = ui->list_computers->currentRow();
    QString comName = QString::fromStdString(elist.getComputerName(row));
    ui->input_current_computer->insert(comName);
    clickedComputer = true;

    if(clickedComputer == true && clickedScientist == true)
    {
        ui->button_edit_connection->setEnabled(true);
    }
}
void EditConnectionsDialog::on_list_scientists_clicked()
{
    ui->input_current_scientist->clear();
    int row = ui->list_scientists->currentRow();
    QString sciName = QString::fromStdString(elist.getScientistName(row));
    ui->input_current_scientist->insert(sciName);
    clickedScientist = true;

    if(clickedComputer == true && clickedScientist == true)
    {
        ui->button_edit_connection->setEnabled(true);
    }
}
void EditConnectionsDialog::on_button_edit_connection_cancel_clicked()
{
    this->close();
}
void EditConnectionsDialog::on_button_edit_connection_clicked()
{
    string comName = ui->input_current_computer->text().toStdString();
    string sciName = ui->input_current_scientist->text().toStdString();
    int sciId = elist.getScientistIdFromName(sciName);
    int comId = elist.getComputerIdFromName(comName);

    bool success = elist.updateConnection(currentId,sciId,comId);

    if (success)
    {
        this->done(1);
    }
    else
    {
        this->done(-1);
    }
}
