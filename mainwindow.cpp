#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "listworker.h"
#include "addscientistdialog.h"
#include "addcomputerdialog.h"
#include "editscientistdialog.h"
#include "editcomputerdialog.h"
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
    showComputersName();
    showConnectionsNameSci();
    showScientistsName();
    populateDropdownMenus();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showScientistsName()
{
    ui->table_scientist->clear();

    ui->table_scientist->setHorizontalHeaderItem(0,new QTableWidgetItem("Name"));
    ui->table_scientist->setHorizontalHeaderItem(1,new QTableWidgetItem("Gender"));
    ui->table_scientist->setHorizontalHeaderItem(2,new QTableWidgetItem("Birth"));
    ui->table_scientist->setHorizontalHeaderItem(3,new QTableWidgetItem("Death"));
    ui->table_scientist->setHorizontalHeaderItem(4,new QTableWidgetItem("Comment"));

    ui->table_scientist->setRowCount(list.personsSize());
    ui->table_scientist->setColumnCount(5);

    int count = 0;

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

            ui->table_scientist->setItem(count,0,new QTableWidgetItem(qname));
            ui->table_scientist->setItem(count,1,new QTableWidgetItem(qgender));
            ui->table_scientist->setItem(count,2,new QTableWidgetItem(qbirth));
            ui->table_scientist->setItem(count,3,new QTableWidgetItem(qdeath));
            ui->table_scientist->setItem(count,4,new QTableWidgetItem(qcomment));
            count++;
        }
    }
   ui->table_scientist->resizeColumnsToContents();

}
void MainWindow::showScientistsGender()
{
    ui->table_scientist->clear();

    ui->table_scientist->setHorizontalHeaderItem(0,new QTableWidgetItem("Name"));
    ui->table_scientist->setHorizontalHeaderItem(1,new QTableWidgetItem("Gender"));
    ui->table_scientist->setHorizontalHeaderItem(2,new QTableWidgetItem("Birth"));
    ui->table_scientist->setHorizontalHeaderItem(3,new QTableWidgetItem("Death"));
    ui->table_scientist->setHorizontalHeaderItem(4,new QTableWidgetItem("Comment"));

    ui->table_scientist->setRowCount(list.personsSize());
    ui->table_scientist->setColumnCount(5);
    int count = 0;
    for(int i = 0; i < list.personsSize(); i++)
    {
        string nameSearch = ui->input_scientist->text().toStdString();
        char genderSearch = nameSearch[0];
        if(genderSearch == 'f')
        {
            genderSearch = 'F';
        }
        else if(genderSearch == 'm')
        {
            genderSearch = 'M';
        }
        if(genderSearch == list.getScientistGender(i))
        {
            int birth = list.getScientistBirth(i);
            int death = list.getScientistDeath(i);

            QString qname = QString::fromStdString(list.getScientistName(i));
            QString qgender = QChar(list.getScientistGender(i));
            QString qbirth = QString::number(birth);
            QString qdeath = QString::number(death);
            QString qcomment = QString::fromStdString(list.getScientistComment(i));

            ui->table_scientist->setItem(count,0,new QTableWidgetItem(qname));
            ui->table_scientist->setItem(count,1,new QTableWidgetItem(qgender));
            ui->table_scientist->setItem(count,2,new QTableWidgetItem(qbirth));
            ui->table_scientist->setItem(count,3,new QTableWidgetItem(qdeath));
            ui->table_scientist->setItem(count,4,new QTableWidgetItem(qcomment));
            count++;
        }
        else if(nameSearch == "")
        {
            int birth = list.getScientistBirth(i);
            int death = list.getScientistDeath(i);

            QString qname = QString::fromStdString(list.getScientistName(i));
            QString qgender = QChar(list.getScientistGender(i));
            QString qbirth = QString::number(birth);
            QString qdeath = QString::number(death);
            QString qcomment = QString::fromStdString(list.getScientistComment(i));

            ui->table_scientist->setItem(count,0,new QTableWidgetItem(qname));
            ui->table_scientist->setItem(count,1,new QTableWidgetItem(qgender));
            ui->table_scientist->setItem(count,2,new QTableWidgetItem(qbirth));
            ui->table_scientist->setItem(count,3,new QTableWidgetItem(qdeath));
            ui->table_scientist->setItem(count,4,new QTableWidgetItem(qcomment));
            count++;
        }
    }
   ui->table_scientist->resizeColumnsToContents();

}
void MainWindow::showScientistsBirthYear()
{
    int yearSearch = -1;
    ui->table_scientist->clear();

    ui->table_scientist->setHorizontalHeaderItem(0,new QTableWidgetItem("Name"));
    ui->table_scientist->setHorizontalHeaderItem(1,new QTableWidgetItem("Gender"));
    ui->table_scientist->setHorizontalHeaderItem(2,new QTableWidgetItem("Birth"));
    ui->table_scientist->setHorizontalHeaderItem(3,new QTableWidgetItem("Death"));
    ui->table_scientist->setHorizontalHeaderItem(4,new QTableWidgetItem("Comment"));

    ui->table_scientist->setRowCount(list.personsSize());
    ui->table_scientist->setColumnCount(5);
    int count = 0;
    for(int i = 0; i < list.personsSize(); i++)
    {
        yearSearch = ui->input_scientist->text().toInt();
        if(yearSearch == list.getScientistBirth(i)) // Brotið, matchar ekki hluta af tölu.
        {
            int birth = list.getScientistBirth(i);
            int death = list.getScientistDeath(i);

            QString qname = QString::fromStdString(list.getScientistName(i));
            QString qgender = QChar(list.getScientistGender(i));
            QString qbirth = QString::number(birth);
            QString qdeath = QString::number(death);
            QString qcomment = QString::fromStdString(list.getScientistComment(i));

            ui->table_scientist->setItem(count,0,new QTableWidgetItem(qname));
            ui->table_scientist->setItem(count,1,new QTableWidgetItem(qgender));
            ui->table_scientist->setItem(count,2,new QTableWidgetItem(qbirth));
            ui->table_scientist->setItem(count,3,new QTableWidgetItem(qdeath));
            ui->table_scientist->setItem(count,4,new QTableWidgetItem(qcomment));
            count++;
        }
        else if(yearSearch == -1)
        {
            int birth = list.getScientistBirth(i);
            int death = list.getScientistDeath(i);

            QString qname = QString::fromStdString(list.getScientistName(i));
            QString qgender = QChar(list.getScientistGender(i));
            QString qbirth = QString::number(birth);
            QString qdeath = QString::number(death);
            QString qcomment = QString::fromStdString(list.getScientistComment(i));

            ui->table_scientist->setItem(count,0,new QTableWidgetItem(qname));
            ui->table_scientist->setItem(count,1,new QTableWidgetItem(qgender));
            ui->table_scientist->setItem(count,2,new QTableWidgetItem(qbirth));
            ui->table_scientist->setItem(count,3,new QTableWidgetItem(qdeath));
            ui->table_scientist->setItem(count,4,new QTableWidgetItem(qcomment));
            count++;
        }
    }
   ui->table_scientist->resizeColumnsToContents();

}
void MainWindow::showScientistsDeathYear()
{
    int yearSearch = -1;
    ui->table_scientist->clear();

    ui->table_scientist->setHorizontalHeaderItem(0,new QTableWidgetItem("Name"));
    ui->table_scientist->setHorizontalHeaderItem(1,new QTableWidgetItem("Gender"));
    ui->table_scientist->setHorizontalHeaderItem(2,new QTableWidgetItem("Birth"));
    ui->table_scientist->setHorizontalHeaderItem(3,new QTableWidgetItem("Death"));
    ui->table_scientist->setHorizontalHeaderItem(4,new QTableWidgetItem("Comment"));

    ui->table_scientist->setRowCount(list.personsSize());
    ui->table_scientist->setColumnCount(5);
    int count = 0;
    for(int i = 0; i < list.personsSize(); i++)
    {
        yearSearch = ui->input_scientist->text().toInt();
        if(yearSearch == list.getScientistDeath(i)) // Brotið, matchar ekki hluta af tölu.
        {
            int birth = list.getScientistBirth(i);
            int death = list.getScientistDeath(i);

            QString qname = QString::fromStdString(list.getScientistName(i));
            QString qgender = QChar(list.getScientistGender(i));
            QString qbirth = QString::number(birth);
            QString qdeath = QString::number(death);
            QString qcomment = QString::fromStdString(list.getScientistComment(i));

            ui->table_scientist->setItem(count,0,new QTableWidgetItem(qname));
            ui->table_scientist->setItem(count,1,new QTableWidgetItem(qgender));
            ui->table_scientist->setItem(count,2,new QTableWidgetItem(qbirth));
            ui->table_scientist->setItem(count,3,new QTableWidgetItem(qdeath));
            ui->table_scientist->setItem(count,4,new QTableWidgetItem(qcomment));
            count++;
        }
        else if(yearSearch == -1)
        {
            int birth = list.getScientistBirth(i);
            int death = list.getScientistDeath(i);

            QString qname = QString::fromStdString(list.getScientistName(i));
            QString qgender = QChar(list.getScientistGender(i));
            QString qbirth = QString::number(birth);
            QString qdeath = QString::number(death);
            QString qcomment = QString::fromStdString(list.getScientistComment(i));

            ui->table_scientist->setItem(count,0,new QTableWidgetItem(qname));
            ui->table_scientist->setItem(count,1,new QTableWidgetItem(qgender));
            ui->table_scientist->setItem(count,2,new QTableWidgetItem(qbirth));
            ui->table_scientist->setItem(count,3,new QTableWidgetItem(qdeath));
            ui->table_scientist->setItem(count,4,new QTableWidgetItem(qcomment));
            count++;
        }
    }
   ui->table_scientist->resizeColumnsToContents();

}
void MainWindow::showComputersName()
{
    ui->table_computer->clear();
    ui->table_computer->setHorizontalHeaderItem(0,new QTableWidgetItem("Name"));
    ui->table_computer->setHorizontalHeaderItem(1,new QTableWidgetItem("Type"));
    ui->table_computer->setHorizontalHeaderItem(2,new QTableWidgetItem("Date"));
    ui->table_computer->setHorizontalHeaderItem(3,new QTableWidgetItem("Was it built"));

    ui->table_computer->setRowCount(list.computerSize());
    ui->table_computer->setColumnCount(4);
    int count = 0;
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

            ui->table_computer->setItem(count,0,new QTableWidgetItem(qname));
            ui->table_computer->setItem(count,1,new QTableWidgetItem(qtype));
            ui->table_computer->setItem(count,2,new QTableWidgetItem(qdate));
            ui->table_computer->setItem(count,3,new QTableWidgetItem(qwasitbuilt));
            count++;

        }
    }
    ui->table_computer->resizeColumnsToContents();
}
void MainWindow::showComputersType()
{
    ui->table_computer->clear();
    ui->table_computer->setHorizontalHeaderItem(0,new QTableWidgetItem("Name"));
    ui->table_computer->setHorizontalHeaderItem(1,new QTableWidgetItem("Type"));
    ui->table_computer->setHorizontalHeaderItem(2,new QTableWidgetItem("Date"));
    ui->table_computer->setHorizontalHeaderItem(3,new QTableWidgetItem("Was it built"));

    ui->table_computer->setRowCount(list.computerSize());
    ui->table_computer->setColumnCount(4);
    int count = 0;
    for(int i = 0; i < list.computerSize(); i++)
    {
        string nameSearch = ui->input_computer->text().toStdString();
        transform(nameSearch.begin(), nameSearch.end(), nameSearch.begin(), ::tolower);
        size_t found = list.getComputerLowerCaseType(i).find(nameSearch);
        if(found!=std::string::npos)
        {
            int date = list.getComputerDate(i);

            QString qname = QString::fromStdString(list.getComputerName(i));
            QString qtype = QString::fromStdString(list.getComputerType(i));
            QString qdate = QString::number(date);
            QString qwasitbuilt = QString::fromStdString(list.getComputerWasItBuilt(i));

            ui->table_computer->setItem(count,0,new QTableWidgetItem(qname));
            ui->table_computer->setItem(count,1,new QTableWidgetItem(qtype));
            ui->table_computer->setItem(count,2,new QTableWidgetItem(qdate));
            ui->table_computer->setItem(count,3,new QTableWidgetItem(qwasitbuilt));
            count++;
        }
    }
    ui->table_computer->resizeColumnsToContents();
}
void MainWindow::showComputersYear()
{
    int yearSearch = -1;
    ui->table_computer->clear();

    ui->table_computer->clear();
    ui->table_computer->setHorizontalHeaderItem(0,new QTableWidgetItem("Name"));
    ui->table_computer->setHorizontalHeaderItem(1,new QTableWidgetItem("Type"));
    ui->table_computer->setHorizontalHeaderItem(2,new QTableWidgetItem("Date"));
    ui->table_computer->setHorizontalHeaderItem(3,new QTableWidgetItem("Was it built"));

    ui->table_computer->setRowCount(list.computerSize());
    ui->table_computer->setColumnCount(4);
    int count = 0;
    for(int i = 0; i < list.computerSize(); i++)
    {
        yearSearch = ui->input_computer->text().toInt();
        if(yearSearch == list.getComputerDate(i)) // Brotið, matchar ekki hluta af tölu.
        {
            int date = list.getComputerDate(i);

            QString qname = QString::fromStdString(list.getComputerName(i));
            QString qtype = QString::fromStdString(list.getComputerType(i));
            QString qdate = QString::number(date);
            QString qwasitbuilt = QString::fromStdString(list.getComputerWasItBuilt(i));

            ui->table_computer->setItem(count,0,new QTableWidgetItem(qname));
            ui->table_computer->setItem(count,1,new QTableWidgetItem(qtype));
            ui->table_computer->setItem(count,2,new QTableWidgetItem(qdate));
            ui->table_computer->setItem(count,3,new QTableWidgetItem(qwasitbuilt));
            count++;
        }
        else if(yearSearch == -1)
        {
            int date = list.getComputerDate(i);

            QString qname = QString::fromStdString(list.getComputerName(i));
            QString qtype = QString::fromStdString(list.getComputerType(i));
            QString qdate = QString::number(date);
            QString qwasitbuilt = QString::fromStdString(list.getComputerWasItBuilt(i));

            ui->table_computer->setItem(count,0,new QTableWidgetItem(qname));
            ui->table_computer->setItem(count,1,new QTableWidgetItem(qtype));
            ui->table_computer->setItem(count,2,new QTableWidgetItem(qdate));
            ui->table_computer->setItem(count,3,new QTableWidgetItem(qwasitbuilt));
            count++;
        }
    }
   ui->table_computer->resizeColumnsToContents();

}
void MainWindow::showConnectionsNameSci()
{
    list.eraser(); // skítmix
    ui->table_connections->clearContents();
    list.sortConnections("1"); //þegar sort verður lagfært þá verður þetta kannski fært.

    ui->table_connections->clear();

    ui->table_connections->setHorizontalHeaderItem(0,new QTableWidgetItem("Scientist Name"));
    ui->table_connections->setHorizontalHeaderItem(1,new QTableWidgetItem("Computer Name"));

    ui->table_connections->setRowCount(list.getLinkOutputSize());
    ui->table_connections->setColumnCount(2);
    int count = 0;
    for(int i = 0; i < list.getLinkOutputSize(); i++)
    {
        string nameSearch = ui->input_connections->text().toStdString();
        transform(nameSearch.begin(), nameSearch.end(), nameSearch.begin(), ::tolower);
        size_t found = list.getLinkOutputSciNameLower(i).find(nameSearch);
        if(found!=std::string::npos)
        {
            QString qsciname = QString::fromStdString(list.getLinkOutputSciName(i));
            QString qcompname = QString::fromStdString(list.getLinkOutputCompName(i));

            ui->table_connections->setItem(count,0,new QTableWidgetItem(qsciname));
            ui->table_connections->setItem(count,1,new QTableWidgetItem(qcompname));
            count++;
       }
    }
    ui->table_connections->resizeColumnsToContents();
}
void MainWindow::showConnectionsNameComp()
{
    list.eraser(); // skítmix
    ui->table_connections->clearContents();
    list.sortConnections("1"); //þegar sort verður lagfært þá verður þetta kannski fært.

    ui->table_connections->clear();

    ui->table_connections->setHorizontalHeaderItem(0,new QTableWidgetItem("Scientist Name"));
    ui->table_connections->setHorizontalHeaderItem(1,new QTableWidgetItem("Computer Name"));

    ui->table_connections->setRowCount(list.getLinkOutputSize());
    ui->table_connections->setColumnCount(2);
    int count = 0;
    for(int i = 0; i < list.getLinkOutputSize(); i++)
    {
        string nameSearch = ui->input_connections->text().toStdString();
        transform(nameSearch.begin(), nameSearch.end(), nameSearch.begin(), ::tolower);
        size_t found = list.getLinkOutputCompNameLower(i).find(nameSearch);
        if(found!=std::string::npos)
        {

            QString qsciname = QString::fromStdString(list.getLinkOutputSciName(i));
            QString qcompname = QString::fromStdString(list.getLinkOutputCompName(i));

            ui->table_connections->setItem(count,0,new QTableWidgetItem(qsciname));
            ui->table_connections->setItem(count,1,new QTableWidgetItem(qcompname));
            count++;
       }
    }
    ui->table_connections->resizeColumnsToContents();
}
void MainWindow::on_dropdown_scientist_activated(const QString &arg1)
{
        //QMessageBox::information(this, "Item Selection",
        //ui->dropdown_scientist->currentText());
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

void MainWindow::on_button_scientist_add_clicked()
{
    addScientistDialog addScientist;

    int add = addScientist.exec();
    if (add == 0)
    {
        list.refreshVector();
        showScientistsName();
        statusBar()->showMessage("Scientist added!",2000);
    }
    else
    {
        QMessageBox::warning(this, "error", "asdfasdfadsf");
    }
}
void MainWindow::on_table_scientist_clicked(const QModelIndex &index)
{
     ui->button_scientist_remove->setEnabled(true);
     ui->button_scientist_edit->setEnabled(true);
}

void MainWindow::on_button_scientist_remove_clicked()
{
    int scientistRemove = ui->table_scientist->currentRow();
    bool sucsess = list.removePerson(scientistRemove);

    if (sucsess)
    {
        showScientistsName();
        ui->button_scientist_remove->setEnabled(false);
        statusBar()->showMessage("Scientist removed!",2000);
    }
    else
    {
        QMessageBox::warning(this, "Warning!", "Unable to remove scientist!😡");
    }
    disableButtons();
}
void MainWindow::on_input_scientist_textEdited(const QString &arg1)
{
    int i = ui->dropdown_scientist->currentIndex();

    if(i == 0)  // NAME
    {
        showScientistsName();
    }
    else if (i == 1) // Gender
    {
        showScientistsGender();
    }
    else if (i == 2) // Birth
    {
        showScientistsBirthYear();
    }
    else if (i == 3) // Death
    {
        showScientistsDeathYear();
    }
}
void MainWindow::on_input_computer_textEdited(const QString &arg1)
{
    int i = ui->dropdown_computer->currentIndex();

    if(i == 0)  // NAME
    {
        showComputersName();
    }
    else if (i == 1) // Type
    {
        showComputersType();
    }
    else if (i == 2) // Year
    {
        showComputersYear();
    }
}

void MainWindow::on_input_connections_textEdited(const QString &arg1)
{
    int i = ui->dropdown_connections->currentIndex();

    if(i == 0)  // Scientist
    {
        showConnectionsNameSci();
    }
    else if (i == 1) // Computer
    {
        showConnectionsNameComp();
    }
}

void MainWindow::on_table_computer_clicked(const QModelIndex &index)
{
    ui->button_computer_remove->setEnabled(true);
    ui->button_computer_edit->setEnabled(true);
}

void MainWindow::on_button_computer_remove_clicked()
{
    int computerRemove = ui->table_computer->currentRow();
    bool success = list.removeComputer(computerRemove);

    if (success)
    {
        showComputersName();
        ui->button_computer_remove->setEnabled(false);
        statusBar()->showMessage("Computer removed!",2000);
    }
    else
    {
        QMessageBox::warning(this, "Warning!", "Unable to remove computer!😡");
    }
    disableButtons();
}
void MainWindow::on_button_connections_edit_clicked()
{

}


void MainWindow::on_button_scientist_edit_clicked()
{
    int row = ui->table_scientist->currentRow();
    Person esci;

    string name = list.getScientistName(row);
    char gender = list.getScientistGender(row);
    int birth = list.getScientistBirth(row);
    int death = list.getScientistDeath(row);
    string comment = list.getScientistComment(row);
    int id = list.getScientistId(row);

    esci = Person(name,gender,birth,death,comment,id);

    EditScientistDialog editSci;
    editSci.prepare(esci);
        editSci.exec();
        list.refreshVector();
        showScientistsName();
    disableButtons();
}
void MainWindow::on_button_computer_add_clicked()
{
    addComputerDialog addComputer;
    int add = addComputer.exec();
    if (add == 0)
    {
        list.refreshVector();
        showComputersName();
        statusBar()->showMessage("Computer added!",2000);
    }
    else
    {
        QMessageBox::warning(this, "error", "asdfasdfadsf");
    }
}

void MainWindow::on_button_computer_edit_clicked()
{
        int row = ui->table_computer->currentRow();
        Computer ecom;

        string name = list.getComputerName(row);
        string type = list.getComputerType(row);
        int date = list.getComputerDate(row);
        string wasItBuilt = list.getComputerWasItBuilt(row);
        int id = list.getComputerId(row);

        ecom = Computer(name, wasItBuilt, date, type, id);

        EditComputerDialog editCom;
        editCom.prepare(ecom);
            editCom.exec();
            list.refreshVector();
            showComputersName();
    disableButtons();
}
void MainWindow::disableButtons()
{
    ui->button_scientist_remove->setEnabled(false);
    ui->button_scientist_edit->setEnabled(false);
    ui->button_computer_remove->setEnabled(false);
    ui->button_computer_edit->setEnabled(false);
}

void MainWindow::on_table_connections_clicked(const QModelIndex &index)
{
    ui->button_connections_remove->setEnabled(true);
}

void MainWindow::on_button_connections_remove_clicked()
{
    int connectionremove = ui->table_connections->currentRow();
    int sciID = list.getLinkSciId(connectionremove);
    int compID = list.getLinkCompId(connectionremove);
    bool success = list.removeConnection(sciID,compID);
    if (success)
    {
        showConnectionsNameComp();
        showConnectionsNameSci();
        ui->button_connections_remove->setEnabled(false);
        statusBar()->showMessage("Connection removed!",2000);
    }
    else
    {
        QMessageBox::warning(this, "Warning!", "Unable to remove connection!😡");
    }
    disableButtons();
}
void MainWindow::on_action_add_scientist_triggered()
{
    on_button_scientist_add_clicked();
}

void MainWindow::on_action_add_computer_triggered()
{
    on_button_computer_add_clicked();
}

void MainWindow::on_action_edit_scientist_triggered()
{
    on_button_scientist_edit_clicked();
}

void MainWindow::on_action_edit_computer_triggered()
{
    on_button_computer_edit_clicked();

}
