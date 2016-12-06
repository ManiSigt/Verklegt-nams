#include "datalayer.h"
#include "person.h"
#include "computer.h"
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
    return lhs._getNamePerson() < rhs._getNamePerson();
}
bool sortByScientistBirth(const Person &lhs, const Person &rhs)
{
    return lhs._getBirthPerson() < rhs._getBirthPerson();
}
bool sortByScientistGender(const Person &lhs, const Person &rhs)
{
    return lhs._getGenderPerson() < rhs._getGenderPerson();
}
bool sortByScientistAge(const Person &lhs, const Person &rhs)
{
    return lhs._getAgePerson() < rhs._getAgePerson();
}
bool sortByNameComputers(const Computer &lhs, const Computer &rhs)
{
    return lhs._getNameComputer() < rhs._getNameComputer();
}
bool sortByDateComputers(const Computer &lhs, const Computer &rhs)
{
    return lhs._getDateComputer() < rhs._getDateComputer();
}
bool sortByTypeComputers(const Computer &lhs, const Computer &rhs)
{
    return lhs._getTypeComputer() < rhs._getTypeComputer();
}
void DataLayer::sortScientistNames(vector<Person>& getPersons)
{
    std::sort(getPersons.begin(),getPersons.end(), sortByScientistName);
}
void DataLayer::sortScientistBirth(vector<Person>& getPersons)
{
    std::sort(getPersons.begin(),getPersons.end(), sortByScientistBirth);
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
void DataLayer::sortDateComputers(vector<Computer>& com)
{
    std::sort(com.begin(),com.end(), sortByDateComputers);
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
        string name = query.value("name").toString().toStdString();
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
        string name = query.value("name").toString().toStdString();
        string type = query.value("type").toString().toStdString();
        int date = query.value("date").toUInt();
        string wasItBuilt = query.value("wasitbuilt").toString().toStdString();

        com.push_back(Computer(name, wasItBuilt, date, type, id));

   }
}
bool DataLayer::addScientist(string name, char gender, int yearOfBirth, int yearOfDeath, string comment, int vsize)
{
    bool success = false;

    QString qname = QString::fromStdString(name);
    QString qcomment = QString::fromStdString(comment);
    QString qgender = QChar(gender);

        QSqlQuery queryAdd;
        queryAdd.prepare("INSERT INTO Scientist (id, name, gender, yearofbirth, yearofdeath, comment) VALUES (:id, :name, :gender, :yearofbirth, :yearofdeath, :comment)");

        queryAdd.bindValue(":id", vsize+1);
        queryAdd.bindValue(":name", qname);
        queryAdd.bindValue(":gender", qgender);
        queryAdd.bindValue(":yearofbirth", yearOfBirth);
        if (yearOfDeath != 0)
        {
            queryAdd.bindValue(":yearofdeath", yearOfDeath);
        }
        queryAdd.bindValue(":comment", qcomment);
        if(queryAdd.exec())
        {
            success = true;
        }
        else
        {
            qDebug() << "add person failed: " << queryAdd.lastError();
        }

    return success;
}

bool DataLayer::addComputer(string name, string type, int yearbuilt, string isbuilt, int vsize)
{
    bool success = false;

    QString qname = QString::fromStdString(name);
    QString qtype = QString::fromStdString(type);
    QString qisbuilt = QString::fromStdString(isbuilt);

        QSqlQuery queryAdd;
        queryAdd.prepare("INSERT INTO Computers (ID, Name, Type, Date, WasItBuilt) VALUES (:id, :name, :type, :yearbuilt, :isbuilt)");

        queryAdd.bindValue(":id", vsize);
        queryAdd.bindValue(":name", qname);
        queryAdd.bindValue(":isbuilt", qisbuilt);
        queryAdd.bindValue(":yearbuilt", yearbuilt);
        queryAdd.bindValue(":type", qtype);

        if(queryAdd.exec())
        {
            success = true;
        }
        else
        {
            qDebug() << "add computer failed: " << queryAdd.lastError();
        }

    return success;
}
