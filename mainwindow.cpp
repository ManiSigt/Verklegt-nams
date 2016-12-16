#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "listworker.h"
#include "addscientistdialog.h"
#include "addcomputerdialog.h"
#include "addconnectiondialog.h"
#include "editscientistdialog.h"
#include "editcomputerdialog.h"
#include "editconnectionsdialog.h"
#include "themedialog.h"
#include "infoscientistdialog.h"
#include "infocomputerdialog.h"
#include <QMessageBox>
#include <algorithm>
#include <QDebug>
#include <string>
#include <QList>
#include <QPushButton>
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
    defaultTheme();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showScientistsName()
{
    ui->table_scientist->clear();

    ui->table_scientist->horizontalHeader()->setStyleSheet("QHeaderView { font-size: 12pt; }");
    ui->table_scientist->resizeColumnsToContents();

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
    ui->table_scientist->setRowCount(count);

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
    ui->table_scientist->setRowCount(count);
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
    ui->table_scientist->setRowCount(count);
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
    ui->table_scientist->setRowCount(count);

}
void MainWindow::showComputersName()
{
    ui->table_computer->clear();
    ui->table_computer->clearContents();
    ui->table_computer->horizontalHeader()->setStyleSheet("QHeaderView { font-size: 12pt; }");
    ui->table_computer->resizeColumnsToContents();
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
    ui->table_computer->setRowCount(count);
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
    ui->table_computer->setRowCount(count);
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
    ui->table_computer->setRowCount(count);

}
void MainWindow::showConnectionsNameSci()
{
    ui->table_connections->clearContents();
    list.sortConnections("1"); //þegar sort verður lagfært þá verður þetta kannski fært.

    ui->table_connections->clear();
    ui->table_connections->horizontalHeader()->setStyleSheet("QHeaderView { font-size: 12pt; }");
    ui->table_connections->resizeColumnsToContents();
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
    ui->table_connections->setRowCount(count);
    ui->table_connections->resizeColumnsToContents();
}
void MainWindow::showConnectionsNameComp()
{
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
    ui->table_connections->setRowCount(count);
    ui->table_connections->resizeColumnsToContents();
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
    if (add == 1)
    {
        //list.eraser();
        list.refreshVector();
        showScientistsName();
        statusBar()->showMessage("Scientist added!",2000);
    }
    else
    {
        statusBar()->showMessage("Canceled!",2000);
    }
}
void MainWindow::on_table_scientist_clicked()
{
     ui->button_scientist_remove->setEnabled(true);
     ui->button_scientist_edit->setEnabled(true);
     ui->action_edit_scientist->setEnabled(true);
}

void MainWindow::on_button_scientist_remove_clicked()
{
    int getRow = ui->table_scientist->currentRow();
    QTableWidgetItem *cellName = ui->table_scientist->item(getRow, 0);
    QString qsciName = cellName->text();
    string sciName = qsciName.toStdString();
    qDebug() << qsciName;
    int scientistRemove = list.getScientistIdFromName(sciName);
    qDebug() << scientistRemove;
    bool success = list.removePerson(scientistRemove);

    QMessageBox::StandardButton textBox;
    textBox = QMessageBox::question(this, "Remove", "Are you sure you want to remove scientist?",
                              QMessageBox::Yes|QMessageBox::No);
    if (textBox == QMessageBox::Yes)
    {
        if (success)
        {
            list.eraser();
            list.refreshVector();
            showScientistsName();
            ui->button_scientist_remove->setEnabled(false);
            statusBar()->showMessage("Scientist removed!",2000);
        }
    }
    else
    {
        QMessageBox::warning(this, "Abort", "Scientist not removed.");
    }

  disableButtons();
}
void MainWindow::on_input_scientist_textEdited()
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
void MainWindow::on_input_computer_textEdited()
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

void MainWindow::on_input_connections_textEdited()
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

void MainWindow::on_table_computer_clicked()
{
    ui->button_computer_remove->setEnabled(true);
    ui->button_computer_edit->setEnabled(true);
    ui->action_edit_computer->setEnabled(true);
}

