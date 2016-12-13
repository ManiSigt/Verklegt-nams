#include "addscientistdialog.h"
#include "ui_addscientistdialog.h"
#include "listworker.h"
#include <QString>



using namespace std;

AddScientistDialog::AddScientistDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddScientistDialog)
{
    ui->setupUi(this);
}

AddScientistDialog::~AddScientistDialog()
{
    delete ui;
}

void AddScientistDialog::on_button_addScientist_clicked()
{
    QString name = ui->input_scientistName->text();
    QString gender = ui->input_scientistGender->text();
    QString birth = ui->input_scientistBirth->text();
    QString death = ui->input_scientistDeath->text();
    QString comment = ui->input_scientistComment->text();

    //list2.addNewScientist(name.toStdString(), gender.toStdString(), birth.toInt(), death.toInt(), comment.toStdString());
/*
    if(name.isEmpty())
    {
        // do nothing, show some error later
        return;
    }

    if(gender.isEmpty())
    {
        // also do nothing
        return;
    }

    bool success = */
    //ListWorker.addNewScientist(name.toStdString(), gender.toStdString(), birth.toInt(), death.toInt(), comment.toStdString());

   /* if(success)
    {
        return;
    }
    else
    {

    }*/
}
