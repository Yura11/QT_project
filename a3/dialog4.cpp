// dialog4.cpp
#include "dialog4.h"
#include "ui_dialog4.h"
#include "QMessageBox"

Dialog4::Dialog4(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog4)
{
    ui->setupUi(this);
    this->setFixedSize(906, 606);
    setWindowTitle("Galician Lions");
}

Dialog4::~Dialog4()
{
    delete ui;
}

QString Dialog4::getMessageForDate(const QDate &date)
{
    QString message;

    if (date == QDate(date.year(), 11, 20)) {
        message = "20 листопада: Всеукраїнський турнір, місто Коломия";
    } else if (date == QDate(date.year(), 11, 25)) {
        message = "25 листопада: Всеукраїнський турнір, місто Тернопіль";
    } else if (date == QDate(date.year(), 11, 30)) {
        message = "30 листопада: Обласний турнір, місто Тернопіль";
    } else {
        message = "Ви вибрали дату: " + date.toString("dd.MM.yyyy");
    }

    return message;
}

void Dialog4::on_calendarWidget_clicked(const QDate &date)
{
    QString message = getMessageForDate(date);
    QMessageBox::information(this, "Інформація", message);
}
