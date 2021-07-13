#ifndef ASSO_H
#define ASSO_H

#include <QWidget>
#include<QString>
#include<QVector>
class Association{
public:
    Association(){}
    Association(QString a,QString b,QString c):assoName(a),assoLeader(b),assoAct(c),assoNumber(0){}
    //设定社团名字
    void setAssoName(QString a){
        assoName=a;
    }
    //设定社团负责人
    void setAssoLeader(QString a){
        assoLeader=a;
    }
    //设定社团活动
    void setAssoAct(QString a){
        assoAct=a;
    }
    //设定社团人员
    void addMemmber(QString a){
        member.push_back(a);
        assoNumber++;
    }
    void setPix(QPixmap q){
        assoPix=q;
    }
    //    获取社团名称
    QString getAssoName(){
        return assoName;
    }
    //    获取社团负责人
    QString getAssoLeader(){
        return assoLeader;
    }
    //    获取社团活动
    QString getAssoAct(){
        return assoAct;
    }
    //    获取社团人数
    int getAssoNumber(){
        return assoNumber;
    }
    //    社团人员列表
    QVector<QString>member;
    QVector<QString>newmember;
    QString assoName,assoLeader,assoAct;
    int assoNumber;
    QPixmap assoPix;
};
#endif // ASSO_H
