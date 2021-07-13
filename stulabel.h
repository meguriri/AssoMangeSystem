#ifndef STULABEL_H
#define STULABEL_H
#include<QLabel>
#include<QMainWindow>
#include<QPushButton>
#include<QFile>
#include<QDebug>
#include<QVector>
#include"asso.h"
#include<QMessageBox>
class StuLabel:public QLabel{
public:
    explicit StuLabel(QMainWindow *parent = nullptr);
    void chooseway(int choose){

//        ldsAsso->member;
        /*

            输出社团成员
        */
        //qDebug()<<ldsAsso->getAssoName();
        if(choose==1){//负责人
            //qDebug()<<ldsAsso->getAssoName();
            int x=550,y=430;
            chengyuan=new QLabel(this);
            chengyuan->setText("负责的社团："+ldsAsso->getAssoName()+"\n社团成员：");
            chengyuan->setGeometry(500,330,250,150);
            chengyuan->setStyleSheet("font-size:22px");
            for(int i=0;i<ldsAsso->member.size();i++)
            {
                personname[i]=new QLabel(this);
                personname[i]->move(x,y);
                personname[i]->setText(ldsAsso->member[i]);
                personname[i]->setGeometry(x,y,200,40);
                personname[i]->setStyleSheet("font-size:22px");
                x=x+200;
            }
            an=new QLabel(this);
            ming=new QLabel(this);
            an->setText("申请加入的人：");
            an->setGeometry(200,500,200,40);

            an->setStyleSheet("font-size:22px");

            accept=new QPushButton(this);
            refuse=new QPushButton(this);
            ming->setText("比企谷八幡");
            ming->setGeometry(300,550,200,40);
            ming->setStyleSheet("font-size:22px");
            accept->setText("接受");
            accept->setGeometry(550,550,100,40);
            accept->setStyleSheet("font-size:22px");
            refuse->setText("拒绝");
            refuse->setGeometry(680,550,100,40);
            refuse->setStyleSheet("font-size:22px");
            accept->setObjectName("join");
            refuse->setObjectName("back");
            this->setStyleSheet(
                               "QPushButton#join{"
                                    "background: #3bee41;"
                                    "border-radius: 6px;"
                                    "color: white;"
                                    "font-size:20px;"
                               "}"
                               "QPushButton#back{"
                                    "background: #F44336;"
                                    "border-radius: 6px;"
                                    "color: white;"
                                    "font-size:20px;"
                               "}"
                               );
            connect(accept,&QPushButton::clicked,this,&StuLabel::accepta);
            connect(refuse,&QPushButton::clicked,this,&StuLabel::refusea);

        }
        else if(choose==2){//成员
            QLabel *cshetuan;
            QLabel *shetuan[10];
            cshetuan=new QLabel(this);
            cshetuan->setGeometry(100,500,150,40);
            cshetuan->setText("参加的社团：");
            cshetuan->setStyleSheet("font-size:24px");
            int x=250,y=550,k=0;
            for(int i=0;i<assList.size();i++)
            {
                for(int j=0;j<assList[i].member.size();j++)
                {
                    if(assList[i].member[j]==user)
                    {
                        shetuan[k]=new QLabel(this);
                        shetuan[k]->setGeometry(x,y,150,40);
                        shetuan[k]->setText(assList[i].getAssoName());
                        shetuan[k]->setStyleSheet("font-size:24px");
                        x=x+200;
                        k++;
                        break;
                    }
                }

            }

        }
    }
    QLabel *personname[10];
    QLabel *chengyuan;
    QLabel *an,*ming;
    QPushButton *accept,*refuse;
    QLabel *stuPhoto;
    QPushButton *btn1;
    QLabel *stuNameLbl;
    QLabel *stuNumLbl;
    QLabel *stuPswLbl;
    QString user;
    int choose;
    Association *ldsAsso;
    QVector<Association> assList;
    QLabel *member[15];
public slots:
    void accepta(){
        QMessageBox::information(this,"接受","已接受申请!",QMessageBox::Ok);
        accept->setEnabled(false);
        refuse->setEnabled(false);
        accept->setStyleSheet("background:rgb(180,180,180)");
        refuse->setStyleSheet("background:rgb(180,180,180)");
    }
    void refusea(){
        QMessageBox::information(this,"拒绝","已拒绝申请!",QMessageBox::Ok);
        accept->setEnabled(false);
        refuse->setEnabled(false);
        accept->setStyleSheet("background:rgb(180,180,180)");
        refuse->setStyleSheet("background:rgb(180,180,180)");
    }
};

#endif // STULABEL_H
