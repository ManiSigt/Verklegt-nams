#ifndef DATALAYER_H
#define DATALAYER_H
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct person{
    string _name = "1";
    char _gender = '1';
    int _yearOfBirth = 1;
    int _yearOfDeath = 1;
};


class DataLayer
{
public:
    DataLayer();
    void writeToFile(string name, char gender, int yearOfBirth, int yearOfDeath);
    void readFromFile();
private:
    vector<person> persons;
};

#endif // DATALAYER_H
