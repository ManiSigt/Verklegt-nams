#ifndef COMPUTER_H
#define COMPUTER_H

#include <string>

using namespace std;

class computer
{
public:
    computer();
    computer(string name, char wasItBuilt, int date, string type); // Class constructor for variables.
    string _getName() const
    {
        return _name;
    }
    string _getType() const
    {
        return _type;
    }
    char _getWasItBuilt() const
    {
        return _WasItBuilt;
    }
    int _getDate() const
    {
        return _date;
    }

    int _getNameSize()
    {
        return _name.size();
    }


private:
    string _name;
    string _type;
    char _WasItBuilt;
    int _date;

};

#endif // COMPUTER_H
