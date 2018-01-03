#ifndef SHOWALLRELATION_H
#define SHOWALLRELATION_H

#include <QDialog>

namespace Ui {
  class ShowAllRelation;
}

class ShowAllRelation : public QDialog
{
  Q_OBJECT

public:
  explicit ShowAllRelation(QWidget *parent = 0);
  ~ShowAllRelation();

private:
  Ui::ShowAllRelation *ui;
};

#endif // SHOWALLRELATION_H
