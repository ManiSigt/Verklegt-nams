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
    void addNewScientist(string name, char gender, int yearOfBirth, int yearOFDeath, string comment); //Adds a person to the vector persons and adds them to the database.
    void addNewComputer(string name, string type, int yearbuilt, string isbuilt); //Adds a computer to the vector that holds the list of computers and then adds it to the database.
    void addNewConnection(int linkId, int compId, int sciId);
    void sortScientistBirth();                          // Calls the function sortBirth from the datalayer class.
    void sortScientistBirthReverse();
    void sortScientistNames();                          // Calls the function sortNames from the datalayer class.
    void sortScientistNamesReverse();
    void sortScientistGender();                         // Calls the function sortGender from the datalayer class.
    void sortScientistAge();                            // Calls the function sortAge from the datalayer class.
    void sortComputerName();
    void sortComputerNameReverse();
    void sortComputerDate();
    void sortComputerDateReverse();
    void sortComputerType();
    void refreshVector();
    void removeConnection(string scientist, string computer);
    void removeConnection(int s, int c);
    void saveFile();                                    // Deletes the file and makes a new one, and reads the vector into the new file.
    bool computerNameSearcher(string name);
    bool ageSearcher(int age);                          // Searches for a specific age within the vector using a for-loop.
    bool builtDateSearcher(int year);                   // Searches for a specific date within the vector using a for-loop
    bool genderSearcher(char gender);                   // Searches for a specific gender within the vector using a for-loop.
    bool nameSearcher(string name);                     // Searches for a specific name within the vector using a for-loop.
    bool removePerson(string name);                     // Remove person from the vector.
    bool removePersonFound(string name);                // Check if person to remove is found or not.
    bool removeComputer(string name);                   // Remove computer from the vector.
    bool removeComputerFound(string name);              // Check if computer to remove is found or not.
    bool typeSearcher(string type);
    bool yearSearcher(int year);                        // Searches for a specific year within the vector using a for loop.
    int computerIdFinder();
    int scientistIdFinder();
    int editPersonFinder(string name);                  // Edit a scientist.
    int getScientistNameSize(int n) const;              // Returns the size of _name from persons.
    int getComputerNameSize(int n) const;               // Returns the size of _name from Computer.
    string getComputerNameFromId(int n) const;          // Get computer name from compId
    string getScientistNameFromId(int n) const;         // Get scientist name from sciId
    string getScientistName(int n) const                // Make _name from persons available.
    {
        return persons[n].getScientistName();
    }
    string getScientistLowerCaseName(int n)
    {
        return persons[n].getScientistLowerCaseName();
    }
    string getComputerName(int n) const                // Make name from the vector com available.
    {
        return com[n].getComputerName();
    }
    string getComputerLowerCaseName(int n)
    {
        return com[n].getComputerLowerCaseName();
    }
    string getScientistComment(int n) const             // Make comment from the vector persons available.
    {
        return persons[n].getScientistComment();
    }
    string getComputerType(int n) const                 // Make type from the vector com available.
    {
        return com[n].getComputerType();
    }
    string getComputerWasItBuilt(int n) const           // Make wasItBuilt from the vector com available.
    {
        return com[n].getComputerWasItBuilt();
    }
    char getScientistGender(int n) const               // Make gender from the vector persons available.
    {
        return persons[n].getScientistGender();
    }
    int getScientistBirth(int n) const                 // Make yearOfBirth from the vector persons available.
    {
        return persons[n].getScientistBirth();
    }
    int getScientistDeath(int n) const                 // Make yearOfDeath from the vector persons available.
    {
        return persons[n].getScientistDeath();
    }
    int getComputerDate(int n) const                   // Make getDate from the vector com available.
    {
        return com[n].getComputerDate();
    }
    int getComputerId(int n) const                      // Make getDate from the vector com available.
    {
        return com[n].getComputerId();
    }

    int getScientistAge(int n) const                    // Make getScientistAge from the vector persons available.
    {
        return persons[n].getScientistAge();
    }
    int getScientistId(int n) const                     // Make getScientistId from the vector persons available.
    {
        return persons[n].getScientistId();
    }
    int getLinkId(int n) const                          // Make _id from vector link available.
    {
        return link[n].getId();
    }
    int getLinkCompId(int n) const                      // Make _compId from vector link available.
    {
        return link[n].getComId();
    }
    int getLinkSciId(int n) const                       // Make _sciId from vector link available.
    {
        return link[n].getSciId();
    }
    int getLinkSize() const                             // Returns size of vector link
    {
        return link.size();
    }
    int personsSize() const                             // Returns the size of vector persons.
    {
        return persons.size();
    }
    int computerSize() const                            // Returns the size of vector Computer.
    {
        return com.size();
    }

private:
    DataLayer data;
    vector<Person> persons;                             // The vector containing all persons from the database.
    vector<Computer> com;                               // The vector containing all computers from the database.
    vector<Linker> link;                                // The vector containing all connections from the database.
};

#endif // LISTWORKER_H
