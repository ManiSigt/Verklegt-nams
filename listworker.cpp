#include "listworker.h"
#include "datalayer.h"
#include "linkeroutput.h"
#include <iostream>
#include <string>
#include <QDebug>
#include <QString>

using namespace std;

ListWorker::ListWorker()
{
    data.readScientistsFromDatabase(persons);
    data.readComputersFromDatabase(com);
    data.readLinksFromDatabase(link);
    data.readImagesFromDatabase(img);
}
bool ListWorker::addNewScientist(string name, char gender, int yearOfBirth, int yearOfDeath, string comment, QString fileName)
{
    int vsize = scientistIdFinder();
    Person p(name, gender, yearOfBirth, yearOfDeath, comment, vsize);
    persons.push_back(p);
    data.addScientist(name, gender, yearOfBirth, yearOfDeath, comment, vsize);

    if(fileName != "0")
    {
        data.addImage(fileName, vsize, 0);
    }
    return true;
}
bool ListWorker::removeConnectionById(int id)
{
    data.removeConnection(id);
    return true;
}
bool ListWorker::addNewComputer(string name, string type, int yearbuilt, string isbuilt, QString fileName)
{
    int vsize = computerIdFinder();
    Computer c(name, isbuilt, yearbuilt, type, vsize);
    com.erase (com.begin(),com.end());
    data.addComputer(name, type, yearbuilt, isbuilt, vsize);

    if(fileName != "0")
    {
        data.addImage(fileName, 0, vsize);
    }
    return true;
}
bool ListWorker::addNewConnection(int compId, int sciId)
{
    int linkId;

    if(getLinkSize() == 0)
    {
        linkId = 1;
    }
    else
    {
        for(int i = 1; i < getLinkSize()+2; i++)
        {
            if(i != getLinkId(i))
            {
                linkId = i;
            }
        }
    }

    Linker l(linkId, sciId, compId);
    link.push_back(l);
    data.addConnection(linkId, sciId, compId);

    return true;
}
void ListWorker::sortScientistNames()
{
    data.sortScientistNames(persons);
}
void ListWorker::sortScientistNamesReverse()
{
    data.sortScientistNamesReverse(persons);
}
void ListWorker::sortScientistBirth()
{
    data.sortScientistBirth(persons);
}
void ListWorker::sortScientistBirthReverse()
{
    data.sortScientistBirthReverse(persons);
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
void ListWorker::sortComputerNameReverse()
{
    data.sortNamesComputersReverse(com);
}
void ListWorker::sortComputerDate()
{
    data.sortDateComputers(com);
}
void ListWorker::sortComputerDateReverse()
{
    data.sortDateComputersReverse(com);
}
void ListWorker::sortComputerType()
{
    data.sortTypeComputers(com);
}
bool ListWorker::removePerson(int rowNumber)
{
    string name = getScientistNameFromId(rowNumber);
    QString qname = QString::fromStdString(name);

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
bool ListWorker::removeConnection(int s, int c)
{
    if(c == 0)
    {
        int removeId = getScientistId(s);
        QString qbirth = QString::number(removeId);
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

    return true;
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
bool ListWorker::removeComputer(int rownumber)
{
    string name = getComputerNameFromId(rownumber);

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
        std::size_t found = getScientistLowerCaseName(i).find(name);

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
        std::size_t found = getComputerLowerCaseName(i).find(name);

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

    for (int i = 1; i < personsSize()+1; i++)
    {
        if(i != getScientistId(i-1))
        {
            return i;
        }
        else
        {
            idValue = i+1;
        }
    }

    return idValue;
}
void ListWorker::refreshVector()
{
    data.readComputersFromDatabase(com);
    persons.erase (persons.begin(),persons.end());
    data.readScientistsFromDatabase(persons);
    link.erase(link.begin(),link.end());
    linkout.erase(linkout.begin(),linkout.end());
    data.readLinksFromDatabase(link);
    img.erase(img.begin(),img.end());
    data.readImagesFromDatabase(img);
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
int ListWorker::getComputerIdFromName(string name) const
{
    int id;

    for(unsigned int i = 0; i < com.size(); i++)
    {
        if(name == com[i].getComputerName())
        {
            id = com[i].getComputerId();
        }
    }

    return id;
}
int ListWorker::getScientistIdFromName(string name) const
{
    int id;
    string check;

    for(int i = 0; i < personsSize(); i++)
    {
       check = getScientistName(i);
        if(name == check)
        {
            id = getScientistId(i);
        }
    }

    return id;
}
int ListWorker::getLinkIdFromSciComIds(int sciId, int comId) const
{
    int id;

    for(unsigned int i = 0; i < link.size(); i++)
    {
        if(getLinkCompId(i) == comId && getLinkSciId(i) == sciId)
        {
            id = getLinkId(i);
        }
    }

    return id;
}
bool ListWorker::updateConnection(int currentId, int sciId, int comId)
{
    data.updateConnection(currentId,sciId,comId);

    return true;
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
void ListWorker::removeConnection(string scientist, string computer)
{
    int scientId;
    int compId;

    for(int i = 0; i < personsSize(); i++)
    {
        if(scientist == getScientistName(i))
        {
            scientId = getScientistId(i);
        }
    }

    for(int j = 0; j < computerSize(); j++)
    {
        if(computer == getComputerName(j))
        {
            compId = getComputerId(j);
        }
    }

    data.removeConnection(scientId, compId);
}
void ListWorker::sortConnections(string selection)
{
    if (selection == "1")
    {
        data.sortConnectionsBySciName(linkout);
    }
    else if(selection == "2")
    {
        data.sortConnectionsBySciNameDesc(linkout);
    }
    else if(selection == "3")
    {
        data.sortConnectionsByCompName(linkout);
    }
    else if(selection == "4")
    {
        data.sortConnectionsByCompNameDesc(linkout);
    }
}
int ListWorker::getLinkoutputCompNameSize(int n)
{
    string name = linkout[n].getCompName();
    int size = name.size();

    return size;
}
bool ListWorker::updateScientist(string name,char gender, int birth, int death, string comment, int sciId, QString fileName)
{
    int found = 0;
    data.updateScientist(name,gender,birth,death,comment,sciId);

    for(unsigned int i = 0; i < img.size(); i++)
    {
        int id = img[i].getId();

        if(sciId == img[i].getSciId())
        {
            qDebug() << id << sciId << img[i].getSciId();
            data.updateImage(fileName, id);
            found++;
        }
    }

    if (found == 0)
        {
            data.addImage(fileName,sciId, 0);
        }

    return true;
}
bool ListWorker::updateComputer(string name, string type, string isbuilt, int Yearbuilt, int compId, QString fileName)
{
    int found = 0;
    data.updateComputer(name, type, isbuilt, Yearbuilt, compId);

    for(unsigned int i = 0; i < img.size(); i++)
    {
        int id = img[i].getId();

        if(compId == img[i].getComId())
        {
            data.updateImage(fileName, id);
            found++;
        }
    }

    if (found == 0)
        {
            data.addImage(fileName,0, compId);
        }

    return true;
}
void ListWorker::searchConnectionsByComp(int n)
{
    data.searchConnectionsByComp(linkout,n);
}
void ListWorker::searchConnectionsBySci(int n)
{
    data.searchConnectionsBySci(linkout,n);
}
void ListWorker::eraser()
{
    com.erase(com.begin(),com.end());
    linkout.erase(linkout.begin(),linkout.end());
}
int ListWorker::getImageSci(int sciId)
{
    int result;
    int found = 0;

    for(size_t i = 0; i < img.size(); i++)
    {
        if(sciId == img[i].getSciId())
        {
            result = i;
            found++;
        }
    }

    if(found == 0)
    {
        result = 12;
    }

    return result;
}
int ListWorker::getImageCom(int comId)
{
    int result;
    int found = 0;

    for(size_t i = 0; i < img.size(); i++)
    {
        if(comId == img[i].getComId())
        {
            result = i;
            found++;
        }
    }

    if(found == 0)
    {
        result = 0;
    }

    return result;
}
