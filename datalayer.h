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
    vector<Person> readFromFile();
private:
    vector<Person> persons;
};

#endif // DATALAYER_H
