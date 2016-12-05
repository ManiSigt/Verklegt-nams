#include "computer.h"

computer::computer()
{

}
computer::computer(string name, char wasItBuilt, int date, string type)
{
    _name = name;
    _WasItBuilt = wasItBuilt;
    _date = date;
    _type = type;
}
