#ifndef LISTWORKER_H
#define LISTWORKER_H
#include "datalayer.h"
#include "person.h"
#include <iostream>
#include <string>

using namespace std;

class ListWorker
{
public:
    ListWorker();
    void addNewPerson(string name, char gender, int yearOfBirth, int yearOFDeath, string comment);
    void viewAll();

    void sortNames();
    void sortBirth();

    bool removePerson(string name);

    string getName(int n) const
    {
        return getPersons[n]._getName();;
    }
    char getGender(int n) const
    {
        return getPersons[n]._getGender();;
    }
    int getBirth(int n) const
    {
        return getPersons[n]._getBirth();;
    }
    int getDeath(int n) const
    {
        return getPersons[n]._getDeath();
    }
    string getComment(int n) const
    {
        return getPersons[n]._getComment();
    }
    int getNameSize(int n) const
    {
        string name = getPersons[n]._getName();
        int size = name.size();
        return size;
    }
    int getPersonsSize() const
    {
        return getPersons.size();
    }

    friend bool equals (const Person &lhs, const string searchChoice);
    void saveFile();

private:
    DataLayer data;
    vector<Person> getPersons;
};

#endif // LISTWORKER_H
