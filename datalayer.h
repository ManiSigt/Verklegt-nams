#ifndef DATALAYER_H
#define DATALAYER_H
#include "person.h"
#include <vector>

class DataLayer
{
public:
    DataLayer();
    void writeToFile(string name, char gender, int yearOfBirth, int yearOfDeath, string comment);   // Writes person to the file amazingDataBase.txt.
    void readFromFile(vector<Person>& getPersons);                                                  // Reads the file into the vector persons.
    friend bool sortByName(const Person &lhs, const Person &rhs);                                   // Compares two names and returns the one that is lower in alphabetical order.
    friend bool sortByAge(const Person &lhs, const Person &rhs);                                    // Compares two years and returns the one that is lower in chronological order.
    friend bool sortByGender(const Person &lhs, const Person &rhs);                                 // Compares the two genders and just returns the one that the user wants to find.
    void sortNames(vector<Person>& getPersons);                                                     // Sorts the vector by names of people.
    void sortBirth(vector<Person>& getPersons);                                                     // Sorts the vector by year of birth.
    void sortGender(vector<Person>& getPersons);                                                    // Sorts the vector by gender
    void deleteFile();                                                                              // Delete the file amazingDataBase.txt.
    int stringToNumber(string st);                                                                  // Convert a string to a int.
 };

#endif // DATALAYER_H
