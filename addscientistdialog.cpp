#include "addscientistdialog.h"
#include "ui_addscientistdialog.h"
#include <QDebug>

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
        ui->error_name->setText("<span style='color: #FF1100'>No name in input!</span>");
        return;
    }
    QString birth = ui->input_scientist_birth->text();
    int birth1 = ui->input_scientist_birth->text().toUInt();
    if (birth.isEmpty())
    {
        ui->error_birth->setText("<span style='color: #FF1100'>No birth year in input!</span>");
        return;
    }
    if (birth1 < 0)
    {
        ui->error_birth->setText("<span style='color: #FF1100'>Not a valid birth year!</span>");
        return;
    }
    else if (birth1 > 2016)
    {
        ui->error_birth->setText("<span style='color: #FF1100'>Not a valid birth year!</span>");
        return;
    }
    QString death = ui->input_scientist_death->text();
    int death1 = ui->input_scientist_death->text().toUInt();
    if(death1 < birth1)
    {
        ui->error_birth->setText("<span style='color: #FF1100'>Not a valid death year!</span>");
        return;
    }
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
        this->done(1);
        qDebug() << "wassup";
    }
    else
    {
        this->done(-1);
        qDebug() << "mani ad flasha";
    }

}
