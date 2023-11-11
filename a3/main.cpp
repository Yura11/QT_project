#include "mainwindow.h"
#include <QApplication>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QMediaPlayer>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();


    if (!QFile::exists("users.db")) {
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("users.db");

        if (!db.open()) {
            qDebug() << "Database connection failed.";
        } else {
            QSqlQuery query;


            query.exec("CREATE TABLE users (id INTEGER PRIMARY KEY AUTOINCREMENT, username TEXT, password TEXT)");


           query.exec("CREATE TABLE persons (last_name TEXT, first_name TEXT, category TEXT)");


            query.exec("CREATE TABLE telephone (id INTEGER PRIMARY KEY AUTOINCREMENT, contact_name TEXT, phone_number TEXT)");

            db.close();
        }
    } else {
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("users.db");

        if (!db.open()) {
            qDebug() << "Database connection failed.";
        }
    }
    QMediaPlayer audioPlayer;
       audioPlayer.setMedia(QUrl::fromLocalFile("welcome-to-korea-173264.mp3"));
       audioPlayer.setVolume(1);
       audioPlayer.play();
    return a.exec();
}
