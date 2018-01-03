#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QLayout>
#include <QWidget>
#include "mapsrc/Person.h"
#include "mapsrc/Relation.h"
#include "mapsrc/IO.h"
#include "mapsrc/LinkedList.h"
#include "mapsrc/Map.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QString getRelation(int i1,int i2);
    Person getPersonInfo(int no);

private slots:
    void LianXiRenChaxun();
    void LianXiRenXiugai();
    void LianXiChaxun();
    void LianXiXiugai();
    void ShowRelation();

private:
    void initJieMian();//画出初始界面
    void createAction();//显示菜单
    void readInfomation();//初始化关系图
    //查询菜单动作
    QAction *LianXiRenChaxunAction;
    QAction *LianXiChaxunAction;
    QAction *showAllRelation;
    //修改菜单动作
    QAction *LianXiRenXiugaiAction;
    QAction *LianXiXiugaiAction;

    //主界面栏信息
    QWidget *thisWiget;
    QLabel *text1;
    QLabel *text2;
    QLabel *text3;
    QGridLayout *mainLayout;
    //图信息
    Map<int> *thisMap;
    string path;
    vector<Person> personArray;
    vector<Relation> relationArray;
    vector<int> personNoArray;
    IO *dataIO;
    DoubleLinkedList<Person> *thisList;
};

#endif // MAINWINDOW_H
