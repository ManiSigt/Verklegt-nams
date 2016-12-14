#ifndef LISTWORKER_H
#define LISTWORKER_H
#include "datalayer.h"
#include "person.h"
#include "linker.h"
#include "Computer.h"
#include <iostream>
#include <string>
#include "linkeroutput.h"

using namespace std;

class ListWorker
{
public:
    ListWorker();
    bool addNewScientist(string name, char gender, int yearOfBirth, int yearOFDeath, string comment); // Adds a person to the vector persons and adds them to the database.
    bool addNewComputer(string name, string type, int yearbuilt, string isbuilt);                     // Adds a computer to the vector that holds the list of computers and then adds it to the database.
    void addNewConnection(int compId, int sciId);                                                     // Adds a link between a computer and a scientist that the user chooses and adds them to the SQL database.
    void sortScientistBirth();                                                                        // Calls the function sortScientistBirth from the datalayer class.
    void sortScientistBirthReverse();                                                                 // Calls the function sortScientistBirthReverse from the datalayer class.
    void sortScientistNames();                                                                        // Calls the function sortScientistNames from the datalayer class.
    void sortScientistNamesReverse();                                                                 // Calls the function sortScientistNamesReverse from the datalayer class.
    void sortScientistGender();                                                                       // Calls the function sortScientistGender from the datalayer class.
    void sortScientistAge();                                                                          // Calls the function sortScientistAge from the datalayer class.
    void sortComputerName();                                                                          // Calls the function sortComputerName from the datalayer.
    void sortComputerNameReverse();                                                                   // Calls the function sortComputerNameReverse from the datalayer.
    void sortComputerDate();                                                                          // Calls the function sortComputerDate from the datalayer class.
    void sortComputerDateReverse();                                                                   // Calls the function sortComputerDateReverse from the datalayer class.
    void sortComputerType();                                                                          // Calls the function sortComputerType from the datalayer class.
    void refreshVector();                                                                             // Deletes what has been removed from the vector and adds what has been added deending on the users instructions.
    void sortConnections(string selection);                                                           // Sort connections menu.
    void searchConnectionsByComp(int n);                                                              // Calls the function searchConnectionsByComp in datalayer.
    void searchConnectionsBySci(int n);                                                               // Calls the function searchConnectionsBySci in datalayer.
    void removeConnection(string scientist, string computer);                                         // Removes a computer or a scientist from the database.
    bool removeConnection(int s, int c);                                                              // Removes a computer or a scientist from the database.
    void updateScientist(string name,char gender, int birth, int death, string comment, int sciId);   // Calls the function updateScientist in datalayer.
    void updateComputer(string name, string type, string isbuilt, int Yearbuilt, int compId);         // Calls the function updateComputer in datalayer.
    bool computerNameSearcher(string name);                                                           // Searches for a specific name within the vector com.
    bool ageSearcher(int age);                                                                        // Searches for a specific age within the vector using a for-loop.
    bool builtDateSearcher(int year);                                                                 // Searches for a specific date within the vector using a for-loop
    bool genderSearcher(char gender);                                                                 // Searches for a specific gender within the vector using a for-loop.
    bool nameSearcher(string name);                                                                   // Searches for a specific name within the vector using a for-loop.
    bool removePerson(int rowNumber);                                                                   // Remove a scientist from the vector person.
    bool removePersonFound(string name);                                                              // Check if the scientist that user wants to remove is found or not.
    bool removeComputer(int rowNumber);                                                                 // Remove a computer from the vector com.
    bool removeComputerFound(string name);                                                            // Check if the computer tat the user wants to remove is found or not.
    bool typeSearcher(string type);                                                                   // Finds a specific type of computer.
    bool yearSearcher(int year);                                                                      // Searches for a specific year within the vector using a for loop.
    int computerIdFinder();                                                                           // Finds ID of computer.
    int scientistIdFinder();                                                                          // Finds ID of scientist.
    int editPersonFinder(string name);                                                                // Edit a scientist.
    int getScientistNameSize(int n) const;                                                            // Returns the size of _name from persons.
    int getComputerNameSize(int n) const;                                                             // Returns the size of _name from Computer.
    string getComputerNameFromId(int n) const;                                                        // Get computer name from compId
    string getScientistNameFromId(int n) const;                                                       // Get scientist name from sciId
    string getScientistName(int n) const                                                              // Make _name from the vector persons available.
    {
        return persons[n].getScientistName();
    }
    string getScientistLowerCaseName(int n)                                                           // Returns the name of a scientist in lower case.
    {
        return persons[n].getScientistLowerCaseName();
    }
    string getComputerName(int n) const                                                               // Make name from the vector com available.
    {
        return com[n].getComputerName();
    }
    string getComputerLowerCaseName(int n)                                                            // Reurns the name of a computer in lower case.
    {
        return com[n].getComputerLowerCaseName();
    }
    string getComputerLowerCaseType(int n)                                                            // Reurns the type of a computer in lower case.
    {
        return com[n].getComputerLowerCaseType();
    }
    string getScientistComment(int n) const                                                           // Make comment from the vector persons available.
    {
        return persons[n].getScientistComment();
    }
    string getComputerType(int n) const                                                               // Make type from the vector com available.
    {
        return com[n].getComputerType();
    }
    string getComputerWasItBuilt(int n) const                                                         // Make wasItBuilt from the vector com available.
    {
        return com[n].getComputerWasItBuilt();
    }
    char getScientistGender(int n) const                                                              // Make gender from the vector persons available.
    {
        return persons[n].getScientistGender();
    }
    int getScientistBirth(int n) const                                                                // Make yearOfBirth from the vector persons available.
    {
        return persons[n].getScientistBirth();
    }
    int getScientistDeath(int n) const                                                                // Make yearOfDeath from the vector persons available.
    {
        return persons[n].getScientistDeath();
    }
    int getComputerDate(int n) const                                                                  // Make getDate from the vector com available.
    {
        return com[n].getComputerDate();
    }
    int getComputerId(int n) const                                                                    // Make getDate from the vector com available.
    {
        return com[n].getComputerId();
    }
    int getScientistAge(int n) const                                                                  // Make getScientistAge from the vector persons available.
    {
        return persons[n].getScientistAge();
    }
    int getScientistId(int n) const                                                                   // Make getScientistId from the vector persons available.
    {
        return persons[n].getScientistId();
    }
    int getLinkId(int n) const                                                                        // Make _id from vector link available.
    {
        return link[n].getId();
    }
    int getLinkCompId(int n) const                                                                    // Make _compId from vector link available.
    {
        return link[n].getComId();
    }
    int getLinkSciId(int n) const                                                                     // Make _sciId from vector link available.
    {
        return link[n].getSciId();
    }
    int getLinkSize() const                                                                           // Returns size of vector link.
    {
        return link.size();
    }
    int getLinkOutputSize() const                                                                     // Returns size of vector linkout.
    {
        return linkout.size();
    }
    string getLinkOutputCompName(int n) const                                                         // Returns computer name from vector linkout.
    {
        return linkout[n].getCompName();
    }
    string getLinkOutputSciName(int n) const                                                          // Returns scientist name from vector linkout.
    {
        return linkout[n].getSciName();
    }
    string getLinkOutputCompNameLower(int n) const                                                    // Returns computer name in lower case from vector linkout.
    {
        return linkout[n].getCompNameLower();
    }
    string getLinkOutputSciNameLower(int n) const                                                     // Returns scientist name in lower case from vector linkout.
    {
        return linkout[n].getSciNameLower();
    }
    int getLinkoutputCompNameSize(int n);
    int personsSize() const                                                                           // Returns the size of vector persons.
    {
        return persons.size();
    }
    int computerSize() const                                                                          // Returns the size of vector Computer.
    {
        return com.size();
    }

    void eraser();
private:

    DataLayer data;
    vector<Person> persons;                                                                           // The vector containing all persons from the database.
    vector<Computer> com;                                                                             // The vector containing all computers from the database.
    vector<Linker> link;                                                                              // The vector containing all connections from the database.
    vector<LinkerOutput> linkout;                                                                    // The vector containing all names from connections from the database.
};

#endif // LISTWORKER_H
