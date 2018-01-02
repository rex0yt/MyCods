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

private:
  Ui::DialogXiugaiLianxi *ui;
};

#endif // DIALOGXIUGAILIANXI_H
