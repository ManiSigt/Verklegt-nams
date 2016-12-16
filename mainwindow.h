#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "listworker.h"
#include "addscientistdialog.h"
#include "addcomputerdialog.h"

#include <string>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void christmasTheme();                                  // The setup for the christmas theme, makes all the icons into christmas icons.
    void sexyTheme();                                       // The setup for the sexy theme, makes all the icons into sexy icons.
    void skullTheme();                                      // The setup for the skull theme, makes all the icons into skull icons.
    void defaultTheme();                                    // The setup for the normal theme, makes all the icons normal.
    void showComputersName();                               // Adds the computer name to the table in the mainwindow.
    void showComputersYear();                               // Adds the computer year to the table in the mainwindow.
    void showComputersType();                               // Adds the computer type to the table in the mainwindow.
    void showConnectionsNameSci();                          // Adds the scientist name to the connection table in the mainwindow.
    void showConnectionsNameComp();                         // Adds the computer name to the connection table in the mainwindow.
    void showScientistsName();                              // Adds the scientist name to the table in the mainwindow.
    void showScientistsGender();                            // Adds the scientist gender to the table in the mainwindow.
    void showScientistsBirthYear();                         // Adds the scientist birth year to the table in the mainwindow.
    void showScientistsDeathYear();                         // Adds the scientist death year to the table in the mainwindow.
    void populateDropdownMenus();                           // Adds selection menu to the dropdown menu, for search.
    void on_button_scientist_add_clicked();                 // A function that dictates what happens when the user presses a specific button.
    void on_table_scientist_clicked();                      // A function that dictates what happens when the user presses a specific button.
    void on_button_scientist_remove_clicked();              // A function that dictates what happens when the user presses a specific button.
    void on_input_scientist_textEdited();                   // Searches for input in the text box in the scientist menu.
    void on_input_computer_textEdited();                    // Searches for input in the text box in the computer menu.
    void on_input_connections_textEdited();                 // Searches for input in the text box in the connections menu.
    void on_table_computer_clicked();                       // Makes the buttons available if you click on a item in the table menu.
    void on_button_computer_remove_clicked();               // A function that dictates what happens when the user presses a specific button.
    void on_button_connections_edit_clicked();              // A function that dictates what happens when the user presses a specific button.
    void disableButtons();                                  // Disables buttons, f.e. the remove button after you remove someone.
    void on_button_scientist_edit_clicked();                // A function that dictates what happens when the user presses a specific button.
    void on_button_computer_add_clicked();                  // A function that dictates what happens when the user presses a specific button.
    void on_button_computer_edit_clicked();                 // A function that dictates what happens when the user presses a specific button.
    void on_table_connections_clicked();                    // A function that dictates what happens when the user presses a specific button.
    void on_button_connections_remove_clicked();            // A function that dictates what happens when the user presses a specific button.
    void on_tabWidget_tabBarClicked();                      // A function that dictates what happens when the user presses a specific button.
    void on_actionRed_triggered();                          // Makes the background color cyan when clicked.
    void on_actionPink_triggered();                         // Makes the background color pink when clicked.
    void on_actionWhite_triggered();                        // Makes the background color crimson when clicked.
    void on_actionOrange_triggered();                       // Makes the  background color orange when clicked.
    void on_button_connections_add_clicked();               // a function that dictates what happens when the user presses a specific button.
    void on_actionNormal_triggered();                       // Changes the background color back to normal.
    void on_button_connections_theme_clicked();             // A function that dictates what happens when the user presses a specific button.
    void on_button_computer_theme_clicked();                // A function that dictates what happens when the user presses a specific button.
    void on_button_scientist_theme_clicked();               // A function that dictates what happens when the user presses a specific button.
    void on_button_scientist_info_clicked();                // A function that dictates what happens when the user presses a specific button.
    void on_button_computer_info_clicked();                 // A function that dictates what happens when the user presses a specific button.
    void on_tabWidget_tabBarClicked(int index);             // Automaticly disables all buttons when you switch between tabs.

private:
    Ui::MainWindow *ui;
    ListWorker list;
    addComputerDialog addComp;
};

#endif // MAINWINDOW_H
