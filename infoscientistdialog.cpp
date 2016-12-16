#include "infoscientistdialog.h"
#include "ui_infoscientistdialog.h"
#include <QDebug>

infoScientistDialog::infoScientistDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::infoScientistDialog)
{
    ui->setupUi(this);
    //prepareShowSci(person);
}

infoScientistDialog::~infoScientistDialog()
{
    delete ui;
}
void infoScientistDialog::prepareShowSci(Person infoSci)
{
    currentID = infoSci.getScientistId();
    ui->label_show_name->setText(QString::fromStdString(infoSci.getScientistName()));
    if(infoSci.getScientistGender() == 'M')
    {
        ui->label_show_gender->setText("Male");
    }
    if(infoSci.getScientistGender() == 'F')
    {
        ui->label_show_gender->setText("Female");
    }
    ui->label_show_year_birth->setText(QString::number(infoSci.getScientistBirth()));
    if(infoSci.getScientistDeath() == 0)
    {
        ui->label_show_year_death->setText("");
    }
    else
    {
        ui->label_show_year_death->setText(QString::number(infoSci.getScientistDeath()));
    }

    ui->label_show_comment->setText(QString::fromStdString(infoSci.getScientistComment()));

}
