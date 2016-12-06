#include "computer.h"
#include <iostream>

using namespace std;

Computer::Computer()
{

}
Computer::Computer(string name, string wasItBuilt, int date, string type)
{
    _name = name;
    _wasItBuilt = wasItBuilt;
    _date = date;
    _type = type;

    cout << "name: " << name << " , type: " << type << " , date: " << date << " , wasItBuilt: " << wasItBuilt << endl;
}
