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
    std::getline(std::cin,name);
    cout << "Input gender (M/F): ";
    cin >> gender;
    cout << "Input year of birth: ";
    cin >> yearOfBirth;
    cout << "Input year of birth: ";
    cin >> yearOfDeath;

    data.writeToFile(name, gender, yearOfBirth, yearOfDeath);
}
