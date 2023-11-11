#ifndef DIALOG1_H
#define DIALOG1_H
#include <QtWidgets/QDialog>



namespace Ui {
class Dialog1;
}

class Dialog1 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog1(QWidget *parent = nullptr);
    ~Dialog1();

private slots:
    void on_calendarWidget_clicked(const QDate &date);

private:
    Ui::Dialog1 *ui;
};

#endif // DIALOG1_H
