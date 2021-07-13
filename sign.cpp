#include "sign.h"
#include<QMessageBox>

Sign::Sign(QDialog *parent) : QDialog(parent){
    setWindowFlags (Qt::FramelessWindowHint);
    this->resize(340,260);
    //设置窗口标题
    this->setWindowTitle("社团管理系统登录");
    //用户名Label
    usernameLbl =new QLabel(this);
    usernameLbl->move(80,80);
    usernameLbl->setText("用户名:");
    //用户名输入框
    usernameLed =new QLineEdit(this);
    usernameLed->move(135,80);
    usernameLed->setPlaceholderText("用户名");
    //密码Label
    pwdLbl =new QLabel(this);
    pwdLbl->move(90,130);
    pwdLbl->setText("密码:");
    //密码输入框
    pwdLed =new QLineEdit(this);
    pwdLed->move(135,130);
    pwdLed->setPlaceholderText("密码");
    pwdLed->setEchoMode(QLineEdit::Password);
    //登录按钮
    loginBtn =new QPushButton(this);
    loginBtn->move(90,200);
    loginBtn->setText("登录");
    loginBtn->setObjectName("log");
    //退出按钮
    exitBtn=new QPushButton(this);
    exitBtn->move(180,200);
    exitBtn->setText("退出");
    exitBtn->setObjectName("exit");

    //定义样式表
    QFile qssfile(":/signstyle.qss");
    qssfile.open(QFile::ReadOnly);
    QString qss;
    qss =qssfile.readAll();
    this->setStyleSheet(qss);
    qssfile.close();
    connect(loginBtn,&QPushButton::clicked,this,&Sign::login);
    connect(exitBtn,&QPushButton::clicked,this,&Sign::close);
}

void Sign::login(){
    int flag=0;
    for(int i=0;i<stuList.size();i++){
        if(stuList[i].stuNumber==usernameLed->text().trimmed()){
            if(pwdLed->text()==stuList[i].stuPassword){
                flag++;
                user=&stuList[i];
                choose=2;
                for(int j=0;j<assList.size();j++){
                    if(assList[j].getAssoLeader()==stuList[i].stuName){
                        choose=1;
                    }
                }
                accept();
                return;
            }
        }
    }
    if(flag==0){
        QMessageBox::warning(this,"警告","用户名或密码错误",QMessageBox::Ok);
        usernameLed->clear();
        pwdLed->clear();
        usernameLed->setFocus();//光标定位
    }
}
