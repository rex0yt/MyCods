#include "dialogchaxunlianxiren.h"
#include "ui_dialogchaxunlianxiren.h"

#include <QMessageBox>

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

void DialogChaxunLianxiren::on_pushButton_chaxun_clicked()
{
  QString text1 = this->ui->textEdit_bianhao->toPlainText();
  char *end;
  for(int i=0; i<text1.length(); i++)
  {
    if(text1[i]<'0' || text1[i]>'9')
    {
      QMessageBox thisBox(this);
      thisBox.setText(tr("输入格式有误，编号为纯数字"));
      thisBox.exec();
      personNo = 0;
      return ;
    }
  }
  personNo = static_cast<int>(strtol((char*)text1.data(),&end,10));
}
