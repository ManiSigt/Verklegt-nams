#include "datalayer.h"
#include "person.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

DataLayer::DataLayer()
{

}
void DataLayer::writeToFile(string name, char gender, int yearOfBirth, int yearOfDeath, string comment)
{
     ofstream myfile("amazingDatabase.txt", ios::app);
     myfile << name << endl;
     myfile << gender << endl;
     myfile << yearOfBirth << endl;
     myfile << yearOfDeath << endl;
     myfile << comment << endl;
     myfile.close();
}
void DataLayer::readFromFile(vector<Person>& getPersons)
{
    string line;
    string name = "1";
    string comment = "1";
    char gender = '1';
    int yearOfBirth = 1;
    int yearOfDeath = 1;
    ifstream myfile ("amazingDatabase.txt");
    if (myfile.is_open())
      {
        while ( getline (myfile,line) )
        {
          if(name == "1" && gender == '1' && yearOfBirth == 1 && yearOfDeath == 1 && comment == "1")
          {
              name = line;
          }
          else if(name != "1" && gender == '1' && yearOfBirth == 1 && yearOfDeath == 1 && comment == "1")
          {
              gender = line[0];
          }
          else if(name != "1" && gender != '1' && yearOfBirth == 1 && yearOfDeath == 1 && comment == "1")
          {
              yearOfBirth = stringToNumber(line);
          }
          else if(name != "1" && gender != '1' && yearOfBirth != 1 && yearOfDeath == 1 && comment == "1")
          {
              yearOfDeath = stringToNumber(line);
          }
          else if(name != "1" && gender != '1' && yearOfBirth != 1 && yearOfDeath != 1 && comment == "1")
          {
              comment = line;
              Person p(name, gender, yearOfBirth, yearOfDeath, comment);
              getPersons.push_back(p);
              name = "1";
              gender = '1';
              yearOfBirth = 1;
              yearOfDeath = 1;
              comment = "1";
          }
        }
    myfile.close();
    }
    else cout << "Unable to open file!" << endl;
}
bool sortByName(const Person &lhs, const Person &rhs)
{
    return lhs._getName() < rhs._getName();
}
bool sortByBirth(const Person &lhs, const Person &rhs)
{
    return lhs._getBirth() < rhs._getBirth();
}
bool sortByGender(const Person &lhs, const Person &rhs)
{
    return lhs._getGender() < rhs._getGender();
}
bool sortByAge(const Person &lhs, const Person &rhs)
{
    return lhs._getAge() < rhs._getAge();
}
void DataLayer::sortNames(vector<Person>& getPersons)
{
    std::sort(getPersons.begin(),getPersons.end(), sortByName);
}
void DataLayer::sortBirth(vector<Person>& getPersons)
{
    std::sort(getPersons.begin(),getPersons.end(), sortByBirth);
}
void DataLayer::sortGender(vector<Person>& getPersons)
{
    std::sort(getPersons.begin(),getPersons.end(), sortByGender);
}
void DataLayer::sortAge(vector<Person>& getPersons)
{
    std::sort(getPersons.begin(),getPersons.end(), sortByAge);
}
void DataLayer::deleteFile()
{
    remove("amazingDatabase.txt");
    ofstream myfile;
    myfile.open("amazingDatabase.txt");
    myfile.close();
}
int DataLayer::stringToNumber(string st)
{
    string text = st;
    int value = atoi(text.c_str());
    return value;
}
