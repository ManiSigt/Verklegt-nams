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
        searching();
    }
}
void classUI::view()
{
    list.viewAll();
}

void classUI::searching()
{
    string searchChoice;
    cout << "----------Select any of the following options----------" << endl;
    cout << "What do you want to search for? " << endl;
    cout << "Name -- Searches for a name" << endl;
    cout << "Gender -- Searches for a Gender" << endl;
    cout << "Year -- Searches for a year born" << endl;
    cin >> searchChoice;
    if (searchChoice == "Name" || searchChoice == "name" || searchChoice == "NAME")
    {
            string namesearch;
            cout << "Enter a name you want to search for: ";
            cin >> namesearch;
            //if ( std::find(person.begin(), person.end(), namesearch) != person.end() )
              // cout << "We found the name you were looking for" << endl;
              // TODO: Setja inn þannig að allt prentist út tengt þessu nafni.
            //else
             // cout << "Sorry that name is not in our database, but you can add id in the 'Add' section in the main menu" << endl;
    }
    else if (searchChoice == "Gender" || searchChoice == "GENDER" || searchChoice == "gender")
    {
            char gendersearch;
            cout << "Enter a Gender you want to search for: ";
            cin >> gendersearch;
            //if ( std::find(person.begin(), person.end(), gendersearch) != person.end() )
              // cout << "We found the name you were looking for" << endl;
             // TODO: Setja inn þannig að allt prentist út tengt þessu kyni.
            //else
               //cout << "Sorry that name is not in our database, but you can add id in the 'Add' section in the main menu" << endl;
    }
    else if (searchChoice == "year" || searchChoice == "YEAR" || searchChoice == "Year")
    {
            int yearsearch;
            cout << "Enter a Year you want to search for: ";
            cin >> yearsearch;
            //if ( std::find(person.begin(), person.end(), yearsearch) != person.end() )
              // cout << "We found the name you were looking for" << endl;
              // TODO: Setja inn þannig að allt prentist út tengt þessu fæðingarári.
            //else
             //  cout << "Sorry that name is not in our database, but you can add id in the 'Add' section in the main menu" << endl;
    }
    else
    {
        cout << "Error reading input" << endl;
    }
}
