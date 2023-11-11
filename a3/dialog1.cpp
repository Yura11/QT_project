#include "dialog1.h"
#include "ui_dialog1.h"
#include <QMessageBox>

Dialog1::Dialog1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog1)
{
    ui->setupUi(this);
    setWindowTitle("Galician Lions");
   this->setFixedSize(820, 596);
}

Dialog1::~Dialog1()
{
    delete ui;
}

void Dialog1::on_calendarWidget_clicked(const QDate &date)
{
    QString message;

        if (date.dayOfWeek() == Qt::Saturday) {
            message = "Графік тренувань:"
                    "1 - 11:00";
        } else if (date.dayOfWeek() == Qt::Sunday) {
            message = "Неділя - вихідний день!";
        } else {
            message = "Графік тренувань:"
                       "1 - 14:00!"
                       "2 - 15:30!"
                       "3 - 17:30!";
        }

        // Виведіть віконечко з повідомленням
        QMessageBox::information(this, "Інформація", message);
}

