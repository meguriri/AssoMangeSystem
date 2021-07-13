#ifndef SIGN_H
#define SIGN_H

#include <QWidget>
#include <QDialog>
#include<QLabel>
#include<QLineEdit>
#include<QPushButton>
#include<QFile>
#include"student.h"
#include"asso.h"
#include<QVector>
#include<QDebug>
class Sign : public QDialog
{
    Q_OBJECT
public:
    explicit Sign(QDialog *parent = nullptr);
    void getstulist(QVector<Student>a){
        for(int i=0;i<a.size();i++){
            stuList.push_back(a[i]);
        }
    }
    void getasslist(QVector<Association>a){
        for(int i=0;i<a.size();i++){
            assList.push_back(a[i]);
        }
    }
        Student *user;
        int choose;
signals:
public slots:
    void login();
private:
    QLabel *usernameLbl;
    QLabel *pwdLbl;
    QLineEdit *usernameLed;
    QLineEdit *pwdLed;
    QPushButton *loginBtn;
    QPushButton *exitBtn;
    QVector<Association>assList;
    QVector<Student>stuList;
};

#endif // SIGN_H
