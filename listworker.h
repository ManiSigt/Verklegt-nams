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
    void addNewPerson(string name, char gender, int yearOfBirth, int yearOFDeath, string comment); //adds a person to the vector getPersons and adds them to the database.
    bool genderSearcher(char gender);           //
    bool nameSearcher(string name);             //
    bool removePerson(string name);             //
    bool removePersonFound(string name);        //
    void sortBirth();                           //
    void sortNames();                           //
    bool yearSearcher(int year);                //
    string getName(int n) const                 //
    {
        return getPersons[n]._getName();;
    }
    char getGender(int n) const                 //
    {
        return getPersons[n]._getGender();;
    }
    int getBirth(int n) const                   //
    {
        return getPersons[n]._getBirth();;
    }
    int getDeath(int n) const                   //
    {
        return getPersons[n]._getDeath();
    }
    string getComment(int n) const              //
    {
        return getPersons[n]._getComment();
    }
    int getNameSize(int n) const;               //returns the size of string name
    int getPersonsSize() const                  //returns the size of vector getPersons
    {
        return getPersons.size();
    }
    void saveFile();                            //

private:
    DataLayer data;
    vector<Person> getPersons;                  //the vector containing all persons from the database
};

#endif // LISTWORKER_H
