#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QMainWindow>

namespace Ui {
class secondwindow;
}

class secondwindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit secondwindow(QWidget *parent = nullptr);
    ~secondwindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_action_triggered();

    void on_action_2_triggered();

    void on_action_3_triggered();

    void on_action_4_triggered();

    void on_action_5_triggered();

    void on_action_6_triggered();

    void on_action_7_triggered();

private:
    Ui::secondwindow *ui;
};

#endif // SECONDWINDOW_H
