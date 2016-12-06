#ifndef DATALAYER_H
#define DATALAYER_H
#include "person.h"
#include "computer.h"
#include <vector>
#include <Qtsql>

class DataLayer
{
public:
    DataLayer();
    friend bool sortByName(const Person &lhs, const Person &rhs);                                   // Compares two names and returns the one that is lower in alphabetical order.
    friend bool sortByBirth(const Person &lhs, const Person &rhs);                                  // Compares two years of birth and returns the one that is lower in chronological order.
    friend bool sortByGender(const Person &lhs, const Person &rhs);                                 // Compares the two genders and just returns the one that the user wants to find.
    friend bool sortByAge(const Person &lhs, const Person &rhs);                                    // Compares two ages of scientists and return from lowest to highest.
    friend bool sortByNameComputers(const computer &lhs, const computer &rhs);
    friend bool sortByDateComputers(const computer &lhs, const computer &rhs);
    friend bool sortByTypeComputers(const computer &lhs, const computer &rhs);
    void sortNames(vector<Person>& getPersons);                                                     // Sorts the vector by names of people.
    void sortBirth(vector<Person>& getPersons);                                                     // Sorts the vector by year of birth.
    void sortGender(vector<Person>& getPersons);                                                    // Sorts the vector by gender.
    void sortAge(vector<Person>& getPersons);                                                       // Sorts the vector by age.
    void sortNamesComputers(vector<computer>& com);
    void sortDateComputers(vector<computer>& com);
    void sortTypeComputers(vector<computer>& com);
    int stringToNumber(string st);                                                                  // Convert a string to a int.

    void readScientistsFromDatabase(vector<Person>& sci);
    void readComputersFromDatabase(vector<computer>& com);
    bool addScientist(string name, char gender, int yearOfBirth, int yearOfDeath, string comment, int vsize);
    bool addComputer(string name, string type, int yearbuilt, string isbuilt, int vsize);
    QSqlDatabase db;
 };

#endif // DATALAYER_H
