#include "datalayer.h"
#include "person.h"
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
void DataLayer::writeToFile(string name, char gender, int yearOfBirth, int yearOfDeath, string comment)
{
     ofstream myfile("amazingDatabase.txt", ios::app);
     myfile << name << endl;
     myfile << gender << endl;
     myfile << yearOfBirth << endl;
     myfile << yearOfDeath << endl;
     myfile << comment << endl;
     myfile.close();
}

bool sortByName(const Person &lhs, const Person &rhs)
{
    return lhs._getName() < rhs._getName();
}
bool sortByBirth(const Person &lhs, const Person &rhs)
{
    return lhs._getBirth() < rhs._getBirth();
}
bool sortByGender(const Person &lhs, const Person &rhs)
{
    return lhs._getGender() < rhs._getGender();
}
bool sortByAge(const Person &lhs, const Person &rhs)
{
    return lhs._getAge() < rhs._getAge();
}
void DataLayer::sortNames(vector<Person>& getPersons)
{
    std::sort(getPersons.begin(),getPersons.end(), sortByName);
}
void DataLayer::sortBirth(vector<Person>& getPersons)
{
    std::sort(getPersons.begin(),getPersons.end(), sortByBirth);
}
void DataLayer::sortGender(vector<Person>& getPersons)
{
    std::sort(getPersons.begin(),getPersons.end(), sortByGender);
}
void DataLayer::sortAge(vector<Person>& getPersons)
{
    std::sort(getPersons.begin(),getPersons.end(), sortByAge);
}
void DataLayer::deleteFile()
{
    remove("amazingDatabase.txt");
    ofstream myfile;
    myfile.open("amazingDatabase.txt");
    myfile.close();
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

void DataLayer::readComputersFromDatabase(vector<computer>& com)
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

        com.push_back(computer(name, type, date, wasItBuilt));
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

        cout << vsize << endl;
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

