#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "listworker.h"

#include <QDebug>
#include <string>
#include <QList>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    showThings();
    showComputers();
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::showThings()
{
    ui->table_scientist->clear();

    ui->table_scientist->setHorizontalHeaderItem(0,new QTableWidgetItem("Name"));
    ui->table_scientist->setHorizontalHeaderItem(1,new QTableWidgetItem("Gender"));
    ui->table_scientist->setHorizontalHeaderItem(2,new QTableWidgetItem("Birth"));
    ui->table_scientist->setHorizontalHeaderItem(3,new QTableWidgetItem("Death"));
    ui->table_scientist->setHorizontalHeaderItem(4,new QTableWidgetItem("Comment"));

    ui->table_scientist->setRowCount(listWorker.personsSize());
    ui->table_scientist->setColumnCount(5);
    for(int i = 0; i < listWorker.personsSize(); i++)
    {
        int birth = listWorker.getScientistBirth(i);
        int death = listWorker.getScientistDeath(i);

        QString qname = QString::fromStdString(listWorker.getScientistName(i));
        QString qgender = QChar(listWorker.getScientistGender(i));
        QString qbirth = QString::number(birth);
        QString qdeath = QString::number(death);
        QString qcomment = QString::fromStdString(listWorker.getScientistComment(i));

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

    ui->table_computer->setRowCount(listWorker.computerSize());
    ui->table_computer->setColumnCount(4);
    for(int i = 0; i < listWorker.computerSize(); i++)
    {
        int date = listWorker.getComputerDate(i);

        QString qname = QString::fromStdString(listWorker.getComputerName(i));
        QString qtype = QString::fromStdString(listWorker.getComputerType(i));
        QString qdate = QString::number(date);
        QString qwasitbuilt = QString::fromStdString(listWorker.getComputerWasItBuilt(i));

        ui->table_computer->setItem(i,0,new QTableWidgetItem(qname));
        ui->table_computer->setItem(i,1,new QTableWidgetItem(qtype));
        ui->table_computer->setItem(i,2,new QTableWidgetItem(qdate));
        ui->table_computer->setItem(i,3,new QTableWidgetItem(qwasitbuilt));
    }
    ui->table_computer->resizeColumnsToContents();
}
/*
void MainWindow::on_button_computers_clicked()
{
    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(listWorker.computerSize());
    ui->tableWidget->setColumnCount(4);
    ui->listWidget->clear();
    for(int i = 0; i < listWorker.computerSize(); i++)
    {
        int date = listWorker.getComputerDate(i);

        QString qname = QString::fromStdString(listWorker.getComputerName(i));
        QString qdate = QString::number(date);
        QString qtype = QString::fromStdString(listWorker.getComputerType(i));
        QString qbuilt = QString::fromStdString(listWorker.getComputerWasItBuilt(i));

        ui->listWidget->addItem(QString::fromStdString(listWorker.getScientistName(i)));

        ui->tableWidget->setItem(i,0,new QTableWidgetItem(qname));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(qdate));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(qtype));
        ui->tableWidget->setItem(i,3,new QTableWidgetItem(qbuilt));
    }
    ui->tableWidget->resizeColumnsToContents();
}

void MainWindow::on_button_scientist_clicked()
{
     showThings();
}
*/

void MainWindow::on_tabWidget_tabBarClicked(int index)
{

}
