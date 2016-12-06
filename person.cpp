#include "person.h"

Person::Person()
{

}
Person::Person(string name, char gender, int birth, int death, string comment, int id)
{
    _name = name;
    _gender = gender;
    _yearOfBirth = birth;
    _yearOfDeath = death;
    _comment = comment;
    _id = id;

    if(_yearOfDeath > 0)
    {
    _age = _yearOfDeath - _yearOfBirth;
    }
    else
    {
        _age = 2016 - _yearOfBirth;
    }
}
