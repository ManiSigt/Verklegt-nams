#ifndef DATALAYER_H
#define DATALAYER_H
#include <iostream>
#include <string>
#include <vector>

struct person{
    string _name;
    char _gender;
    int _yearOfBirth;
    int _yearOfDeath;
};

using namespace std;

class DataLayer
{
public:
    DataLayer();
    void writeToFile(string name, char gender, int yearOfBirth, int yearOfDeath);
    void readFromFile();
private;
    vector<person> persons;
};

#endif // DATALAYER_H
