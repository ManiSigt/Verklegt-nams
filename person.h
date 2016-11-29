#ifndef PERSON_H
#define PERSON_H
#include <string>

using namespace std;

class Person
{
public:
    Person(string name, char gender, int birth, int death);
    friend class DataLayer;
private:
    string _name;
    char _gender;
    int _yearOfBirth;
    int _yearOfDeath;
};

#endif // PERSON_H
