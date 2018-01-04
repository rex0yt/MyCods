#include "dialogxiugailianxi.h"
#include "ui_dialogxiugailianxi.h"

#include <QMessageBox>

DialogXiugaiLianxi::DialogXiugaiLianxi(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::DialogXiugaiLianxi)
{
  ui->setupUi(this);
  setWindowTitle(tr("关系修改界面："));
}

DialogXiugaiLianxi::~DialogXiugaiLianxi()
{
  delete ui;
}

bool DialogXiugaiLianxi::getText()
{
  QString text1 = this->ui->textEdit_per1->toPlainText();
  QString text2 = this->ui->textEdit_per2->toPlainText();
  QString text3 = this->ui->textEdit_qinmi->toPlainText();
  for(int i=0; i<text1.length(); i++)
  {
      if(text1[i]<'0' || text1[i]>'9')
      {
          QMessageBox thisBox(this);
          thisBox.setText(tr("输入格式有误，编号为纯数字"));
          thisBox.exec();
          return false;
      }
  }
  for(int i=0; i<text2.length(); i++)
  {
      if(text2[i]<'0' || text2[i]>'9')
      {
          QMessageBox thisBox(this);
          thisBox.setText(tr("输入格式有误，编号为纯数字"));
          thisBox.exec();
          return false;
      }
  }
  for(int i=0; i<text3.length(); i++)
  {
      if(text3[i]<'0' || text3[i]>'9')
      {
          QMessageBox thisBox(this);
          thisBox.setText(tr("输入格式有误，编号为纯数字"));
          thisBox.exec();
          return false;
      }
  }
  info1 = atoi(text1.toStdString().c_str());
  info2 = atoi(text2.toStdString().c_str());
  qinmi = atoi(text3.toStdString().c_str());
  return true;
}

void DialogXiugaiLianxi::on_pushButton_xiugai_clicked()
{
    if(!getText()) return ;
    if(info1 == info2)
      {
        QMessageBox thisBox(this);
        thisBox.setText(tr("自己对自己的关系不能操作！！！！"));
        thisBox.exec();
        return ;
      }
    int oldRelation = toGetRelation(info1,info2);
    if(oldRelation==0 && qinmi==0)
      {
        QMessageBox thisBox(this);
        thisBox.setText(tr("关系不存在，无法删除！！！！"));
        thisBox.exec();
        return ;
      }
    toUpdateRelation(info1,info2,qinmi);
    QMessageBox thisBox(this);
    thisBox.setText(tr("关系更新完成！！！"));
    thisBox.exec();
}
