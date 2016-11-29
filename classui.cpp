#include "classui.h"
#include "listworker.h"
#include <iostream>
#include <string>

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
        cout << "Destroy" << endl;
    }
}
void classUI::view()
{
    list.viewAll();
}
