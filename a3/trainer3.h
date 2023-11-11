#ifndef TRAINER3_H
#define TRAINER3_H

#include <QDialog>

namespace Ui {
class trainer3;
}

class trainer3 : public QDialog
{
    Q_OBJECT

public:
    explicit trainer3(QWidget *parent = nullptr);
    ~trainer3();

private:
    Ui::trainer3 *ui;
};

#endif // TRAINER3_H
