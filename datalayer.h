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

    void writeToFile(string name, char gender, int yearOfBirth, int yearOfDeath);
    void readFromFile(vector<Person>& getPersons);
    void sortNames(vector<Person>& getPersons);
    friend bool sortByName(const Person &lhs, const Person &rhs);
    void sortBirth(vector<Person>& getPersons);
    friend bool sortByAge(const Person &lhs, const Person &rhs);

};

#endif // DATALAYER_H
