#include "datalayer.h"
#include <fstream>
#include <iostream>

using namespace std;

DataLayer::DataLayer()
{

}

void DataLayer::writeToFile(string name, char gender, int yearOfBirth, int yearOfDeath)
{
     ofstream myfile;
     myfile.open ("example.txt");
     myfile << name << endl;
     myfile << gender << endl;
     myfile << yearOfBirth << endl;
     myfile << yearOfDeath << endl;

     myfile.close();
}
