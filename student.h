#ifndef STUDENT_H
#define STUDENT_H

#include<QString>
#include<QVector>
#include<QPixmap>
#include"asso.h"
class Student
{
public:
    Student(){}
        Student(QString a,QString b,QString d):stuName(a),stuPassword(b),stuNumber(d),assoNumber(0){}
        QString stuName,stuPassword,stuNumber;
        int assoNumber;
        void addAsso(QString asso){
            assoList.push_back(asso);
            assoNumber++;
        }
        void setPix(QPixmap q){
            stuPix=q;
        }
        void getAsso(){
            QVector<QString>::iterator it=assoList.begin();
            for(;it!=assoList.end();it++){
                //cout<<*it<<" ";
            }
        }
        QPixmap stuPix;
        QVector<QString> assoList;
};

#endif // STUDENT_H
