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
    else if(ch == "view" || ch == "View" || ch == "VIEW")
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
        remove();
    }
}
void classUI::view()
{
    for(unsigned int i = 0; i < list.getPersons.size(); i++)
    {
        cout << "#########################################" << endl;
        cout << "\t" << "Name: " << list.getPersons[i].getName() << endl;
        cout << "\t" << "Gender: " << list.getPersons[i].getGender() << endl;
        cout << "\t" << "Year of birth: " << list.getPersons[i].getBirth() << endl;
        if(list.getPersons[i].getDeath() == 0)
        {
            cout << "\t" << "Year of death: 'Still kickin'"  << endl;
        }
        else
        {
            cout << "\t" << "Year of death: " << list.getPersons[i].getDeath() << endl;
        }
    }
    cout << "#########################################" << endl;
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

void classUI::remove()
{
    string name;
    cout << "Enter a name of person that you want to remove: ";
    cin >> name;
    list.removePerson(name);


}
