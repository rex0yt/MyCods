#ifndef DIALOGXIUGAILIANXIREN_H
#define DIALOGXIUGAILIANXIREN_H

#include <QDialog>

namespace Ui {
  class DialogXiugaiLianxiren;
}

class DialogXiugaiLianxiren : public QDialog
{
  Q_OBJECT

public:
  explicit DialogXiugaiLianxiren(QWidget *parent = 0);
  ~DialogXiugaiLianxiren();

private:
  Ui::DialogXiugaiLianxiren *ui;
  int personNo;
  QString name;
  QString other1;
  QString other2;
};

#endif // DIALOGXIUGAILIANXIREN_H
