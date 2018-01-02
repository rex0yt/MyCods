#include "dialogchaxunlianxi.h"
#include "ui_dialogchaxunlianxi.h"

DialogChaxunLianxi::DialogChaxunLianxi(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::DialogChaxunLianxi)
{
  ui->setupUi(this);
}

DialogChaxunLianxi::~DialogChaxunLianxi()
{
  delete ui;
}
