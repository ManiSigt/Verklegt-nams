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
    void showThings();
    void showComputers();

    void on_tabWidget_tabBarClicked(int index);

private:
    Ui::MainWindow *ui;
    ListWorker listWorker;
};

#endif // MAINWINDOW_H
