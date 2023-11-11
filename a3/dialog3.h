#ifndef DIALOG3_H
#define DIALOG3_H
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialog>
#include <QSqlDatabase>

namespace Ui {
class Dialog3;
}

class Dialog3 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog3(QWidget *parent = nullptr);
    ~Dialog3();

private slots:


    void on_tableWidget_clicked(const QModelIndex &index);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::Dialog3 *ui;
    QSqlDatabase db;
};

#endif // DIALOG3_H
