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
        cout << "#########################################" << endl;
        cout << "add - Add to the list" << endl;
        cout << "remove - Remove from the list" << endl;
        cout << "view - View the entire list" << endl;
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
        list.addNewPerson();
    }
    else if(ch == "view" || ch == "Veiw" || ch == "VEIW")
    {
    view();
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
        //list.removePerson();
    }
}
void classUI::view()
{
    for(unsigned int i = 0; i < list.getPersons.size(); i++)
    {
        int nameSize  = list.getPersons[i].getNameSize();
        cout << nameSize << endl;
        cout << endl;
        cout << "Name" << "\t" << "\t" << "\t" << "\t" << "Gender" << "\t" << "Born" << "\t" << "Death" << "\t" << endl;
        cout << "-----------------------------------------------------------" << endl;
        cout << list.getPersons[i].getName();
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

        if(list.getPersons[i].getGender() == 'M')
        {
            cout << "Male" << "\t";
        }
        else
        {
            cout << "Female" << "\t";
        }
        cout << list.getPersons[i].getBirth();
        if(list.getPersons[i].getDeath() == 0)
        {
            cout << "\t" << "Still kickin'"  << endl;
        }
        else
        {
            cout << "\t" << list.getPersons[i].getDeath() << endl;
        }
        cout << endl;

    }
    cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
    cout << endl;
}

void classUI::searching()
{

    cout << "----------Select any of the following options----------" << endl;
    cout << "What do you want to search for? " << endl;
    cout << "Name -- Searches for a name" << endl;
    cout << "Gender -- Searches for a Gender" << endl;
    cout << "Year -- Searches for a year born" << endl;
    list.search();

}
