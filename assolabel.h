#ifndef ASSOLABEL_H
#define ASSOLABEL_H

#include <QWidget>
#include<QLabel>
#include<QPushButton>
#include<QDebug>
#include"asso.h"
#include"assolab.h"
class AssoLabel:public QLabel{
public:
    explicit AssoLabel(QWidget *parent = nullptr);
    QLabel *pixLbl;
    QLabel *assoName;
    QPushButton *assoBtn;
    Association *asso;
    Assolab *assolab;
    QString user;
    int choose;
public slots:
    void getmsg();
    void closelab();
    void getnew(){
        asso->newmember.push_back(user);
        qDebug()<<user;
    }
};


#endif // ASSOLABEL_H
