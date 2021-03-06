#include "classui.h"
#include "listworker.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <time.h>

using namespace std;
const int maxTries = 5; // A number for hangman, used for how many tries you got left.
const int maxArraySize = 25; // A number for hangman, used for an array that takes in the input from the user.

ClassUI::ClassUI()
{

}
void ClassUI::mainMenu()
{
    if (firstRun == true)
    {
        cout << "\t" << "Welcome to the Amazing Database! " << endl;
        cout << "--------------------------------------------------------------" << endl;
        cout << "\t" << "   *** Quote of the day ***" << endl;
        cout << getQuotes() << endl;
        firstRun = false;
    }
    string choice;
    do
    {
        list.refreshVector();
        cout << "--------------------------------------------------------------" << endl;
        cout << " (1) - "  << "Add to the database." << endl;
        cout << " (2) - "  << "Remove from the database." << endl;
        cout << " (3) - "  << "View." << endl;
        cout << " (4) - "  << "Search." << endl;
        cout << " (5) - "  << "Edit database." << endl;
        cout << " (6) - "  << "Play hangman." << endl;
        cout << " (7) - "  << "Exit." << endl;
        cout << "Enter your command (1 - 7): ";
        cin >> choice;
        if (choice != "7")
        {
           select(choice);
        }
        else
        {
            runOn = false;
        }

    }while(runOn == true);

    cout << endl;
}
void ClassUI::select(string ch)
{
    if(ch == "1")
    {  
        string choice;
        cout << " (1) - Add a scientist." << endl;
        cout << " (2) - Add a computer." << endl;
        cout << " (3) - Add a connection between computer and scientist." << endl;
        cout << " (4) - Return to main menu." << endl;
        cout << "Enter your command (1 - 4): ";
        cin >> choice;

        if (choice == "1")
        {
            cin.ignore();           // When using editScientist it will ignore the first letter unless this ignore is here rather then in addScientist
            addScientist();
        }
            else if (choice == "2")
        {
            cin.ignore();
            addComputer();
        }
            else if (choice == "3")
        {
            cin.ignore();
            addConnection();
        }
            else if (choice == "4")
        {
            clearTheScreen();

            return mainMenu();
        }
            else
        {
            cout << "Invalid input. Please enter a number between 1 - 4." << endl;
            select("1");
        }
    }
    else if(ch == "2")
    {
        string choice;
        cout << " (1) - Remove scientist." << endl;
        cout << " (2) - Remove computer." << endl;
        cout << " (3) - Return to main menu." << endl;
        cout << "Enter your command (1 - 3): ";
        cin >> choice;
        if (choice == "1")
        {
            removeScientist();
        }
        else if (choice == "2")
        {
            removeComputer();
        }
        else if (choice == "3")
        {
            clearTheScreen();
            return mainMenu();
        }
        else
        {
            cout << "Invalid input. Please enter a number between 1 - 3." << endl;
            select("2");
        }
    }
    else if(ch == "3")
    {
        viewMenu();
    }
    else if(ch == "4")
    {
        selectSearch();
    }
    else if(ch == "5")
    {
        string choice;
        cout << " (1) - Edit a scientist." << endl;
        cout << " (2) - Edit a computer." << endl;
        cout << " (3) - Return to main menu." << endl;
        cout << "Enter your command (1 - 3): ";
        cin >> choice;
        if (choice == "1")
        {
            editScientist();
        }
        else if (choice == "2")
        {
            editComputer();
        }
        else if (choice == "3")
        {
            clearTheScreen();
            return mainMenu();
        }
        else
        {
            cout << "Invalid input. Please enter a number between 1 - 3." << endl;
            select("5");
        }
    }
    else if (ch == "6")
    {
        hangman();
    }
    else if(ch == "yo")
    {
        yo();
    }
    else
    {
        cout << "Invalid input. Please enter a number between 1 - 7." << endl;
    }
}
void ClassUI::viewScientist(int i)
{
    cout << "--------------------------------------------------------------" << endl;
    int nameSize  = list.getScientistNameSize(i);

    cout << list.getScientistName(i);

    if(nameSize > 0 && nameSize <= 7)
    {
        cout << "\t" << "\t" << "\t" << "\t";
    }
    else if(nameSize > 7 && nameSize <= 15)
    {
        cout << "\t" << "\t" << "\t";
    }
    else if(nameSize > 15 && nameSize <= 23)
    {
        cout << "\t" << "\t";
    }
    else if(nameSize > 23 && nameSize <= 31)
    {
        cout << "\t";
    }

    if(list.getScientistGender(i) == 'M' || list.getScientistGender(i) == 'm')
    {
        cout << "|Male" << "\t";
    }
    else
    {
        cout << "|Female" << "\t";
    }

    cout  << "|" << list.getScientistBirth(i);

    if(list.getScientistDeath(i) == 0)
    {
        cout << "\t" << "| n/a"  << "\t" << "|" << list.getScientistAge(i) << endl;
    }
    else
    {
        cout << "\t" << "|" << list.getScientistDeath(i) << "\t" << "|" << list.getScientistAge(i) <<  endl;
    }

    cout << list.getScientistComment(i) << "\t" << endl;
}
void ClassUI::viewComputer(int i)
{
    cout << "--------------------------------------------------------------" << endl;
    int nameSize  = list.getComputerNameSize(i);

    cout << list.getComputerName(i);

    if(nameSize > 0 && nameSize <= 7)
    {
        cout << "\t" << "\t" << "\t" << "\t";
    }
    else if(nameSize > 7 && nameSize <= 15)
    {
        cout << "\t" << "\t" << "\t";
    }
    else if(nameSize > 15 && nameSize <= 23)
    {
        cout << "\t" << "\t";
    }
    else if(nameSize > 23 && nameSize <= 31)
    {
        cout << "\t";
    }
    cout  << "|" << list.getComputerDate(i) << "\t|" << list.getComputerWasItBuilt(i) << "\t|" << list.getComputerType(i) << endl;
}
void ClassUI::viewAllScientist()
{
    cout << "--------------------------------------------------------------" << endl;

    cout << "Name" << "\t" << "\t" << "\t" << "\t" << "|Gender " << "|Born " << "\t" << "|Death"  << "\t" << "|Age" << endl;
    for(int i = 0; i < list.personsSize(); i++)
    {
        viewScientist(i);
    }
}
void ClassUI::viewAllComputers()
{
    cout << "--------------------------------------------------------------" << endl;
    cout << "Name" << "\t" << "\t" << "\t" << "\t" << "|Date " << "\t" << "|Built " << "\t" << "|Type" << endl;

    for(int i = 0; i < list.computerSize(); i++)
    {
        viewComputer(i);
    }
}
void ClassUI::addScientist()
{
    string name;
    string comment;
    char gender;
    char yesOrNo;
    int yearOfBirth = 0;
    int yearOfDeath = 0;

    cout << "--------------------------------------------------------------" << endl;
    cout << "Enter name of the scientist: ";
    std::getline(std::cin,name);

    if(name == "")
    {
        cout << "Invalid name! Try again." << endl;
        return mainMenu();
    }
    cout << "Enter a gender (M/F): ";
    cin >> gender;

    if (gender == 'm')
    {
        gender = 'M';
    }
    else if (gender == 'f')
    {
        gender = 'F';
    }

    if (gender == 'm' || gender == 'M' || gender == 'f' || gender == 'F')
    {
       cout << "Enter a year of birth: ";
       cin >> yearOfBirth;

       if (yearOfBirth < 0 || yearOfBirth > 2016)
       {
           cout << "Not a valid year of birth." << endl;
           return mainMenu();
       }
       cout << "Is the individual deceased? (y/n) ";
       cin >> yesOrNo;

       if (yesOrNo == 'Y' || yesOrNo == 'y')
       {
            cout << "Enter a year of death: ";
            cin >> yearOfDeath;
            if(yearOfBirth > yearOfDeath)
            {
                cout << "Not a valid year of death." << endl;
                return mainMenu();
            }
       }
       cout << "Enter a comment about the scientist(optional): ";
       cin.ignore();
       std::getline(std::cin,comment);
    }
    else
    {
        cout << "Invalid gender! Try again." << endl;
        return mainMenu();
    }

    cout << "Are you sure that you want to add this scientist? (y/n) ";
    string validatePerson;
    cin >> validatePerson;

    if(validatePerson == "y")
    {
        cout << "New scientist added!" << endl;
        list.addNewScientist(name, gender, yearOfBirth, yearOfDeath, comment);
    }
    else
    {
        cout << "Scientist not added!" << endl;
    }
}
void ClassUI::addComputer()
{
    string name;
    string type;
    string isbuilt;
    int Yearbuilt = 0;

    cout << "--------------------------------------------------------------" << endl;
    cout << "Enter name of the computer: ";
    std::getline(std::cin,name);

    if(name == "")
    {
        cout << "Invalid name! Try again." << endl;
        return mainMenu();
    }
    cout << "Enter the type of the computer: ";
    std::getline(std::cin,type);

    if(type == "")
    {
        cout << "Invalid type! Try again." << endl;
        return mainMenu();
    }
    cout << "Enter the year the computer was built: ";
    cin >> Yearbuilt;

    if (Yearbuilt < 0 || Yearbuilt > 2016)
    {
       cout << "Not a valid building year." << endl;
       return mainMenu();
    }
    cout << "Did they finish building the computer? (y/n) ";
    cin >> isbuilt;

    if (isbuilt == "y" || isbuilt == "y")
    {
       isbuilt = "Yes";
    }
    else if (isbuilt == "n" || isbuilt == "N")
    {
       isbuilt = "No";
    }
    else
    {
        cout << "Not a valid input." << endl;
        return mainMenu();
    }
    cout << "Are you sure that you want to add this computer? (y/n) ";
    string validateComputer;
    cin >> validateComputer;

    if(validateComputer == "y")
    {
        cout << "New computer added!" << endl;
        list.addNewComputer(name, type ,Yearbuilt, isbuilt);
    }
    else
    {
        cout << "Computer not added!" << endl;
    }
}
void ClassUI::addConnection()
{
    int linkId = 0;
    int compId = 0;
    int sciId = 0;
    int validateComputer = 0;
    int validateScientist = 0;
    cout << "--------------------------------------------------------------" << endl;
    cout << "Number - Scientist name" << endl;

    for(int i = 0; i < list.personsSize(); i++)
    {
     cout << list.getScientistId(i) << " - " << list.getScientistName(i) << endl;
    }
    cout << "Enter the number in front of the scientist you wish to connect: ";
    cin >> sciId;

    for(int i = 0; i < list.personsSize(); i++)
    {
        if(sciId == list.getScientistId(i))
        {
            validateScientist = 1;
        }
    }

    if(validateScientist == 0)
    {
        cout << "Wrong input! Try again." << endl;
        cin.ignore();
        addConnection();
    }
    cout << "--------------------------------------------------------------" << endl;
    cout << "Number - Computer name" << endl;

    for(int i = 0; i < list.computerSize(); i++)
    {
     cout << list.getComputerId(i) << " - " << list.getComputerName(i) << endl;
    }
    cout << "Enter the number in front of the computer you wish to connect: ";
    cin.ignore();
    cin >> compId;

    for(int i = 0; i < list.computerSize(); i++)
    {
        if(compId == list.getComputerId(i))
        {
            validateComputer = 1;
        }
    }

    if(validateComputer == 0)
    {
        cout << "Wrong input! Try again." << endl;
        cin.ignore();
        addConnection();
    }

    //get free ID in database
    for(int i = 1; i < list.getLinkSize()+2; i++)
    {
        if(i != list.getLinkId(i))
        {
            linkId = i;
        }
    }

    cout << "Are you sure that you want to add this connection? (y/n) ";
    string validate;
    cin >> validate;

    if(validate == "y")
    {
        cout << "New connection added!" << endl;
        list.addNewConnection(linkId, compId , sciId);
    }
    else
    {
        cout << "Connection not added!" << endl;
    }
}
void ClassUI::selectSearch()
{
    string searchChoice;
    cout << "-------------Select any of the following commands-------------" << endl;
    cout << "What do you want to search for?" << endl;
    cout << " (1) - Search for a scientist." << endl;
    cout << " (2) - Search for a computer." << endl;
    cout << " (3) - Search for a connection." << endl;
    cout << " (4) - Return to main menu." << endl;
    cout << "Enter your command (1 - 4): ";
    cin >> searchChoice;

    if(searchChoice == "1")
    {
        searchingScientist();
    }
    else if(searchChoice == "2")
    {
        searchingComputer();
    }
    else if(searchChoice == "3")
    {
        searchConnections();
    }
    else if(searchChoice == "4")
    {
        clearTheScreen();
        return mainMenu();
    }
    else
    {
        cout << "Error reading input. Please enter a number between 1- 4." << endl;
        return selectSearch();
    }
}
void ClassUI::searchingScientist()
{
    cout << "-------------Select any of the following commands-------------" << endl;
    cout << "What do you want to search for?" << endl;
    cout << " (1) - Search by name." << endl;
    cout << " (2) - Search by gender." << endl;
    cout << " (3) - Search by year of birth." << endl;
    cout << " (4) - Search by age." << endl;
    cout << " (5) - Return to main menu." << endl;
    cout << "Enter your command (1 - 5): ";

    searchScientist();
}
void ClassUI::searchingComputer()
{
    cout << "-------------Select any of the following commands-------------" << endl;
    cout << "What do you want to search for?" << endl;
    cout << " (1) - Search by name." << endl;
    cout << " (2) - Search by type." << endl;
    cout << " (3) - Search by year it was built." << endl;
    cout << " (4) - Return to main menu." << endl;
    cout << "Enter your command (1 - 4): ";

    searchComputer();
}
void ClassUI::searchComputer()
{
    string searchChoice;
    cin >> searchChoice;

    if (searchChoice == "1")
    {
        string nameSearch;
        cout << "--------------------------------------------------------------" << endl;
        cout << "Enter a name you want to search for: ";
        cin.ignore();
        std::getline(std::cin,nameSearch);

        transform(nameSearch.begin(), nameSearch.end(), nameSearch.begin(), ::tolower);

        for(int i = 0; i < list.computerSize();++i)
        {
            std::size_t found = list.getComputerLowerCaseName(i).find(nameSearch);
            if (found!=std::string::npos)
            {
                viewComputer(i);
            }
        }

        if (list.computerNameSearcher(nameSearch) == false)
        {
            cout << "Sorry that name is not in our database, but you can add a new computer in the 'Add section' in the main menu." << endl;
            return mainMenu();
        }
    }
    else if (searchChoice == "2")
    {
        string typesearch;
        cout << "Enter a type you want to search for: ";
        cin.ignore();
        std::getline(std::cin,typesearch);
        for(int i = 0; i < list.computerSize();++i)
        {
            std::size_t found = list.getComputerType(i).find(typesearch);

            if (found!=std::string::npos)
            {
                viewComputer(i);
            }
        }

        if(list.typeSearcher(typesearch) == false)
        {
            cout << "Sorry that type is not in our database, but you can add a new type in the 'Add section' in the main menu." << endl;
            return mainMenu();
        }
    }
    else if (searchChoice == "3")
    {
            int yearSearch;
            cout << "Enter a year you want to search for: ";
            cin >> yearSearch;

            for(int i = 0; i < list.computerSize(); i++)
            {
                if(yearSearch == list.getComputerDate(i))
                {
                    yearSearch = list.getComputerDate(i);
                    viewComputer(i);
                }
            }

            if(list.builtDateSearcher(yearSearch) == false)
            {
                cout << "Sorry that year is not in our database, but you can add a new scientist in the 'Add section' in the main menu." << endl;
                return mainMenu();
            }
    }
    else if (searchChoice == "4")
    {
        clearTheScreen();
        mainMenu();
    }
    else
    {
        cout << "Error reading input. Please enter a number between 1- 4." << endl;
        return searchComputer();
    }
}
void ClassUI::searchScientist()
{
    string searchChoice;
    cin >> searchChoice;

    if (searchChoice == "1")
    {
        string nameSearch;
        cout << "--------------------------------------------------------------" << endl;
        cout << "Enter a name you want to search for: ";
        cin.ignore();
        getline(cin,nameSearch);
        transform(nameSearch.begin(), nameSearch.end(), nameSearch.begin(), ::tolower);
        cout << "--------------------------------------------------------------" << endl;

        for(int i = 0; i < list.personsSize();++i)
        {
            std::size_t found = list.getScientistLowerCaseName(i).find(nameSearch);
            if (found!=std::string::npos)
            {
                viewScientist(i);
            }     
        }

        if (list.nameSearcher(nameSearch) == false)
        {
            cout << "Sorry that name is not in our database, but you can add a new scientist in the 'Add section' in the main menu." << endl;
            return mainMenu();
        }
    }
    else if (searchChoice == "2")
    {
        char genderSearch;

        cout << "Enter a gender you want to search for: (M/F) ";
        cin >> genderSearch;

        if(genderSearch == 'm')
            {
                 genderSearch = 'M';
            }
        else if (genderSearch == 'f')
            {
                 genderSearch = 'F';
            }

        for(int i = 0; i < list.personsSize();++i)
        {
            if(genderSearch == list.getScientistGender(i))
            {
                genderSearch = list.getScientistGender(i);
                viewScientist(i);
            }
        }

        if(list.genderSearcher(genderSearch) == false)
        {
            cout << "Sorry that gender is not in our database, but you can add a new scientist in the 'Add section' in the main menu." << endl;
            return mainMenu();
        }
    }
    else if (searchChoice == "3")
    {
            int yearSearch;
            cout << "Enter a year you want to search for: ";
            cin >> yearSearch;

            for(int i = 0; i < list.personsSize();++i)
            {
                if(yearSearch == list.getScientistBirth(i))
                {
                    yearSearch = list.getScientistBirth(i);
                    viewScientist(i);
                }
            }

            if(list.yearSearcher(yearSearch) == false)
            {
                cout << "Sorry that year is not in our database, but you can add a new scientist in the 'Add section' in the main menu." << endl;
                return mainMenu();
            }
    }
    else if (searchChoice == "4")
    {
        int ageSearch;
        cout << "Enter a age you want to search for: ";
        cin >> ageSearch;

        for(int i = 0; i < list.personsSize();++i)
        {
            if(ageSearch == list.getScientistAge(i))
            {
                ageSearch = list.getScientistAge(i);
                viewScientist(i);
            }
        }

        if(list.ageSearcher(ageSearch) == false)
        {
            cout << "Sorry that age is not in our database, but you can add a new scientist in the 'Add section' in the main menu." << endl;
            return mainMenu();
        }
    }
    else if (searchChoice == "5")
    {
        clearTheScreen();
        mainMenu();
    }
    else
    {
        cout << "Error reading input. Please enter a number between 1- 5." << endl;
        return searchScientist();
    }
}
void ClassUI::removeScientist()
{
    string name;
    cout << "--------------------------------------------------------------" << endl;
    cout << "Enter the full name of the scientist that you want to remove: ";
    cin.ignore();
    std::getline(std::cin,name);

    if (list.removePersonFound(name) == true)
    {
        char validateRemove;
        cout << "Scientist found!" << endl;
        cout << "Are you sure you want to remove this scientist? (y/n): ";
        cin >> validateRemove;

        if(validateRemove == 'y' || validateRemove == 'Y')
        {
            if(list.removePerson(name) == true)
            {
                cout << "Scientist removed!" << endl;
            }
            else
            {
                cout << "Scientist not removed!" << endl;
            }
        }
        else
        {
            cout << "Scientist not removed!" << endl;
        }
    }
    else
    {
        cout << "Scientist not found!" << endl;
    }
}
void ClassUI::removeComputer()
{
    string name;
    cout << "--------------------------------------------------------------" << endl;
    cout << "Enter the full name of the computer that you want to remove: ";
    cin.ignore();
    std::getline(std::cin,name);

    if (list.removeComputerFound(name) == true)
    {
        char validateRemove;
        cout << "Computer found!" << endl;
        cout << "Are you sure you want to remove this computer? (y/n): ";
        cin >> validateRemove;

        if(validateRemove == 'y' || validateRemove == 'Y')
        {
            if(list.removeComputer(name) == true)
            {
                cout << "Computer removed!" << endl;
            }
            else
            {
                cout << "Computer not removed!" << endl;
            }
        }
        else
        {
            cout << "Computer not removed!" << endl;
        }
    }
    else
    {
        cout << "Computer not found!" << endl;
    }

}
void ClassUI::yo()
{
    clearTheScreen();
    cout << "--------------------------------------------------------------" << endl;
    cout << endl;
    cout << "`8.`8888.      ,8'     ,o888888o.     " << endl;
    cout << " `8.`8888.    ,8'   . 8888     `88.   " << endl;
    cout << "  `8.`8888.  ,8'   ,8 8888       `8b  " << endl;
    cout << "   `8.`8888.,8'    88 8888        `8b " << endl;
    cout << "    `8.`88888'     88 8888         88 " << endl;
    cout << "     `8. 8888      88 8888         88 " << endl;
    cout << "      `8 8888      88 8888        ,8P " << endl;
    cout << "       8 8888      `8 8888       ,8P  " << endl;
    cout << "       8 8888       ` 8888     ,88'   " << endl;
    cout << "       8 8888          `8888888P'     " << endl;
    cout << endl;
}
string ClassUI::getQuotes()
{
    string quotes[5] = {"\"A good programmer is someone who always looks both ways before crossing a one-way street.\" (Doug Linder)",
                        "\"Programming is like sex. One mistake and you have to support it for the rest of your life.\" (Michael Sinz)",
                        "\"Walking on water and developing software from a specification are easy if both are frozen.\" (Edward V Berard)",
                        "\"One man's crappy software is another man's full time job.\" (Jessica Gaston)",
                        "\"A C program is like a fast dance on a newly waxed dance floor by people carrying razors.\" (Waldi Ravens)"
                       };
    int v1 = 0;
    srand (time(NULL));
    v1 = rand() % 5;
    return quotes[v1];
}
void ClassUI::viewMenu()
{
    string viewBy;
    string viewCho;
    cout << "--------------------------------------------------------------" << endl;
    cout << " (1) - View scientists." << endl;
    cout << " (2) - View computers." << endl;
    cout << " (3) - View connections." << endl;
    cout << " (4) - Return to main menu." << endl;
    cout << "Enter your command (1 - 4): ";
    cin >> viewBy;
    if(viewBy == "1")
    {
        cout << "--------------------------------------------------------------" << endl;
        cout << " (1) - Sorted by ascending alphabetical order." << endl;
        cout << " (2) - Sorted by descending alphabetical order." << endl;
        cout << " (3) - Sorted by ascending chronological order." << endl;
        cout << " (4) - Sorted by descending chronological order." << endl;
        cout << " (5) - Sorted by gender." << endl;
        cout << " (6) - Sorted by age." << endl;
        cout << " (7) - Return to main menu." << endl;
        cout << "Enter your command (1 - 7): ";
        cin >> viewCho;

        if(viewCho == "1")
        {
            list.sortScientistNames();
            viewAllScientist();
        }
        else if(viewCho == "2")
        {
            list.sortScientistNamesReverse();
            viewAllScientist();
        }
        else if(viewCho == "3")
        {
            list.sortScientistBirth();
            viewAllScientist();
        }
        else if(viewCho == "4")
        {
            list.sortScientistBirthReverse();
            viewAllScientist();
        }
        else if(viewCho == "5")
        {
            list.sortScientistGender();
            viewAllScientist();
        }
        else if(viewCho == "6")
        {
            list.sortScientistAge();
            viewAllScientist();

        }
        else if(viewCho == "7")
        {
            clearTheScreen();
            mainMenu();
        }
        else
        {
            cout << "That is not a valid command! Try again." << endl;
            viewMenu();
        }
    }
    else if(viewBy == "2")
    {
        cout << "--------------------------------------------------------------" << endl;
        cout << " (1) - Sorted by ascending alphabetical order." << endl;
        cout << " (2) - Sorted by descending alpabetical order." << endl;
        cout << " (3) - Sorted by ascending chronological order." << endl;
        cout << " (4) - Sorted by descending chronological order." << endl;
        cout << " (5) - Sorted by type." << endl;
        cout << " (6) - Return to main menu." << endl;
        cout << "Enter your command (1 - 6): ";
        cin >> viewCho;
        cout << endl;

        if(viewCho == "1")
        {
            list.sortComputerName();
            viewAllComputers();
        }
        else if(viewCho == "2")
        {
            list.sortComputerNameReverse();
            viewAllComputers();
        }
        else if(viewCho == "3")
        {
            list.sortComputerDate();
            viewAllComputers();
        }
        else if(viewCho == "4")
        {
            list.sortComputerDateReverse();
            viewAllComputers();
        }
        else if(viewCho == "5")
        {
            list.sortComputerType();
            viewAllComputers();
        }
        else if(viewCho == "6")
        {
            clearTheScreen();
            mainMenu();
        }
        else
        {
            cout << "That is not a valid command! Try again." << endl;
            viewMenu();
        }
    }
    else if(viewBy == "3")
    {
        cout << "--------------------------------------------------------------" << endl;
        cout << " (1) - Sort scientists by ascending alphabetical order." << endl;
        cout << " (2) - Sort scientists by descending alphabetical order." << endl;
        cout << " (3) - Sort computers by ascending alphabetical order." << endl;
        cout << " (4) - Sort computers by descending alphabetical order." << endl;
        cout << " (5) - Return to main menu." << endl;
        cout << "Enter your command (1 - 5): ";
        cin >> viewCho;
        if(viewCho == "1" || viewCho == "2" || viewCho == "3" || viewCho == "4")
        {
            list.sortConnections(viewCho);
            showScientistAndComputerConnections();
        }
        else if (viewCho == "5")
        {
            clearTheScreen();
            mainMenu();
        }
        else
        {
            cout << "That is not a valid command! Try again." << endl;
            viewMenu();
        }
    }
    else if(viewBy == "4")
    {
        clearTheScreen();
        mainMenu();
    }
    else
    {
        cout << "That is not a valid command! Try again." << endl;
        viewMenu();
    }
}
void ClassUI::editScientist()
{
    string ename;
    int found = -1;
    cout << "Enter the full name of the scientist that you want to edit: ";
    cin.ignore();
    std::getline(std::cin,ename);
    for(int i = 0; i < list.personsSize(); i++)
    {
        if(ename == list.getScientistName(i))
        {
            found = i;
        }
    }
    int sciId = list.getScientistId(found);

    if(found >= 0)
    {
        string name;
        string comment;
        char gender;
        char yesOrNo;
        int yearOfBirth = 0;
        int yearOfDeath = 0;

        cout << "--------------------------------------------------------------" << endl;
        cout << "Enter new name of the scientist: ";
        std::getline(std::cin,name);

        if(name == "")
        {
            cout << "Invalid name! Try again." << endl;
            return mainMenu();
        }
        cout << "Enter a gender (M/F): ";
        cin >> gender;

        if (gender == 'm')
        {
            gender = 'M';
        }
        else if (gender == 'f')
        {
            gender = 'F';
        }

        if (gender == 'm' || gender == 'M' || gender == 'f' || gender == 'F')
        {
           cout << "Enter a year of birth: ";
           cin >> yearOfBirth;
           if (yearOfBirth < 0 || yearOfBirth > 2016)
           {
               cout << "Not a valid year of birth." << endl;
               return mainMenu();
           }
           cout << "Is the individual deceased? (y/n) ";
           cin >> yesOrNo;

           if (yesOrNo == 'Y' || yesOrNo == 'y')
           {
                cout << "Enter a year of death: ";
                cin >> yearOfDeath;
                if(yearOfBirth > yearOfDeath)
                {
                    cout << "Not a valid year of death." << endl;
                    return mainMenu();
                }
            }

            cout << "Enter a comment about the scientist(optional): ";
            cin.ignore();
            std::getline(std::cin,comment);
            }
        else
        {
            cout << "Invalid gender! Try again." << endl;
            return mainMenu();
        }
        cout << "The Scientist has been edited." << endl;
        list.updateScientist(name,gender,yearOfBirth,yearOfDeath,comment, sciId);

    }
    else
    {
        cout << "Scientist not found!" << endl;
    }
}
void ClassUI::showScientistAndComputerConnections()
{
    int found = 0;
    cout << "--------------------------------------------------------------" << endl;
    cout << "Computer name" << "\t" << "\t" << "Scientist name" << endl;
    cout << "--------------------------------------------------------------" << endl;

    for(int i = 0; i < list.getLinkOutputSize(); i++)
    {
        int nameSize  = list.getLinkoutputCompNameSize(i);

        found++;
        cout << list.getLinkOutputCompName(i);

        if(nameSize > 0 && nameSize <= 7)
        {
            cout << "\t" << "\t" << "\t";
        }
        else if(nameSize > 7 && nameSize <= 15)
        {
            cout << "\t" << "\t";
        }
        else if(nameSize > 15 && nameSize <= 23)
        {
            cout << "\t";
        }
        cout << "|" << list.getLinkOutputSciName(i) << endl;
    }
}
void ClassUI::clearTheScreen()
{
    system("cls||clear");
    return;
}
void ClassUI::editComputer()
{
    string ename;
    int found = -1;
    cout << "Enter the full name of the computer that you want to edit: ";
    cin.ignore();
    std::getline(std::cin,ename);
    for(int i = 0; i < list.computerSize(); i++)
    {
        if(ename == list.getComputerName(i))
        {
            found = i;
        }
    }
    int compId = list.getComputerId(found);

    if(found >= 0)
    {
        string name;
        string type;
        string isbuilt;
        int Yearbuilt = 0;

        cout << "--------------------------------------------------------------" << endl;
        cout << "Enter a new name of the computer: ";
        std::getline(std::cin,name);

        if(name == "")
        {
            cout << "Invalid name! Try again." << endl;
            return mainMenu();
        }
        cout << "Enter the type of the computer: ";
        std::getline(std::cin,type);

        if(type == "")
        {
            cout << "Invalid type! Try again." << endl;
            return mainMenu();
        }
        cout << "Enter the year the computer was designed: ";
        cin >> Yearbuilt;

        if (Yearbuilt < 0 || Yearbuilt > 2016)
        {
           cout << "Not a valid building year." << endl;
           return mainMenu();
        }
        cout << "Did they finish building the computer, i.e. has it ever been built? (y/n) ";
        cin >> isbuilt;

        if (isbuilt == "y" || isbuilt == "y")
        {
           isbuilt = "Yes";
        }
        else if (isbuilt == "n" || isbuilt == "N")
        {
           isbuilt = "No";
        }
        else
        {
            cout << "Not a valid input." << endl;
            return mainMenu();
        }

        cout << "Are you sure that you want to edit this computer? (y/n) ";
        string validateComputer;
        cin >> validateComputer;

        if(validateComputer == "y" || validateComputer == "Y")
        {
            list.updateComputer(name, type, isbuilt, Yearbuilt, compId);
            cout << "Computer edited!" << endl;
        }
        else
        {
            cout << "Computer not edited!" << endl;
        }
    }
    else
    {
        cout << "Computer not found!" << endl;
    }
}

