#ifndef TRAINER1_H
#define TRAINER1_H

#include <QDialog>

namespace Ui {
class trainer1;
}

class trainer1 : public QDialog
{
    Q_OBJECT

public:
    explicit trainer1(QWidget *parent = nullptr);
    ~trainer1();

private:
    Ui::trainer1 *ui;
};

#endif // TRAINER1_H
