#include "secondwindow.h"
#include "ui_secondwindow.h"
#include "dialog1.h"
#include "trainer1.h"
#include "trainer2.h"
#include "trainer3.h"
#include "trainer4.h"
#include "dialog2.h"
#include "dialog3.h"
#include "dialog4.h"
#include <QMessageBox>
#include <QDesktopServices>
#include <QUrl>

secondwindow::secondwindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::secondwindow)
{
    ui->setupUi(this);
    this->setFixedSize(1106, 706);

    setWindowTitle("Galician Lions");
    QString menuStyle = "QMenuBar {"
                       "background-color: #333; /* Фон меню бару */"
                       "color: white; /* Колір тексту в меню барі */"
                       "font-size: 16px; /* Розмір шрифту для тексту в меню барі */"
                       "font-weight: bold; /* Жирний шрифт для тексту в меню барі */"
                       "text-transform: uppercase; /* Текст великими літерами */"
                       "}"

                       "QMenuBar::item {"
                       "background-color: transparent; /* Фон пунктів меню бару */"
                       "color: white; /* Колір тексту пунктів меню бару */"
                       "}"

                       "QMenuBar::item:selected {"
                       "background-color: #555; /* Фон виділеного пункту меню бару */"
                       "color: red; /* Колір виділеного тексту пункту меню бару */"
                       "}"

                       "QMenuBar::item:pressed {"
                       "background-color: #777; /* Фон натисканого пункту меню бару */"
                       "color: blue; /* Колір тексту при натисканні */"
                       "}"

                       "QMenu {"
                       "background-color: #333; /* Фон меню */"
                       "color: white; /* Колір тексту */"
                       "}"

                       "QMenu::item {"
                       "background-color: transparent; /* Фон пунктів меню */"
                       "color: white; /* Колір тексту пунктів меню */"
                       "}"

                       "QMenu::item:selected {"
                       "background-color: #555; /* Фон виділеного пункту меню */"
                       "color: red; /* Колір виділеного тексту пункту меню */"
                       "}";

    // Встановлення стилю для меню бару та меню
    ui->menubar->setStyleSheet(menuStyle);
    ui->menu->setStyleSheet(menuStyle);
    ui->menu_2->setStyleSheet(menuStyle);
    ui->menu_3->setStyleSheet(menuStyle);
}

secondwindow::~secondwindow()
{
    delete ui;
}

void secondwindow::on_pushButton_clicked()
{
    Dialog1 *dialog = new Dialog1(this);


     dialog->exec();
}


void secondwindow::on_pushButton_2_clicked()
{
    Dialog2 *dialog = new Dialog2(this);


     dialog->exec();
}



void secondwindow::on_pushButton_3_clicked()
{
    Dialog3 *dialog = new Dialog3(this);


     dialog->exec();
}


void secondwindow::on_pushButton_4_clicked()
{
    Dialog4 *dialog = new Dialog4(this);


     dialog->exec();
}


void secondwindow::on_action_triggered()
{
    // Виведення інформації про розробника в вікні інформація
    QString developerInfo = "Беліченко Юрій КІ-406\n"
                            "ВСП 'ТФК ТНТУ імені Івана Пулюя' 2023\n"
                            "Розробка програмного забезпечення інформаційно-довідкової\n"
                            "системи для спортивного клубу 'Галицькі Леви'";

    QMessageBox msgBox;
    msgBox.setText(developerInfo);
    msgBox.setWindowTitle("Про програму");
    msgBox.exec();
}


void secondwindow::on_action_2_triggered()
{
    QString aboutUsInfo = "--------------------------------------------------------------\n"
                        "                   Спортивний клуб \"Галицькі леви\"          \n"
                        "--------------------------------------------------------------\n"
                        "\n"
                        "                   Наші послуги та досягнення:\n"
                        "\n"
                        " - Тренування та навчання вільній боротьбі для всіх вікових\n"
                        "   категорій та рівнів навиків.\n"
                        "\n"
                        " - Команда кваліфікованих тренерів, які навчать вас\n"
                        "   техніці боротьби та підготують до змагань на різних\n"
                        "   рівнях.\n"
                        "\n"
                        " - Участь у турнірах та змаганнях для отримання цінного\n"
                        "   досвіду та досягнень у світі вільної боротьби.\n"
                        "\n"
                        "                   Наші контакти:\n"
                        "\n"
                        " Адреса: вул. Павла Чубинського, 23\n"
                        " Телефон: +380 678 915 899\n"
                        "\n"
                        "                   Слідкуйте за нами в мережі:\n"
                        "\n"
                        " Facebook: https://www.facebook.com/sportshkola1\n"
                        "--------------------------------------------------------------";

        QMessageBox::information(this, "Про нас", aboutUsInfo);
}


void secondwindow::on_action_3_triggered()
{
    trainer1 *dialog = new trainer1(this);

     // Покажіть діалогове вікно
     dialog->exec(); // Використовуйте exec() для модального діало
}


void secondwindow::on_action_4_triggered()
{
     trainer3 *dialog = new  trainer3(this);

     // Покажіть діалогове вікно
     dialog->exec(); // Використовуйте exec() для модального діало
}


void secondwindow::on_action_5_triggered()
{
    trainer2 *dialog = new  trainer2(this);

     // Покажіть діалогове вікно
     dialog->exec(); // Використовуйте exec() для модального діало
}


void secondwindow::on_action_6_triggered()
{
     trainer4 *dialog = new  trainer4(this);

     // Покажіть діалогове вікно
     dialog->exec(); // Використовуйте exec() для модального діало
}


void secondwindow::on_action_7_triggered()
{
    // Use a relative path to the index.html file
        QString htmlFilePath = "index.html";

        // Open the HTML file in the default web browser
        QDesktopServices::openUrl(QUrl::fromLocalFile(htmlFilePath));
}

