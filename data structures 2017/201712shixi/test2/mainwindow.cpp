#include <QAction>
#include <QMenuBar>
#include <QMessageBox>
#include <QStatusBar>
#include <QDialog>
#include <QLabel>
#include <QGridLayout>
#include <QWidget>
#include <QFont>

#include "mainwindow.h"
#include "dialogchaxunlianxiren.h"
#include "dialogchaxunlianxi.h"
#include "dialogxiugailianxiren.h"
#include "dialogxiugailianxi.h"

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent)
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

  createAction();
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
  connect(LianXiRenChaxunAction, &QAction::triggered, this, &MainWindow::LianXiRenChaxun);
  connect(LianXiChaxunAction, &QAction::triggered, this, &MainWindow::LianXiChaxun);
  QMenu *chaxun = menuBar()->addMenu(tr("信息查询"));
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

void MainWindow::LianXiRenChaxun()
{
  DialogChaxunLianxiren thisDialog;
  thisDialog.exec();
  return ;
}

void MainWindow::LianXiChaxun()
{
  DialogChaxunLianxi thisDialog;
  thisDialog.exec();
  return ;
}

void MainWindow::LianXiRenXiugai()
{
  DialogXiugaiLianxiren thisDialog;
  thisDialog.exec();
  return ;
}

void MainWindow::LianXiXiugai()
{
  DialogXiugaiLianxi thisDialog;
  thisDialog.exec();
  return ;
}
