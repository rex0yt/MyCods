#include "dialogchaxunlianxi.h"
#include "ui_dialogchaxunlianxi.h"

#include <QMessageBox>
#include <QPushButton>
#include <sstream>
#include <vector>

DialogChaxunLianxi::DialogChaxunLianxi(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogChaxunLianxi)
{
    ui->setupUi(this);
    setWindowTitle(tr("关系查询界面："));
    //    connect(ui->pushButton_query,SIGNAL(clicked()),this,SLOT(on_pushButton_query_clicked()));
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
    //    this->getTextEdit();
    getTextEdit();
    if(info2 == 0)//查询一个人所有的联系
    {
        std::vector<Relation> thisRelation = getOneAllRelation(info1);
        Relation relaArray[1000];
        for(unsigned int i=0; i<thisRelation.size(); i++)
        {
            relaArray[i] = thisRelation[i];
        }
        std::sort(relaArray,relaArray+thisRelation.size());//快速排序方法
        QString ans;
        for(unsigned int i=0; i<thisRelation.size(); i++)
        {
            ans.append(QString::number(relaArray[i].getPer2()));
            ans.append("(");
            ans.append(QString::number(relaArray[i].getWeight()));
            ans.append(") ");
        }
        this->ui->textBrowser->setPlainText(ans);
    }
    else//查询两个人的关系值
    {
        int rela = getRelation(info1,info2);
        this->ui->textBrowser->setPlainText(QString::number(rela));
    }
}
