#include "listworker.h"
#include "datalayer.h"
#include <iostream>
#include <string>

using namespace std;

ListWorker::ListWorker()
{
    data.readFromFile(getPersons);
}

void ListWorker::addNewPerson()
{
    string name;
    char gender;
    int yearOfBirth = 0;
    int yearOfDeath = 0;

    cout << "Input Name: ";
    cin.ignore();
    std::getline(std::cin,name);
    cout << "Input gender (M/F): ";
    cin >> gender;
    if (gender == 'm' || gender == 'M' || gender == 'f' || gender == 'F')
    {
       cout << "Input year of birth: ";
       cin >> yearOfBirth;
       cout << "Input year of death: ";
       cin >> yearOfDeath;
    }
    else
    {
        cout << "Invalid gender! Try again." << endl;
        addNewPerson();
    }
    Person p(name, gender, yearOfBirth, yearOfDeath);
    getPersons.push_back(p);
    data.writeToFile(name, gender, yearOfBirth, yearOfDeath);
}

void ListWorker::viewAll()
{/*
    for(unsigned int i = 0; i < getPersons.size(); i++)
    {
        cout << "#########################################" << endl;
        cout << "\t" << "Name: " << getPersons[i].getName() << endl;
        cout << "\t" << "Gender: " << getPersons[i].getGender() << endl;
        cout << "\t" << "Year of birth: " << getPersons[i].getBirth() << endl;
        if(getPersons[i].getDeath() == 0)
        {
            cout << "\t" << "Year of death: Still kickin'"  << endl;
        }
        else
        {
            cout << "\t" << "Year of death: " << getPersons[i].getDeath() << endl;
        }
    }
    cout << "#########################################" << endl;
    cout << endl;
    */
}

void ListWorker::search()
{
    string searchChoice;
    cin >> searchChoice;
    if (searchChoice == "Name" || searchChoice == "name" || searchChoice == "NAME")
    {
            string namesearch;
            cout << "Enter a name you want to search for: ";
            cin >> namesearch;
            //if( std::find(getPersons.begin(), getPersons.end(), namesearch) != getPersons.end() )
              //cout << "We found the name you were looking for" << endl;
              //TODO: Setja inn þannig að allt prentist út tengt þessu nafni.
            //else
             //cout << "Sorry that name is not in our database, but you can add a new instance in the 'Add' section in the main menu" << endl;
    }
    else if (searchChoice == "Gender" || searchChoice == "GENDER" || searchChoice == "gender")
    {
            char gendersearch;
            cout << "Enter a Gender you want to search for: ";
            cin >> gendersearch;
            //if ( std::find(getPersons.begin(), getPersons.end(), gendersearch) != getPersons.end() )
               //cout << "We found the name you were looking for" << endl;
             // TODO: Setja inn þannig að allt prentist út tengt þessu kyni.
            //else
               //cout << "Sorry that gender is not in our database, but you can add a new instance in the 'Add' section in the main menu" << endl;
    }
    else if (searchChoice == "year" || searchChoice == "YEAR" || searchChoice == "Year")
    {
            int yearsearch;
            cout << "Enter a Year you want to search for: ";
            cin >> yearsearch;
            //if ( std::find(getPersons.begin(), getPersons.end(), yearsearch) != getPersons.end() )
              // cout << "We found the name you were looking for" << endl;
              // TODO: Setja inn þannig að allt prentist út tengt þessu fæðingarári.
            //else
              //cout << "Sorry that year is not in our database, but you can add a new instance in the 'Add' section in the main menu" << endl;
    }
    else
    {
        cout << "Error reading input" << endl;
    }
}

void ListWorker::sortNames()
{
    data.sortNames(getPersons);
}
void ListWorker::sortBirth()
{
    data.sortBirth(getPersons);
}
/*
void ListWorker::removePerson()
{
    string name;
    cout << "Enter a name of a person that you want to remove: ";
    getline(cin, name);

    for(size_t i = 0; i < getPersons.size(); ++i)
    {
        if(getPersons[i] == name)
        {
            getPersons.erase(getPersons.begin() + i);
            cout << "Person removed!" << endl;
        }
    }
  //  data.removeFromFile();

}
bool equals (const Person &lhs, const string name)
{
    return lhs.getName() == searchChoise;
}
*/