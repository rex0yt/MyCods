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

private:
  Ui::DialogChaxunLianxiren *ui;
};

#endif // DIALOGCHAXUNLIANXIREN_H
