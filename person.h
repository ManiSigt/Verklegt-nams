#ifndef PERSON_H
#define PERSON_H
#include <string>

using namespace std;

class Person
{
public:
    Person();
    Person(string name, char gender, int birth, int death, string comment, int id); // Class constructor for variables.
    string getScientistName() const
    {
        return _name;
    }
    string getScientistComment() const
    {
        return _comment;
    }
    char getScientistGender() const
    {
        return _gender;
    }
    int getScientistBirth() const
    {
        return _yearOfBirth;
    }
    int getScientistDeath() const
    {
        return _yearOfDeath;
    }
    int getNameSizePerson()
    {
        return _name.size();
    }
    int getScientistAge() const
    {
        return _age;
    }
    int getScientistId() const
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
