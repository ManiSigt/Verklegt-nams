#ifndef CLASSUI_H
#define CLASSUI_H
#include "listworker.h"

class ClassUI
{
public:
    ClassUI();
    void mainMenu();             // This is the main menu for the program. It shows all commands to interact.
    void select(string ch);      // Checks the input from main menu and calls the correct function compared to the input.
    void viewPersons(int i);     // This prints out a single scientist from the vector.
    void viewComputers(int i);   // This prints out a single computer from the vector.
    void viewPer();              // This prints out the whole list of scientists, Name, Gender, Birth year, Death year and a comment.
    void viewCom();              // This prints out the whole list of computer, Name, type, date and if it was built.
    void addPerson();            // Add a person to the database
    void addComputer();          // Add a computer to the database
    void searchingScientist();   //
    void searchComputer();       //
    void searchingComputer();    // Checks what option you took in search for computer and then asks for what keyword you want to search for. And looks it up in the database and prints it out.
    void searchScientist();      // Checks what option you took in search for scientist and then asks for what keyword you want to search for. And looks it up in the database and prints it out.
    void selectSearch();
    void removeScientist();      // Checks if the person you wanted to delete is found then asks if you want to delete it or not, then removes it if the input was y and aborts if input was anything alse.
    void removeComputer();       // Checks if the computer you wanted to delete is found then asks if you want to delete it or not, then removes it if the input was y and aborts if input was anything alse.
    void yo();                   // Secret phase
    void viewMenu();
    void editPerson();           // Edit a scientist that already exists.
    void clearTheScreen();       // Function to clear the screen.
    void findComputerConnections(int i);
    void findScientistConnections();
    void removeConnection();
    void addConnection();
    void editComputer();
    void hangman();
    int fillIn(char guess, string secretword, string &guessword);
    void hangmanPicture(int wrong_guess);

private:
    bool runOn = true;
    ListWorker list;
    string getQuotes();         // The random quote generator.
    bool firstRun = true;

};

#endif // CLASSUI_H
