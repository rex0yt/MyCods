#ifndef DIALOGXIUGAILIANXI_H
#define DIALOGXIUGAILIANXI_H

#include <QDialog>

namespace Ui {
  class DialogXiugaiLianxi;
}

class DialogXiugaiLianxi : public QDialog
{
  Q_OBJECT

public:
  explicit DialogXiugaiLianxi(QWidget *parent = 0);
  ~DialogXiugaiLianxi();
  bool getText();

signals:
  bool toUpdateRelation(int no1,int no2, int relation);//更新亲密度的值
  int toGetRelation(int no1,int no2);//查询亲密度的值

private slots:
  void on_pushButton_xiugai_clicked();

private:
  Ui::DialogXiugaiLianxi *ui;
  int info1;
  int info2;
  int qinmi;
};

#endif // DIALOGXIUGAILIANXI_H
