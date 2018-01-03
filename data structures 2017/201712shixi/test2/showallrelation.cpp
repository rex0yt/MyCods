#include "showallrelation.h"
#include "ui_showallrelation.h"

ShowAllRelation::ShowAllRelation(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::ShowAllRelation)
{
  ui->setupUi(this);
}

ShowAllRelation::~ShowAllRelation()
{
  delete ui;
}
