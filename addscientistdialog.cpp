#include "addscientistdialog.h"
#include "ui_addscientistdialog.h"

addScientistDialog::addScientistDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addScientistDialog)
{
    ui->setupUi(this);
}

addScientistDialog::~addScientistDialog()
{
    delete ui;
}

void addScientistDialog::on_button_add_scientist_clicked()
{
    char sex = 'a';
    QString name = ui->input_scientist_name->text();
    if (name.isEmpty())
    {
        ui->error_name->setText("No name in input!");
        return;
    }
    QString birth = ui->input_scientist_birth->text();
    if (birth.isEmpty())
    {
        ui->error_birth->setText("no birth year in input!");
        return;
    }
    QString death = ui->input_scientist_death->text();
    QString comment = ui->input_scientist_comment->text();


    if(ui->radio_button_female->isChecked())
    {
        sex = 'F';
    }
    if(ui->radio_button_male->isChecked())
    {
        sex = 'M';
    }

    bool success = list.addNewScientist(name.toStdString(), sex , birth.toInt(), death.toInt(), comment.toStdString());
    if (success)
    {
        this->done(0);
    }
    else
    {
        this->done(1);
    }

}
