#ifndef LISTWORKER_H
#define LISTWORKER_H
#include "datalayer.h"
#include "person.h"
#include "computer.h"
#include <iostream>
#include <string>

using namespace std;

class ListWorker
{
public:
    ListWorker();

    void addNewPerson(string name, char gender, int yearOfBirth, int yearOFDeath, string comment); //Adds a person to the vector persons and adds them to the database.
    void addNewComputer(string name, string type, int yearbuilt, string isbuilt);
    bool ageSearcher(int age);                  // Searches for a specific age within the vector using a for loop.
    bool builtDateSearcher(int year);           //
    bool genderSearcher(char gender);           // Searches for a specific gender within the vector using a for loop.
    bool nameSearcher(string name);             // Searches for a specific name within the vector using a for loop.
    bool removePerson(string name);             // Remove person from the vector.
    bool removePersonFound(string name);        // Check if person to remove is found or not.
    void sortBirth();                           // Calls the function sortBirth from the datalayer class.
    void sortNames();                           // Calls the function sortNames from the datalayer class.
    void sortGender();                          // Calls the function sortGender from the datalayer class.
    void sortAge();                             // Calls the function sortAge from the datalayer class.
    bool typeSearcher(string type);
    bool yearSearcher(int year);                // Searches for a specific year within the vector using a for loop.
    int editPersonFinder(string name);          // Edit a scientist.
    string getName(int n) const                 // Make _name from persons available.
    {
        return persons[n]._getName();
    }
    int getBuiltDate(int n) const
    {
        return com[n]._getDate();
    }
    string getComputerName(int n) const
    {
        return com[n]._getComputerName();
    }
    string getType(int n) const
    {
        return com[n]._getType();
    }
    char getGender(int n) const                 // Make _gender from persons available.
    {
        return persons[n]._getGender();
    }
    int getBirth(int n) const                   // Make _yearOfBirth from persons available.
    {
        return persons[n]._getBirth();
    }
    int getDeath(int n) const                   // Make _yearOfDeath from persons available.
    {
        return persons[n]._getDeath();
    }
    string getComment(int n) const              // Make _comment from persons available.
    {
        return persons[n]._getComment();
    }
    int getAge(int n) const
    {
        return persons[n]._getAge();
    }
    int getNameSize(int n) const;               // Returns the size of _name from persons.
    int personsSize() const                     // Returns the size of vector persons.
    {
        return persons.size();
    }
    int comSize() const                        // Returns the size of vector com.
    {
        return com.size();
    }
private:
    DataLayer data;
    vector<Person> persons;                     // The vector containing all persons from the database.
    vector<computer> com;
};

#endif // LISTWORKER_H
