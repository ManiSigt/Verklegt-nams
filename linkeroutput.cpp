#include "linkeroutput.h"
#include <string>
#include <algorithm>
using namespace std;

LinkerOutput::LinkerOutput(string sciName, string compName)
{
    _sciName = sciName;
    _comName = compName;
    _lowercaseSciName = sciName;
    _lowercaseCompName = compName;

     transform(_lowercaseSciName.begin(), _lowercaseSciName.end(), _lowercaseSciName.begin(), ::tolower);
     transform(_lowercaseCompName.begin(), _lowercaseCompName.end(), _lowercaseCompName.begin(), ::tolower);
}
