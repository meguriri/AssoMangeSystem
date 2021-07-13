#include "assolab.h"
#include<QPixmap>
#include<QDebug>
Assolab::Assolab(QWidget *parent):QLabel (parent)
{
    resize(1500,710);
    setWindowTitle("社团介绍");
    joinbut=new QPushButton;
    joinbut->setParent(this);
    joinbut->setText("加入社团");
    joinbut->setGeometry(1200,120,100,100);
    joinbut->setObjectName("join");

    backbut=new QPushButton;
    backbut->setParent(this);
    backbut->setText("返回");
    backbut->setGeometry(0,0,50,30);
    backbut->setObjectName("back");
    chengyuan=new QLabel(this);
    chengyuan->setText("成员信息：  ");
    chengyuan->setGeometry(0,350,110,40);

       setStyleSheet("background:#FAFAFA");
       assophoto =new QLabel(this);
       assophoto->move(150,100);
       assophoto->resize(300,200);
       assophoto->setScaledContents(true);
       //社团信息
       assoname=new QLabel(this);
       repername=new QLabel(this);
       reperpsw=new QLabel(this);
       assoname->move(500,100);
       repername->move(500,200);       reperpsw->move(500,300);


       connect(joinbut,&QPushButton::clicked,this,&Assolab::joinasso);
       //样式表
       this->setStyleSheet(
                   "QPushButton#join{"
                        "background: #3bee41;"
                        "border-radius: 6px;"
                        "color: white;"
                   "}"
                   "QPushButton#back{"
                        "background: #7bbfea;"
                        "border-radius: 6px;"
                        "color: white;"
                        "font-size:20px;"
                   "}"
                   "*{"
                       "font-family:\"Microsoft YaHei\";"
                        "font-size:24px;"
                   "}"

                   "*{"
                        "background: white;"
                   "}"
                   );
       //
}

void Assolab::joinasso(){
    QMessageBox::information(this,"加入社团","已提交申请!",QMessageBox::Ok);
    joinbut->setText("已申请");
    joinbut->setEnabled(false);
    joinbut->setStyleSheet("background:#ffc20e");

    //写入文件
    QFile aFile(":/image/3.txt");
   if( !aFile.open(QIODevice::WriteOnly|QIODevice::Text| QIODevice::Append))
       return;
       QTextStream aStream(&aFile); //用文本流读取文件
       QString str="cwewwwwwwwww";
       const char *sTemp=str.toStdString().c_str();
       //aStream<<str<<endl; //写入文本流
       aFile.write(sTemp,20);
       aFile.flush();//清理缓冲区
       aFile.close();//关闭文件
}
