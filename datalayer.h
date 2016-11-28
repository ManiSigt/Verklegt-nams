#ifndef DATALAYER_H
#define DATALAYER_H
#include <iostream>
#include <string>

using namespace std;

class DataLayer
{
public:
    DataLayer();
    void writeToFile(string name, char gender, int yearOfBirth, int yearOfDeath);
    void readFromFile();
};

#endif // DATALAYER_H
