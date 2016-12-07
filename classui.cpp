#include "classui.h"
#include "listworker.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <time.h>

using namespace std;
const int MAX_TRIES = 5;
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
        cout << "--------------------------------------------------------------" << endl;
        cout << " (1) - "  << "Add to the database." << endl;
        cout << " (2) - "  << "Remove a from the database." << endl;
        cout << " (3) - "  << "View." << endl;
        cout << " (4) - "  << "Search." << endl;
        cout << " (5) - "  << "Edit a scientist." << endl;
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
        list.refreshVector();
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
        cout << " (3) - Add a connection between computer and scientist" << endl;
        cout << " (4) - Return to main menu." << endl;
        cout << "Enter your command (1 - 4): ";
        cin >> choice;
        if (choice == "1")
        {
        cin.ignore();           // When using editPerson it will ignore the first letter unless this ignore is here rather then in addPerson
        addPerson();
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
            cout << "Invalid input. Please enter a number between 1 - 3." << endl;
            select("1");
        }
    }
    else if(ch == "2")
    {
        string choice;
        cout << " (1) - Remove scientist." << endl;
        cout << " (2) - Remove Computer." << endl;
        cout << " (3) - Return to main menu." << endl;
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
            cout << "Invalid input. Please enter a number between 1 - 3" << endl;
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
        cout << " (2) - Edit a Computer." << endl;
        cout << " (3) - Return to main menu." << endl;
        cin >> choice;
        if (choice == "1")
        {
            editPerson();
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
            cout << "Invalid input. Please enter a number between 1 - 3" << endl;
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


void ClassUI::viewPersons(int i)
{
    cout << "--------------------------------------------------------------" << endl;
    int nameSize  = list.getNameSizePerson(i);


    cout << list.getNamePerson(i);



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

    if(list.getGenderPerson(i) == 'M' || list.getGenderPerson(i) == 'm')
    {
        cout << "|Male" << "\t";
    }
    else
    {
        cout << "|Female" << "\t";
    }

    cout  << "|" << list.getBirthPerson(i);

    if(list.getDeathPerson(i) == 0)
    {
        cout << "\t" << "| n/a"  << "\t" << "|" << list.getAgePerson(i) << endl;
    }
    else
    {
        cout << "\t" << "|" << list.getDeathPerson(i) << "\t" << "|" << list.getAgePerson(i) <<  endl;
    }

    cout << list.getCommentperson(i) << "\t" << endl;
}
void ClassUI::viewComputers(int i)
{
    cout << "--------------------------------------------------------------" << endl;
    int nameSize  = list.getNameSizeComputer(i);

    cout << list.getNameComputer(i);

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

    cout  << "|" << list.getDateComputer(i) << "\t|" << list.getWasItBuilt(i) << "\t|" << list.getTypeComputer(i) << endl;

}
void ClassUI::viewPer()
{
    cout << "--------------------------------------------------------------" << endl;

    cout << "Name" << "\t" << "\t" << "\t" << "\t" << "|Gender " << "|Born " << "\t" << "|Death"  << "\t" << "|Age" << endl;
    for(int i = 0; i < list.personsSize(); i++)
    {
        viewPersons(i);
    }
}
void ClassUI::viewCom()
{
    cout << "--------------------------------------------------------------" << endl;
    cout << "Name" << "\t" << "\t" << "\t" << "\t" << "|Date " << "|Built " << "\t" << "|Type" << endl;

    for(int i = 0; i < list.computerSize(); i++)
    {
        viewComputers(i);
    }
}

void ClassUI::addPerson()
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
           cout << "not a valid year of birth" << endl;
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
                cout << "Not a valid year of death" << endl;
                return mainMenu();
            }
       }

       cout << "Enter a comment about the scientist: ";
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
        list.addNewPerson(name, gender, yearOfBirth, yearOfDeath, comment);
    }
    else
    {
        cout << "scientist not added!" << endl;
    }
}
void ClassUI::addComputer()
    {
        string name;
        string type;
        string isbuilt;
        int Yearbuilt = 0;

        cout << "--------------------------------------------------------------" << endl;
        cout << "Enter name of the Computer: ";
        std::getline(std::cin,name);
        cout << "Enter the type of the computer: ";
        std::getline(std::cin,type);
        cout << "Enter the year the computer was built: ";
           cin >> Yearbuilt;
           if (Yearbuilt < 0 || Yearbuilt > 2016)
           {
               cout << "not a valid building year" << endl;
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
            cout << "scientist not added!" << endl;
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
    cout << "ID - Scientist name" << endl;
    for(int i = 0; i < list.personsSize(); i++)
    {
     cout << list.getPersonId(i) << " - " << list.getNamePerson(i) << endl;
    }

    cout << "Enter id of the Scientist to connect: ";
    cin >> sciId;

    //checking for valid input
    for(int i = 0; i < list.personsSize(); i++)
    {
        if(sciId == list.getPersonId(i))
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
    cout << "ID - Computer name" << endl;

    for(int i = 0; i < list.computerSize(); i++)
    {
     cout << list.getIdComputer(i) << " - " << list.getNameComputer(i) << endl;
    }

    cout << "Enter id of the Computer: ";
    cin.ignore();
    cin >> compId;

    //checking for valid input
    for(int i = 0; i < list.computerSize(); i++)
    {
        if(compId == list.getIdComputer(i))
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
    cout << linkId << endl;

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
                cout << "connection not added!" << endl;
            }

}
void ClassUI::selectSearch()
{
    string searchChoice;
    cout << "-------------Select any of the following commands-------------" << endl;
    cout << "What do you want to search for?" << endl;
    cout << " (1) - Search for a Scientist." << endl;
    cout << " (2) - Search for a Computer." << endl;
    cout << " (3) - Return to main menu." << endl;
    cout << "Enter your command (1 - 3): ";
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
        clearTheScreen();
        return mainMenu();
    }
    else
    {
        cout << "Error reading input. Please enter a number between 1- 3." << endl;
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
    cout << endl;

    if (searchChoice == "1")
    {
        string namesearch;
        cout << "--------------------------------------------------------------" << endl;
        cout << "Enter a name you want to search for: ";
        cin.ignore();
        std::getline(std::cin,namesearch);
        cout << "--------------------------------------------------------------" << endl;
        for(int i = 0; i < list.computerSize();++i)
        {
            std::size_t found = list.getNameComputer(i).find(namesearch);
            if (found!=std::string::npos)
            {
                viewComputers(i);
            }
        }

        if(list.computerNameSearcher(namesearch) == false)
        {
            cout << "Sorry that name is not in our database, but you can add a new computer in the 'Add section' in the main menu." << endl;
            return searchComputer();
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
            std::size_t found = list.getTypeComputer(i).find(typesearch);
            if (found!=std::string::npos)
            {
                viewComputers(i);
            }
        }

        if(list.typeSearcher(typesearch) == false)
        {
            cout << "Sorry that type is not in our database, but you can add a new type in the 'Add section' in the main menu." << endl;
            return searchComputer();
        }
    }
    else if (searchChoice == "3")
    {
            int yearsearch;
            cout << "Enter a year you want to search for: ";
            cin >> yearsearch;

            for(int i = 0; i < list.computerSize(); i++)
            {
                if(yearsearch == list.getDateComputer(i))
                {
                    yearsearch = list.getDateComputer(i);
                    viewComputers(i);
                }
            }

            if(list.builtDateSearcher(yearsearch) == false)
            {
                cout << "Sorry that year is not in our database, but you can add a new scientist in the 'Add section' in the main menu." << endl;
                return searchComputer();
            }
    }
    else if (searchChoice == "4")
    {
        clearTheScreen();
        mainMenu();
    }
    else
    {
        cout << "Error reading input. Please enter a number between 1- 3." << endl;
        return searchComputer();
    }
}
void ClassUI::searchScientist()
{
    string searchChoice;
    cin >> searchChoice;
    cout << endl;

    if (searchChoice == "1")
    {
        string namesearch;
        cout << "--------------------------------------------------------------" << endl;
        cout << "Enter a name you want to search for: ";
        cin.ignore();
        std::getline(std::cin,namesearch);
        cout << "--------------------------------------------------------------" << endl;
        for(int i = 0; i < list.personsSize();++i)
        {
            std::size_t found = list.getNamePerson(i).find(namesearch);
            if (found!=std::string::npos)
            {
                viewPersons(i);
            }
        }

        if(list.nameSearcher(namesearch) == false)
        {
            cout << "Sorry that name is not in our database, but you can add a new scientist in the 'Add section' in the main menu." << endl;
            return searchScientist();
        }
    }
    else if (searchChoice == "2")
    {
        char gendersearch;

        cout << "Enter a gender you want to search for: (M/F)";
        cin >> gendersearch;

        if(gendersearch == 'm')
            {
                 gendersearch = 'M';
            }
        else if (gendersearch == 'f')
            {
                 gendersearch = 'F';
            }

        for(int i = 0; i < list.personsSize();++i)
        {
            if(gendersearch == list.getGenderPerson(i))
            {
                gendersearch = list.getGenderPerson(i);
                viewPersons(i);
            }
        }

        if(list.genderSearcher(gendersearch) == false)
        {
            cout << "Sorry that gender is not in our database, but you can add a new scientist in the 'Add section' in the main menu." << endl;
            return searchScientist();
        }
    }
    else if (searchChoice == "3")
    {
            int yearsearch;
            cout << "Enter a year you want to search for: ";
            cin >> yearsearch;

            for(int i = 0; i < list.personsSize();++i)
            {
                if(yearsearch == list.getBirthPerson(i))
                {
                    yearsearch = list.getBirthPerson(i);
                    viewPersons(i);
                }
            }

            if(list.yearSearcher(yearsearch) == false)
            {
                cout << "Sorry that year is not in our database, but you can add a new scientist in the 'Add section' in the main menu." << endl;
                return searchScientist();
            }
    }
    else if (searchChoice == "4")
    {
        int ageSearch;
        cout << "Enter a age you want to search for: ";
        cin >> ageSearch;

        for(int i = 0; i < list.personsSize();++i)
        {
            if(ageSearch == list.getAgePerson(i))
            {
                ageSearch = list.getAgePerson(i);
                viewPersons(i);
            }
        }

        if(list.ageSearcher(ageSearch) == false)
        {
            cout << "Sorry that age is not in our database, but you can add a new scientist in the 'Add section' in the main menu." << endl;
            return searchScientist();
        }
    }
    else if (searchChoice == "5")
    {
        clearTheScreen();
        mainMenu();
    }
    else
    {
        cout << "Error reading input. Please enter a number between 1- 3." << endl;
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
    //int id;
    cout << "--------------------------------------------------------------" << endl;
    cout << "Enter the full name of the computer that you want to remove: ";
    cin.ignore();
    std::getline(std::cin,name);
    //cin >> id;

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
    cout << "Enter a view command:" << endl;
    cout << "--------------------------------------------------------------" << endl;
    cout << " (1) - View scientists." << endl;
    cout << " (2) - View computers." << endl;
    cout << " (3) - View connections." << endl;
    cout << " (4) - Return to main menu." << endl;
    cout << "Enter your command (1 - 4): ";
    cin >> viewBy;
    cout << endl;

    if(viewBy == "1")
    {
        cout << "--------------------------------------------------------------" << endl;
        cout << " (1) - Sorted by alphabetical order." << endl;
        cout << " (2) - Sorted by chronological order." << endl;
        cout << " (3) - Sorted by gender." << endl;
        cout << " (4) - Sorted by age." << endl;
        cout << " (5) - Return to main menu." << endl;
        cout << "Enter your command (1 - 5): ";
        cin >> viewCho;
        //cout << endl;

        if(viewCho == "1")
        {
            list.sortScientistNames();
            viewPer();
        }
        else if(viewCho == "2")
        {
            list.sortScientistBirth();
            viewPer();
        }
        else if(viewCho == "3")
        {
            list.sortScientistGender();
            viewPer();
        }
        else if(viewCho == "4")
        {
            list.sortScientistAge();
            viewPer();

        }
        else if(viewCho == "5")
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
        cout << " (1) - Sorted by alphabetical order." << endl;
        cout << " (2) - Sorted by chronological order." << endl;
        cout << " (3) - Sorted by type." << endl;
        cout << " (4) - Return to main menu." << endl;
        cout << "Enter your command (1 - 4): ";
        cin >> viewCho;
        cout << endl;

        if(viewCho == "1")
        {
            list.sortComputerName();
            viewCom();
        }
        else if(viewCho == "2")
        {
            list.sortComputerDate();
            viewCom();
        }
        else if(viewCho == "3")
        {
            list.sortComputerType();
            viewCom();
        }
        else if(viewCho == "4")
        {
            clearTheScreen();
            mainMenu();
        }
    }


    else if(viewBy == "3")
    {
        findScientistConnections();
        mainMenu();
    }
    else
    {
        cout << "That is not a valid command! Try again." << endl;
        viewMenu();
    }

}
void ClassUI::editPerson()
{
    string name;
    cout << "Enter the full name of the Scientist that you want to edit: ";

    cin.ignore();
    std::getline(std::cin,name);
    if(list.removePersonFound(name))
    {
        list.removePerson(name);
        addPerson();
    }
    else
    {
        cout << "Scientist not found!" << endl;
    }
}


void ClassUI::findScientistConnections()
{
    int found = 0;

    cout << "--------------------------------------------------------------" << endl;
    for(int i = 0; i < list.getLinkSize(); i++)
    {
        int compId = list.getLinkCompId(i);
        int sciId = list.getLinkSciId(i);

        string compName = list.getComputerNameFromId(compId);
        string sciName = list.getScientistNameFromId(sciId);

        int nameSize = compName.size();
        found++;

        cout << compName;

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

        cout << "|" << sciName << endl;
    }

    if (found > 0)
    {
        cout << endl;
    }
}

void ClassUI::clearTheScreen() //A function that we wanted to use but had platform issues following it's use.
{
    system("cls||clear");
    return;
}


void ClassUI::editComputer()
{
    string cmpname;
    cout << "Enter the full name of the computer that you want to edit: ";
    cin.ignore();
    std::getline(std::cin,cmpname);
    if(list.removeComputerFound(cmpname))
    {
        list.removeComputer(cmpname);
        addComputer();
    }
    else
    {
        cout << "Computer not found!" << endl;
    }
}

void ClassUI::hangman()
{

    string name;
    char letter;
    int num_of_wrong_guesses = 0;
    string word;

    srand(time(NULL));

    cout << "Welcome to hangman!!" << endl;
    string level;
    cout << "Choose a LEVEL" << endl;
    cout << " (1) - Easy" << endl;
    cout << " (2) - Avarage" << endl;
    cout << " (3) - Hard" << endl;
    cin >> level;

    if (level == "1")
    {
        string easy[] = { "array", "matrix", "binary", "virus" };
        string word;

        int n = rand() % 4;
        word = easy[n];
        string unknown(word.length(), '*');

        cout << "Each letter is represented by an asterisk." << endl;
        cout << "You have to type only one letter in one try." << endl;
        cout << "You have " << MAX_TRIES << " tries to try and guess the word." << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        while (num_of_wrong_guesses < MAX_TRIES)
        {
            cout << unknown << endl;
            cout << "Guess a letter: ";
            cin >> letter;
            if (letterFill(letter, word, unknown) == 0)
            {
                cout << endl << "Whoops! That letter isn't in there!" << endl;
                num_of_wrong_guesses++;
                hangmanPicture(num_of_wrong_guesses);
            }
            else
            {
                cout << endl << "You found a letter! Isn't that exciting?" << endl;
            }
            cout << "You have " << MAX_TRIES - num_of_wrong_guesses;
            cout << " guesses left." << endl;
            if (word == unknown)
            {
                cout << word << endl;
                cout << "Yeah! You got it!" << endl;
                cout << "Press Enter to continue" << endl;
                break;
            }
        }
        if (num_of_wrong_guesses == MAX_TRIES)
        {
            cout << "Sorry, you lose...you've been hanged." << endl;
            cout << "The word was : " << word << endl;
            cout << "Press Enter to continue" << endl;
        }
        cin.ignore();
        cin.get();
        mainMenu();
    }

    else if (level == "2")
    {
        string average[] = { "bit", "runtime", "supercomputer" };

        int n = rand() % 3;
        word = average[n];

        string unknown(word.length(), '*');
        cout << "Each letter is represented by an asterisk." << endl;
        cout << "You have to type only one letter in one try." << endl;
        cout << "You have " << MAX_TRIES << " tries to try and guess the word." << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        while (num_of_wrong_guesses < MAX_TRIES)
        {
            cout << unknown << endl;
            cout << "Guess a letter: " << endl;
            cin >> letter;
            if (letterFill(letter, word, unknown) == 0)
            {
                cout << endl << "Whoops! That letter isn't in there!" << endl;
                num_of_wrong_guesses++;
                hangmanPicture(num_of_wrong_guesses);
            }
            else
            {
                cout << endl << "You found a letter! Isn't that exciting?" << endl;
            }
            cout << "You have " << MAX_TRIES - num_of_wrong_guesses;
            cout << " guesses left." << endl;
            if (word == unknown)
            {
                cout << word << endl;
                cout << "Yeah! You got it!";
                cout << "Press Enter to continue" << endl;
                break;
            }
        }
        if (num_of_wrong_guesses == MAX_TRIES)
        {
            cout << "Sorry, you lose...you've been hanged." << endl;
            cout << "The word was : " << word << endl;
            cout << "Press Enter to continue" << endl;
        }
        cin.ignore();
        cin.get();
        mainMenu();
    }

    else if (level == "3")
    {
        string hard[] = { "microprocessor", "nanotechnology", "telecommunication" };

        int n = rand() % 3;
        word = hard[n];

        string unknown(word.length(), '*');
        cout << "Each letter is represented by an asterisk." << endl;
        cout << "You have to type only one letter in one try." << endl;
        cout << "You have " << MAX_TRIES << " tries to try and guess the word." << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        while (num_of_wrong_guesses < MAX_TRIES)
        {
            cout  << unknown << endl;
            cout << "Guess a letter: " << endl;
            cin >> letter;
            if (letterFill(letter, word, unknown) == 0)
            {
                cout << endl << "Whoops! That letter isn't in there!" << endl;
                num_of_wrong_guesses++;
                hangmanPicture(num_of_wrong_guesses);
            }
            else
            {
                cout << endl << "You found a letter! Isn't that exciting?" << endl;
            }
            cout << "You have " << MAX_TRIES - num_of_wrong_guesses;
            cout << " guesses left." << endl;
            if (word == unknown)
            {
                cout << word << endl;
                cout << "Yeah! You got it!" << endl;
                cout << "Press Enter to continue" << endl;
                break;
            }
        }
        if (num_of_wrong_guesses == MAX_TRIES)
        {
            cout << "Sorry, you lose...you've been hanged." << endl;
            cout << "The word was : " << word << endl;
            cout << "Press Enter to continue" << endl;
        }
        cin.ignore();
        cin.get();
        mainMenu();
    }
}
int ClassUI::letterFill(char guess, string secretword, string &guessword)
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
void ClassUI::hangmanPicture(int wrong_guess)
{
    if (wrong_guess == 1)
    {
      cout << "_ ___" << endl;
    }
    else if (wrong_guess == 2)
    {
        cout << " |" << endl;
        cout << " |" << endl;
        cout << " |" << endl;
        cout << " |" << endl;
        cout << " |" << endl;
        cout << " |" << endl;
        cout << "_|___" << endl;
    }
    else if (wrong_guess == 3)
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
    else if (wrong_guess == 4)
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
    else if (wrong_guess == 5)
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
