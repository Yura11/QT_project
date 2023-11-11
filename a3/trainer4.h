#ifndef TRAINER4_H
#define TRAINER4_H

#include <QDialog>

namespace Ui {
class trainer4;
}

class trainer4 : public QDialog
{
    Q_OBJECT

public:
    explicit trainer4(QWidget *parent = nullptr);
    ~trainer4();

private:
    Ui::trainer4 *ui;
};

#endif // TRAINER4_H
