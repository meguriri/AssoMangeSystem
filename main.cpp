#include "mainwindow.h"
#include"sign.h"
#include <QApplication>
#include<QVector>
#include<QFile>
#include"asso.h"
#include<QTextStream>
#include<QDebug>
#include<QTextCodec>
#include<QVector>
int main(int argc, char *argv[])
{
    //解决汉字乱码问题
    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForLocale(codec);
    //解决汉字乱码问题
    QApplication a(argc, argv);
    //
    QVector<Association>assList;
    QVector<Student>stuList;
    QFile file(":/image/1.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)){
            QString line="hahahah";
            //bool isTrue=true;
            int cnt=1;
            QTextStream in(&file);  //用文件构造流
            while(!line.isNull()){//字符串有内容
                line=in.readLine();//循环读取下行
                QString a=line;
                line=in.readLine();
                QString b=line;
                line=in.readLine();
                QString c=line;
                Association a1(a,b,c);
                QString s =":/image/"+QString::number(cnt)+".jpg";
                QPixmap q(s);
                a1.setPix(q);

                do{
                    line=in.readLine();
                    if(line=="")
                       break;
                    a1.member.push_back(line);
                }while(line!="");
                cnt++;
                assList.push_back(a1);
            }
    }
    file.close();
    QFile file2(":/image/2.txt");
    if (file2.open(QIODevice::ReadOnly | QIODevice::Text)){
            QString line="hahahah";
            int cnt=0;
            QTextStream in(&file2);  //用文件构造流
            while(!line.isNull()){//字符串有内容
                do{
                    line=in.readLine();
                    if(line=="")
                       break;
                    QString a=line;
                    line=in.readLine();
                    QString b=line;
                    line=in.readLine();
                    QString c=line;
                    Student s1(a,b,c);
                    QString s =":/stu/student/"+QString::number(cnt)+".jpg";
                    QPixmap q(s);
                    s1.setPix(q);
                    stuList.push_back(s1);
                    cnt++;
                }while(line!="");
            }
    }
    file2.close();
    MainWindow w;
    w.getasso(assList);
    w.getstu(stuList);
    Sign s;
    s.getstulist(stuList);
    s.getasslist(assList);
    if(s.exec()==QDialog::Accepted){
        w.getuser(s.user);
        w.choose=s.choose;
        w.stuLabel->choose=w.choose;
        w.stuLabel->user=w.user->stuName;
        w.setAsso();
        w.stuLabel->chooseway(w.stuLabel->choose);
        w.show();
        return a.exec();
    }
    else
        return 0;
}
