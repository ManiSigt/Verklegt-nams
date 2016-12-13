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
    void showComputers();
    void showConnections();
    void showScientists();
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

private:
    Ui::MainWindow *ui;
    ListWorker list;
};

#endif // MAINWINDOW_H
