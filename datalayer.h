#ifndef DATALAYER_H
#define DATALAYER_H
#include "person.h"
#include "computer.h"
#include "linker.h"
#include "images.h"
#include <vector>
#include <Qtsql>
#include "linkeroutput.h"

class DataLayer
{
public:
    DataLayer();
    void sortConnectionsBySciName(vector<LinkerOutput>& linkout);                                               // Sorts connections between scientist and computers in ascending order by scientist name.
    void sortConnectionsByCompName(vector<LinkerOutput>& linkout);                                              // Sorts connections between scientist and computers in ascending order by computer name.
    void sortConnectionsBySciNameDesc(vector<LinkerOutput>& linkout);                                           // Sorts connections between scientist and computers in descending order by scientist name.
    void sortConnectionsByCompNameDesc(vector<LinkerOutput>& linkout);                                          // Sorts connections between scientist and computers in descending order by computer name.
    void searchConnectionsByComp(vector<LinkerOutput>& linkout, int sciId);                                     // Searches the database for connections between scientists and computers.
    void searchConnectionsBySci(vector<LinkerOutput>& linkout, int compId);                                     // Searches the database for connections between computers and scientists.
    void sortNamesComputers(vector<Computer>& com);                                                             // Sorts the vector com in ascending alphabetical order.
    void sortNamesComputersReverse(vector<Computer>& com);                                                      // Sorts the vector com in descending alphabetical order.
    void sortTypeComputers(vector<Computer>& com);                                                              // Sorts the vector com after computer type.
    void sortDateComputers(vector<Computer>& com);                                                              // Sorts the vector com in ascending chronological order.
    void sortDateComputersReverse(vector<Computer>& com);                                                       // Sorts the vector com in desending chronological order.
    void sortScientistNames(vector<Person>& getPersons);                                                        // Sorts the vector person in acsending alphabetical order.
    void sortScientistNamesReverse(vector<Person>& getPersons);                                                 // Sorts the vector person in desending alphabetical order.
    void sortScientistBirth(vector<Person>& getPersons);                                                        // Sorts the vector person in ascending chronological order.
    void sortScientistBirthReverse(vector<Person>& getPersons);                                                 // Sorts the vector person in descending chronological order.
    void sortScientistGender(vector<Person>& getPersons);                                                       // Sorts the vector person by gender.
    void sortScientistAge(vector<Person>& getPersons);                                                          // Sorts the vector person by age.
    void deleteFile();                                                                                          // Delete the file amazingDataBase.txt.
    void removeConnection(int sciId, int compId);                                                               // Removes connection from SQL database
    void removeComputer(string name);                                                                           // Removes computer from SQL database.
    void removeScientist(string name);                                                                          // Removes scientist from SQL database.
    void removeConnection(int id);                                                                              // Removes connection from SQL database
    void readLinksFromDatabase(vector<Linker>& link);                                                           // Adds the links between computers and scientists to the vector link.
    void readScientistsFromDatabase(vector<Person>& sci);                                                       // Adds the computers from the SQL database to the vector com.
    void readComputersFromDatabase(vector<Computer>& com);                                                      // Adds the scientists from the SQL database to the vector person.
    void addImage(QString fileName, int sciId, int comId);
    void readImagesFromDatabase(vector<Images>& img);
    void updateImage(QString fileName, int id);
    bool addScientist(string name, char gender, int yearOfBirth, int yearOfDeath, string comment, int vsize);   // Adds a scientist to the SQL database.
    void addComputer(string name, string type, int yearbuilt, string isbuilt, int vsize);                       // Adds a computer to the SQL databse.
    void addConnection(int linkId, int sciId, int compId);                                                      // Adds a connection from to the SQL databse.
    void updateScientist(string name, char gender, int yearOfBirth, int yearOfDeath, string comment, int sciId);// Updates a scientist in the database with new info.
    void updateComputer(string name, string type, string isbuilt, int Yearbuilt, int compId);                   // Updates a computer in the database with new info.
    void updateConnection(int currentId,int sciId,int comId);
    friend bool sortByNameComputers(const Computer &lhs, const Computer &rhs);                                  // Compares two instances of name in the vector com and returns the one that is lower in alphabetical order.
    friend bool sortByNameComputersReverse(const Computer &lhs, const Computer &rhs);                           // Compares two instances of name in the vector com and returns the one that is higher in alphabetical order.
    friend bool sortByDateComputers(const Computer &lhs, const Computer &rhs);                                  // Compares two instances of date in the vector com and returns the one that is lower in chronological order.
    friend bool sortByDateComputersReverse(const Computer &lhs, const Computer &rhs);                           // Compares two instances of date in the vector com and returns the one that is higher in chronological order.
    friend bool sortByTypeComputers(const Computer &lhs, const Computer &rhs);                                  // Compares two instances of type in the vector com and returns the type order alphabetically.
    friend bool sortByScientistName(const Person &lhs, const Person &rhs);                                      // Compares two instances of name in the vector person and returns the one that is lower in alphabetical order.
    friend bool sortByScientistNameReverse(const Person &lhs, const Person &rhs);                               // Compares two instances of name in the vector person and returns the one that is higher in alphabetical order.
    friend bool sortByScientistBirth(const Person &lhs, const Person &rhs);                                     // Compares two instances of birth in the vector person and returns the one that is lower in chronological order.
    friend bool sortByScientistBirthReverse(const Person &lhs, const Person &rhs);                              // Compares two instances of birth in the vector person and returns the one that is higher in chronological order.
    friend bool sortByScientistGender(const Person &lhs, const Person &rhs);                                    // Compares the two instances of gender in the vector person and just returns the one that the user wants to find.
    friend bool sortByScientistAge(const Person &lhs, const Person &rhs);                                       // Compares two instances of age in the vector person of scientists and returns from lowest to highest.
    int stringToNumber(string st);                                                                              // Convert a string to a int.
    QSqlDatabase db;
 };

#endif // DATALAYER_H
