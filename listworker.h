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
    void addNewPerson(string name, char gender, int yearOfBirth, int yearOFDeath, string comment); //Adds a person to the vector getPersons and adds them to the database.
    bool genderSearcher(char gender);           //
    bool nameSearcher(string name);             //
    bool removePerson(string name);             //
    bool removePersonFound(string name);        //
    void sortBirth();                           //
    void sortNames();                           //
    void sortGender();                          //
    bool yearSearcher(int year);                //
    string getName(int n) const                 //Make _name from getPersons available.
    {
        return getPersons[n]._getName();;
    }
    char getGender(int n) const                 //Make _gender from getPersons available.
    {
        return getPersons[n]._getGender();;
    }
    int getBirth(int n) const                   //Make _yearOfBirth from getPersons available.
    {
        return getPersons[n]._getBirth();;
    }
    int getDeath(int n) const                   //Make _yearOfDeath from getPersons available.
    {
        return getPersons[n]._getDeath();
    }
    string getComment(int n) const              //Make _comment from getPersons available.
    {
        return getPersons[n]._getComment();
    }
    int getNameSize(int n) const;               //Returns the size of _name from getPersons.
    int getPersonsSize() const                  //Returns the size of vector getPersons.
    {
        return getPersons.size();
    }
    void saveFile();                            //Deletes the file and makes a new one, and reads the vector into the new file.

private:
    DataLayer data;
    vector<Person> getPersons;                  //The vector containing all persons from the database.
};

#endif // LISTWORKER_H
