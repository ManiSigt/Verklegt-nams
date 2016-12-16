#include "infocomputerdialog.h"
#include "ui_infocomputerdialog.h"
#include "computer.h"
#include <QPixmap>

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
    qDebug() << "1";
    currentID = infoCom.getComputerId();
    ui->label_show_name->setText(QString::fromStdString(infoCom.getComputerName()));
    ui->label_show_type->setText(QString::fromStdString(infoCom.getComputerType()));
    ui->label_show_date->setText(QString::number(infoCom.getComputerDate()));
    ui->label_show_wasItMade->setText(QString::fromStdString(infoCom.getComputerWasItBuilt()));
qDebug() << "2";
        /*QPixmap  mypix(elist.getImage(1));

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

            }while(h >= 261);
        }
        else
            do
            {

                h--;
                w--;

            }while(w >= 261);
        qDebug() << w << " " << h << " " << labelHeight;

        ui->label_image->setPixmap(mypix);
        ui->label_image->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
        ui->label_image->setPixmap(mypix.scaled(w,h,Qt::KeepAspectRatioByExpanding));
*/


}

void infoComputerDialog::on_button_close_clicked()
{
    this->close();
}