void ClassUI::hangman()
{
    clearTheScreen();
    string name;
    char letter = ' ';
    int numOfWrongGuesses = 0;
    string word;
    char theArray [maxArraySize];

    srand(time(NULL));

    cout <<"  ***Welcome to hangman***" << endl;
    cout << "***~~~~~~~~~~~~~~~~~~~~~~***" << endl;
    string level;
    cout << "Choose a level of difficulty (note; all words are related to computer science)" << endl;
    cout << " (1) - Easy" << endl;
    cout << " (2) - Avarage" << endl;
    cout << " (3) - Hard" << endl;
    cout << " (4) - Return to main menu." << endl;
    cout << "Enter your command (1 - 4): ";
    cin >> level;

    if (level == "1")
    {
        string easy[] = { "array", "matrix", "binary", "virus" };
        string word;
        int n = rand() % 4;
        word = easy[n];
        string unknown(word.length(), '*');

        cout << "Each letter is represented by an asterisk." << endl;
        cout << "You may type only one letter in one try." << endl;
        cout << "You have " << maxTries << " tries to try and guess the word." << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        hangmanRun(numOfWrongGuesses, unknown, letter, word, theArray);

        if (numOfWrongGuesses == maxTries)
        {
            cout << "Sorry, you lose...you've been hanged." << endl;
            cout << "The word was : " << word << endl;
            cout << "Press Enter to continue" << endl;
        }
        cin.ignore();
        cin.get();
        clearTheScreen();
        mainMenu();
    }
    else if (level == "2")
    {
        string average[] = { "bit", "runtime", "supercomputer" };
        int n = rand() % 3;
        word = average[n];
        string unknown(word.length(), '*');

        cout << "Each letter is represented by an asterisk." << endl;
        cout << "You may type only one letter in one try." << endl;
        cout << "You have " << maxTries << " tries to try and guess the word." << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        hangmanRun(numOfWrongGuesses, unknown, letter, word, theArray);

        if (numOfWrongGuesses == maxTries)
        {
            cout << "Sorry, you lose...you've been hanged." << endl;
            cout << "The word was : " << word << endl;
            cout << "Press Enter to continue" << endl;
        }
        cin.ignore();
        cin.get();
        clearTheScreen();
        mainMenu();
    }
    else if (level == "3")
    {
        string hard[] = { "microprocessor", "nanotechnology", "telecommunication" };
        int n = rand() % 3;
        word = hard[n];
        string unknown(word.length(), '*');

        cout << "Each letter is represented by an asterisk." << endl;
        cout << "You may type only one letter in one try." << endl;
        cout << "You have " << maxTries << " tries to try and guess the word." << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        hangmanRun(numOfWrongGuesses, unknown, letter, word, theArray);

        if (numOfWrongGuesses == maxTries)
        {
            cout << "Sorry, you lose...you've been hanged." << endl;
            cout << "The word was : " << word << endl;
            cout << "Press Enter to continue to main menu." << endl;
        }
        cin.ignore();
        cin.get();
        clearTheScreen();
        mainMenu();
    }
    else if (level == "4")
    {
        clearTheScreen();
        mainMenu();
    }
}
int ClassUI::fillIn(char guess, string secretword, string &guessword)
{
    int i;
    int matches = 0;
    int len = secretword.length();

    for (i = 0; i< len; i++)
    {
        if (guess == guessword[i])
        {
            return 0;
        }
        if (guess == secretword[i])
        {
            guessword[i] = guess;
            matches++;
        }
    }
    return matches;
}
void ClassUI::hangmanPicture(int wrongGuess)
{
    if (wrongGuess == 1)
    {
      cout << "_ ___" << endl;
    }
    else if (wrongGuess == 2)
    {
        cout << " |" << endl;
        cout << " |" << endl;
        cout << " |" << endl;
        cout << " |" << endl;
        cout << " |" << endl;
        cout << " |" << endl;
        cout << "_|___" << endl;
    }
    else if (wrongGuess == 3)
    {
        cout << " ________" << endl;
        cout << " |" << endl;
        cout << " |" << endl;
        cout << " |" << endl;
        cout << " |" << endl;
        cout << " |" << endl;
        cout << " |" << endl;
        cout << "_|___" << endl;
    }
    else if (wrongGuess == 4)
    {
        cout << " ________" << endl;
        cout << " |/" << endl;
        cout << " |" << endl;
        cout << " |" << endl;
        cout << " |" << endl;
        cout << " |" << endl;
        cout << " |" << endl;
        cout << "_|___" << endl;
    }
    else if (wrongGuess == 5)
    {
        cout << "  _______" << endl;
       cout << " |/      |" << endl;
       cout << " |      (_)" << endl;
       cout << " |      \\|/" << endl;
       cout << " |       |" << endl;
       cout << " |      / \\ " << endl;
       cout << " |" << endl;
      cout << "_|___" << endl;
    }
}
void ClassUI::hangmanRun(int &numWrongGuess, string secretWord, char input, string theword, char myarray[maxArraySize])
{
    int i = 0;

    while (numWrongGuess < maxTries)
    {
        cout  << secretWord << endl;
        cout << " You have entered the following letters: ";
        for (int k = 0; k < i; k++ )
        {
            cout << myarray[k] << " ";
        }
        cout << endl;
        cout << "Guess a letter: ";
        cin >> input;
        if (fillIn(input, theword, secretWord) == 0)
        {
            cout << endl << "That letter isn't in there!" << endl;
            numWrongGuess++;
            hangmanPicture(numWrongGuess);
        }
        else
        {
            cout << endl << "You found a letter!" << endl;
        }
        myarray[i] = input;
        cout << "You have " << maxTries - numWrongGuess;
        cout << " guesses left." << endl;
        if (theword == secretWord)
        {
            cout << theword << endl;
            cout << "Well done, you WIN!" << endl;
            cout << "Press Enter to continue" << endl;
            break;
        }
        i++;
    }
}
void ClassUI::removeConnection()
{
    string removeScientistConnection;
    string removeComputerConnection;

    showScientistAndComputerConnections();
    cout << "Here you can remove a connection between a Scientist and a Computer" << endl;
    cout << "Enter the name of the Scientist: ";
    cin.ignore();
    std::getline(std::cin,removeScientistConnection);
    cout << "Enter the name of the Computer: ";
    std::getline(std::cin,removeComputerConnection);

    if(list.removePersonFound(removeScientistConnection) == true && list.removeComputerFound(removeComputerConnection) == true)
    {
        char validateRemove;

        cout << "Are you sure you want to remove this connection? (y/n): ";
        cin >> validateRemove;

        if(validateRemove == 'y' || validateRemove == 'Y')
        {
              list.removeConnection(removeScientistConnection, removeComputerConnection);
              cout << "Connection removed!" << endl;
              return mainMenu();
        }
        else
        {
            cout << "Connection not removed!" << endl;
            return mainMenu();
        }
    }
    cout << "Connection not found!" << endl;
}
void ClassUI::searchConnections()
{
    int select = 0;
    int id = -1;
    string name;

    cout << "--------------------------------------------------------------" << endl;
    cout << " (1) - Search connections by scientists." << endl;
    cout << " (2) - Search connections by computers." << endl;
    cout << " (3) - Exit to main menu." << endl;
    cout << "Enter your command (1 - 3): ";
    cin >> select;

    if(select < 1 || select > 2)
    {
        cout << "Invalid input!" << endl;
        mainMenu();
    }
    else if(select == 1)
    {
        cout << "Enter a full name of scientist: ";
        cin.ignore();
        getline(cin,name);

        transform(name.begin(), name.end(), name.begin(), ::tolower);
        for(int i = 0; i < list.personsSize(); i++)
        {
            if(name == list.getScientistLowerCaseName(i))
            {
                id = list.getScientistId(i);
            }
        }
        if (id < 0)
        {
            cout << "Scientist not found!" << endl;
            return mainMenu();
        }
        list.searchConnectionsBySci(id);
        showScientistAndComputerConnections();
    }
    else if(select == 2)
    {
        cout << "Enter full name of computer: ";
        cin.ignore();
        getline(cin,name);

        transform(name.begin(), name.end(), name.begin(), ::tolower);
        for(int i = 0; i < list.computerSize(); i++)
        {
            if(name == list.getComputerLowerCaseName(i))
            {
                id = list.getComputerId(i);
            }
        }
        if (id < 0)
        {
            cout << "Computer not found!" << endl;
            return mainMenu();
        }
        list.searchConnectionsByComp(id);
        showScientistAndComputerConnections();
    }
}
