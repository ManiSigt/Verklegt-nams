#include "person.h"


Person::Person()
{

}

Person::Person(string name, char gender, int birth, int death)
{
    _name = name;
    _gender = gender;
    _yearOfBirth = birth;
    _yearOfDeath = death;
}
string Person::getName() const
{
    return _name;
}
char Person::getGender() const
{
    return _gender;
}
int Person::yearOfBirth() const
{
    return _yearOfBirth;
}
int Person::yearOfDeath() const
{
    return _yearOfDeath;
}



