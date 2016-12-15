#include "editscientistdialog.h"
#include "ui_editscientistdialog.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QPixmap>

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
    if(esci.getScientistDeath() == 0)
    {
        ui->input_scientist_death->insert("n/a");
    }
    else
    {
        ui->input_scientist_death->insert(QString::number(esci.getScientistDeath()));
    }
    ui->input_scientist_comment->insert(QString::fromStdString(esci.getScientistComment()));
}

void EditScientistDialog::on_button_scientist_edit_cancel_clicked()
{
    close();
}

void EditScientistDialog::on_button_scientist_edit_clicked()
{
    int error = 0;
    int birth = -1;
    int death = -1;
    char gender = 'a';
    string name = ui->input_scientist_name->text().toStdString();
    birth = ui->input_scientist_birth->text().toUInt();
    if(ui->input_scientist_death->text() == "n/a")
    {
        death = 0;
    }
    else
    {
        death = ui->input_scientist_death->text().toUInt();
    }
    string comment = ui->input_scientist_comment->text().toStdString();

    if(ui->edit_scientist_radio_button_female->isChecked())
    {
        gender = 'F';
    }
    else
    {
        gender = 'M';
    }


    if(name == "")
    {
        QMessageBox::warning(this, "Error!", "Name can not be empty!");
        error++;
    }

    if(birth <= 0 || birth >= 2016 || birth == -1)
    {
        QMessageBox::warning(this, "Error!", "Not a valid year of birth!");
        error++;
    }
    if(death != 0)
        {
        if(death - birth <= 0)
            {
                QMessageBox::warning(this, "Error!", "Not a valid year of death!");
                error++;
            }
        }

    if(error == 0)
    {
        bool success = elist.updateScientist(name, gender, birth, death, comment, currentId);
        if (success)
        {
            this->done(1);
        }
        else
        {
            this->done(-1);
        }
    }
}

void EditScientistDialog::on_button_file_open_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
            tr("Jpg image"), "",
            tr("Image file (*.jpg);;All Files (*)"));
    ui->input_imagename->setText(fileName);
    elist.updateScientistImage(fileName);
    QPixmap  mypix(fileName);

    int w = mypix.width();
    int h = mypix.height();

    int labelHeight = ui->label_image->height();

    qDebug() << w << " " << h << " " << labelHeight;
    if(h >= w)
    {
        do
        {

            h--;
            w--;

        }while(h >= 250);
    }
    else
        do
        {

            h--;
            w--;

        }while(w >= 350);
    qDebug() << w << " " << h << " " << labelHeight;

    ui->label_image->setPixmap(mypix);
    ui->label_image->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    ui->label_image->setPixmap(mypix.scaled(w,h,Qt::KeepAspectRatioByExpanding));
}

void EditScientistDialog::on_button_file_save_clicked()
{

}
