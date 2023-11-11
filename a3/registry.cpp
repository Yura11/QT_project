#include "registry.h"
#include "ui_registry.h"

#include <QDebug>
#include <QRegularExpression>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>


registry::registry(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::registry)
{
    ui->setupUi(this);
    this->setFixedSize(538, 327);
    setWindowTitle("Galician Lions");
}

registry::~registry()
{
    delete ui;
}



void registry::on_pushButton_2_clicked()
{
    // Отримайте дані з lineEdit та lineEdit_2
    QString username = ui->lineEdit->text();
    QString password = ui->lineEdit_2->text();

    // Перевірка, чи логін є валідною електронною адресою
    QRegularExpression emailRegex("^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,4}$");
    if (!emailRegex.match(username).hasMatch()) {
        ui->lineEdit_3->setText("Введіть правильну адресу електронної пошти.");
        return;
    }

    // Перевірка, чи пароль не є пустим і має мінімальну довжину, наприклад, 6 символів
    if (password.isEmpty() || password.length() < 6) {
        ui->lineEdit_3->setText("Пароль має містити принаймні 6 символів.");
        return;
    }

    // Встановлюємо підключення до бази даних (попередньо ви повинні встановити підключення в іншому місці вашого коду)
    QSqlDatabase db = QSqlDatabase::database();

    if (!db.open()) {
        ui->lineEdit_3->setText("Помилка підключення до бази даних.");
    } else {
        // Виконуємо SQL-запит для перевірки, чи логін вже існує в базі даних
        QSqlQuery checkQuery;
        checkQuery.prepare("SELECT username FROM users WHERE username = :value1");
        checkQuery.bindValue(":value1", username);

        if (checkQuery.exec() && checkQuery.next()) {
            ui->lineEdit_3->setText("Користувач з такою адресою електронної пошти вже існує.");
        } else {
            // Якщо логін унікальний, виконуємо вставку даних
            QSqlQuery insertQuery;
            insertQuery.prepare("INSERT INTO users (username, password) VALUES (:value1, :value2)");
            insertQuery.bindValue(":value1", username);
            insertQuery.bindValue(":value2", password);

            if (insertQuery.exec()) {
                ui->lineEdit_3->setText("Дані успішно вставлені!");
                accept();
            } else {
                ui->lineEdit_3->setText("Помилка вставки даних.");
            }
        }

        // Закриваємо підключення до бази даних
        db.close();
    }
}


void registry::on_pushButton_clicked()
{
     accept();
}

