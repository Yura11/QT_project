#include "trainer4.h"
#include "ui_trainer4.h"

trainer4::trainer4(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::trainer4)
{
    ui->setupUi(this);
    this->setFixedSize(599, 475);
    setWindowTitle("Galician Lions");
}

trainer4::~trainer4()
{
    delete ui;
}
