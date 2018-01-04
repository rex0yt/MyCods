#include "dialogxiugailianxiren.h"
#include "ui_dialogxiugailianxiren.h"
#include "mapsrc/LinkedList.h"
#include "mapsrc/Person.h"
#include <QMessageBox>

DialogXiugaiLianxiren::DialogXiugaiLianxiren(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::DialogXiugaiLianxiren)
{
  ui->setupUi(this);
  setWindowTitle(tr("联系人信息修改界面："));
}

DialogXiugaiLianxiren::~DialogXiugaiLianxiren()
{
  delete ui;
}

void DialogXiugaiLianxiren::on_pushButton_add_clicked()
{
  getAllText();
  if(isThisNoExist(personNo))
    {
      QMessageBox thisBox(this);
      thisBox.setText(tr("联系人已经存在，无法添加！！！！！"));
      thisBox.exec();
    }
  this->toAddPerson(thisPerson);
  //////////////////////////////////////////
  QMessageBox thisBox(this);
  thisBox.setText(tr("联系人添加成功！！！！！"));
  thisBox.exec();
}

void DialogXiugaiLianxiren::on_pushButton_delete_clicked()
{
  getAllText();
  if(!isThisNoExist(personNo))
    {
      QMessageBox thisBox(this);
      thisBox.setText(tr("联系人不存在，无法删除！！！！！"));
      thisBox.exec();
    }
  this->toDeletePerson(thisPerson);
  //////////////////////////////////////////
  QMessageBox thisBox(this);
  thisBox.setText(tr("联系人删除成功！！！！！"));
  thisBox.exec();
}

void DialogXiugaiLianxiren::on_pushButton_update_clicked()
{
  getAllText();
  if(!isThisNoExist(personNo))//判断联系人是否存在
    {
      QMessageBox thisBox(this);
      thisBox.setText(tr("联系人不存在，无法更新！！！！！"));
      thisBox.exec();
    }
  this->toUpdatePerson(thisPerson);
  //////////////////////////////////////////
  QMessageBox thisBox(this);
  thisBox.setText(tr("联系人更新成功！！！！！"));
  thisBox.exec();
}

void DialogXiugaiLianxiren::getAllText()
{
  QString text1 = this->ui->textEdit_bianhao->toPlainText();
  name = this->ui->textEdit_name->toPlainText();
  sex = this->ui->textEdit_sex->toPlainText();
  degree = this->ui->textEdit_degree->toPlainText();
  job = this->ui->textEdit_job->toPlainText();
  office = this->ui->textEdit_office->toPlainText();
  telephone = this->ui->textEdit_telephone->toPlainText();

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
  personNo = atoi(text1.toStdString().data());
  thisPerson.setNo(personNo);
  thisPerson.setName(name.toLocal8Bit().toStdString());
  thisPerson.setSex(sex.toLocal8Bit().toStdString());
  thisPerson.setDegree(degree.toLocal8Bit().toStdString());
  thisPerson.setJob(job.toLocal8Bit().toStdString());
  thisPerson.setOffice(office.toLocal8Bit().toStdString());
  thisPerson.setTelephone(telephone.toLocal8Bit().toStdString());
}
