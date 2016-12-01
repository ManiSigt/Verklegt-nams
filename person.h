#ifndef PERSON_H
#define PERSON_H
#include <string>

using namespace std;

class Person
{
public:
    Person();
    Person(string name, char gender, int birth, int death, string comment);
    string _getName() const
    {
        return _name;
    }
    char _getGender() const
    {
        return _gender;
    }
    int _getBirth() const
    {
        return _yearOfBirth;
    }
    int _getDeath() const
    {
        return _yearOfDeath;
    }
    int _getNameSize()
    {
        return _name.size();
    }
    string _getComment() const
    {
        return _comment;
    }

private:
    string _name;
    string _comment;
    char _gender;
    int _yearOfBirth;
    int _yearOfDeath;

};

#endif // PERSON_H
