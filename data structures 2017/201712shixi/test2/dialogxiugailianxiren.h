#ifndef DIALOGXIUGAILIANXIREN_H
#define DIALOGXIUGAILIANXIREN_H

#include <QDialog>
#include "mapsrc/Person.h"

namespace Ui {
  class DialogXiugaiLianxiren;
}

class DialogXiugaiLianxiren : public QDialog
{
  Q_OBJECT

public:
  explicit DialogXiugaiLianxiren(QWidget *parent = 0);
  ~DialogXiugaiLianxiren();

signals://信号函数
  bool isThisNoExist(int no);//通过编号判断联系人是否存在
  bool toUpdatePerson(Person info);//传出Person以修改信息
  bool toAddPerson(Person info);//传出Person以增加联系人
  bool toDeletePerson(Person info);//传出Person以删除联系人

private slots:
  void on_pushButton_add_clicked();
  void on_pushButton_delete_clicked();
  void on_pushButton_update_clicked();

private:
  Ui::DialogXiugaiLianxiren *ui;
  int personNo;
  QString name;
  QString sex;
  QString degree;
  QString job;
  QString office;
  QString telephone;
  Person thisPerson;

  void getAllText();
};

#endif // DIALOGXIUGAILIANXIREN_H
