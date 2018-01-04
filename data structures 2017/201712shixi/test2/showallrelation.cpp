#include "showallrelation.h"
#include "ui_showallrelation.h"
#include <sstream>

ShowAllRelation::ShowAllRelation(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::ShowAllRelation)
{
  ui->setupUi(this);

}

void ShowAllRelation::showThisRealtion()
{
  vector<Person> allPerson = this->getallPerson();
  int num = (int)allPerson.size();
  cout << num << endl;
  ui->tableWidget->setRowCount(num+1);
  ui->tableWidget->setColumnCount(num+1);

  ui->tableWidget->setItem(0,0,new QTableWidgetItem(QString("关系网络图:")));
  for(int i=0; i<num; i++)
    {
      QString thisText = QString::number(allPerson[i].getNo());
      thisText.append(QString::fromLocal8Bit(allPerson[i].getName().c_str()));
      ui->tableWidget->setItem(0,i+1,new QTableWidgetItem(thisText));
      ui->tableWidget->setItem(i+1,0,new QTableWidgetItem(thisText));
    }
  for(int i=1; i<=num; i++)
    {
      for(int j=1; j<=num; j++)
        {
          ui->tableWidget->setItem(i,j,new QTableWidgetItem(this->getRelation(allPerson[i-1].getNo(),allPerson[j-1].getNo())));
        }
    }
}

ShowAllRelation::~ShowAllRelation()
{
  delete ui;
}
