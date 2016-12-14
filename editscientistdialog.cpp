#include "editscientistdialog.h"
#include "ui_editscientistdialog.h"

EditScientistDialog::EditScientistDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditScientistDialog)
{
    ui->setupUi(this);
}

EditScientistDialog::~EditScientistDialog()
{
    delete ui;
}

void EditScientistDialog::prepare(Person esci)
{
    currentId = esci.getScientistId();
    ui->input_scientist_name->insert(QString::fromStdString(esci.getScientistName()));

    if(esci.getScientistGender() == 'm' || esci.getScientistGender() == 'M')
    {
        ui->edit_scientist_radio_button_male->setChecked(true);
    }
    if(esci.getScientistGender() == 'f' || esci.getScientistGender() == 'F')
    {
        ui->edit_scientist_radio_button_female->setChecked(true);
    }

    ui->input_scientist_birth->insert(QString::number(esci.getScientistBirth()));
    ui->input_scientist_death->insert(QString::number(esci.getScientistDeath()));
    ui->input_scientist_comment->insert(QString::fromStdString(esci.getScientistComment()));
}

void EditScientistDialog::on_button_add_scientist_clicked()
{
    char gender = 'a';
    string name = ui->input_scientist_name->text().toStdString();
    int birth = ui->input_scientist_birth->text().toUInt();
    int death = ui->input_scientist_death->text().toUInt();
    string comment = ui->input_scientist_comment->text().toStdString();

    if(ui->edit_scientist_radio_button_female->isChecked())
    {
        gender = 'F';
    }
    else
    {
        gender = 'M';
    }


    elist.updateScientist(name,gender,birth,death,comment,currentId);
}


//updateScientist(string name,char gender, int birth, int death, string comment, int sciId)
