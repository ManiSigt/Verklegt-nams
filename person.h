#ifndef PERSON_H
#define PERSON_H
#include <string>

using namespace std;

class Person
{
public:
    Person();
    Person(string name, char gender, int birth, int death, string comment, int id); // Class constructor for variables.
    string _getName() const
    {
        return _name;
    }
    string _getComment() const
    {
        return _comment;
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
    int _getAge() const
    {
        return _age;
    }
    int _getID() const
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
