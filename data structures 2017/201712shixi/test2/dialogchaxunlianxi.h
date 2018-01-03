#ifndef DIALOGCHAXUNLIANXI_H
#define DIALOGCHAXUNLIANXI_H

#include <QDialog>

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
  QString getRelation(int info, int info2=0);

private slots:
  void on_pushButton_query_clicked();

private:
  Ui::DialogChaxunLianxi *ui;
  bool getTextEdit();
  int info1;
  int info2;
};

#endif // DIALOGCHAXUNLIANXI_H
