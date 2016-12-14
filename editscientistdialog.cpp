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
    ui->input_scientist_name->insert(QString::fromStdString(esci.getScientistName()));
    ui->input_scientist_gender->insert(QChar(esci.getScientistGender()));
}
