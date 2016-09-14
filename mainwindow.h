#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QLabel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    QLineEdit *le;
    Ui::MainWindow *ui;
    QPushButton *qpb ;
    QHBoxLayout *hl;
    QWidget *myWidget;
    QLabel *label1;
    QLabel *label2;
public slots:
    void slotCalled();
    void slotCalled2();
    void slotCalled3();
signals:
//    Q_SIGNALS:
    void mysignal();
public:
    void setUI();
};

#endif // MAINWINDOW_H
