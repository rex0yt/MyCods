#include "dialogxiugailianxi.h"
#include "ui_dialogxiugailianxi.h"

DialogXiugaiLianxi::DialogXiugaiLianxi(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::DialogXiugaiLianxi)
{
  ui->setupUi(this);
}

DialogXiugaiLianxi::~DialogXiugaiLianxi()
{
  delete ui;
}
