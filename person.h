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

    string getName() const
    {
        return _name;
    }
    int getGender() const
    {
        return _gender;
    }
    int getBirth() const
    {
        return _yearOfBirth;
    }
    int getDeath() const
    {
        return _yearOfDeath;
    }



private:
    string _name;
    char _gender;
    int _yearOfBirth;
    int _yearOfDeath;
};

#endif // PERSON_H
