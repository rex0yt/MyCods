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

private:
  Ui::DialogChaxunLianxi *ui;
};

#endif // DIALOGCHAXUNLIANXI_H
