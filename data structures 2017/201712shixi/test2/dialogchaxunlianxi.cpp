#include "dialogchaxunlianxi.h"
#include "ui_dialogchaxunlianxi.h"

#include <QMessageBox>
#include <QPushButton>
#include <sstream>

DialogChaxunLianxi::DialogChaxunLianxi(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogChaxunLianxi)
{
    ui->setupUi(this);
    connect(ui->pushButton_query,SIGNAL(clicked()),this,SLOT(on_pushButton_query_clicked()));
}

DialogChaxunLianxi::~DialogChaxunLianxi()
{
    delete ui;
}

bool DialogChaxunLianxi::getTextEdit()
{
    QString text1 = this->ui->textEdit_p1->toPlainText();
    QString text2 = this->ui->textEdit_p2->toPlainText();

    for(int i=0; i<text1.length(); i++)
    {
        if(text1[i]<'0' || text1[i]>'9')
        {
            QMessageBox thisBox(this);
            thisBox.setText(tr("输入格式有误，编号为纯数字"));
            thisBox.exec();
            return false;
        }
    }
    for(int i=0; i<text2.length(); i++)
    {
        if(text2[i]<'0' || text2[i]>'9')
        {
            QMessageBox thisBox(this);
            thisBox.setText(tr("输入格式有误，编号为纯数字"));
            thisBox.exec();
            return false;
        }
    }
    info1 = atoi(text1.toStdString().c_str());
    info2 = atoi(text2.toStdString().c_str());
    return true;
}

void DialogChaxunLianxi::on_pushButton_query_clicked()
{
    this->getTextEdit();
    this->ui->textBrowser->setPlainText(QString(getRelation(info1,info2)));
}
