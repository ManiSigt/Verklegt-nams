#include "classui.h"
#include "listworker.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <time.h>

using namespace std;

ClassUI::ClassUI()
{

}
void ClassUI::run()
{
    cout << "\t" << "Welcome to the Amazing Database! " << endl;
    cout << "--------------------------------------------------------------" << endl;
    cout << "\t" << "   *** Quote of the day ***" << endl;
    cout << getQuotes() << endl;
    mainMenu();
}
void ClassUI::mainMenu()
{
    string choice;
    do
    {
        cout << "-----------------------------------------------------------" << endl;
        cout << " (1) - " << "\t" << "Add a person to the database." << endl;
        cout << " (2) - " << "\t" << "Remove a person from the database." << endl;
        cout << " (3) - " << "\t" << "View the entire database." << endl;
        cout << " (4) - " << "\t" << "Save the database." << endl;
        cout << " (5) - " << "\t" << "Search the database." << endl;
        cout << " (6) - " << "\t" << "Sort the database." << endl;
        cout << " (7) - " << "\t" << "Exit." << endl;
        cout << "Enter your command (1 - 7): ";
        cin >> choice;
        cout << endl;

        if (choice != "7")
        {
           select(choice);
        }
        else{
            list.saveFile();
            runOn = false;
        }
    }while(runOn == true);
}
void ClassUI::select(string ch)
{
    if(ch == "1")
    {
        addPerson();
    }

    else if(ch == "3")
    {
        viewAll();
    }
    else if(ch == "6")
    {
        string sortcho;
        cout << "Enter a sort command (1 - 3):" << endl;
        cout << "------------------------" << endl;
        cout << " (1) - Sort by alphabetical order" << endl;
        cout << " (2) - Sort by chronological order" << endl;
        cout << " (3) - Return to main menu" << endl;
        cout << "Enter your command (1 - 2): ";
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
            mainMenu();
        }

    }
    else if(ch == "5")
    {
        searching();
    }
    else if(ch == "2")
    {
        remove();
    }
    else if(ch == "4")
    {
        save();
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
    int nameSize  = list.getNameSize(i);
    cout << endl;
    cout << "--------------------------------------------------------------" << endl;
    cout << "Name" << "\t" << "\t" << "\t" << "\t" << "|Gender " << "|Born " << "\t" << "|Death" << endl;
    cout << "--------------------------------|-------|-------|-------------" << endl;
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
        cout << "\t" << "| n/a"  << endl;
    }
    else
    {
        cout << "\t" << "|" << list.getDeath(i)  << endl;
    }
    cout << list.getComment(i) << endl;
    cout << "--------------------------------------------------------------" << endl;
    cout << endl;
}
void ClassUI::searching()
{

    cout << "-------------Select any of the following commands-------------" << endl;
    cout << "What do you want to search for? (1 - 4)" << endl;
    cout << " (1) - Searches for a name." << endl;
    cout << " (2) - Searches for a Gender." << endl;
    cout << " (3) - Searches for a year born." << endl;
    cout << " (4) - Return to main menu" << endl;

    search();
}
void ClassUI::addPerson()
{
    string name;
    char gender;
    char yesOrNo;
    int yearOfBirth = 0;
    int yearOfDeath = 0;
    string comment;

    cout << "Input Name: ";
    cin.ignore();
    std::getline(std::cin,name);
    cout << "Input gender (M/F): ";
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
       cout << "Input year of birth: ";
       cin >> yearOfBirth;

       cout << "Is the individual deceased? (y/n)";
       cin >> yesOrNo;
       if (yesOrNo == 'Y' || yesOrNo == 'y')
       {
            cout << "Input year of death: ";
            cin >> yearOfDeath;
       }
        cout << "Input a comment about the individual: ";
        cin.ignore();
        std::getline(std::cin,comment);
    }
    else
    {
        cout << "Invalid gender! Try again." << endl;
        addPerson();
    }
    cout << "Are you sure that you want to add this person? (y/n)"; // Þetta er ógeðslegur texti, endilega finnum eitthvað skárra
    string validatePerson;
    cin >> validatePerson;
    if(validatePerson == "y")
    {
        cout << "New person added!" << endl;
        list.addNewPerson(name, gender, yearOfBirth, yearOfDeath, comment);
    }
    else
    {
        cout << "Operation addPerson aborted!" << endl; // Endilega komið með tillögu að breytingu á þessum texta
    }
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
        cout << "Enter a name you want to search for: ";
        cin.ignore();
        std::getline(std::cin,namesearch);

        for(int i = 0; i < list.getPersonsSize();++i)
        {
            std::size_t found = list.getName(i).find(namesearch);
            if (found!=std::string::npos)
            {
                view(i);
            }
        }
        if(list.nameSearcher(namesearch) == false)
        {
            cout << "Sorry that name is not in our database, but you can add a new instance in the 'Add' section in the main menu." << endl;
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

        for(int i = 0; i < list.getPersonsSize();++i)
        {
            if(gendersearch == list.getGender(i))
            {
                gendersearch = list.getGender(i);
                view(i);
            }
        }
        if(list.genderSearcher(gendersearch) == false)
        {
            cout << "Sorry that gender is not in our database, but you can add a new instance in the 'Add' section in the main menu." << endl;
            searching();
        }
    }
    else if (searchChoice == "3")
    {
            int yearsearch;
            cout << "Enter a year you want to search for: ";
            cin >> yearsearch;

            for(int i = 0; i < list.getPersonsSize();++i)
            {
                if(yearsearch == list.getBirth(i))
                {
                    yearsearch = list.getBirth(i);
                    view(i);
                }
            }
            if(list.yearSearcher(yearsearch) == false)
            {
                cout << "Sorry that year is not in our database, but you can add a new instance in the 'Add' section in the main menu." << endl;
                searching();
            }
    }
    else if (searchChoice == "4")
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
    cout << "Enter the full name of the person that you want to remove: ";
    cin.ignore();
    std::getline(std::cin,name);
    if (list.removePersonFound(name) == true)
    {
        char validateRemove;
        cout << "Person found!" << endl;
        cout << "Are you sure you want to remove this person? (y/n): ";
        cin >> validateRemove;

        if(validateRemove == 'y' || validateRemove == 'Y')
        {
            if(list.removePerson(name) == true)
            {
                cout << "Person removed!" << endl;
            }
            else
            {
                cout << "Person not removed!" << endl;
            }
        }
    }
    else
    {
        cout << "Person not found!" << endl;
    }
}
void ClassUI::save()
{
    list.saveFile();
}
void ClassUI::viewAll()
{
    for(int i = 0; i < list.getPersonsSize(); i++)
    {
        view(i);
    }
}
void ClassUI::yo()
{
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
