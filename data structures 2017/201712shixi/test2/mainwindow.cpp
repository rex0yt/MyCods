#include <QAction>
#include <QMenuBar>
#include <QMessageBox>
#include <QStatusBar>
#include <QDialog>
#include <QLabel>
#include <QGridLayout>
#include <QWidget>
#include <QFont>
#include <iostream>
#include <sstream>

#include "mainwindow.h"
#include "dialogchaxunlianxiren.h"
#include "dialogchaxunlianxi.h"
#include "dialogxiugailianxiren.h"
#include "dialogxiugailianxi.h"
#include "showallrelation.h"
#include "mapsrc/Relation.h"
#include "mapsrc/LinkedList.h"
#include "mapsrc/Person.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent)
{
  initJieMian();
  createAction();
  readInfomation();
}

MainWindow::~MainWindow()
{
}

void MainWindow::createAction()
{
  //  信息查询菜单实现
  LianXiRenChaxunAction = new QAction(tr("联系人查询"), this);
  LianXiRenChaxunAction->setStatusTip(tr("查询联系人..."));
  LianXiChaxunAction = new QAction(tr("关系查询"), this);
  LianXiChaxunAction->setStatusTip(tr("查询联系人的关系..."));
  showAllRelation = new QAction(tr("展示社交网络图"), this);
  showAllRelation->setStatusTip(tr("通过表格展现所有联系..."));
  connect(LianXiRenChaxunAction, &QAction::triggered, this, &MainWindow::LianXiRenChaxun);
  connect(LianXiChaxunAction, &QAction::triggered, this, &MainWindow::LianXiChaxun);
  connect(showAllRelation, &QAction::triggered, this, &MainWindow::ShowRelation);
  QMenu *chaxun = menuBar()->addMenu(tr("信息查询"));
  chaxun->addAction(showAllRelation);
  chaxun->addAction(LianXiRenChaxunAction);
  chaxun->addAction(LianXiChaxunAction);

  //  信息修改菜单实现
  LianXiRenXiugaiAction = new QAction(tr("修改联系人"), this);
  LianXiRenXiugaiAction->setStatusTip(tr("修改联系人的信息..."));
  LianXiXiugaiAction = new QAction(tr("修改关系"), this);
  LianXiXiugaiAction->setStatusTip(tr("对关系的修改..."));
  connect(LianXiRenXiugaiAction, &QAction::triggered, this, &MainWindow::LianXiRenXiugai);
  connect(LianXiXiugaiAction, &QAction::triggered, this, &MainWindow::LianXiXiugai);
  QMenu *xiugai = menuBar()->addMenu(tr("信息修改"));
  xiugai->addAction(LianXiRenXiugaiAction);
  xiugai->addAction(LianXiXiugaiAction);

  //  状态菜单显示准备
  statusBar()->showMessage(tr("准备完成！"));
}

void MainWindow::readInfomation()
{
  path = "data.txt";
  dataIO = new IO(path);
  dataIO->openFile();
  dataIO->readData(personArray, relationArray);
  dataIO->closeFile();

  int tmpPersonNo;
  for (unsigned int i=0; i<personArray.size(); i++)
    {
      tmpPersonNo = personArray[i].getNo();
      personNoArray.push_back(tmpPersonNo);
    }
  thisMap = new Map<int>(personNoArray, relationArray);
  thisList = new DoubleLinkedList<Person>(personArray);
  thisMap->Output();
  thisList->Output();
}

void MainWindow::initJieMian()
{
  setWindowTitle(tr("社交网络关系:"));
  this->resize(400,300);
  thisWiget = new QWidget(this);
  setCentralWidget(thisWiget);
  text1 = new QLabel(thisWiget);
  text1->setText(tr("社交网络关系操作系统\n"));
  text1->setFont(QFont("Arial", 30, QFont::Black));
  text2 = new QLabel(thisWiget);
  text2->setText("\t作者：殷童-陈越-侯君瑶");
  text2->setFont(QFont("Arial", 18, QFont::Black));
  text3 = new QLabel(thisWiget);
  text3->setText("\t时间：2017年12月31日");
  text3->setFont(QFont("Arial", 18, QFont::Black));
  mainLayout = new QGridLayout(thisWiget);
  mainLayout->addWidget(text1,0,0);
  mainLayout->addWidget(text2,1,0);
  mainLayout->addWidget(text3,2,0);
}

void MainWindow::LianXiRenChaxun()
{
  DialogChaxunLianxiren thisDialog;
  connect(&thisDialog,&DialogChaxunLianxiren::getPerson,this,MainWindow::getPersonInfo);
  thisDialog.exec();
  return ;
}

Person MainWindow::getPersonInfo(int no)
{
  return thisList->SearchNo(no)->data;
}

