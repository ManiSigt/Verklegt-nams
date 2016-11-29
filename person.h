#ifndef PERSON_H
#define PERSON_H
#include <string>

using namespace std;

class Person
{
public:
    Person();
    Person(string name, char gender, int birth, int death);
    friend class DataLayer;
    string getName() const;
    char getGender() const;
    int yearOfBirth() const;
    int yearOfDeath() const;
private:
    string _name;
    char _gender;
    int _yearOfBirth;
    int _yearOfDeath;
};

#endif // PERSON_H
