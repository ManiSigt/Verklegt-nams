#include "datalayer.h"
#include "person.h"
#include "computer.h"
#include "linkeroutput.h"
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

DataLayer::DataLayer()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbName = "amazingDatabase.sqlite";
    db.setDatabaseName(dbName);
}
bool sortByScientistName(const Person &lhs, const Person &rhs)
{
    return lhs.getScientistLowerCaseName() < rhs.getScientistLowerCaseName();
}
bool sortByScientistNameReverse(const Person &lhs, const Person &rhs)
{
    return lhs.getScientistLowerCaseName() > rhs.getScientistLowerCaseName();
}
bool sortByScientistBirth(const Person &lhs, const Person &rhs)
{
    return lhs.getScientistBirth() < rhs.getScientistBirth();
}
bool sortByScientistBirthReverse(const Person &lhs, const Person &rhs)
{
    return lhs.getScientistBirth() > rhs.getScientistBirth();
}
bool sortByScientistGender(const Person &lhs, const Person &rhs)
{
    return lhs.getScientistGender() < rhs.getScientistGender();
}
bool sortByScientistAge(const Person &lhs, const Person &rhs)
{
    return lhs.getScientistAge() < rhs.getScientistAge();
}
bool sortByNameComputers(const Computer &lhs, const Computer &rhs)
{
    return lhs.getComputerLowerCaseName() < rhs.getComputerLowerCaseName();
}
bool sortByNameComputersReverse(const Computer &lhs, const Computer &rhs)
{
    return lhs.getComputerLowerCaseName() > rhs.getComputerLowerCaseName();
}
bool sortByDateComputers(const Computer &lhs, const Computer &rhs)
{
    return lhs.getComputerDate() < rhs.getComputerDate();
}
bool sortByDateComputersReverse(const Computer &lhs, const Computer &rhs)
{
    return lhs.getComputerDate() > rhs.getComputerDate();
}
bool sortByTypeComputers(const Computer &lhs, const Computer &rhs)
{
    return lhs.getComputerType() < rhs.getComputerType();
}
void DataLayer::sortScientistNames(vector<Person>& getPersons)
{
    std::sort(getPersons.begin(),getPersons.end(), sortByScientistName);
}
void DataLayer::sortScientistNamesReverse(vector<Person>& getPersons)
{
    std::sort(getPersons.begin(),getPersons.end(), sortByScientistNameReverse);
}
void DataLayer::sortScientistBirth(vector<Person>& getPersons)
{
    std::sort(getPersons.begin(),getPersons.end(), sortByScientistBirth);
}
void DataLayer::sortScientistBirthReverse(vector<Person>& getPersons)
{
    std::sort(getPersons.begin(),getPersons.end(), sortByScientistBirthReverse);
}
void DataLayer::sortScientistGender(vector<Person>& getPersons)
{
    std::sort(getPersons.begin(),getPersons.end(), sortByScientistGender);
}
void DataLayer::sortScientistAge(vector<Person>& getPersons)
{
    std::sort(getPersons.begin(),getPersons.end(), sortByScientistAge);
}
void DataLayer::sortNamesComputers(vector<Computer>& com)
{
    std::sort(com.begin(),com.end(), sortByNameComputers);
}
void DataLayer::sortNamesComputersReverse(vector<Computer>& com)
{
    std::sort(com.begin(),com.end(), sortByNameComputersReverse);
}
void DataLayer::sortDateComputers(vector<Computer>& com)
{
    std::sort(com.begin(),com.end(), sortByDateComputers);
}
void DataLayer::sortDateComputersReverse(vector<Computer>& com)
{
    std::sort(com.begin(),com.end(), sortByDateComputersReverse);
}
void DataLayer::sortTypeComputers(vector<Computer>& com)
{
    std::sort(com.begin(),com.end(), sortByTypeComputers);
}
int DataLayer::stringToNumber(string st)
{
    string text = st;
    int value = atoi(text.c_str());
    return value;
}
void DataLayer::readScientistsFromDatabase(vector<Person>& sci)
{
    db.open();

    QSqlQuery query(db);
    query.exec("SELECT * FROM Scientist");

    while(query.next())
    {
        int id = query.value("id").toUInt();
        string name = query.value("SciName").toString().toStdString();
        string gen = query.value("gender").toString().toStdString();
        int birth = query.value("YearOfBirth").toUInt();
        int death = query.value("YearOfDeath").toUInt();
        string comment = query.value("comment").toString().toStdString();

        if(death < 0 && death > 2016)
        {
            death = 0;
        }
        char gender = gen[0];
        sci.push_back(Person(name, gender, birth, death, comment, id));
    }
}
void DataLayer::readComputersFromDatabase(vector<Computer>& com)
{
    db.open();

    QSqlQuery query(db);
    query.exec("SELECT * FROM Computers");

    while(query.next())
    {
        int id = query.value("id").toUInt();
        string name = query.value("CompName").toString().toStdString();
        string type = query.value("type").toString().toStdString();
        int date = query.value("date").toUInt();
        string wasItBuilt = query.value("wasitbuilt").toString().toStdString();
        com.push_back(Computer(name, wasItBuilt, date, type, id));
    }
}
bool DataLayer::addScientist(string name, char gender, int yearOfBirth, int yearOfDeath, string comment, int vsize)
{
    QString qname = QString::fromStdString(name);
    QString qcomment = QString::fromStdString(comment);
    QString qgender = QChar(gender);

    QSqlQuery queryAdd;
    queryAdd.prepare("INSERT INTO Scientist (id, SciName, gender, yearofbirth, yearofdeath, comment) VALUES (:id, :name, :gender, :yearofbirth, :yearofdeath, :comment)");

    queryAdd.bindValue(":id", vsize);
    queryAdd.bindValue(":name", qname);
    queryAdd.bindValue(":gender", qgender);
    queryAdd.bindValue(":yearofbirth", yearOfBirth);

    if (yearOfDeath != 0)
    {
        queryAdd.bindValue(":yearofdeath", yearOfDeath);
    }
    queryAdd.bindValue(":comment", qcomment);
    queryAdd.exec();
    return true;
}
void DataLayer::addComputer(string name, string type, int yearbuilt, string isbuilt, int vsize)
{
    QString qname = QString::fromStdString(name);
    QString qtype = QString::fromStdString(type);
    QString qisbuilt = QString::fromStdString(isbuilt);

    QSqlQuery queryAdd;
    queryAdd.prepare("INSERT INTO Computers (ID, CompName, Type, Date, WasItBuilt) VALUES (:id, :name, :type, :yearbuilt, :isbuilt)");

    queryAdd.bindValue(":id", vsize);
    queryAdd.bindValue(":name", qname);
    queryAdd.bindValue(":isbuilt", qisbuilt);
    queryAdd.bindValue(":yearbuilt", yearbuilt);
    queryAdd.bindValue(":type", qtype);
    queryAdd.exec();
}
void DataLayer::updateScientist(string name, char gender, int yearOfBirth, int yearOfDeath, string comment, int sciId)
{
    QString qname = QString::fromStdString(name);
    QString qcomment = QString::fromStdString(comment);
    QString qgender = QChar(gender);

    QSqlQuery queryAdd;
    queryAdd.prepare("UPDATE Scientist SET SciName=:name, Gender=:gender, YearOfbirth=:yearofbirth, YearOfDeath=:yearofdeath, Comment=:comment WHERE ID=:id");

    queryAdd.bindValue(":id", sciId);
    queryAdd.bindValue(":name", qname);
    queryAdd.bindValue(":gender", qgender);
    queryAdd.bindValue(":yearofbirth", yearOfBirth);
    if(yearOfDeath != 0)
    {
        queryAdd.bindValue(":yearofdeath", yearOfDeath);
    }
    queryAdd.bindValue(":comment", qcomment);
    queryAdd.exec();
}
void DataLayer::updateComputer(string name, string type, string isbuilt, int Yearbuilt, int compId)
{
    QString qname = QString::fromStdString(name);
    QString qtype = QString::fromStdString(type);
    QString qisbuilt = QString::fromStdString(isbuilt);

    QSqlQuery queryAdd;
    queryAdd.prepare("UPDATE Computers SET CompName=:name, Type=:type, Date=:yearbuilt, WasItBuilt=:isbuilt WHERE ID=:id");

    queryAdd.bindValue(":id", compId);
    queryAdd.bindValue(":name", qname);
    queryAdd.bindValue(":type", qtype);
    queryAdd.bindValue(":isbuilt", qisbuilt);
    queryAdd.bindValue(":yearbuilt", Yearbuilt);
    queryAdd.exec();
}

