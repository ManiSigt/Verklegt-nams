#include "listworker.h"
#include "datalayer.h"
#include <iostream>
#include <string>

using namespace std;

ListWorker::ListWorker()
{
    data.readScientistsFromDatabase(persons);
    data.readComputersFromDatabase(com);
}

void ListWorker::addNewPerson(string name, char gender, int yearOfBirth, int yearOfDeath, string comment)
{
    int vsize = personsSize()+1;
    Person p(name, gender, yearOfBirth, yearOfDeath, comment, vsize);
    persons.push_back(p);
    data.addScientist(name, gender, yearOfBirth, yearOfDeath, comment, vsize);
}
void ListWorker::addNewComputer(string name, string isbuilt, int yearbuilt, string type)
{
    int vsize = computerSize()+1;
    computer c(name, isbuilt, yearbuilt, type);
    com.push_back(c);
    data.addComputer(name, type, yearbuilt, isbuilt, vsize);
}
void ListWorker::sortNames()
{
    data.sortNames(persons);
}
void ListWorker::sortBirth()
{
    data.sortBirth(persons);
}
void ListWorker::sortGender()
{
    data.sortGender(persons);
}
void ListWorker::sortAge()
{
    data.sortAge(persons);
}
bool ListWorker::removePerson(string name)
{
    for(size_t i = 0; i < persons.size(); ++i)
    {
        if(name == persons[i]._getNamePerson())
        {
            persons.erase(persons.begin() + i);
            return true;
        }
    }
    return false;
}
bool ListWorker::removePersonFound(string name)
{
    for(size_t i = 0; i < persons.size(); ++i)
    {
        if(name == persons[i]._getNamePerson())
        {
            return true;
        }
    }
    return false;
}
int ListWorker::getNameSizePerson(int n) const
{
    string name = persons[n]._getNamePerson();
    int size = name.size();
    return size;
}
int ListWorker::getNameSizeComputer(int n) const
{
    string name = com[n]._getNameComputer();
    int size = name.size();
    return size;
}
bool ListWorker::nameSearcher(string name)
{
    for(unsigned int i = 0; i < persons.size(); i++)
    {
        std::size_t found = getNamePerson(i).find(name);
        if (found!=std::string::npos)
        {
            return true;
            break;
        }
    }
    return false;
}
bool ListWorker::genderSearcher(char gender)
{
    for(unsigned int i = 0; i < persons.size(); i++)
    {
        if(gender == getGenderPerson(i))
        {
             return true;
             break;
        }
    }
    return false;
}
bool ListWorker::typeSearcher(string type)
{
    for(unsigned int i = 0; i < com.size(); i++)
    {
        if(type == getTypeComputer(i))
        {
             return true;
             break;
        }
    }
    return false;
}

bool ListWorker::yearSearcher(int year)
{
    for(unsigned int i = 0; i < persons.size(); i++)
    {
        if(year == getBirthPerson(i))
        {
             return true;
             break;
        }
    }
    return false;
}
bool ListWorker::builtDateSearcher(int year)
{
    for(unsigned int i = 0; i < com.size(); i++)
    {
        if(year == getDateComputer(i))
        {
             return true;
             break;
        }
    }
    return false;
}

bool ListWorker::ageSearcher(int age)
{
    for(unsigned int i = 0; i < persons.size(); i++)
    {
        if(age == getAgePerson(i))
        {
             return true;
             break;
        }
    }
    return false;
}
