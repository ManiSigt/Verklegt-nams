#include "addcomputerdialog.h"
#include "ui_addcomputerdialog.h"
#include <QPushButton>
#include <QDebug>
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
    int date1 = ui->input_computer_date->text().toUInt();
    if (date.isEmpty())
    {
        ui->error_date->setText("<span style='color: #FF1100'>No date in input!</span>");
        return;
    }
    if(date1 > 2016)
    {
       ui->error_date->setText("<span style='color: #FF1100'>Not a valid date!</span>");
       return;
    }
    if(date < 0)
    {
      ui->error_date->setText("<span style='color: #FF1100'>Not a valid date!</span>");
    }
    if(ui->radioButton_Yes->isChecked())
    {
        yesNo = "Yes";
    }
    if(ui->radioButton_No->isChecked())
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
void addComputerDialog::themeChanger(int changer)
{
    if(changer == 1)  //Skulltheme
    {
        qDebug() << "drunk";
        setWindowIcon(QIcon(":/icons/icons/skull-512.ico"));
        ui->add_computer_button->setIcon(QIcon(":/icons/icons/ninjaskull"));
        ui->add_computer_button->setIconSize(QSize(30,30));
    }
    if(changer == 2)  // Annað theme
    {
        setWindowIcon(QIcon(":/icons/icons/skull-512.ico"));
        ui->add_computer_button->setIcon(QIcon(":/icons/icons/ninjaskull"));
        ui->add_computer_button->setIconSize(QSize(30,30));
    }
    if(changer == 3)  //Annað theme
    {
        setWindowIcon(QIcon(":/icons/icons/skull-512.ico"));
        ui->add_computer_button->setIcon(QIcon(":/icons/icons/ninjaskull"));
        ui->add_computer_button->setIconSize(QSize(30,30));
    }
    if(changer == 4)  //Annað theme
    {
        setWindowIcon(QIcon(":/icons/icons/skull-512.ico"));
        ui->add_computer_button->setIcon(QIcon(":/icons/icons/ninjaskull"));
        ui->add_computer_button->setIconSize(QSize(30,30));
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
