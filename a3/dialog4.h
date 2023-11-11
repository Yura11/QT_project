// dialog4.h
#ifndef DIALOG4_H
#define DIALOG4_H

#include <QDialog>
#include <QDate>

namespace Ui {
class Dialog4;
}

class Dialog4 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog4(QWidget *parent = nullptr);
    ~Dialog4();

    QString getMessageForDate(const QDate &date); // Declaration

public slots:
    void on_calendarWidget_clicked(const QDate &date);

private:
    Ui::Dialog4 *ui;
};

#endif // DIALOG4_H
