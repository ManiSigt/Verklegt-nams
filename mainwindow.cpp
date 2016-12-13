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

    ui->table_scientist->setRowCount(listWorker.personsSize());
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
