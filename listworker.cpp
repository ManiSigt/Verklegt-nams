#include "listworker.h"
#include "datalayer.h"
#include <iostream>
#include <string>

using namespace std;

ListWorker::ListWorker()
{
    data.readScientistsFromDatabase(persons);
}
void ListWorker::addNewPerson(string name, char gender, int yearOfBirth, int yearOfDeath, string comment)
{
    int vsize = personsSize()+1;
    Person p(name, gender, yearOfBirth, yearOfDeath, comment, vsize);
    persons.push_back(p);
    data.addScientist(name, gender, yearOfBirth, yearOfDeath, comment, vsize);
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
        if(name == persons[i]._getName())
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
        if(name == persons[i]._getName())
        {
            return true;
        }
    }
    return false;
}
int ListWorker::getNameSize(int n) const
{
    string name = persons[n]._getName();
    int size = name.size();
    return size;
}
void ListWorker::saveFile()
{
    string saveName, saveComment;
    char saveGender;
    int saveYearOfBirth, saveYearOfDeath;
    data.deleteFile();

    for(unsigned int i = 0; i < persons.size(); i++)
    {
        saveName = getName(i);
        saveGender = getGender(i);
        saveYearOfBirth = getBirth(i);
        saveYearOfDeath = getDeath(i);
        saveComment = getComment(i);
        data.writeToFile(saveName, saveGender, saveYearOfBirth, saveYearOfDeath, saveComment);
    }
}
bool ListWorker::nameSearcher(string name)
{
    for(unsigned int i = 0; i < persons.size(); i++)
    {
        std::size_t found = getName(i).find(name);
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
        if(gender == getGender(i))
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
        if(type == getType(i))
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
        if(year == getBirth(i))
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
        if(year == getBuiltDate(i))
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
        if(age == getAge(i))
        {
             return true;
             break;
        }
    }
    return false;
}
