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

    void addNewPerson(string name, char gender, int yearOfBirth, int yearOFDeath, string comment); //Adds a person to the vector persons and adds them to the database.
    bool genderSearcher(char gender);           // Searches for a specific gender within the vector using a for loop.
    bool nameSearcher(string name);             // Searches for a specific name within the vector using a for loop.
    bool removePerson(string name);             // Remove person from the vector.
    bool removePersonFound(string name);        // Check if person to remove is found or not.
    void sortBirth();                           // Calls the function sortBirth from the datalayer class.
    void sortNames();                           // Calls the function sortNames from the datalayer class.
    void sortGender();                          // Calls the function sortGender from the datalayer class.
    bool yearSearcher(int year);                // Searches for a specific year within the vector using a for loop.
    int editPersonFinder(string name);                //Comment með engu bili. Illa nett.
    string getName(int n) const                 // Make _name from persons available.
    {
        return persons[n]._getName();
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
    int getNameSize(int n) const;               // Returns the size of _name from persons.
    int personsSize() const                     // Returns the size of vector persons.
    {
        return persons.size();
    }
    void saveFile();                            // Deletes the file and makes a new one, and reads the vector into the new file.

private:
    DataLayer data;
    vector<Person> persons;                     // The vector containing all persons from the database.
};

#endif // LISTWORKER_H
