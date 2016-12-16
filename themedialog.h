#ifndef THEMEDIALOG_H
#define THEMEDIALOG_H
#include "mainwindow.h"
#include <QDialog>

namespace Ui {
class ThemeDialog;
}

class ThemeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ThemeDialog(QWidget *parent = 0);
    ~ThemeDialog();

private slots:
    void on_theme_ok_button_clicked();                          // a function that dictates what happens when the user presses a specific button
    void on_theme_cancel_button_clicked();                      // a function that dictates what happens when the user presses a specific button

private:
    Ui::ThemeDialog *ui;
};

#endif // THEMEDIALOG_H