void MainWindow::on_button_computer_remove_clicked()
{
    int getRow = ui->table_computer->currentRow();
    QTableWidgetItem *cellName = ui->table_computer->item(getRow, 0);
    QString qcompName = cellName->text();
    string compName = qcompName.toStdString();
    int computerRemove = list.getComputerIdFromName(compName);
    bool success = list.removeComputer(computerRemove);

    QMessageBox::StandardButton textBox;
    textBox = QMessageBox::question(this, "Remove", "Are you sure you want to remove computer?",
    QMessageBox::Yes|QMessageBox::No);
    if (textBox == QMessageBox::Yes)
    {
        if (success)
        {
            list.eraser();
            list.refreshVector();
            showComputersName();
            ui->button_computer_remove->setEnabled(false);
            statusBar()->showMessage("Computer removed!",2000);
        }
    }
    else
    {
        QMessageBox::warning(this, "Abort", "Computer not removed.");
    }

    disableButtons();
}
void MainWindow::on_button_connections_edit_clicked()
{
        int row = ui->table_connections->currentRow();
        string comName = list.getLinkOutputCompName(row);
        string sciName = list.getLinkOutputSciName(row);

        int sciId = list.getScientistIdFromName(sciName);
        int comId = list.getComputerIdFromName(comName);
        int id = list.getLinkIdFromSciComIds(sciId,comId);

        Linker elink = Linker(id,sciId,comId);
        EditConnectionsDialog editCon;
        editCon.prepare(elink);

        bool add = editCon.exec();

        if (add == 1)
        {
            list.eraser();
            list.refreshVector();
            showConnectionsNameComp();
            disableButtons();
            statusBar()->showMessage("Connection edited!",2000);
        }
        else
        {
            statusBar()->showMessage("Canceled!",2000);
        }

        editCon.exec();
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

    bool add = editSci.exec();

    if (add == 1)
    {
        list.eraser();
        list.refreshVector();
        showScientistsName();
        disableButtons();
        statusBar()->showMessage("Scientist edited!",2000);
    }
    else
    {
        statusBar()->showMessage("Canceled!",2000);
    }
}
void MainWindow::on_button_computer_add_clicked()
{
    addComputerDialog addComputer;
    int add = addComputer.exec();
    if (add == 1)
    {

        statusBar()->showMessage("Computer added!",2000);
    }
    else
    {
        statusBar()->showMessage("Canceled!",2000);
    }
    list.eraser();
    list.refreshVector();
    showComputersName();
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

        bool add = editCom.exec();

        if (add == 1)
        {
            list.eraser();
            list.refreshVector();
            showComputersName();
            disableButtons();
            statusBar()->showMessage("Computer edited!",2000);
        }
        else
        {
            statusBar()->showMessage("Canceled!",2000);
        }

}
void MainWindow::disableButtons()
{
    ui->button_scientist_remove->setEnabled(false);
    ui->button_scientist_edit->setEnabled(false);
    ui->button_computer_remove->setEnabled(false);
    ui->button_computer_edit->setEnabled(false);
    ui->button_connections_remove->setEnabled(false);
    ui->button_connections_edit->setEnabled(false);
}

void MainWindow::on_table_connections_clicked()
{
    ui->button_connections_remove->setEnabled(true);
    ui->button_connections_edit->setEnabled(true);
}

void MainWindow::on_button_connections_remove_clicked()
{
    int row = ui->table_connections->currentRow();
    string comName = list.getLinkOutputCompName(row);
    string sciName = list.getLinkOutputSciName(row);

    int sciId = list.getScientistIdFromName(sciName);
    int comId = list.getComputerIdFromName(comName);
    int id = 0;

    for(unsigned int i = 0; i < 16;i++)
    {
        if(sciId == list.getLinkSciId(i))
        {
            if(comId == list.getLinkCompId(i))
            {
                id = list.getLinkId(i);
            }
        }
    }
    bool success = list.removeConnectionById(id);
    QMessageBox::StandardButton textBox;
    textBox = QMessageBox::question(this, "Remove", "Are you sure you want to remove connection?",
                                QMessageBox::Yes|QMessageBox::No);
    if (success)
    {
        list.eraser();
        list.refreshVector();
        showConnectionsNameComp();
        ui->button_connections_remove->setEnabled(false);
        statusBar()->showMessage("Connection removed!",2000);
    }
    else
    {
        QMessageBox::warning(this, "Abort", "Connection not removed.");
    }
    disableButtons();
}


