#include "editcomputerdialog.h"
#include "ui_editcomputerdialog.h"
#include "computer.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QPixmap>

EditComputerDialog::EditComputerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditComputerDialog)
{
    ui->setupUi(this);
}
EditComputerDialog::~EditComputerDialog()
{
    delete ui;
}
void EditComputerDialog::prepare(Computer ecom)
{
    currentId = ecom.getComputerId();
    ui->input_computer_name->insert(QString::fromStdString(ecom.getComputerName()));
    ui->input_computer_type->insert(QString::fromStdString(ecom.getComputerType()));
    ui->input_computer_date->insert(QString::number(ecom.getComputerDate()));
}

void EditComputerDialog::on_button_computer_edit_clicked()
{
    int error = 0;
    string built = "";
    string name = ui->input_computer_name->text().toStdString();
    int date = ui->input_computer_date->text().toUInt();
    string type = ui->input_computer_type->text().toStdString();

    if(ui->edit_computer_radiobutton_yes->isChecked())
    {
        built = "Yes";
    }
    else
    {
        built = "No";
    }

    if(name == "")
    {
        QMessageBox::warning(this, "Error!", "Name can not be empty!");
        error++;
    }

    if(date <= 0 || date >= 2016 || date == -1)
    {
        QMessageBox::warning(this, "Error!", "Not a valid year of birth!");
        error++;
    }

    if(error == 0)
    {
        bool success = elist.updateComputer(name, type, built, date, currentId,fileName);
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
void EditComputerDialog::on_button_computer_edit_cancel_clicked()
{
    close();
}
void EditComputerDialog::on_button_edit_picture_clicked()
{
    fileName = QFileDialog::getOpenFileName(this,
    tr("Jpg image"), "",
    tr("Image file (*.jpg *.png);;All Files (*)"));

    QFileInfo name(fileName);
    QString baseName = name.fileName();

    ui->button_edit_picture->setText(baseName);
}
