#include "datalayer.h"
#include "person.h"
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

DataLayer::DataLayer()
{

}

void DataLayer::writeToFile(string name, char gender, int yearOfBirth, int yearOfDeath)
{
     ofstream myfile("example.txt", ios::app);
     myfile << name << endl;
     myfile << gender << endl;
     myfile << yearOfBirth << endl;
     myfile << yearOfDeath << endl;

     myfile.close();
}

vector<Person> DataLayer::readFromFile()
{
    string line;
    string name = "1";       //notað til að tékka hvort búið sé að lesa inn nafnið.
    char gender = '1';
    int yearOfBirth = 1;
    int yearOfDeath = 1;
    ifstream myfile ("example.txt");
    if (myfile.is_open())
      {
        while ( getline (myfile,line) )
        {
          if(name == "1" && gender == '1' && yearOfBirth == 1 && yearOfDeath == 1)
          {
              name = line;
          }
          else if(name != "1" && gender == '1' && yearOfBirth == 1 && yearOfDeath == 1)
          {
              gender = line[0];
          }
          else if(name != "1" && gender != '1' && yearOfBirth == 1 && yearOfDeath == 1)
          {
              yearOfBirth = stoi(line);
          }
          else if(name != "1" && gender != '1' && yearOfBirth != 1 && yearOfDeath == 1)
          {

              yearOfDeath = stoi(line);
              Person p(name, gender, yearOfBirth, yearOfDeath);
              persons.push_back(p);
              name = "1";
              gender = '1';
              yearOfBirth = 1;
              yearOfDeath = 1;
          }
        }
        myfile.close();
      }
      else cout << "Unable to open file";
    for(unsigned int i = 0; i < persons.size(); i++)
    {
        cout << persons[i]._name << endl;
    }
    return persons;
}


