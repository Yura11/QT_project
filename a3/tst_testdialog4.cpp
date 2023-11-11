// tst_testdialog4.cpp
#include <QtTest/QtTest>
#include "dialog4.h"

class TestDialog4 : public QObject
{
    Q_OBJECT

private slots:
    void testGetMessageForDate();
};

void TestDialog4::testGetMessageForDate()
{
    Dialog4 dialog;

    QCOMPARE(dialog.getMessageForDate(QDate(2023, 11, 20)), "20 листопада: Всеукраїнський турнір, місто Коломия");
    QCOMPARE(dialog.getMessageForDate(QDate(2023, 11, 25)), "25 листопада: Всеукраїнський турнір, місто Тернопіль");
    QCOMPARE(dialog.getMessageForDate(QDate(2023, 11, 30)), "30 листопада: Обласний турнір, місто Тернопіль");
    QCOMPARE(dialog.getMessageForDate(QDate(2023, 11, 21)), "Ви вибрали дату: 21.11.2023");
}

QTEST_MAIN(TestDialog4)
#include "tst_testdialog4.moc"
