#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QLayout>

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void LianXiRenChaxun();
    void LianXiRenXiugai();
    void LianXiChaxun();
    void LianXiXiugai();

private:
    void createAction();
    //查询菜单动作
    QAction *LianXiRenChaxunAction;
    QAction *LianXiChaxunAction;
    //修改菜单动作
    QAction *LianXiRenXiugaiAction;
    QAction *LianXiXiugaiAction;

    //
    QLabel *text1;
    QGridLayout *mainLayout;
};

#endif // MAINWINDOW_H
