#include "mainwindow.h"
#include<QPixmap>
#include"assolabel.h"
#include<QFile>
#include"asso.h"
#include<QDebug>
MainWindow::MainWindow(QWidget *parent): QMainWindow(parent){
    this->resize(1500,800);
    //禁止改变窗口大小
    this->setWindowFlags (Qt::FramelessWindowHint);
    docLbl =new QLabel(this);
    docLbl->resize(1500,90);
    docLbl->setObjectName("doc");
    //doc栏布局
    asso=new QPushButton(this);
    asso->setText("社团");
    asso->setGeometry(60,20,120,70);
    asso->setObjectName("asso");
    stu=new QPushButton(this);
    exit=new QPushButton(this);
    stu->setText("个人信息");
    stu->setObjectName("stu");
    stu->setGeometry(190,20,120,70);
    exit->setGeometry(1465,5,30,30);
    exit->setObjectName("exit");
    QIcon myicon; //新建QIcon对象
    myicon.addFile(tr(":/image/icon_close.svg")); //让QIcon对象指向想要的图标
    exit->setIcon(myicon); //给按钮添加图标
    exit->setIconSize(QSize(30,30));
    //滚动窗口
    //滚动窗口的载体
    pLabelTitle = new QLabel(this);
    pLabelTitle->resize(1500,710);
    pLabelTitle->move(0,90);
    pLabelTitle->setStyleSheet("background:rgb(0,0,240)");
    //滚动区域
    scrollArea=new QScrollArea(pLabelTitle);
    scrollArea->setGeometry(0, 0, 1500, 710);//左上长宽
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//隐藏横向滚动条
    scrollArea->setFrameShape(QFrame::NoFrame);
    scrollArea->setStyleSheet( "border:1px solid rgb(180,180,180);width:8px;background:#FAFAFA");
    //滚动内容载体
    widget = new QWidget(pLabelTitle);
    widget->setContentsMargins(0, 0, 0, 0);//设置外边距为0
    widget->setFixedSize(1492, 1900);
    widget->setStyleSheet("border-style:hidden;background:#FFFFFF");
    scrollArea->verticalScrollBar()->setStyleSheet(
    "QScrollBar:vertical"
    "{"
        "width:8px;"
        "background:rgba(0,0,0,0%);"
        "margin:0px,0px,0px,0px;"
        "padding-top:4px;"
        "padding-bottom:4px;"
    "}"
    "QScrollBar::handle:vertical"
    "{"
        "width:8px;"
        "background:rgba(0,0,0,25%);"
        " border-radius:2px;"
        "min-height:20;"
    "}"
    "QScrollBar::handle:vertical:hover"
    "{"
        "width:8px;"
        "background:rgba(0,0,0,50%);"
        " border-radius:2px;"
        "min-height:20;"
    "}"
    );
    scrollArea->setWidget(widget);
    widget->setObjectName("we");
    //pLabelGetInfo，显示信息界面

    //学生个人界面
    stuLabel=new StuLabel(this);
    stuLabel->close();
    //
    QFile qssfile(":/mainwindowstyle.qss");
    qssfile.open(QFile::ReadOnly);
    QString qss;
    qss =qssfile.readAll();
    this->setStyleSheet(qss);
    qssfile.close();
    //

    connect(exit,&QPushButton::clicked,this,&MainWindow::close);
    connect(stu,&QPushButton::clicked,this,&MainWindow::choose_stu);
    connect(asso,&QPushButton::clicked,this,&MainWindow::choose_asso);
}
void MainWindow::choose_stu(){
    pLabelTitle->close();
    stuLabel->show();
    stu->setStyleSheet(
        "color:#7bbfea;"
        "background-color:white;"
    );
    asso->setStyleSheet(
        "color:white;"
        "background-color:#7bbfea;"
    );
}
void MainWindow::choose_asso(){
    pLabelTitle->show();
    stuLabel->close();
    stu->setStyleSheet(
        "color:white;"
        "background-color:#7bbfea;"
    );
    asso->setStyleSheet(
        "color:#7bbfea;"
        "background-color:white;"
    );

}
void MainWindow::close_list(){
    for(int i=1;i<=20;i++){
        list[i]->close();
    }
}
void MainWindow::show_list(){
    for(int i=1;i<=20;i++){
        list[i]->show();
    }
}
