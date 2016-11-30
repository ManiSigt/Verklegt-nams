#include "classui.h"
#include "listworker.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

classUI::classUI()
{

}

void classUI::run()
{
    bool runOn = true;
    string choice;
    do
    {
        cout << "List of things: " << endl;
        cout << "-----------------------------------------------------------" << endl;
        cout << "add - Add to the list" << endl;
        cout << "remove - Remove from the list" << endl;
        cout << "view - View the entire list" << endl;
        cout << "save - save the file" << endl;
        cout << "search - Search the list" << endl;
        cout << "sort - Sort the list by name/yearofbirth" << endl;
        cout << "exit - Exit" << endl;
        cin >> choice;
        if (choice != "exit"){
           select(choice);
        }
        else{
            runOn = false;
        }

    }while(runOn == true);
}

void classUI::select(string ch)
{
    if(ch == "add" || ch == "ADD" || ch == "Add" ){
        addPerson();
    }

    else if(ch == "view" || ch == "View" || ch == "VIEW")
    {
    viewAll();
    }
    else if(ch == "sort")
    {
        string sortcho;
        cout << "Enter 'name' or 'year' and then re-enter the 'view' command." << endl;
        cin >> sortcho;

        if(sortcho == "name")
        {
            list.sortNames();
        }
        else if(sortcho == "year")
        {
            list.sortBirth();
        }

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
    else
    {
        cout << "Invalid input" << endl;
    }
}
void classUI::view(int i)
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

void classUI::searching()
{

    cout << "----------Select any of the following options----------" << endl;
    cout << "What do you want to search for? " << endl;
    cout << "Name -- Searches for a name" << endl;
    cout << "Gender -- Searches for a Gender" << endl;
    cout << "Year -- Searches for a year born" << endl;
    search();
}
void classUI::addPerson()
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

void classUI::search()
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


void classUI::remove()
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
void classUI::save()
{
    list.saveFile();
}
void classUI::viewAll()
{
    for(int i = 0; i < list.getPersonsSize(); i++)
    {
        view(i);
    }
}
