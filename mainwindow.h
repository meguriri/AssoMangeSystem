#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QLabel>
#include<QDockWidget>
#include<QPushButton>
#include<QFile>
#include<QHBoxLayout>
#include<QScrollArea>
#include<QScrollBar>
#include<QImage>
#include<QPixmap>
#include"stulabel.h"
#include"asso.h"
#include<QString>
#include<QVector>
#include"assolabel.h"
#include"asso.h"
#include"student.h"
#include"assolab.h"
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent =0);

    void getasso(QVector<Association>a){
        for(int i=0;i<a.size();i++){
            assList.push_back(a[i]);
        }
        for(int i=1;i<=5;i++){
            for(int j=1;j<=4;j++){
                list[(i-1)*4+j] =new AssoLabel(widget);
                list[(i-1)*4+j]->assolab=new Assolab(widget);
                list[(i-1)*4+j]->assolab->close();
                list[(i-1)*4+j]->assolab =new Assolab(widget);
                list[(i-1)*4+j]->assolab->close();
                list[(i-1)*4+j]->asso=&assList[(i-1)*4+j-1];
                list[(i-1)*4+j]->setObjectName("lbl");
                list[(i-1)*4+j]->setParent(widget);
                list[(i-1)*4+j]->setGeometry(300*(j-1)+59*j,70*i+300*(i-1),300,300);
                list[(i-1)*4+j]->setStyleSheet("background:white");
                //个人头像
                list[(i-1)*4+j]->pixLbl->setPixmap(assList[(i-1)*4+j-1].assoPix);
                list[(i-1)*4+j]->pixLbl->setScaledContents(true);
                //社团名字
                QString s=assList[(i-1)*4+j-1].getAssoName();
                list[(i-1)*4+j]->assoName->setText(s);
                list[(i-1)*4+j]->assoName->setStyleSheet("font-size:25px;color:rgb(150,150,150)");
            }
        }
        for(int i=1;i<=20;i++){
            connect(list[i]->assoBtn,&QPushButton::clicked,list[i],&AssoLabel::getmsg);
            connect(list[i]->assoBtn,&QPushButton::clicked,this,&MainWindow::close_list);
            connect(list[i]->assolab->backbut,&QPushButton::clicked,list[i],&AssoLabel::closelab);
            connect(list[i]->assolab->backbut,&QPushButton::clicked,this,&MainWindow::show_list);
        }
    }
    void getstu(QVector<Student>a){
        for(int i=0;i<a.size();i++){
            stuList.push_back(a[i]);
        }

    }
    void getuser(Student *s){
        user=s;
        QString name="姓名：     "+user->stuName;
        QString num="账号：     "+user->stuNumber;
        QString psw="密码：     "+user->stuPassword;
        stuLabel->stuNameLbl->setText(name);
        stuLabel->stuNumLbl->setText (num);
        stuLabel->stuPswLbl->setText (psw);
        stuLabel->stuPhoto->setPixmap(user->stuPix);
    }
    void setAsso(){
        for(int i=0;i<assList.size();i++){
            this->stuLabel->assList.push_back(assList[i]);
            for(int j=0;j<assList[i].member.size();j++){
                if(assList[i].member[j]==user->stuName){
                    this->stuLabel->ldsAsso=&assList[i];
                    break;
                }
            }
        }
        for(int i=1;i<=20;i++){
            list[i]->user=user->stuName;
            list[i]->choose=this->choose;
        }
    }
    int choose;
    QLabel *docLbl;
    QPushButton *asso;
    QPushButton *stu;
    QPushButton *exit;
    //滚动窗口
    QWidget *widget;
    QScrollArea *scrollArea;
    QLabel *pLabelTitle;
    QLabel *pLabelGetInfo;
    StuLabel *stuLabel;
    QVector<Association>assList;
    QVector<Student>stuList;
    Student *user;
    AssoLabel* list[21];
signals://信号

public slots://槽
    void choose_asso();
    void choose_stu();
    void close_list();
    void show_list();
};
#endif // MAINWINDOW_H
