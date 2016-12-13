#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "listworker.h"
#include <QMessageBox>
#include <algorithm>
#include <QDebug>
#include <string>
#include <QList>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    showComputers();
    showConnections();
    showScientists();
    populateDropdownMenus();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showScientists()
{
    ui->table_scientist->clear();

    ui->table_scientist->setHorizontalHeaderItem(0,new QTableWidgetItem("Name"));
    ui->table_scientist->setHorizontalHeaderItem(1,new QTableWidgetItem("Gender"));
    ui->table_scientist->setHorizontalHeaderItem(2,new QTableWidgetItem("Birth"));
    ui->table_scientist->setHorizontalHeaderItem(3,new QTableWidgetItem("Death"));
    ui->table_scientist->setHorizontalHeaderItem(4,new QTableWidgetItem("Comment"));

    ui->table_scientist->setRowCount(list.personsSize());
    ui->table_scientist->setColumnCount(5);
    for(int i = 0; i < list.personsSize(); i++)
    {
        string nameSearch = ui->input_scientist->text().toStdString();
        transform(nameSearch.begin(), nameSearch.end(), nameSearch.begin(), ::tolower);
        size_t found = list.getScientistLowerCaseName(i).find(nameSearch);
        if(found!=std::string::npos)
        {
            int birth = list.getScientistBirth(i);
            int death = list.getScientistDeath(i);

            QString qname = QString::fromStdString(list.getScientistName(i));
            QString qgender = QChar(list.getScientistGender(i));
            QString qbirth = QString::number(birth);
            QString qdeath = QString::number(death);
            QString qcomment = QString::fromStdString(list.getScientistComment(i));

            ui->table_scientist->setItem(i,0,new QTableWidgetItem(qname));
            ui->table_scientist->setItem(i,1,new QTableWidgetItem(qgender));
            ui->table_scientist->setItem(i,2,new QTableWidgetItem(qbirth));
            ui->table_scientist->setItem(i,3,new QTableWidgetItem(qdeath));
            ui->table_scientist->setItem(i,4,new QTableWidgetItem(qcomment));
        }
    }
    ui->table_scientist->resizeColumnsToContents();

}
void MainWindow::showComputers()
{
    int rowCount;
    ui->table_computer->clear();

    ui->table_computer->setHorizontalHeaderItem(0,new QTableWidgetItem("Name"));
    ui->table_computer->setHorizontalHeaderItem(1,new QTableWidgetItem("Type"));
    ui->table_computer->setHorizontalHeaderItem(2,new QTableWidgetItem("Date"));
    ui->table_computer->setHorizontalHeaderItem(3,new QTableWidgetItem("Was it built"));

    ui->table_computer->setRowCount(list.computerSize());
    ui->table_computer->setColumnCount(4);

    for(int i = 0; i < list.computerSize(); i++)
    {
        string nameSearch = ui->input_computer->text().toStdString();
        transform(nameSearch.begin(), nameSearch.end(), nameSearch.begin(), ::tolower);
        size_t found = list.getComputerLowerCaseName(i).find(nameSearch);
        if(found!=std::string::npos)
        {
            int date = list.getComputerDate(i);

            QString qname = QString::fromStdString(list.getComputerName(i));
            QString qtype = QString::fromStdString(list.getComputerType(i));
            QString qdate = QString::number(date);
            QString qwasitbuilt = QString::fromStdString(list.getComputerWasItBuilt(i));

            ui->table_computer->setItem(i,0,new QTableWidgetItem(qname));
            ui->table_computer->setItem(i,1,new QTableWidgetItem(qtype));
            ui->table_computer->setItem(i,2,new QTableWidgetItem(qdate));
            ui->table_computer->setItem(i,3,new QTableWidgetItem(qwasitbuilt));
            rowCount = i;
        }
    }
    ui->table_computer->resizeColumnsToContents();
}
void MainWindow::showConnections()
{
    ui->table_connections->clearContents();
    list.sortConnections("1"); //þegar sort verður lagfært þá verður þetta kannski fært.

    ui->table_connections->clear();

    ui->table_connections->setHorizontalHeaderItem(0,new QTableWidgetItem("Scientist Name"));
    ui->table_connections->setHorizontalHeaderItem(1,new QTableWidgetItem("Computer Name"));

    ui->table_connections->setRowCount(list.getLinkOutputSize());
    ui->table_connections->setColumnCount(2);

    for(int i = 0; i < list.getLinkOutputSize(); i++)
    {
        string nameSearch = ui->input_connections->text().toStdString();
        transform(nameSearch.begin(), nameSearch.end(), nameSearch.begin(), ::tolower);
        size_t found = list.getScientistLowerCaseName(i).find(nameSearch);
        if(found!=std::string::npos)
        {
            QString qsciname = QString::fromStdString(list.getLinkOutputSciName(i));
            QString qcompname = QString::fromStdString(list.getLinkOutputCompName(i));

            ui->table_connections->setItem(i,0,new QTableWidgetItem(qsciname));
            ui->table_connections->setItem(i,1,new QTableWidgetItem(qcompname));
       }
    }
    ui->table_connections->resizeColumnsToContents();
}

void MainWindow::on_dropdown_scientist_activated(const QString &arg1)
{
        QMessageBox::information(this, "Item Selection",
        ui->dropdown_scientist->currentText());
}

void MainWindow::populateDropdownMenus()
{
        ui->dropdown_scientist->addItem("Name");
        ui->dropdown_scientist->addItem("Gender");
        ui->dropdown_scientist->addItem("Birth");
        ui->dropdown_scientist->addItem("Death");

        ui->dropdown_computer->addItem("Name");
        ui->dropdown_computer->addItem("Type");
        ui->dropdown_computer->addItem("Year");

        ui->dropdown_connections->addItem("Scientist");
        ui->dropdown_connections->addItem("Computer");
}
void MainWindow::on_table_scientist_clicked(const QModelIndex &index)
{
     ui->button_scientist_remove->setEnabled(true);
}

void MainWindow::on_button_scientist_remove_clicked()
{
    int scientistRemove = ui->table_scientist->currentRow();
    bool sucsess = list.removePerson(scientistRemove);

    if (sucsess)
    {
        showScientists();
    }
    else
    {
        QMessageBox::warning(this, "Warning!", "Unable to remove scientist!😡");
    }
}
void MainWindow::on_input_scientist_textEdited(const QString &arg1)
{
    showScientists();
}

void MainWindow::on_input_computer_textEdited(const QString &arg1)
{
    showComputers();
}

void MainWindow::on_input_connections_textEdited(const QString &arg1)
{
    showConnections();
}

void MainWindow::on_table_computer_clicked(const QModelIndex &index)
{
    ui->button_computer_remove->setEnabled(true);
}

void MainWindow::on_button_computer_remove_clicked()
{
    int computerRemove = ui->table_computer->currentRow();
    bool sucsess = list.removeComputer(computerRemove);

    if (sucsess)
    {
        showComputers();
    }
    else
    {
        QMessageBox::warning(this, "Warning!", "Unable to remove scientist!😡");
    }
}
