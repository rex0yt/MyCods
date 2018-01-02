#include "dialogxiugailianxiren.h"
#include "ui_dialogxiugailianxiren.h"

DialogXiugaiLianxiren::DialogXiugaiLianxiren(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::DialogXiugaiLianxiren)
{
  ui->setupUi(this);
}

DialogXiugaiLianxiren::~DialogXiugaiLianxiren()
{
  delete ui;
}
