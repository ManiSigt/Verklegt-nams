#ifndef CLASSUI_H
#define CLASSUI_H
#include "listworker.h"

class ClassUI
{
public:
    ClassUI();
    void addPerson();           // Add a person to the database
    void mainMenu();            // This is the main menu for the program. It shows all commands to interact.
    void remove();              // Checks if the person you wanted to delete is found then asks if you want to delete it or not, then removes it if the input was y and aborts if input was anything alse.
    void run();                 // This prints out a welcome message and prints out a random quote, then calls main menu.
    void save();                // Calls the savefile function in the datalayer class.
    void search();              // Checks what option you took in searching and then asks for what keyword you want to search for, and looks it up in the database and prints it out
    void searching();           // Prints out the options to search for in search then calls search.
    void select(string ch);     // Checks the input from main menu and calls the correct function compared to the input.
    void sorting();             // Prints out a list of things to sort and asks for a input then calls the sort functions in the listworker class.
    void view(int i);           // This prints out a single  scientist from the vector.
    void viewAll();             // This prints out the whole list of scientists, Name, Gender, Birth year, Death year and a comment.
    void yo();                  // Secret phase
    void editPerson();          // Edit a scientist that already exists.
    void clearTheScreen();      // Function to clear the screen.
private:
    bool runOn = true;
    ListWorker list;
    string getQuotes();         // The random quote generator.

};

#endif // CLASSUI_H
