#ifndef TRAINER2_H
#define TRAINER2_H

#include <QDialog>

namespace Ui {
class trainer2;
}

class trainer2 : public QDialog
{
    Q_OBJECT

public:
    explicit trainer2(QWidget *parent = nullptr);
    ~trainer2();

private:
    Ui::trainer2 *ui;
};

#endif // TRAINER2_H
