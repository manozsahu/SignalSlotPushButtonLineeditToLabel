#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QHBoxLayout>
#include <QDebug>
#include <QLineEdit>
#include <QLabel>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    qDebug()<<__FILE__<<__LINE__<<__FUNCTION__<<endl;
    ui->setupUi(this);

//    qpb =new QPushButton("HitMe");
//    hl = new QHBoxLayout;
//    le = new QLineEdit();
//    label1 =new QLabel;
//    hl->addWidget(le);
//    hl->addWidget(qpb);
//    hl->addWidget(label1);

//    myWidget = new QWidget;
//    myWidget->setLayout(hl);
//    myWidget->show();

//    QObject::connect(qpb,SIGNAL(clicked()),this,SLOT(slotCalled()));

}

MainWindow::~MainWindow()
{
    delete ui;
    delete qpb;
    delete hl;
    delete label1;
}
void MainWindow::setUI()
{
    qpb =new QPushButton("HitMe");
    hl = new QHBoxLayout;
    le = new QLineEdit();
    label1 =new QLabel;
    label2 =new QLabel;
    hl->addWidget(le);
    hl->addWidget(qpb);
    hl->addWidget(label1);
    hl->addWidget(label1);

    myWidget = new QWidget;
    myWidget->setLayout(hl);
    myWidget->show();

    QObject::connect(qpb,SIGNAL(clicked()),this,SLOT(slotCalled()));
    //QObject::connect(qpb,SIGNAL(clicked()),this,SLOT(slotCalled2()));
   // QObject::connect(qpb,SIGNAL(mysignal()),this,SLOT(slotCalled()));
    QObject::connect(this,SIGNAL(mysignal()),this,SLOT(slotCalled2()));
    QObject::connect(this,SIGNAL(mysignal()),this,SLOT(slotCalled3()));//one signal connected with 2 slots gets called in order of connect
}

//void MainWindow::mysignal()
//{
//    qDebug()<<"Signal is called.\n\n\n";
//}
void MainWindow::slotCalled()
{
    qDebug()<<"slotCalled"<<endl;
    //QString data = le->text();
   // qDebug()<<"data"<<data<<endl;
    //label1->setText(data);
    //label1->setText(le->text());
    qDebug()<<"emmitting mysignal from slotCalled()..."<<endl;
    emit mysignal();

}
void MainWindow::slotCalled2()
{
    qDebug()<<"slotCalled2"<<endl;
//    QString data = le->text();
//    qDebug()<<"data"<<data<<endl;
//    label1->setText(data);
    label1->setText(le->text());

}
void MainWindow::slotCalled3()
{
    qDebug()<<"slotCalled3"<<endl;
}
