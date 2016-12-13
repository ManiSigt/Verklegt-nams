#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "listworker.h"

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

    void on_input_scientist_textEdited(const QString &arg1);

    void on_input_computer_textEdited(const QString &arg1);

    void on_input_connections_textEdited(const QString &arg1);

private:
    Ui::MainWindow *ui;
    ListWorker list;
};

#endif // MAINWINDOW_H
