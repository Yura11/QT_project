#include "trainer3.h"
#include "ui_trainer3.h"

trainer3::trainer3(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::trainer3)
{
    ui->setupUi(this);
    this->setFixedSize(623, 446);
    setWindowTitle("Galician Lions");
}

trainer3::~trainer3()
{
    delete ui;
}
