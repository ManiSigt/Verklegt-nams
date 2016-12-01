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
    void deleteFile();                                                                              //delete the file amazingDataBase.txt
    void readFromFile(vector<Person>& getPersons);                                                  //reads the file into the vector getPersons
    void sortBirth(vector<Person>& getPersons);                                                     //sorts the vector by year of birth
    friend bool sortByAge(const Person &lhs, const Person &rhs);                                    //
    friend bool sortByName(const Person &lhs, const Person &rhs);                                   //
    friend bool sortByGender(const Person &lhs, const Person &rhs);                                 //
    void sortGender(vector<Person>& getPersons);                                                     //
    void sortNames(vector<Person>& getPersons);                                                     //sorts the vector by names of people
    int stringToNumber(string st);                                                                  //convert string to int
    void writeToFile(string name, char gender, int yearOfBirth, int yearOfDeath, string comment);   //writes person to the file amazingDataBase.txt
};

#endif // DATALAYER_H
