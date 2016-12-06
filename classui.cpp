#include "classui.h"
#include "listworker.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <time.h>
#include <stdlib.h>

using namespace std;

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
        cout << " (5) - "  << "Sort." << endl;
        cout << " (6) - "  << "Edit a scientist." << endl;
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
        cout << " (3) - Return to main menu." << endl;
        cout << "Enter your command (1 - 3): ";
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
        remove();
    }
    else if(ch == "3")
    {
        string choice;
        cout << " (1) - View scientists." << endl;
        cout << " (2) - View computers." << endl;
        cout << " (3) - Return to main menu." << endl;
        cout << "Enter your command (1 - 3): ";
        cin >> choice;
        if (choice == "1")
        {
            viewPer();
        }
        else if (choice == "2")
        {
            viewCom();
        }
        else if (choice == "3")
        {
            return mainMenu();
        }
        else
        {
            cout << "Invalid input. Please enter a number between 1 - 3." << endl;
            select("3");
        }
    }
    else if(ch == "4")
    {
        selectSearch();
    }
    else if(ch == "5")
    {
        sorting();
    }
    else if(ch == "6")
    {
        editPerson();
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

    cout << list.getCommentperson(i) << endl;
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
        string Type;
        string isbuilt;
        int Yearbuilt = 0;

        cout << "--------------------------------------------------------------" << endl;
        cout << "Enter name of the Computer: ";
        std::getline(std::cin,name);
        cout << "Enter the type of the computer: ";
        cin >> Type;
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
            list.addNewComputer(name, Type ,Yearbuilt, isbuilt);
        }
        else
        {
            cout << "scientist not added!" << endl;
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
        mainMenu();
    }
    else
    {
        cout << "Error reading input. Please enter a number between 1- 3." << endl;
        return searchScientist();
    }
}
void ClassUI::remove()
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
        cout << "Serson not found!" << endl;
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
void ClassUI::sorting()
{
    string sortBy;
    string sortcho;
    cout << "Enter a sort command:" << endl;
    cout << "--------------------------------------------------------------" << endl;
    cout << " (1) - Sort by Scientists." << endl;
    cout << " (2) - Sort by Computers." << endl;
    cout << " (3) - Return to main menu" << endl;
    cout << "Enter your command (1 - 3): ";
    cin >> sortBy;
    cout << endl;

    if(sortBy == "1")
    {
        cout << "Enter a sort command for Scientists:" << endl;
        cout << "--------------------------------------------------------------" << endl;
        cout << " (1) - Sort by alphabetical order." << endl;
        cout << " (2) - Sort by chronological order." << endl;
        cout << " (3) - Sort by gender." << endl;
        cout << " (4) - Sort by age." << endl;
        cout << " (5) - Return to main menu." << endl;
        cout << "Enter your command (1 - 5): ";
        cin >> sortcho;
        //cout << endl;

        if(sortcho == "1")
        {
            list.sortScientistNames();
            viewPer();
        }
        else if(sortcho == "2")
        {
            list.sortScientistBirth();
            viewPer();
        }
        else if(sortcho == "3")
        {
            list.sortScientistGender();
            viewPer();
        }
        else if(sortcho == "4")
        {
            list.sortScientistAge();
            viewPer();

        }
        else if(sortcho == "5")
        {
            mainMenu();
        }
        else
        {
            cout << "That is not a valid command! Try again." << endl;
            sorting();
        }
    }

    else if(sortBy == "2")
    {
        cout << "Enter a sort command for Computers:" << endl;
        cout << "--------------------------------------------------------------" << endl;
        cout << " (1) - Sort by alphabetical order." << endl;
        cout << " (2) - Sort by chronological order." << endl;
        cout << " (3) - Sort by type." << endl;
        cout << " (4) - Return to main menu." << endl;
        cout << "Enter your command (1 - 4): ";
        cin >> sortcho;
        cout << endl;

        if(sortcho == "1")
        {

        }
        else if(sortcho == "2")
        {

        }
        else if(sortcho == "3")
        {

        }
        else if(sortcho == "4")
        {

        }
    }


    else if(sortBy == "3")
    {
        mainMenu();
    }
    else
    {
        cout << "That is not a valid command! Try again." << endl;
        sorting();
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
/*
void ClassUI::clearTheScreen() //A function that we wanted to use but had platform issues following it's use.
{
    #if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
        system("clear");
    #endif

    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #endif
}
*/
/*
void ClassUI::editComputer()
{
    string cmpname;
    cout << "Enter the full name of the computer that you want to edit: ";
    cin.ignore();
    std::getline(std::cin,cmpname);
    if(list.removePersonFound(cmpname))
    {
        list.removePerson(cmpname);
        addPerson();
    }
    else
    {
        cout << "Computer not found!" << endl;
    }
}
*/
