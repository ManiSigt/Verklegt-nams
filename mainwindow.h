#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "listworker.h"
#include "addscientistdialog.h"

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
    void showComputersName();
    void showComputersYear();
    void showComputersType();
    void showConnectionsNameSci();
    void showConnectionsNameComp();
    void showScientistsName();
    void showScientistsGender();
    void showScientistsBirthYear();
    void showScientistsDeathYear();
    void populateDropdownMenus();
    void on_dropdown_scientist_activated(const QString &arg1);
    void on_button_scientist_add_clicked();
    void on_table_scientist_clicked(const QModelIndex &index);
    void on_button_scientist_remove_clicked();
    void on_input_scientist_textEdited(const QString &arg1);
    void on_input_computer_textEdited(const QString &arg1);
    void on_input_connections_textEdited(const QString &arg1);
    void on_table_computer_clicked(const QModelIndex &index);
    void on_button_computer_remove_clicked();
    void on_button_connections_edit_clicked();
    void disableButtons();

    void on_button_scientist_edit_clicked();

    void on_button_computer_add_clicked();

    void on_button_computer_edit_clicked();

    void on_table_connections_clicked(const QModelIndex &index);

    void on_button_connections_remove_clicked();

    void on_action_add_scientist_triggered();

    void on_action_add_computer_triggered();

    void on_action_edit_scientist_triggered();

    void on_action_edit_computer_triggered();

private:
    Ui::MainWindow *ui;
    ListWorker list;
};

#endif // MAINWINDOW_H
