#ifndef DATALAYER_H
#define DATALAYER_H
#include "person.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class DataLayer
{
public:
    DataLayer();
    void deleteFile();
    void readFromFile(vector<Person>& getPersons);
    void sortBirth(vector<Person>& getPersons);
    friend bool sortByAge(const Person &lhs, const Person &rhs);
    friend bool sortByName(const Person &lhs, const Person &rhs);
    void sortNames(vector<Person>& getPersons);
    int stringToNumber(string st);
    void writeToFile(string name, char gender, int yearOfBirth, int yearOfDeath, string comment);
};

#endif // DATALAYER_H
