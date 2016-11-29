#include "listworker.h"
#include "datalayer.h"
#include <iostream>
#include <string>

using namespace std;

ListWorker::ListWorker()
{

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
    data.writeToFile(name, gender, yearOfBirth, yearOfDeath);
}

void ListWorker::viewAll()
{
    getPersons = data.readFromFile();
}


