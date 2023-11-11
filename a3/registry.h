#ifndef REGISTRY_H
#define REGISTRY_H

#include <QDialog>

namespace Ui {
class registry;
}

class registry : public QDialog
{
    Q_OBJECT

public:
    explicit registry(QWidget *parent = nullptr);
    ~registry();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::registry *ui;
};

#endif // REGISTRY_H
