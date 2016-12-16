#include "infocomputerdialog.h"
#include "ui_infocomputerdialog.h"
#include "computer.h"
#include <QPixmap>
using namespace std;

infoComputerDialog::infoComputerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::infoComputerDialog)
{
    ui->setupUi(this);
}
infoComputerDialog::~infoComputerDialog()
{
    delete ui;
}
void infoComputerDialog::prepareShowCom(Computer infoCom)
{
    currentID = infoCom.getComputerId();
    ui->label_show_name->setText(QString::fromStdString(infoCom.getComputerName()));
    ui->label_show_type->setText(QString::fromStdString(infoCom.getComputerType()));
    ui->label_show_date->setText(QString::number(infoCom.getComputerDate()));
    ui->label_show_wasItMade->setText(QString::fromStdString(infoCom.getComputerWasItBuilt()));

    int imageNumber = elist.getImageCom(currentID);

    QPixmap  mypix(elist.getImage(imageNumber));

    int w = mypix.width();
    int h = mypix.height();
    int labelHeight = ui->label_image->height();

    if(h >= w)
    {
        do
        {
            h--;
            w--;
        }while(h >= 280);
    }
    else
        do
        {
            h--;
            w--;
        }while(w >= 270);

    ui->label_image->setPixmap(mypix);
    ui->label_image->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    ui->label_image->setPixmap(mypix.scaled(w,h,Qt::KeepAspectRatioByExpanding));
}

void infoComputerDialog::on_button_close_clicked()
{
    this->close();
}
