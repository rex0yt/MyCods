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
    ///////////以下是槽函数//////////////////////
    QString getRelation(int i1,int i2);//查询关系对话框中查询关系
    Person getPersonInfo(int no);//联系人查询对话框中通过编号查询联系人信息
    bool isNoExist(int no);//联系人修改对话框中判断编号是否存在
    bool toUpdatePerson(Person info);//修改联系人信息
    bool toAddPerson(Person info);//传出Person以增加联系人
    bool toDeletePerson(Person info);//传出Person以删除联系人
    int toGetRelation(int no1,int no2);//查询亲密度的值
    bool toUpdateRelation(int no1,int no2,int relation);//更新亲密度的值
    vector<Person> getallPerson();//返回所有联系人的编号

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
