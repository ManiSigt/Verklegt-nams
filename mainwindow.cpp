#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "listworker.h"
#include <QMessageBox>

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
   // showConnections();
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
    ui->table_scientist->resizeColumnsToContents();

}
void MainWindow::showComputers()
{
    ui->table_computer->clear();

    ui->table_computer->setHorizontalHeaderItem(0,new QTableWidgetItem("Name"));
    ui->table_computer->setHorizontalHeaderItem(1,new QTableWidgetItem("Type"));
    ui->table_computer->setHorizontalHeaderItem(2,new QTableWidgetItem("Date"));
    ui->table_computer->setHorizontalHeaderItem(3,new QTableWidgetItem("Wasitbuilt"));

    ui->table_computer->setRowCount(list.computerSize());
    ui->table_computer->setColumnCount(4);
    for(int i = 0; i < list.computerSize(); i++)
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
    }
    ui->table_computer->resizeColumnsToContents();
}
void MainWindow::showConnections()
{
    ui->table_connections->clear();

    ui->table_connections->setHorizontalHeaderItem(0,new QTableWidgetItem("SciName"));
    ui->table_connections->setHorizontalHeaderItem(1,new QTableWidgetItem("CompName"));
    ui->table_connections->setRowCount(list.computerSize());
    ui->table_connections->setColumnCount(2);

    for(int i = 0; i < list.getLinkSize(); i++)
    {
        QString qsciname = QString::fromStdString(list.getLinkOutputSciName(i));
        QString qcompname = QString::fromStdString(list.getLinkOutputCompName(i));

        ui->table_connections->setItem(i,0,new QTableWidgetItem(qsciname));
        ui->table_connections->setItem(i,1,new QTableWidgetItem(qcompname));
    }
    ui->table_connections->resizeColumnsToContents();
}
/*
void MainWindow::on_button_computers_clicked()
{
    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(list.computerSize());
    ui->tableWidget->setColumnCount(4);
    ui->listWidget->clear();
    for(int i = 0; i < list.computerSize(); i++)
    {
        int date = listWorker.getComputerDate(i);

        QString qname = QString::fromStdString(list.getComputerName(i));
        QString qdate = QString::number(date);
        QString qtype = QString::fromStdString(list.getComputerType(i));
        QString qbuilt = QString::fromStdString(list.getComputerWasItBuilt(i));

        ui->listWidget->addItem(QString::fromStdString(list.getScientistName(i)));

        ui->tableWidget->setItem(i,0,new QTableWidgetItem(qname));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(qdate));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(qtype));
        ui->tableWidget->setItem(i,3,new QTableWidgetItem(qbuilt));
    }
    ui->tableWidget->resizeColumnsToContents();
}
*/

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
