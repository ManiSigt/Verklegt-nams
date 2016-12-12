#ifndef COMPUTER_H
#define COMPUTER_H

#include <string>

using namespace std;

class Computer
{
public:
    Computer();
    Computer(string name, string wasItBuilt, int date, string type, int id); // Class constructor for variables.
    string getComputerName() const
    {
        return _name;
    }
    string getComputerType() const
    {
        return _type;
    }
    string getComputerWasItBuilt() const
    {
        return _wasItBuilt;
    }
    int getComputerDate() const
    {
        return _date;
    }
    int getComputerNameSize()
    {
        return _name.size();
    }
    int getComputerId() const
    {
        return _id;
    }
    string getComputerLowerCaseName() const
    {
        return _lowerCaseName;
    }

private:
    string _name;
    string _lowerCaseName;
    string _type;
    string _wasItBuilt;
    int _date;
    int _id;

};

#endif // COMPUTER_H
