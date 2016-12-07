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
        if(name == persons[i]._getNamePerson())
        {
            persons.erase(persons.begin() + i);
            data.removeScientist(name);
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
bool ListWorker::removeComputer(string name)
{
    for(size_t i = 0; i < com.size(); ++i)
    {
        if(name == com[i]._getNameComputer())
        {

            com.erase(com.begin() + i);
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
        if(name == com[i]._getNameComputer())
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
bool ListWorker::computerNameSearcher(string name)
{
    for(int i = 0; i < computerSize(); i++)
    {
        std::size_t found = getNameComputer(i).find(name);
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
        std::size_t found = getTypeComputer(i).find(type);
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
int ListWorker::computerIdFinder()
{
    int idValue;

    for (int i = 1; i <= computerSize(); i++)
    {
        if(i != getIdComputer(i-1))
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
        if(i != getPersonId(i-1))
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
        if(n == getIdComputer(i))
        {
            name = com[i]._getNameComputer();
        }
    }
    return name;
}
string ListWorker::getScientistNameFromId(int n) const
{
    string name;
    for(unsigned int i = 0; i < persons.size(); i++)
    {
        if(n == persons[i]._getIDPerson())
        {
            name = persons[i]._getNamePerson();
        }
    }
    return name;
}
void ListWorker::removeConnection(string scientist, string computer)
{

}
