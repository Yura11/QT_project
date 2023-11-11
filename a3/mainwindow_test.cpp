// mainwindowtest.cpp
#include <QtTest/QtTest>
#include "mainwindow.h"

// Add this line to declare the private class of MainWindow
Q_DECLARE_PRIVATE(MainWindow)

class TestMainWindow : public QObject {
    Q_OBJECT

private slots:
    // Test the login functionality with correct credentials
    void testLoginSuccess() {
        // Use the private class for MainWindow
        QScopedPointer<MainWindowPrivate> d(new MainWindowPrivate);

        // Set up the initial state (if needed)

        // Set the input values (login and password)
        d->ui->lineEdit_2->setText("valid_username");
        d->ui->lineEdit->setText("valid_password");

        // Trigger the login button click
        QTest::mouseClick(d->ui->pushButton, Qt::LeftButton);

        // Check if the second window is shown
        QVERIFY2(d->isHidden(), "MainWindow should be hidden after successful login");
    }

    // Test the login functionality with incorrect credentials
    void testLoginFailure() {
        // Use the private class for MainWindow
        QScopedPointer<MainWindowPrivate> d(new MainWindowPrivate);

        // Set up the initial state (if needed)

        // Set the input values (invalid login and password)
        d->ui->lineEdit_2->setText("invalid_username");
        d->ui->lineEdit->setText("invalid_password");

        // Trigger the login button click
        QTest::mouseClick(d->ui->pushButton, Qt::LeftButton);

        // Check if an error message is displayed
        QVERIFY2(QMessageBox::warningCalled(), "Error message should be displayed for invalid login");
    }

    // Add more test cases for other functions as needed
};

QTEST_APPLESS_MAIN(TestMainWindow)

