#include "trainer1.h"
#include "ui_trainer1.h"

trainer1::trainer1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::trainer1)
{
    ui->setupUi(this);
    this->setFixedSize(634, 496);
    setWindowTitle("Galician Lions");
}

trainer1::~trainer1()
{
    delete ui;
}
