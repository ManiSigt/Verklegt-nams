#include "listworker.h"
#include "datalayer.h"
#include <iostream>
#include <string>

using namespace std;

ListWorker::ListWorker()
{
    data.readFromFile(persons);
}
void ListWorker::addNewPerson(string name, char gender, int yearOfBirth, int yearOfDeath, string comment)
{
    Person p(name, gender, yearOfBirth, yearOfDeath, comment);
    persons.push_back(p);
    data.writeToFile(name, gender, yearOfBirth, yearOfDeath, comment);
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
