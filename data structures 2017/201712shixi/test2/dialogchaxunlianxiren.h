#ifndef DIALOGCHAXUNLIANXIREN_H
#define DIALOGCHAXUNLIANXIREN_H

#include <QDialog>

namespace Ui {
  class DialogChaxunLianxiren;
}

class DialogChaxunLianxiren : public QDialog
{
  Q_OBJECT

public:
  explicit DialogChaxunLianxiren(QWidget *parent = 0);
  ~DialogChaxunLianxiren();

private slots:
  void on_pushButton_chaxun_clicked();

private:
  Ui::DialogChaxunLianxiren *ui;
  int personNo;
  QString name;
  QString other1;
  QString other2;
};

#endif // DIALOGCHAXUNLIANXIREN_H
