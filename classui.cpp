#include "classui.h"
#include "listworker.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

ClassUI::ClassUI()
{

}

void ClassUI::run()
{
    bool runOn = true;
    string choice;
    do
    {
        cout << "Welcome to the Amazing Database: " << endl;
        cout << "-----------------------------------------------------------" << endl;
        cout << "add" << "\t" << "Add a person to the database" << endl;
        cout << "remove" << "\t" << "Remove a person from the database" << endl;
        cout << "view" << "\t" << "View the entire database" << endl;
        cout << "save" << "\t" << "Save the database" << endl;
        cout << "search" << "\t" << "Search the database" << endl;
        cout << "sort" << "\t" << "Sort the database by name/yearofbirth" << endl;
        cout << "exit" << "\t" << "Exit" << endl;
        cin >> choice;
        if (choice != "exit"){
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
    if(ch == "add" || ch == "ADD" || ch == "Add" ){
        addPerson();
    }

    else if(ch == "view" || ch == "View" || ch == "VIEW")
    {
    viewAll();
    }
    else if(ch == "sort" || ch == "Sort" || ch == "SORT")
    {
        string sortcho;
        cout << "Enter 'name' or 'year' and then re-enter the 'view' command." << endl;
        cin >> sortcho;

        if(sortcho == "name" || sortcho == "Name" || sortcho == "NAME")
        {
            list.sortNames();
        }
        else if(sortcho == "year" || sortcho == "Year" || sortcho == "YEAR")
        {
            list.sortBirth();
        }
        viewAll();

    }
    else if(ch == "search" || ch == "Search" || ch == "SEARCH"){
        searching();
    }
    else if(ch == "remove" || ch == "Remove" || ch == "REMOVE"){
        remove();
    }
    else if(ch == "save" || ch == "Save" || ch == "SAVE"){
        save();
    }
    else if(ch == "yo" || ch == "Yo" || ch == "yO" || ch == "YO")
    {
        yo();
    }
    else
    {
        cout << "Invalid input" << endl;
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
        cout << "\t" << "|Still kickin'"  << endl;
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

    cout << "----------Select any of the following options----------" << endl;
    cout << "What do you want to search for? " << endl;
    cout << "Name -- Searches for a name" << endl;
    cout << "Gender -- Searches for a Gender" << endl;
    cout << "Year -- Searches for a year born" << endl;
    search();
}
void ClassUI::addPerson()
{
    string name;
    char gender;
    int yearOfBirth = 0;
    int yearOfDeath = 0;
    string comment;

    cout << "Input Name: ";
    cin.ignore();
    std::getline(std::cin,name);
    cout << "Input gender (M/F): ";
    cin >> gender;
    if (gender == 'm' || gender == 'M' || gender == 'f' || gender == 'F')
    {
        if(gender == 'M')
        {
            gender = 'm';
        }
        else if (gender == 'F')
        {
            gender = 'f';
        }
       cout << "Input year of birth: ";
       cin >> yearOfBirth;
       cout << "Input year of death: ";
       cin >> yearOfDeath;
       cout << "Input a comment: ";
       cin >> comment;
    }
    else
    {
        cout << "Invalid gender! Try again." << endl;
        addPerson();
    }
    list.addNewPerson(name, gender, yearOfBirth, yearOfDeath, comment);

}

void ClassUI::search()
{
        string searchChoice;
        cin >> searchChoice;
        if (searchChoice == "Name" || searchChoice == "name" || searchChoice == "NAME")
        {
                string namesearch;
                cout << "Enter a name you want to search for: ";
                cin >> namesearch;


                for(int i = 0; i < list.getPersonsSize();++i)
                {
                    if(namesearch == list.getName(i))
                    {
                        namesearch =  list.getName(i);
                        view(i);
                    }
                }
                /*if ( eitthvad dot)
                {
                    cout << "Sorry that name is not in our database, but you can add a new instance in the 'Add' section in the main menu" << endl;
                }*/

        }
        else if (searchChoice == "Gender" || searchChoice == "GENDER" || searchChoice == "gender")
        {
                char gendersearch;

                cout << "Enter a Gender you want to search for: (m/f)";
                cin >> gendersearch;
                if(gendersearch == 'M')
                    {
                         gendersearch = 'm';
                    }
                else if (gendersearch == 'F')
                    {
                         gendersearch = 'f';
                    }

                for(int i = 0; i < list.getPersonsSize();++i)
                {
                    if(gendersearch == list.getGender(i))
                    {
                        gendersearch = list.getGender(i);
                        view(i);
                        cout << "blabla" << endl;
                    }
                }
                /*
                if (eitthvad dot)
                {
                    cout << "Sorry that gender is not in our database, but you can add a new instance in the 'Add' section in the main menu" << endl;
                }*/

        }
        else if (searchChoice == "year" || searchChoice == "YEAR" || searchChoice == "Year")
        {
                int yearsearch;
                cout << "Enter a Year you want to search for: ";
                cin >> yearsearch;


                for(int i = 0; i < list.getPersonsSize();++i)
                {
                    if(yearsearch == list.getBirth(i))
                    {
                        yearsearch = list.getBirth(i);

                         view(i);
                    }
                }/*
                if (eitthvad dot)
                {
                    cout << "Sorry that year is not in our database, but you can add a new instance in the 'Add' section in the main menu" << endl;
                }*/
           }
        else
        {
            cout << "Error reading input" << endl;
        }

}


void ClassUI::remove()
{
    string name;
    cout << "Enter a name of person that you want to remove: ";
    cin >> name;
    if (list.removePerson(name) == true)
    {
        cout << "Person removed!" << endl;
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
