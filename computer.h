#ifndef COMPUTER_H
#define COMPUTER_H

#include <string>

using namespace std;

class Computer
{
public:
    Computer();
    Computer(string name, string wasItBuilt, int date, string type, int id); // Class constructor for variables.

    string _getNameComputer() const

    {
        return _name;
    }
    string _getTypeComputer() const
    {
        return _type;
    }
    string _getWasItBuiltComputer() const
    {
        return _wasItBuilt;
    }
    int _getDateComputer() const
    {
        return _date;
    }
    int _getNameSizeComputer()
    {
        return _name.size();
    }


private:
    string _name;
    string _type;
    string _wasItBuilt;
    int _date;
    int _id;

};

#endif // COMPUTER_H