void DataLayer::updateConnection(int currentId, int sciId, int comId)
{
    QSqlQuery queryAdd;
    queryAdd.prepare("UPDATE CompAndSci SET ComputerID=:comid, ScientistID=:sciid WHERE ID=:id");

    queryAdd.bindValue(":id", currentId);
    queryAdd.bindValue(":comid", comId);
    queryAdd.bindValue(":sciid", sciId);
    queryAdd.exec();
}
void DataLayer::addConnection(int linkId, int sciId, int compId)
{
        QSqlQuery queryAdd;
        queryAdd.prepare("INSERT INTO CompAndSci (ID, ComputerID, ScientistID) VALUES (:id, :compId, :sciId)");

        queryAdd.bindValue(":id", linkId);
        queryAdd.bindValue(":compId", compId);
        queryAdd.bindValue(":sciId", sciId);

        queryAdd.exec();
}
void DataLayer::removeComputer(string name)
{

    QString qname = QString::fromStdString(name);
    QSqlQuery queryRemove;
    queryRemove.prepare("DELETE FROM Computers Where CompName=:name");
    queryRemove.bindValue(":name", qname);

    queryRemove.exec();
}
void DataLayer::removeConnection(int id)
{
    QSqlQuery queryRemove;
    queryRemove.prepare("DELETE FROM CompAndSci Where ID=:id");
    queryRemove.bindValue(":id", id);

    queryRemove.exec();
}
void DataLayer::removeScientist(string name)
{
    QString qname = QString::fromStdString(name);
    QSqlQuery queryRemove;
    queryRemove.prepare("DELETE FROM Scientist Where SciName=:name");
    queryRemove.bindValue(":name", qname);
    queryRemove.exec();
}
void DataLayer::readLinksFromDatabase(vector<Linker>& link)
{
    db.open();

    QSqlQuery query(db);
    query.exec("SELECT * FROM CompAndSci");

    while(query.next())
    {
        int id = query.value("id").toUInt();
        int sciId = query.value("ScientistID").toUInt();
        int comId = query.value("ComputerID").toUInt();

        link.push_back(Linker(id, sciId, comId));
    }
}
void DataLayer::removeConnection(int sciId, int compId)
{
    QSqlQuery queryRemove;
    queryRemove.prepare("DELETE FROM CompAndSci Where ComputerID=:compId AND ScientistID=:sciId");
    queryRemove.bindValue(":sciId", sciId);
    queryRemove.bindValue(":compId", compId);
    queryRemove.exec();

}
void DataLayer::sortConnectionsBySciName(vector<LinkerOutput>& linkout)
{
    db.open();
    QSqlQuery query(db);
    query.exec("SELECT Scientist.SciName, Computers.CompName FROM Scientist, Computers INNER JOIN CompAndSci ON Scientist.ID=CompAndSci.ScientistID AND Computers.ID = CompAndSci.ComputerID ORDER BY Scientist.SciName ASC");

    while(query.next())
    {
        string sciName = query.value("SciName").toString().toStdString();
        string compName = query.value("CompName").toString().toStdString();
        linkout.push_back(LinkerOutput(sciName, compName));
    }
}
void DataLayer::sortConnectionsByCompName(vector<LinkerOutput>& linkout)
{
    db.open();
    QSqlQuery query(db);
    query.exec("SELECT Scientist.SciName, Computers.CompName FROM Scientist, Computers INNER JOIN CompAndSci ON Scientist.ID=CompAndSci.ScientistID AND Computers.ID = CompAndSci.ComputerID ORDER BY Computers.CompName ASC");

    while(query.next())
    {
        string sciName = query.value("SciName").toString().toStdString();
        string compName = query.value("CompName").toString().toStdString();
        linkout.push_back(LinkerOutput(sciName, compName));
    }
}
void DataLayer::sortConnectionsBySciNameDesc(vector<LinkerOutput>& linkout)
{
    db.open();
    QSqlQuery query(db);
    query.exec("SELECT Scientist.SciName, Computers.CompName FROM Scientist, Computers INNER JOIN CompAndSci ON Scientist.ID=CompAndSci.ScientistID AND Computers.ID = CompAndSci.ComputerID ORDER BY Scientist.SciName DESC");

    while(query.next())
    {
        string sciName = query.value("SciName").toString().toStdString();
        string compName = query.value("CompName").toString().toStdString();
        linkout.push_back(LinkerOutput(sciName, compName));
    }
}
void DataLayer::sortConnectionsByCompNameDesc(vector<LinkerOutput>& linkout)
{
    db.open();
    QSqlQuery query(db);
    query.exec("SELECT Scientist.SciName, Computers.CompName FROM Scientist, Computers INNER JOIN CompAndSci ON Scientist.ID=CompAndSci.ScientistID AND Computers.ID = CompAndSci.ComputerID ORDER BY Computers.CompName DESC");

    while(query.next())
    {
        string sciName = query.value("SciName").toString().toStdString();
        string compName = query.value("CompName").toString().toStdString();
        linkout.push_back(LinkerOutput(sciName, compName));
    }
}
void DataLayer::searchConnectionsBySci(vector<LinkerOutput>& linkout, int sciId)
{
    db.open();
    QSqlQuery query(db);
    query.prepare("SELECT Scientist.SciName, Computers.CompName FROM Scientist, Computers INNER JOIN CompAndSci ON Scientist.ID=CompAndSci.ScientistID AND Computers.ID = CompAndSci.ComputerID WHERE CompAndSci.ScientistID=:id");
    query.bindValue(":id", sciId);
    query.exec();

    while(query.next())
    {
        string sciName = query.value("SciName").toString().toStdString();
        string compName = query.value("CompName").toString().toStdString();
        linkout.push_back(LinkerOutput(sciName, compName));
    }
}
void DataLayer::searchConnectionsByComp(vector<LinkerOutput>& linkout, int compId)
{
    db.open();
    QSqlQuery query(db);
    query.prepare("SELECT Scientist.SciName, Computers.CompName FROM Scientist, Computers INNER JOIN CompAndSci ON Scientist.ID=CompAndSci.ScientistID AND Computers.ID = CompAndSci.ComputerID WHERE CompAndSci.ComputerID=:id");
    query.bindValue(":id", compId);
    query.exec();

    while(query.next())
    {
        string sciName = query.value("SciName").toString().toStdString();
        string compName = query.value("CompName").toString().toStdString();
        linkout.push_back(LinkerOutput(sciName, compName));
    }
}
