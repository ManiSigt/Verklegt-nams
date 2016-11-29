#include "datalayer.h"
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

void DataLayer::readFromFile()
{
    string line;
    int p = 0;
    persons.push_back(person());
    ifstream myfile ("example.txt");
    if (myfile.is_open())
      {
        while ( getline (myfile,line) )
        {

          cout << line << '\n';

          if(persons[p]._name == "1" && persons[p]._gender == '1' && persons[p]._yearOfBirth == 1 && persons[p]._yearOfDeath == 1)
          {
              persons.push_back(person());
              persons[p]._name = line;
          }
          else if(persons[p]._name != "1" && persons[p]._gender == '1' && persons[p].yearOfBirth == 1 && persons[p].yearOfDeath == 1)
          {
              persons[p]._gender = line[0];
          }
          else if(persons[p]._name != "1" && persons[p]._gender != '1' && persons[p]._yearOfBirth == 1 && persons[p].yearOfDeath == 1)
          {
              persons[p]._yearOfBirth = stoi(line);
          }
          else if(persons[p]._name != "1" && persons[p]._gender != '1' && persons[p]._yearOfBirth != 1 && persons[p]._yearOfDeath == 1)
          {
              persons[p]._yearOfDeath = stoi(line);
              p++;
          }
        }
        persons.pop_back();
        myfile.close();
      }
      else cout << "Unable to open file";

    for (unsigned int i = 0; i < persons.size(); i++)
    {
        cout << persons[i]._name << " " << persons[i]._gender << " " << persons[i]._yearOfBirth << " " << persons[i]._yearOfDeath << endl;
    }

}