void MainWindow::on_tabWidget_tabBarClicked()
{
    ui->table_computer->clearSelection();
    ui->table_connections->clearSelection();
    ui->table_scientist->clearSelection();
}
void MainWindow::on_actionRed_triggered()
{
        setStyleSheet("background-color: cyan;");
}

void MainWindow::on_actionPink_triggered()
{
        setStyleSheet("background-color: pink;");
}

void MainWindow::on_actionWhite_triggered()
{
        setStyleSheet("background-color: crimson;");
}

void MainWindow::on_actionOrange_triggered()
{
        setStyleSheet("background-color: orange;");
}
void MainWindow::on_button_connections_add_clicked()
{
    AddConnectionDialog addCon;

    int add = addCon.exec();
    if (add == 1)
    {
        list.eraser();
        list.refreshVector();
        showConnectionsNameComp();
        disableButtons();
        statusBar()->showMessage("Connection added!",2000);
    }
    else
    {
        statusBar()->showMessage("Canceled!",2000);
    }
}

void MainWindow::on_actionNormal_triggered()
{
    setStyleSheet("background-color: normal;");
}


void MainWindow::skullTheme()
{
    setWindowIcon(QIcon(":/icons/icons/skull-512.ico"));
    ui->button_computer_add->setIcon(QIcon(":/icons/icons/ninjaskull"));
    ui->button_computer_add->setIconSize(QSize(30,30));
    ui->button_computer_theme->setIcon(QIcon(":/icons/icons/skull"));
    ui->button_computer_theme->setIconSize(QSize(30,30));
    ui->button_computer_edit->setIcon(QIcon(":/icons/icons/pirateSkull"));
    ui->button_computer_edit->setIconSize(QSize(30,30));
    ui->button_computer_remove->setIcon(QIcon(":/icons/icons/death"));
    ui->button_computer_remove->setIconSize(QSize(30,30));
    ui->button_computer_info->setIcon(QIcon(":/icons/icons/skull"));
    ui->button_computer_info->setIconSize(QSize(30,30));

    ui->button_scientist_add->setIcon(QIcon(":/icons/icons/ninjaskull"));
    ui->button_scientist_add->setIconSize(QSize(30,30));
    ui->button_scientist_theme->setIcon(QIcon(":/icons/icons/skull"));
    ui->button_scientist_theme->setIconSize(QSize(30,30));
    ui->button_scientist_edit->setIcon(QIcon(":/icons/icons/pirateSkull"));
    ui->button_scientist_edit->setIconSize(QSize(30,30));
    ui->button_scientist_remove->setIcon(QIcon(":/icons/icons/death"));
    ui->button_scientist_remove->setIconSize(QSize(30,30));
    ui->button_computer_info->setIcon(QIcon(":/icons/icons/skull"));
    ui->button_computer_info->setIconSize(QSize(30,30));

    ui->button_connections_add->setIcon(QIcon(":/icons/icons/ninjaskull"));
    ui->button_connections_add->setIconSize(QSize(30,30));
    ui->button_connections_theme->setIcon(QIcon(":/icons/icons/skull"));
    ui->button_connections_theme->setIconSize(QSize(30,30));
    ui->button_connections_edit->setIcon(QIcon(":/icons/icons/pirateSkull"));
    ui->button_connections_edit->setIconSize(QSize(30,30));
    ui->button_connections_remove->setIcon(QIcon(":/icons/icons/death"));
    ui->button_connections_remove->setIconSize(QSize(30,30));
    ui->button_computer_info->setIcon(QIcon(":/icons/icons/skull"));
    ui->button_computer_info->setIconSize(QSize(30,30));
    setStyleSheet("background-color:grey");
}
void MainWindow::sexyTheme()
{
    setWindowIcon(QIcon(":/icons/icons/Sexymainicon.png"));
    ui->button_computer_add->setIcon(QIcon(":/icons/icons/addsexy"));
    ui->button_computer_add->setIconSize(QSize(30,30));
    ui->button_scientist_add->setIcon(QIcon(":/icons/icons/addsexy"));
    ui->button_scientist_add->setIconSize(QSize(30,30));
    ui->button_connections_add->setIcon(QIcon(":/icons/icons/addsexy"));
    ui->button_connections_add->setIconSize(QSize(30,30));
    ui->button_computer_info->setIcon(QIcon(":/icons/icons/cancelsexy"));
    ui->button_computer_info->setIconSize(QSize(30,30));

    ui->button_computer_edit->setIcon(QIcon(":/icons/icons/editsexy"));
    ui->button_computer_edit->setIconSize(QSize(30,30));
    ui->button_scientist_edit->setIcon(QIcon(":/icons/icons/editsexy"));
    ui->button_scientist_edit->setIconSize(QSize(30,30));
    ui->button_connections_edit->setIcon(QIcon(":/icons/icons/editsexy"));
    ui->button_connections_edit->setIconSize(QSize(30,30));
    ui->button_computer_info->setIcon(QIcon(":/icons/icons/cancelsexy"));
    ui->button_computer_info->setIconSize(QSize(30,30));

    ui->button_computer_remove->setIcon(QIcon(":/icons/icons/deletesexy2"));
    ui->button_computer_remove->setIconSize(QSize(30,30));
    ui->button_scientist_remove->setIcon(QIcon(":/icons/icons/deletesexy2"));
    ui->button_scientist_remove->setIconSize(QSize(30,30));
    ui->button_connections_remove->setIcon(QIcon(":/icons/icons/deletesexy2"));
    ui->button_connections_remove->setIconSize(QSize(30,30));
    ui->button_computer_info->setIcon(QIcon(":/icons/icons/cancelsexy"));
    ui->button_computer_info->setIconSize(QSize(30,30));

    ui->button_computer_theme->setIcon(QIcon(":/icons/icons/themesexy"));
    ui->button_computer_theme->setIconSize(QSize(30,30));
    ui->button_scientist_theme->setIcon(QIcon(":/icons/icons/themesexy"));
    ui->button_scientist_theme->setIconSize(QSize(30,30));
    ui->button_connections_theme->setIcon(QIcon(":/icons/icons/themesexy"));
    ui->button_connections_theme->setIconSize(QSize(30,30));
    ui->button_computer_info->setIcon(QIcon(":/icons/icons/cancelsexy"));
    ui->button_computer_info->setIconSize(QSize(30,30));
    setStyleSheet("background-color:pink");
}
void MainWindow::christmasTheme()
{
    setWindowIcon(QIcon(":/icons/icons/christmas2"));
    ui->button_computer_add->setIcon(QIcon(":/icons/icons/christmas6"));
    ui->button_computer_add->setIconSize(QSize(30,30));
    ui->button_computer_theme->setIcon(QIcon(":/icons/icons/christmas"));
    ui->button_computer_theme->setIconSize(QSize(30,30));
    ui->button_computer_edit->setIcon(QIcon(":/icons/icons/christmas3"));
    ui->button_computer_edit->setIconSize(QSize(30,30));
    ui->button_computer_remove->setIcon(QIcon(":/icons/icons/christmas4"));
    ui->button_computer_remove->setIconSize(QSize(30,30));
    ui->button_computer_info->setIcon(QIcon(":/icons/icons/christmas5"));
    ui->button_computer_info->setIconSize(QSize(30,30));

    ui->button_scientist_add->setIcon(QIcon(":/icons/icons/christmas6"));
    ui->button_scientist_add->setIconSize(QSize(30,30));
    ui->button_scientist_theme->setIcon(QIcon(":/icons/icons/christmas"));
    ui->button_scientist_theme->setIconSize(QSize(30,30));
    ui->button_scientist_edit->setIcon(QIcon(":/icons/icons/christmas3"));
    ui->button_scientist_edit->setIconSize(QSize(30,30));
    ui->button_scientist_remove->setIcon(QIcon(":/icons/icons/christmas4"));
    ui->button_scientist_remove->setIconSize(QSize(30,30));
    ui->button_computer_info->setIcon(QIcon(":/icons/icons/christmas5"));
    ui->button_computer_info->setIconSize(QSize(30,30));

    ui->button_connections_add->setIcon(QIcon(":/icons/icons/christmas6"));
    ui->button_connections_add->setIconSize(QSize(30,30));
    ui->button_connections_theme->setIcon(QIcon(":/icons/icons/christmas"));
    ui->button_connections_theme->setIconSize(QSize(30,30));
    ui->button_connections_edit->setIcon(QIcon(":/icons/icons/christmas3"));
    ui->button_connections_edit->setIconSize(QSize(30,30));
    ui->button_connections_remove->setIcon(QIcon(":/icons/icons/christmas4"));
    ui->button_connections_remove->setIconSize(QSize(30,30));
    ui->button_computer_info->setIcon(QIcon(":/icons/icons/christmas5"));
    ui->button_computer_info->setIconSize(QSize(30,30));
    setStyleSheet("background-color:crimson");
    EditComputerDialog editcomp;

}
void MainWindow::defaultTheme()
{
    setWindowIcon(QIcon(":/icons/icons/mainmynd"));
    ui->button_computer_add->setIcon(QIcon(":/icons/icons/add2"));
    ui->button_computer_add->setIconSize(QSize(30,30));
    ui->button_computer_theme->setIcon(QIcon(":/icons/icons/theme"));
    ui->button_computer_theme->setIconSize(QSize(30,30));
    ui->button_computer_edit->setIcon(QIcon(":/icons/icons/edit2"));
    ui->button_computer_edit->setIconSize(QSize(30,30));
    ui->button_computer_remove->setIcon(QIcon(":/icons/icons/remove"));
    ui->button_computer_remove->setIconSize(QSize(30,30));
    ui->button_computer_info->setIcon(QIcon(":/icons/icons/info"));
    ui->button_computer_info->setIconSize(QSize(30,30));

    ui->button_scientist_add->setIcon(QIcon(":/icons/icons/add2"));
    ui->button_scientist_add->setIconSize(QSize(30,30));
    ui->button_scientist_theme->setIcon(QIcon(":/icons/icons/theme"));
    ui->button_scientist_theme->setIconSize(QSize(30,30));
    ui->button_scientist_edit->setIcon(QIcon(":/icons/icons/edit2"));
    ui->button_scientist_edit->setIconSize(QSize(30,30));
    ui->button_scientist_remove->setIcon(QIcon(":/icons/icons/remove"));
    ui->button_scientist_remove->setIconSize(QSize(30,30));
    ui->button_computer_info->setIcon(QIcon(":/icons/icons/info"));
    ui->button_computer_info->setIconSize(QSize(30,30));

    ui->button_connections_add->setIcon(QIcon(":/icons/icons/add2"));
    ui->button_connections_add->setIconSize(QSize(30,30));
    ui->button_connections_theme->setIcon(QIcon(":/icons/icons/theme"));
    ui->button_connections_theme->setIconSize(QSize(30,30));
    ui->button_connections_edit->setIcon(QIcon(":/icons/icons/edit2"));
    ui->button_connections_edit->setIconSize(QSize(30,30));
    ui->button_connections_remove->setIcon(QIcon(":/icons/icons/remove"));
    ui->button_connections_remove->setIconSize(QSize(30,30));
    ui->button_computer_info->setIcon(QIcon(":/icons/icons/info"));
    ui->button_computer_info->setIconSize(QSize(30,30));
    setStyleSheet("background-color:normal");
}
void MainWindow::on_button_scientist_theme_clicked()
{
    ThemeDialog theme;
    int themes = theme.exec();
    if(themes == 1)
    {
        skullTheme();
    }
    else if(themes == 2)
    {
        sexyTheme();
    }
    else if(themes == 3)
    {
        christmasTheme();
    }
    else if (themes == 4)
    {
        defaultTheme();
    }
}
void MainWindow::on_button_computer_theme_clicked()
{
    ThemeDialog theme;
    int themes = theme.exec();
    if(themes == 1)
    {
        skullTheme();
    }
    else if(themes == 2)
    {
        sexyTheme();
    }
    else if(themes == 3)
    {
        christmasTheme();
    }
    else if(themes == 4)
    {
        defaultTheme();
    }
}
void MainWindow::on_button_connections_theme_clicked()
{
    ThemeDialog theme;
    int themes = theme.exec();
    if(themes == 1)
    {
        skullTheme();
    }
    else if(themes == 2)
    {
        sexyTheme();
    }
    else if(themes == 3)
    {
        christmasTheme();
    }
    else if (themes == 4)
    {
        defaultTheme();
    }
}


void MainWindow::on_button_scientist_info_clicked()
{
    infoScientistDialog infoSci;
    infoSci.exec();
}

void MainWindow::on_button_computer_info_clicked()
{
    infoComputerDialog infoCom;
    infoCom.exec();
}
