#include "addcomputerdialog.h"
#include "ui_addcomputerdialog.h"
#include <QFileDialog>
#include <QPixmap>

addComputerDialog::addComputerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addComputerDialog)
{
    ui->setupUi(this);
}

addComputerDialog::~addComputerDialog()
{
    delete ui;
}

void addComputerDialog::on_add_computer_button_clicked()
{
    string yesNo;
    QString name = ui->input_computer_name->text();
    if(name.isEmpty())
    {
        ui->error_name->setText("<span style='color: #FF1100'>No name in input!</span>");
        return;
    }
    QString type = ui->input_computer_type->text();
    if(type.isEmpty())
    {
        ui->error_type->setText("<span style='color: #FF1100'>No type name in input!</span>");
        return;
    }
    QString date = ui->input_computer_date->text();
    if (date.isEmpty())
    {
        ui->error_date->setText("<span style='color: #FF1100'>No date in input!</span>");
        return;
    }
    if(ui->radioButton_Yes->isChecked())
    {
        yesNo = "Yes";
    }
    if(ui->radioButton_Yes->isChecked())
    {
        yesNo = "No";
    }

    bool success = list.addNewComputer(name.toStdString(), type.toStdString(), date.toInt(), yesNo, fileName);
    if (success)
    {
        this->done(1);
    }
    else
    {
        this->done(-1);
    }
}

void addComputerDialog::on_button_add_picture_clicked()
{
    fileName = QFileDialog::getOpenFileName(this,
            tr("Jpg image"), "",
            tr("Image file (*.jpg *.png *.bmp *.gif);;All Files (*)"));

    QFileInfo name(fileName);
    QString baseName = name.fileName();

    ui->button_add_picture->setText(baseName);
}
