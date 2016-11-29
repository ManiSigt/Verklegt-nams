#include "classui.h"
#include "listworker.h"
#include <iostream>
#include <string>
#include <algorithm>

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
        cout << "###########################" << endl;
        cout << "add - Add to the list" << endl;
        cout << "view - View the entire list" << endl;
        cout << "search - Search the list" << endl;
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
    else if(ch == "view" || ch == "Veiw" || ch == "VEIW"){
    view();
    }
    else if(ch == "search" || ch == "Search" || ch == "SEARCH"){
        searching();
    }
}
void classUI::view()
{
    list.viewAll();
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
