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
    string getNamePerson(int n) const                 // Make _name from persons available.
    {
        return persons[n]._getNamePerson();
    }
    string getNameComputer(int n) const                 // Make _name from computer available.
    {
        return com[n]._getNameComputer();
    }
    char getGenderPerson(int n) const                 // Make _gender from persons available.
    {
        return persons[n]._getGenderPerson();
    }
    int getBirthPerson(int n) const                   // Make _yearOfBirth from persons available.
    {
        return persons[n]._getBirthPerson();
    }
    int getDeathPerson(int n) const                   // Make _yearOfDeath from persons available.
    {
        return persons[n]._getDeathPerson();
    }
    int getDateComputer(int n) const                   //Make _getDate from computer available.
    {
        return com[n]._getDateComputer();
    }
    string getCommentperson(int n) const              // Make _comment from persons available.
    {
        return persons[n]._getCommentPerson();
    }
    string getTypeComputer(int n) const                // Make _type from computer available.
    {
        return com[n]._getTypeComputer();
    }
    string getWasItBuilt(int n) const                   //Make _wasItBuilt from computer available
    {
        return com[n]._getWasItBuiltComputer();
    }
    int getAgePerson(int n) const
    {
        return persons[n]._getAgePerson();
    }
    int getNameSizePerson(int n) const;               // Returns the size of _name from persons.
    int getNameSizeComputer(int n) const;           // Returns the size of _name from computer.
    int personsSize() const                     // Returns the size of vector persons.
    {
        return persons.size();
    }

    int computerSize() const                     // Returns the size of vector computer.
    {
        return com.size();
    }
    void saveFile();                            // Deletes the file and makes a new one, and reads the vector into the new file.

private:
    DataLayer data;
    vector<Person> persons;                     // The vector containing all persons from the database.
    vector<computer> com;
};

#endif // LISTWORKER_H
