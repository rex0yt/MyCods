#ifndef DIALOGCHAXUNLIANXIREN_H
#define DIALOGCHAXUNLIANXIREN_H

#include <QDialog>
#include "mapsrc/Person.h"

namespace Ui {
  class DialogChaxunLianxiren;
}

class DialogChaxunLianxiren : public QDialog
{
  Q_OBJECT

public:
  explicit DialogChaxunLianxiren(QWidget *parent = 0);
  ~DialogChaxunLianxiren();
signals:
    Person getPerson(int personNo);
private slots:
  void on_pushButton_chaxun_clicked();

private:
  Ui::DialogChaxunLianxiren *ui;
  int personNo;
  QString name;
  QString sex;
  QString degree;
  QString job;
  QString office;
  QString telephone;

  void getTextNo();
  void setTextPerson(Person onePerson);
};

#endif // DIALOGCHAXUNLIANXIREN_H
