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
    QString birth = ui->input_scientist_birth->text();
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
    //Á eftir að útfæra villutékk og útfæra að gluggi lokist þegar búið er að adda scientist.
    if (success)
    {
        this->done(0);
    }
    else
    {
        this->done(1);
    }

}
