#ifndef LINKEROUTPUT_H
#define LINKEROUTPUT_H
#include <string>
using namespace std;

class LinkerOutput
{
public:
    LinkerOutput(string sciName, string compName);
    string getSciName() const
    {
        return _sciName;
    }
    string getCompName() const
    {
        return _comName;
    }
private:
    string _sciName;
    string _comName;
};

#endif // LINKEROUTPUT_H
