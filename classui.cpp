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
    search();

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
            //if( std::find(getPersons.begin(), getPersons.end(), namesearch) != getPersons.end() )
              //cout << "We found the name you were looking for" << endl;
              //TODO: Setja inn þannig að allt prentist út tengt þessu nafni.
            //else
             //cout << "Sorry that name is not in our database, but you can add a new instance in the 'Add' section in the main menu" << endl;
    }
    else if (searchChoice == "Gender" || searchChoice == "GENDER" || searchChoice == "gender")
    {
            char gendersearch;
            cout << "Enter a Gender you want to search for: ";
            cin >> gendersearch;
            //if ( std::find(getPersons.begin(), getPersons.end(), gendersearch) != getPersons.end() )
               //cout << "We found the name you were looking for" << endl;
             // TODO: Setja inn þannig að allt prentist út tengt þessu kyni.
            //else
               //cout << "Sorry that gender is not in our database, but you can add a new instance in the 'Add' section in the main menu" << endl;
    }
    else if (searchChoice == "year" || searchChoice == "YEAR" || searchChoice == "Year")
    {
            int yearsearch;
            cout << "Enter a Year you want to search for: ";
            cin >> yearsearch;
            //if ( std::find(getPersons.begin(), getPersons.end(), yearsearch) != getPersons.end() )
              // cout << "We found the name you were looking for" << endl;
              // TODO: Setja inn þannig að allt prentist út tengt þessu fæðingarári.
            //else
              //cout << "Sorry that year is not in our database, but you can add a new instance in the 'Add' section in the main menu" << endl;
    }
    else
    {
        cout << "Error reading input" << endl;
    }
}
