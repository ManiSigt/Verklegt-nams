#include "computer.h"
#include <algorithm>
#include <string>

Computer::Computer()
{

}
Computer::Computer(string name, string wasItBuilt, int date, string type, int id)
{
    _name = name;
    _wasItBuilt = wasItBuilt;
    _date = date;
    _type = type;
    _id = id;
    _lowerCaseName = name;

    transform(_lowerCaseName.begin(), _lowerCaseName.end(), _lowerCaseName.begin(), ::tolower);
}
