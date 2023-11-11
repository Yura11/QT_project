#include "dialog2.h"
#include "ui_dialog2.h"
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QIcon>
#include <QRegExp>
#include <QValidator>

Dialog2::Dialog2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog2)
{
    ui->setupUi(this);
    this->setFixedSize(641, 432);
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("users.db");

    if (!db.open()) {
        QMessageBox::critical(this, "Database Error", "Failed to connect to the database.");
    }

    // Set up a regular expression validator for the phone number
    QRegExp regExp("^[0-9]{10}$");
    QValidator* validator = new QRegExpValidator(regExp);
    ui->lineEdit->setValidator(validator);
    setWindowTitle("Galician Lions");
}

Dialog2::~Dialog2()
{
    delete ui;
}

void Dialog2::on_pushButton_clicked()
{
    QString contactName = ui->lineEdit_2->text();
    QString phoneNumber = ui->lineEdit->text();

    // Validate the phone number
    if (phoneNumber.isEmpty() || phoneNumber.length() != 10) {
        QMessageBox::critical(this, "Помилка", "Введіть правильний номер телефону (10 цифр).");
        return;
    }

    // Validate the contact name
    if (contactName.isEmpty()) {
        QMessageBox::critical(this, "Помилка", "Введіть ім'я контакту.");
        return;
    }

    // Check if the database is open
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) {
        QMessageBox::critical(this, "Database Error", "Помилка підключення до бази даних.");
        return;
    }

    QSqlQuery query;

    // Check if the phone number already exists in the database
    query.prepare("SELECT * FROM telephone WHERE phone_number = :phone_number");
    query.bindValue(":phone_number", phoneNumber);

    if (query.exec() && query.next()) {
        QMessageBox::information(this, "Помилка введення", "Цей номер телефону уже є в базі даних.");
    } else {
        // Check if the contact name already exists in the database
        query.prepare("SELECT * FROM telephone WHERE contact_name = :contact_name");
        query.bindValue(":contact_name", contactName);

        if (query.exec() && query.next()) {
            QMessageBox::information(this, "Помилка введення", "Це ім'я контакту вже є в базі даних.");
        } else {
            // Insert the values into the "telephone" table
            query.prepare("INSERT INTO telephone (contact_name, phone_number) VALUES (:contact_name, :phone_number)");
            query.bindValue(":contact_name", contactName);
            query.bindValue(":phone_number", phoneNumber);

            if (query.exec()) {
                QMessageBox::information(this, "Дякую", "Наш адміністратор зв'яжеться з вами найближчим часом.");
            accept();
            } else {

            }
        }
    }
}


void Dialog2::on_pushButton_2_clicked()
{
    accept();
}

