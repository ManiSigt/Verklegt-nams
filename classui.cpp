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
        cout << " (1) - "  << "Add a scientist to the database." << endl;
        cout << " (2) - "  << "Remove a scientist from the database." << endl;
        cout << " (3) - "  << "View the entire database." << endl;
        cout << " (4) - "  << "Save the database." << endl;
        cout << " (5) - "  << "Search the database." << endl;
        cout << " (6) - "  << "Sort the database." << endl;
        cout << " (7) - "  << "Edit a scientist." << endl;
        cout << " (8) - "  << "Exit." << endl;
        cout << "Enter your command (1 - 8): ";
        cin >> choice;
        if (choice != "8")
        {
           select(choice);
        }
        else
        {
            list.saveFile();
            runOn = false;
        }
    }while(runOn == true);

    cout << endl;

}
void ClassUI::select(string ch)
{
    if(ch == "1")
    {
        cin.ignore();           // When using editPerson it will ignore the first letter unless this ignore is here rather then in addPerson
        addPerson();
    }
    else if(ch == "2")
    {
        remove();
    }
    else if(ch == "3")
    {
        viewAll();
    }
    else if(ch == "4")
    {
        save();
    }
    else if(ch == "5")
    {
        searching();
    }
    else if(ch == "6")
    {
        sorting();
    }
    else if(ch == "7")
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
void ClassUI::view(int i)
{
    cout << "--------------------------------------------------------------" << endl;
    int nameSize  = list.getNameSize(i);

    cout << list.getName(i);

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

    if(list.getGender(i) == 'M' || list.getGender(i) == 'm')
    {
        cout << "|Male" << "\t";
    }
    else
    {
        cout << "|Female" << "\t";
    }

    cout  << "|" << list.getBirth(i);

    if(list.getDeath(i) == 0)
    {
        cout << "\t" << "| n/a"  << "\t" << "|" << list.getAge(i) << endl;
    }
    else
    {
        cout << "\t" << "|" << list.getDeath(i) << "\t" << "|" << list.getAge(i) <<  endl;
    }

    cout << list.getComment(i) << endl;
}
void ClassUI::viewAll()
{
    cout << "--------------------------------------------------------------" << endl;
    cout << "Name" << "\t" << "\t" << "\t" << "\t" << "|Gender " << "|Born " << "\t" << "|Death"  << "\t" << "|Age" << endl;
    for(int i = 0; i < list.personsSize(); i++)
    {
        view(i);
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
void ClassUI::searching()
{
    cout << "-------------Select any of the following commands-------------" << endl;
    cout << "What do you want to search for?" << endl;
    cout << " (1) - Search by name." << endl;
    cout << " (2) - Search by gender." << endl;
    cout << " (3) - Search by year of birth." << endl;
    cout << " (4) - Search by age." << endl;
    cout << " (5) - Return to main menu." << endl;

    search();
}
void ClassUI::search()
{
    string searchChoice;
    cout << "Enter your command (1 - 4): ";
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
            std::size_t found = list.getName(i).find(namesearch);
            if (found!=std::string::npos)
            {
                view(i);
            }
        }

        if(list.nameSearcher(namesearch) == false)
        {
            cout << "Sorry that name is not in our database, but you can add a new scientist in the 'Add section' in the main menu." << endl;
            searching();
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
            if(gendersearch == list.getGender(i))
            {
                gendersearch = list.getGender(i);
                view(i);
            }
        }

        if(list.genderSearcher(gendersearch) == false)
        {
            cout << "Sorry that gender is not in our database, but you can add a new scientist in the 'Add section' in the main menu." << endl;
            searching();
        }
    }
    else if (searchChoice == "3")
    {
            int yearsearch;
            cout << "Enter a year you want to search for: ";
            cin >> yearsearch;

            for(int i = 0; i < list.personsSize();++i)
            {
                if(yearsearch == list.getBirth(i))
                {
                    yearsearch = list.getBirth(i);
                    view(i);
                }
            }

            if(list.yearSearcher(yearsearch) == false)
            {
                cout << "Sorry that year is not in our database, but you can add a new scientist in the 'Add section' in the main menu." << endl;
                searching();
            }
    }
    else if (searchChoice == "4")
    {
        int agesearch;
        cout << "Enter a age you want to search for: ";
        cin >> agesearch;

        for(int i = 0; i < list.personsSize();++i)
        {
            if(agesearch == list.getAge(i))
            {
                agesearch = list.getAge(i);
                view(i);
            }
        }

        if(list.ageSearcher(agesearch) == false)
        {
            cout << "Sorry that age is not in our database, but you can add a new scientist in the 'Add section' in the main menu." << endl;
            searching();
        }
    }
    else if (searchChoice == "5")
    {
        mainMenu();
    }
    else
    {
        cout << "Error reading input. Please enter a number between 1- 3." << endl;
        search();
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
        cout << "scientist found!" << endl;
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
void ClassUI::save()
{
    list.saveFile();
    cout << "Database saved." << endl;
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
    string sortcho;
    cout << "Enter a sort command:" << endl;
    cout << "--------------------------------------------------------------" << endl;
    cout << " (1) - Sort by alphabetical order." << endl;
    cout << " (2) - Sort by chronological order." << endl;
    cout << " (3) - Sort by gender." << endl;
    cout << " (4) - Return to main menu." << endl;
    cout << "Enter your command (1 - 4): ";
    cin >> sortcho;
    cout << endl;

    if(sortcho == "1")
    {
        list.sortNames();
         viewAll();
    }
    else if(sortcho == "2")
    {
        list.sortBirth();
         viewAll();
    }
    else if(sortcho == "3")
    {
        list.sortGender();
        viewAll();
    }
    else if(sortcho == "4")
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
        cout << "Press any key to continue...";
        cin.get();
    }
}
/*
void ClassUI::clearTheScreen() //
{
    #if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
        system("clear");
    #endif

    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #endif
}
*/
