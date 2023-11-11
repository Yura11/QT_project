// test.cpp
#include <QtTest/QtTest>
#include "mainwindow.h"

class TestMainWindow : public QObject {
    Q_OBJECT

private slots:
    void testLoginSuccess() {
        MainWindow mainWindow;

        // Set up the initial state (if needed)

        // Set the input values (login and password)
        mainWindow.ui->lineEdit_2->setText("valid_username");
        mainWindow.ui->lineEdit->setText("valid_password");

        // Simulate button click
        QTest::mouseClick(mainWindow.ui->pushButton, Qt::LeftButton);

        // Check if the second window is shown
        QVERIFY2(mainWindow.isHidden(), "MainWindow should be hidden after successful login");
    }

    void testLoginFailure() {
        MainWindow mainWindow;

        // Set up the initial state (if needed)

        // Set the input values (invalid login and password)
        mainWindow.ui->lineEdit_2->setText("invalid_username");
        mainWindow.ui->lineEdit->setText("invalid_password");

        // Simulate button click
        QTest::mouseClick(mainWindow.ui->pushButton, Qt::LeftButton);

        // Check if an error message is displayed
        QVERIFY2(QMessageBox::warningCalled(), "Error message should be displayed for invalid login");
    }

    void testAboutUsInfo() {
        MainWindow mainWindow;

        // Simulate menu action trigger
        QTest::keyClick(mainWindow.ui->menubar, Qt::Key_A);
        QTest::keyClick(mainWindow.ui->menu_2, Qt::Key_2);

        // Check if the about us information is displayed
        QVERIFY2(QMessageBox::informationCalled(), "About us information should be displayed");
    }

    // Add more test cases for other functions as needed
};

QTEST_APPLESS_MAIN(TestMainWindow)
#include "mainwindow_test.moc"
