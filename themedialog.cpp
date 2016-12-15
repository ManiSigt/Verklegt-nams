#include "themedialog.h"
#include "ui_themedialog.h"

ThemeDialog::ThemeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ThemeDialog)
{
    ui->setupUi(this);
}

ThemeDialog::~ThemeDialog()
{
    delete ui;
}

void ThemeDialog::on_theme_ok_button_clicked()
{
    if(ui->theme_skull_radio_button->isChecked())
    {

    }
    if(ui->theme_sexy_radio_button->isChecked())
    {

    }
    if(ui->theme_christmas_radio_button->isChecked())
    {

    }
    this->close();
}

void ThemeDialog::on_theme_cancel_button_clicked()
{
    this->close();
}
