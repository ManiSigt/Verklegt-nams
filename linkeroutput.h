#ifndef LINKEROUTPUT_H
#define LINKEROUTPUT_H
#include <string>
using namespace std;

class LinkerOutput
{
public:
    LinkerOutput(string sciName, string compName);  // Class constructor for variables.
    string getSciName() const
    {
        return _sciName;
    }
    string getCompName() const
    {
        return _comName;
    }
    string getSciNameLower() const
    {
        return _lowercaseSciName;
    }
    string getCompNameLower() const
    {
        return _lowercaseCompName;
    }

private:
    string _sciName;
    string _comName;
    string _lowercaseSciName;
    string _lowercaseCompName;

};

#endif // LINKEROUTPUT_H
