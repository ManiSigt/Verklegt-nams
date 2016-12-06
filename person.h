#ifndef PERSON_H
#define PERSON_H
#include <string>

using namespace std;

class Person
{
public:
    Person();
    Person(string name, char gender, int birth, int death, string comment, int id); // Class constructor for variables.
    string _getNamePerson() const
    {
        return _name;
    }
    string _getCommentPerson() const
    {
        return _comment;
    }
    char _getGenderPerson() const
    {
        return _gender;
    }
    int _getBirthPerson() const
    {
        return _yearOfBirth;
    }
    int _getDeathPerson() const
    {
        return _yearOfDeath;
    }
    int _getNameSizePerson()
    {
        return _name.size();
    }
    int _getAgePerson() const
    {
        return _age;
    }
    int _getIDPerson() const
    {
        return _id;
    }


private:
    string _name;
    string _comment;
    char _gender;
    int _yearOfBirth;
    int _yearOfDeath;
    int _age;
    int _id;

};

#endif // PERSON_H
