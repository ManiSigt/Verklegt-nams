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

}
