#include "dialogchaxunlianxiren.h"
#include "ui_dialogchaxunlianxiren.h"

DialogChaxunLianxiren::DialogChaxunLianxiren(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::DialogChaxunLianxiren)
{
  ui->setupUi(this);
}

DialogChaxunLianxiren::~DialogChaxunLianxiren()
{
  delete ui;
}
