#include "trainer2.h"
#include "ui_trainer2.h"

trainer2::trainer2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::trainer2)
{
    ui->setupUi(this);
    this->setFixedSize(633, 490);
    setWindowTitle("Galician Lions");
}

trainer2::~trainer2()
{
    delete ui;
}
