#include "listworker.h"
#include "datalayer.h"
#include <iostream>
#include <string>

using namespace std;

ListWorker::ListWorker()
{
    data.readScientistsFromDatabase(persons);
    data.readComputersFromDatabase(com);
    data.readLinksFromDatabase(link);
}

void ListWorker::addNewPerson(string name, char gender, int yearOfBirth, int yearOfDeath, string comment)
{
    int vsize = scientistIdFinder();
    Person p(name, gender, yearOfBirth, yearOfDeath, comment, vsize);
    persons.push_back(p);
    data.addScientist(name, gender, yearOfBirth, yearOfDeath, comment, vsize);
}
void ListWorker::addNewComputer(string name, string type, int yearbuilt, string isbuilt)
{
    int vsize = computerIdFinder();
    Computer c(name, isbuilt, yearbuilt, type, vsize);
    com.erase (com.begin(),com.end());
    data.addComputer(name, type, yearbuilt, isbuilt, vsize);
}
void ListWorker::addNewConnection(int linkId, int compId, int sciId)
{

    Linker l(linkId, sciId, compId);
    link.push_back(l);

    data.addConnection(linkId, sciId, compId);
}


void ListWorker::sortScientistNames()
{
    data.sortScientistNames(persons);
}
void ListWorker::sortScientistBirth()
{
    data.sortScientistBirth(persons);
}
void ListWorker::sortScientistGender()
{
    data.sortScientistGender(persons);
}
void ListWorker::sortScientistAge()
{
    data.sortScientistAge(persons);
}
void ListWorker::sortComputerName()
{
    data.sortNamesComputers(com);
}
void ListWorker::sortComputerDate()
{
    data.sortDateComputers(com);
}
void ListWorker::sortComputerType()
{
    data.sortTypeComputers(com);
}
bool ListWorker::removePerson(string name)
{
    for(size_t i = 0; i < persons.size(); ++i)
    {
        if(name == persons[i].getScientistName())
        {
            persons.erase(persons.begin() + i);
            removeConnection(i,0);
            data.removeScientist(name);
            return true;
        }
    }
    return false;
}
void ListWorker::removeConnection(int s, int c)
{
    if(c == 0)
    {
        int removeId = getScientistId(s);
        for(int i = 0; i < getLinkSize()+2; i++)
        {
            if(removeId == getLinkSciId(i))
            {
                int linkId = getLinkId(i);
                link.erase(link.begin() + i);
                data.removeConnection(linkId);
            }
        }
    }
    else
    {
        int removeId = getComputerId(c);
        for(int i = 0; i < getLinkSize()+2; i++)
        {
            if(removeId == getLinkCompId(i))
            {
                int linkId = getLinkId(i);
                link.erase(link.begin() + i);
                data.removeConnection(linkId);
            }
        }
    }
}

bool ListWorker::removePersonFound(string name)
{
    for(size_t i = 0; i < persons.size(); ++i)
    {
        if(name == persons[i].getScientistName())
        {
            return true;
        }
    }
    return false;
}
bool ListWorker::removeComputer(string name)
{
    for(size_t i = 0; i < com.size(); ++i)
    {
        if(name == com[i].getComputerName())
        {

            com.erase(com.begin() + i);
            removeConnection(0,i);
            data.removeComputer(name);
            return true;
        }
    }
    return false;
}
bool ListWorker::removeComputerFound(string name)
{
    for(size_t i = 0; i < com.size(); ++i)
    {
        if(name == com[i].getComputerName())
        {
            return true;
        }
    }
    return false;
}
int ListWorker::getScientistNameSize(int n) const
{
    string name = persons[n].getScientistName();
    int size = name.size();
    return size;
}
int ListWorker::getComputerNameSize(int n) const
{
    string name = com[n].getComputerName();
    int size = name.size();
    return size;
}
bool ListWorker::nameSearcher(string name)
{
    for(unsigned int i = 0; i < persons.size(); i++)
    {
        std::size_t found = getScientistName(i).find(name);
        if (found!=std::string::npos)
        {
            return true;
            break;
        }
    }
    return false;
}
bool ListWorker::computerNameSearcher(string name)
{
    for(int i = 0; i < computerSize(); i++)
    {
        std::size_t found = getComputerName(i).find(name);
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
        if(gender == getScientistGender(i))
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
        std::size_t found = getComputerType(i).find(type);
        if (found!=std::string::npos)
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
        if(year == getScientistBirth(i))
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
        if(year == getComputerDate(i))
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
        if(age == getScientistAge(i))
        {
             return true;
             break;
        }
    }
    return false;
}
int ListWorker::computerIdFinder()
{
    int idValue;

    for (int i = 1; i <= computerSize(); i++)
    {
        if(i != getComputerId(i-1))
        {
            return i;
        }
        else
        {
            idValue = i + 1;
        }
    }
    return idValue;
}
int ListWorker::scientistIdFinder()
{
    int idValue;

    for (int i = 1; i <= personsSize(); i++)
    {
        if(i != getScientistId(i-1))
        {
            return i;
        }
        else
        {
            idValue = i;
        }
    }
    return idValue;
}
void ListWorker::refreshVector()
{
    com.erase (com.begin(),com.end());
    data.readComputersFromDatabase(com);
    persons.erase (persons.begin(),persons.end());
    data.readScientistsFromDatabase(persons);
}
string ListWorker::getComputerNameFromId(int n) const
{
    string name;
    for(unsigned int i = 0; i < com.size(); i++)
    {
        if(n == getComputerId(i))
        {
            name = com[i].getComputerName();
        }
    }
    return name;
}
string ListWorker::getScientistNameFromId(int n) const
{
    string name;
    for(unsigned int i = 0; i < persons.size(); i++)
    {
        if(n == persons[i].getScientistId())
        {
            name = persons[i].getScientistName();
        }
    }
    return name;
}
