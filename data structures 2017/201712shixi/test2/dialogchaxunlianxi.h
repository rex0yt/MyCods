#ifndef DIALOGCHAXUNLIANXI_H
#define DIALOGCHAXUNLIANXI_H

#include <QDialog>
#include <vector>
#include "mapsrc/Relation.h"

namespace Ui {
  class DialogChaxunLianxi;
}

class DialogChaxunLianxi : public QDialog
{
  Q_OBJECT

public:
  explicit DialogChaxunLianxi(QWidget *parent = 0);
  ~DialogChaxunLianxi();

signals:
  int getRelation(int info, int info2=0);//返回两个人之间的关系
  std::vector<Relation> getOneAllRelation(int no);//返回一个人的所有联系人


private slots:
  void on_pushButton_query_clicked();

private:
  Ui::DialogChaxunLianxi *ui;
  bool getTextEdit();
  int info1;
  int info2;
};

#endif // DIALOGCHAXUNLIANXI_H
