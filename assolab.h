#ifndef ASSOLAB_H
#define ASSOLAB_H
#include<QLabel>
#include<QMainWindow>
#include<QPushButton>
#include<QFile>
#include<QVector>
#include<QMessageBox>
#include<QTextStream>
#include<QDebug>
class Assolab:public QLabel{
public:
    explicit Assolab(QWidget *parent = nullptr);
    QLabel *chengyuan;
    QLabel *assophoto;
    QPushButton *backbut;
    QPushButton *joinbut;
    QPixmap *assoPix;
    QLabel *assoname;
    QLabel *repername;
    QLabel *repernaum;
    QLabel *reperpsw;
    QLabel *pername[10];
    QVector<QString> studentname;
    QVector<QString> studentnum;
    QString user;
    int choose,flag;
public slots:
    void joinasso();
};
#endif // STULABEL_H