void MainWindow::LianXiChaxun()
{
  DialogChaxunLianxi thisDialog;
  connect(&thisDialog,&DialogChaxunLianxi::getRelation,this,MainWindow::getRelation);
  thisDialog.exec();
  return ;
}

QString MainWindow::getRelation(int i1,int i2)
{
  string ans;
  string tmpString;

  if(i2 == 0)
    {
      int vertexPos = thisMap->getVertexPos(i1);
      vector<int> result = thisMap->getAllRelation(vertexPos);
      for(unsigned int i=0; i<result.size(); i++)
        {
          stringstream ss;
          ss << result[i];
          ss >> tmpString;
          ans.append(tmpString);
          ans.append(" ");
        }
      return QString::fromStdString(ans);
    }
  stringstream ss;
  ss << thisMap->getWeight(thisMap->getVertexPos(i1),thisMap->getVertexPos(i2));
  ss >> ans;
  return QString::fromStdString(ans);
}

void MainWindow::LianXiRenXiugai()
{
  DialogXiugaiLianxiren thisDialog;
  connect(&thisDialog,&DialogXiugaiLianxiren::isThisNoExist,this,MainWindow::isNoExist);
  connect(&thisDialog,&DialogXiugaiLianxiren::toUpdatePerson,this,MainWindow::toUpdatePerson);
  connect(&thisDialog,&DialogXiugaiLianxiren::toAddPerson,this,MainWindow::toAddPerson);
  connect(&thisDialog,&DialogXiugaiLianxiren::toDeletePerson,this,MainWindow::toDeletePerson);
  thisDialog.exec();
  return ;
}

bool MainWindow::isNoExist(int no)
{
  int pos = thisMap->getVertexPos(no);
  if(pos == -1)return false;
  return true;
}

bool MainWindow::toUpdatePerson(Person info)
{
  DoubleLinkNode<Person>* tmp = thisList->SearchNo(info.getNo());
  tmp->data.setName(info.getName());
  tmp->data.setSex(info.getSex());
  tmp->data.setDegree(info.getDegree());
  tmp->data.setJob(info.getJob());
  tmp->data.setOffice(info.getOffice());
  tmp->data.setTelephone(info.getTelephone());
  return true;
}

bool MainWindow::toAddPerson(Person info)
{
  thisList->PushBack(info);
  thisMap->insertVertex(info.getNo());
  return true;
}

bool MainWindow::toDeletePerson(Person info)
{
  thisList->DeleteOne(info.getNo());
  thisMap->removeVertex(thisMap->getVertexPos(info.getNo()));
  //  thisList->Output();
  //  thisMap->Output();
  return true;
}
void MainWindow::LianXiXiugai()
{
  DialogXiugaiLianxi thisDialog;
  connect(&thisDialog,&DialogXiugaiLianxi::toUpdateRelation,this,MainWindow::toUpdateRelation);
  connect(&thisDialog,&DialogXiugaiLianxi::toGetRelation,this,MainWindow::toGetRelation);
  thisDialog.exec();
  return ;
}

int MainWindow::toGetRelation(int no1,int no2)//查询亲密度的值
{
  return thisMap->getWeight(thisMap->getVertexPos(no1),thisMap->getVertexPos(no2));
}

bool MainWindow::toUpdateRelation(int no1,int no2,int relation)//更新亲密度的值
{
  int oldRela = thisMap->getWeight(thisMap->getVertexPos(no1),thisMap->getVertexPos(no2));
  if(oldRela == 0) //原先关系不存在 添加关系
    {
      thisMap->insertEdge(thisMap->getVertexPos(no1),thisMap->getVertexPos(no2),relation);
    }
  else//原先关系存在 删除或修改联系
    {
      if(relation == 0)//删除关系
        {
          thisMap->removeEdge(thisMap->getVertexPos(no1),thisMap->getVertexPos(no2));
          return true;
        }
      else    //修改关系
        {
          thisMap->setWeight(thisMap->getVertexPos(no1),thisMap->getVertexPos(no2),relation);
        }
    }
  return false;
}

void MainWindow::ShowRelation()
{
  ShowAllRelation thisDialog;
  connect(&thisDialog,&ShowAllRelation::getRelation,this,MainWindow::getRelation);
  connect(&thisDialog,&ShowAllRelation::getInfo,this,MainWindow::getPersonInfo);
  connect(&thisDialog,&ShowAllRelation::getallPerson,this,MainWindow::getallPerson);
  thisDialog.showThisRealtion();
  thisDialog.exec();
  return ;
}

vector<Person> MainWindow:: getallPerson()//返回所有联系人的编号
{
  vector<Person> ans;
  thisList->Output(ans);
  return ans;
}
