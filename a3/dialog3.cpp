#include "dialog3.h"
#include "ui_dialog3.h"
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QIcon>
#include <QSqlRecord>
#include <QFont>

Dialog3::Dialog3(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog3)
{
    ui->setupUi(this);
    this->setFixedSize(970, 728);
    setWindowTitle("Galician Lions");
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("users.db");

    if (!db.open()) {
        qDebug() << "Database connection failed.";
    } else {
        QSqlQuery query;

        // Execute the SQL query
        if (!query.exec("SELECT * FROM persons")) {
            qDebug() << "Error executing SQL query: " << query.lastError().text();
        } else {
            // Get the number of columns from the metadata of the result
            int columnCount = query.record().count();

            // Count the number of rows
            int rowCount = 0;
            while (query.next()) {
                rowCount++;
            }

            // Set up the QTableWidget
            ui->tableWidget->setRowCount(rowCount);
            ui->tableWidget->setColumnCount(columnCount);
            ui->tableWidget->clear();

            // Create a custom font with a larger font size
            QFont customFont;
            customFont.setPointSize(14); // Adjust the font size as needed

            // Set custom column labels (headers)
            QStringList columnLabels;
            columnLabels << "Прізвище" << "Ім'я" << "Розряд"; // Replace with your desired labels
            ui->tableWidget->setHorizontalHeaderLabels(columnLabels);

            // Set custom row labels (headers)
            QStringList rowLabels;
            for (int i = 1; i <= rowCount; i++) {
                rowLabels << QString::number(i);
            }
            ui->tableWidget->setVerticalHeaderLabels(rowLabels);

            // Populate the QTableWidget with data from the database
            query.exec("SELECT * FROM persons");
            int currentRow = 0;
            while (query.next()) {
                for (int currentColumn = 0; currentColumn < columnCount; currentColumn++) {
                    QTableWidgetItem *item = new QTableWidgetItem(query.value(currentColumn).toString());
                    item->setFont(customFont); // Apply the custom font
                    ui->tableWidget->setItem(currentRow, currentColumn, item);
                }
                currentRow++;
            }
        }

        // Close the database connection
        db.close();

    }
}

Dialog3::~Dialog3()
{
    delete ui;
}

void Dialog3::on_tableWidget_clicked(const QModelIndex &index)
{
    int row = index.row();
        int column = index.column();
        QTableWidgetItem *item = ui->tableWidget->item(row, column);
        if (item) {
            QString cellText = item->text();
            QString additionalInfo;
            switch (column) {
                case 0:
                    additionalInfo = "5-ти кратний чемпіон області,чемпіон України,багатократний чемпіон та призер всеукраїнських та міжнародних турнірів";
                    break;

            }
            QMessageBox::about(this, "Додаткова інформація", "Ви вибрали спортсмена: " + cellText + "\n" + additionalInfo);
        }
 }



void Dialog3::on_pushButton_clicked()
{
    QString lastName = ui->lineEdit->text();
       QString firstName = ui->lineEdit_2->text();
       QString category = ui->lineEdit_3->text();

       // Check if any of the QLineEdit fields are empty
       if (lastName.isEmpty() || firstName.isEmpty() || category.isEmpty()) {
           QMessageBox::warning(this, "Увага", "Заповніть усі поля");
           return;
       }

       QSqlDatabase db = QSqlDatabase::database(); // Use the existing database connection

       QSqlQuery query(db);

       // Check if a sportsperson with the same name already exists
       query.prepare("SELECT COUNT(*) FROM persons WHERE last_name = :last_name AND first_name = :first_name");
       query.bindValue(":last_name", lastName);
       query.bindValue(":first_name", firstName);
       if (query.exec() && query.first() && query.value(0).toInt() > 0) {
           QMessageBox::warning(this, "Увага", "Спортсмен з таким іменем уже існує");
           return;
       }

       // If no sportsperson with the same name exists, insert the new data
       query.prepare("INSERT INTO persons (last_name, first_name, category) VALUES (:last_name, :first_name, :category)");
       query.bindValue(":last_name", lastName);
       query.bindValue(":first_name", firstName);
       query.bindValue(":category", category);

       if (query.exec()) {
           // Insertion was successful
           qDebug() << "Data inserted successfully.";
           // Clear the line edits
           ui->lineEdit->clear();
           ui->lineEdit_2->clear();
           ui->lineEdit_3->clear();
       } else {
           qDebug() << "Error executing SQL query: " << query.lastError().text();
           QMessageBox::critical(this, "Error", "Failed to insert data into the database.");
       }

}


