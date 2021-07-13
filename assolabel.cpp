#include "assolabel.h"
#include<QPixmap>
#include<QDebug>
AssoLabel::AssoLabel(QWidget *parent):QLabel(parent){
    pixLbl=new QLabel(this);
    //assolab =new Assolab(this);
    pixLbl->setGeometry(0,0,300,200);
    //pixLbl->setStyleSheet("background:#00FF00");
    assoName =new QLabel(this);
    assoName->setGeometry(30,215,150,50);
    //assoName->setStyleSheet("background:#00FF00");
    assoBtn =new QPushButton(this);
    assoBtn->setGeometry(205,225,80,35);
    assoBtn->setText("更多内容");
    assoBtn->setStyleSheet(
                "background-color:#3bee41;"
                "font-size:17px;"
                "color:white;"
                "border-radius: 6px;"
                );
}
void AssoLabel::getmsg(){
    assolab->assophoto->setPixmap(asso->assoPix);
    assolab->assoname->setText("社团名称："+asso->getAssoName());
    assolab->repername->setText("社团负责人："+asso->getAssoLeader());
    assolab->reperpsw->setText("社团活动："+asso->getAssoAct());
    assolab->user=this->user;
    int x=120;
    int y=400;
    assolab->flag=0;
    for(int i=0;i<asso->member.size();i++){
        assolab->studentname.push_back(asso->member[i]);
        if(assolab->studentname[i]==user)
            assolab->flag=1;
        assolab->pername[i]=new QLabel(assolab);
        assolab->pername[i]->move(x,y);
        assolab->pername[i]->setText("成员："+assolab->studentname[i]);
        x=x+300;
    }
    if(choose==1){
        assolab->joinbut->setText("无法加入");
        assolab->joinbut->setEnabled(false);
        assolab->joinbut->setStyleSheet("background:#F44336");
    }
    else if(assolab->flag==1){
        assolab->joinbut->setText("已加入");
        assolab->joinbut->setEnabled(false);
        assolab->joinbut->setStyleSheet("background:#F44336");
    }
    assolab->show();
}
void AssoLabel::closelab(){
    assolab->close();
}
