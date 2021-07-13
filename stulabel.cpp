#include "stulabel.h"
#include<QPixmap>
StuLabel::StuLabel(QMainWindow *parent):QLabel(parent){
    this->resize(1500,710);
    this->move(0,90);
    this->setStyleSheet("background:#FAFAFA");
    //个人头像
    stuPhoto =new QLabel(this);
    stuPhoto->move(150,100);
    stuPhoto->resize(300,400);
    stuPhoto->setStyleSheet("background:rgb(0,150,0);border:1px solid rgb(180,180,180)");
    stuPhoto->setScaledContents(true);
    //个人信息
    stuNameLbl=new QLabel(this);
    stuNameLbl->setObjectName("name");
    stuNumLbl=new QLabel(this);
    stuNumLbl->setObjectName("num");
    stuPswLbl=new QLabel(this);
    stuPswLbl->setObjectName("psw");
    stuNameLbl->move(600,100);
    stuNumLbl->move(600,200);
    stuPswLbl->move(600,300);

    //样式表
    QFile qssfile(":/stulablestyle.qss");
    qssfile.open(QFile::ReadOnly);
    QString qss;
    qss =qssfile.readAll();
    this->setStyleSheet(qss);
    qssfile.close();
    //
}
