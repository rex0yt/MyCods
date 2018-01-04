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

void DialogChaxunLianxiren::getTextNo()
{
    QString text1 = this->ui->textEdit_bianhao->toPlainText();
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
}

void DialogChaxunLianxiren::setTextPerson(Person onePerson)
{
  this->name = QString::fromLocal8Bit(onePerson.getName().data(),100);
  this->sex = QString::fromLocal8Bit(onePerson.getSex().data(),100);
  this->degree = QString::fromLocal8Bit(onePerson.getDegree().data(),100);
  this->job = QString::fromLocal8Bit(onePerson.getJob().data(),100);
  this->office = QString::fromLocal8Bit(onePerson.getOffice().data(),100);
  this->telephone = QString::fromLocal8Bit(onePerson.getTelephone().data(),100);

   this->ui->textEdit_name->setText(this->name);
  this->ui->textEdit_sex->setText(this->sex);
  this->ui->textEdit_degree->setText(this->degree);
  this->ui->textEdit_job->setText(this->job);
  this->ui->textEdit_office->setText(this->office);
  this->ui->textEdit_telephone->setText(this->telephone);
}

void DialogChaxunLianxiren::on_pushButton_chaxun_clicked()
{
    getTextNo();
    setTextPerson(getPerson(personNo));
}
