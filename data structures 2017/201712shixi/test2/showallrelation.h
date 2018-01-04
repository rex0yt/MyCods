#ifndef SHOWALLRELATION_H
#define SHOWALLRELATION_H

#include <QDialog>
#include <vector>
#include "mapsrc/Person.h"

namespace Ui {
  class ShowAllRelation;
}

class ShowAllRelation : public QDialog
{
  Q_OBJECT

public:
  explicit ShowAllRelation(QWidget *parent = 0);
  ~ShowAllRelation();
  void showThisRealtion();

signals:
  vector<Person> getallPerson();
  QString getRelation(int no1,int no2);
  Person getInfo(int no);

private:
  Ui::ShowAllRelation *ui;
};

#endif // SHOWALLRELATION_H
