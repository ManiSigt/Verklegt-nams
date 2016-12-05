#include "person.h"

Person::Person()
{

}
Person::Person(string name, char gender, int birth, int death, string comment)
{
    _name = name;
    _gender = gender;
    _yearOfBirth = birth;
    _yearOfDeath = death;
    _comment = comment;

    if(_yearOfDeath > 0)
    {
    _age = _yearOfDeath - _yearOfBirth;
    }
    else
    {
        _age = 2016 - _yearOfBirth;
    }
}