void Dialog3::on_pushButton_2_clicked()
{

        QSqlDatabase db = QSqlDatabase::database(); // Use the existing database connection

        QSqlQuery query(db);

        // Execute the SQL query
        if (!query.exec("SELECT * FROM persons")) {
            qDebug() << "Error executing SQL query: " << query.lastError().text();
            return;
        }

        // Get the number of columns from the metadata of the result
        int columnCount = query.record().count();

        // Count the number of rows
        int rowCount = 0;
        while (query.next()) {
            rowCount++;
        }

        // Clear the existing data in the QTableWidget
        ui->tableWidget->clear();

        // Set up the QTableWidget
        ui->tableWidget->setRowCount(rowCount);
        ui->tableWidget->setColumnCount(columnCount);

        // Create a custom font with a larger font size
        QFont customFont;
        customFont.setPointSize(14); // Adjust the font size as needed

        // Set custom column labels (headers)
        QStringList columnLabels;
        columnLabels << "Прізвище" << "Ім'я" << "Розряд"; // Replace with your desired labels
        ui->tableWidget->setHorizontalHeaderLabels(columnLabels);

        // Set custom row labels (headers)
        QStringList rowLabels;
        for (int i = 1; i <= rowCount; i++) {
            rowLabels << QString::number(i);
        }
        ui->tableWidget->setVerticalHeaderLabels(rowLabels);

        // Populate the QTableWidget with data from the database
        query.exec("SELECT * FROM persons");
        int currentRow = 0;
        while (query.next()) {
            for (int currentColumn = 0; currentColumn < columnCount; currentColumn++) {
                QTableWidgetItem *item = new QTableWidgetItem(query.value(currentColumn).toString());
                item->setFont(customFont); // Apply the custom font
                ui->tableWidget->setItem(currentRow, currentColumn, item);
            }
            currentRow++;
        }
        ui->lineEdit->clear();
            ui->lineEdit_2->clear();
            ui->lineEdit_3->clear();
    }




void Dialog3::on_pushButton_3_clicked()
{
    QString lastName = ui->lineEdit->text();
        QString firstName = ui->lineEdit_2->text();

        if (lastName.isEmpty() || firstName.isEmpty()) {
            QMessageBox::warning(this, "Увага", "Введіть ім'я та прізвище для видалення.");
            return;
        }

        QSqlDatabase db = QSqlDatabase::database(); // Use the existing database connection

        QSqlQuery query(db);

        // Check if the specified sportsperson exists in the database
        query.prepare("SELECT COUNT(*) FROM persons WHERE last_name = :last_name AND first_name = :first_name");
        query.bindValue(":last_name", lastName);
        query.bindValue(":first_name", firstName);
        if (!query.exec() || !query.first() || query.value(0).toInt() == 0) {
            QMessageBox::information(this, "Увага", "Запис із введеними ім'ям та прізвищем не знайдено.");
            return;
        }

        // Execute the SQL query to delete the selected sportsperson
        query.prepare("DELETE FROM persons WHERE last_name = :last_name AND first_name = :first_name");
        query.bindValue(":last_name", lastName);
        query.bindValue(":first_name", firstName);

        if (query.exec()) {
            if (query.numRowsAffected() > 0) {
                // Deletion was successful
                qDebug() << "Data deleted successfully.";
                // Clear the line edits
                ui->lineEdit->clear();
                ui->lineEdit_2->clear();

                // Reload the data in the QTableWidget
                on_pushButton_2_clicked();
            } else {
                QMessageBox::critical(this, "Помилка", "Помилка під час видалення даних з бази даних.");
            }
        } else {
            qDebug() << "Error executing SQL query: " << query.lastError().text();
            QMessageBox::critical(this, "Помилка", "Помилка під час видалення даних з бази даних.");
        }
        ui->lineEdit->clear();
            ui->lineEdit_2->clear();
            ui->lineEdit_3->clear();
}


void Dialog3::on_pushButton_4_clicked()
{
    // Get the selected row and column from the QTableWidget
    int row = ui->tableWidget->currentRow();
    int column = ui->tableWidget->currentColumn();

    // Check if a valid row and column are selected
    if (row < 0 || column < 0) {
        QMessageBox::warning(this, "Увага", "Виберіть комірку для редагування.");
        return;
    }

    QString newValue = ui->tableWidget->item(row, column)->text();

    // Check if the new value is empty
    if (newValue.isEmpty()) {
        QMessageBox::warning(this, "Увага", "Заповніть поле.");
        return;
    }

    QSqlDatabase db = QSqlDatabase::database(); // Use the existing database connection
    QSqlQuery query(db);

    // Determine which column is selected and update the corresponding field in the database
    QString columnName;
    switch (column) {
        case 0:
            columnName = "last_name";
            break;
        case 1:
            columnName = "first_name";
            break;
        case 2:
            columnName = "category";
            break;
        // Add more cases for additional columns if needed
    }

    if (columnName.isEmpty()) {
        return; // Do nothing if an unsupported column is selected
    }

    // Get the previous value before the update
    QString previousValue = ui->tableWidget->item(row, column)->text();

    // Update the selected column in the database
    query.prepare("UPDATE persons SET " + columnName + " = :newValue WHERE rowid = :rowid");
    query.bindValue(":newValue", newValue);
    query.bindValue(":rowid", row + 1); // Assuming rowid starts from 1

    if (query.exec()) {
        // Update was successful
        QString message = "Значення " + columnName + " змінено на \"" + previousValue ;
        qDebug() << "Data updated successfully in the database. " << message;

        // Display a QMessageBox to show what has been edited
        QMessageBox::information(this, "Редагування", message);
    } else {
        qDebug() << "Error executing SQL query: " << query.lastError().text();
        QMessageBox::critical(this, "Помилка", "Помилка під час оновлення даних.");
    }
}


