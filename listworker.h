#ifndef LISTWORKER_H
#define LISTWORKER_H
#include "datalayer.h"
#include "person.h"
#include "linker.h"
#include "Computer.h"
#include <iostream>
#include <string>

using namespace std;

class ListWorker
{
public:
    ListWorker();

    void addNewPerson(string name, char gender, int yearOfBirth, int yearOFDeath, string comment); //Adds a person to the vector persons and adds them to the database.
    void addNewComputer(string name, string type, int yearbuilt, string isbuilt); //Adds a computer to the vector that holds the list of computers and then adds it to the database.
    void addNewConnection(int linkId, int compId, int sciId);
    bool ageSearcher(int age);                  // Searches for a specific age within the vector using a for-loop.
    bool builtDateSearcher(int year);           // Searches for a specific date within the vector using a for-loop
    bool genderSearcher(char gender);           // Searches for a specific gender within the vector using a for-loop.
    bool nameSearcher(string name);             // Searches for a specific name within the vector using a for-loop.
    bool removePerson(string name);             // Remove person from the vector.
    bool removePersonFound(string name);        // Check if person to remove is found or not.
    bool removeComputer(string name);           // Remove computer from the vector.
    bool removeComputerFound(string name);      // Check if computer to remove is found or not.
    void sortScientistBirth();                  // Calls the function sortBirth from the datalayer class.
    void sortScientistNames();                  // Calls the function sortNames from the datalayer class.
    void sortScientistGender();                 // Calls the function sortGender from the datalayer class.
    void sortScientistAge();                    // Calls the function sortAge from the datalayer class.
    void sortComputerName();                    //nenni ekki að commenta ef við breytum
    void sortComputerDate();                    //nenni ekki að commenta ef við breytum
    void sortComputerType();                    //nenni ekki að commenta ef við breytum
    bool computerNameSearcher(string name);
    bool typeSearcher(string type);
    bool yearSearcher(int year);                // Searches for a specific year within the vector using a for loop.
    int editPersonFinder(string name);          // Edit a scientist.
    string getNamePerson(int n) const                 // Make _name from persons available.
    {
        return persons[n]._getNamePerson();
    }
    string getNameComputer(int n) const                 // Make _name from the vector com available.
    {
        return com[n]._getNameComputer();
    }
    char getGenderPerson(int n) const                 // Make _gender from the vector persons available.
    {
        return persons[n]._getGenderPerson();
    }
    int getBirthPerson(int n) const                   // Make _yearOfBirth from the vector persons available.
    {
        return persons[n]._getBirthPerson();
    }
    int getDeathPerson(int n) const                   // Make _yearOfDeath from the vector persons available.
    {
        return persons[n]._getDeathPerson();
    }
    int getDateComputer(int n) const                   //Make _getDate from the vector com available.
    {
        return com[n]._getDateComputer();
    }
    int getIdComputer(int n) const                   //Make _getDate from the vector com available.
    {
        return com[n]._getIdComputer();
    }
    string getCommentperson(int n) const              // Make _comment from the vector persons available.
    {
        return persons[n]._getCommentPerson();
    }
    string getTypeComputer(int n) const                // Make _type from the vector com available.
    {
        return com[n]._getTypeComputer();
    }
    string getWasItBuilt(int n) const                   //Make _wasItBuilt from the vector com available
    {
        return com[n]._getWasItBuiltComputer();
    }
    int getAgePerson(int n) const                       // Make _getAgePerson from the vector persons available
    {
        return persons[n]._getAgePerson();
    }
    int getPersonId(int n) const                         // Make _getPersonId from the vector persons available
    {
        return persons[n]._getIDPerson();
    }
    int getLinkId(int n) const
    {
        return link[n]._getId();
    }
    int getLinkCompId(int n) const
    {
        return link[n]._getComId();
    }
    int getLinkSciId(int n) const
    {
        return link[n]._getSciId();
    }
    string getComputerNameFromId(int n) const;
    string getScientistNameFromId(int n) const;
    int getLinkSize() const
    {
        return link.size();
    }
    int getNameSizePerson(int n) const;                 // Returns the size of _name from persons.
    int getNameSizeComputer(int n) const;               // Returns the size of _name from Computer.
    int personsSize() const                             // Returns the size of vector persons.
    {
        return persons.size();
    }

    int computerSize() const                             // Returns the size of vector Computer.
    {
        return com.size();
    }
    void saveFile();                                    // Deletes the file and makes a new one, and reads the vector into the new file.

private:
    DataLayer data;
    vector<Person> persons;                              // The vector containing all persons from the database.
    vector<Computer> com;
    vector<Linker> link;
};

#endif // LISTWORKER_H
