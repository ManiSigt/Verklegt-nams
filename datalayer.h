#ifndef DATALAYER_H
#define DATALAYER_H
#include "person.h"
#include "computer.h"
#include "linker.h"
#include <vector>
#include <Qtsql>

class DataLayer
{
public:
    DataLayer();
    friend bool sortByNameComputers(const Computer &lhs, const Computer &rhs);
    friend bool sortByDateComputers(const Computer &lhs, const Computer &rhs);
    friend bool sortByTypeComputers(const Computer &lhs, const Computer &rhs);
    void sortNamesComputers(vector<Computer>& com);
    void sortDateComputers(vector<Computer>& com);
    void sortTypeComputers(vector<Computer>& com);
    friend bool sortByScientistName(const Person &lhs, const Person &rhs);                          // Compares two names and returns the one that is lower in alphabetical order.
    friend bool sortByScientistBirth(const Person &lhs, const Person &rhs);                         // Compares two years of birth and returns the one that is lower in chronological order.
    friend bool sortByScientistGender(const Person &lhs, const Person &rhs);                        // Compares the two genders and just returns the one that the user wants to find.
    friend bool sortByScientistAge(const Person &lhs, const Person &rhs);                           // Compares two ages of scientists and return from lowest to highest.
    void sortScientistNames(vector<Person>& getPersons);                                            // Sorts the vector by names of people.
    void sortScientistBirth(vector<Person>& getPersons);                                            // Sorts the vector by year of birth.
    void sortScientistGender(vector<Person>& getPersons);                                           // Sorts the vector by gender.
    void sortScientistAge(vector<Person>& getPersons);                                              // Sorts the vector by age.
    void deleteFile();                                                                              // Delete the file amazingDataBase.txt.
    int stringToNumber(string st);                                                                  // Convert a string to a int.
    void removeComputer(string name);                                                               // Removes computer from SQL database.
    void removeScientist(string name);                                                              // Removes scientist from SQL database.
    void removeConnection(int id);                                                                  // Removes connection from SQL database
    void readLinksFromDatabase(vector<Linker>& link);
    void readScientistsFromDatabase(vector<Person>& sci);
    void readComputersFromDatabase(vector<Computer>& com);
    void addScientist(string name, char gender, int yearOfBirth, int yearOfDeath, string comment, int vsize);   // Adds a scientist to the SQL database.
    void addComputer(string name, string type, int yearbuilt, string isbuilt, int vsize);           // Adds a computer to the SQL databse.
    void addConnection(int linkId, int sciId, int compId);                                          // Adds a connection from to the SQL databse.
    QSqlDatabase db;
 };

#endif // DATALAYER_H
