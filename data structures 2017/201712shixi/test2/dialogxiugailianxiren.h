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
};

#endif // DIALOGXIUGAILIANXIREN_H
