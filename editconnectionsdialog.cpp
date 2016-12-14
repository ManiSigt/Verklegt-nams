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

void EditConnectionsDialog::on_list_computers_clicked(const QModelIndex &index)
{
    clickedComputer = true;
    if(clickedComputer == true && clickedScientist == true)
    {
        ui->button_edit_connection->setEnabled(true);
    }
}

void EditConnectionsDialog::on_list_scientists_clicked(const QModelIndex &index)
{
    clickedScientist = true;
    if(clickedComputer == true && clickedScientist == true)
    {
        ui->button_edit_connection->setEnabled(true);
    }
}
