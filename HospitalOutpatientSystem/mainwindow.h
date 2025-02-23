//***************************************************
// 文件名 ：            mainwindow.h
//版本 ：                   5.0
//目的及主要功能 ：        主对话框
//创建日期 ：            2024.08.26
//修改日期 ：            2024.09.11
//作者 ：                 Ada Cao
//联系方式 ：         2928588633@qq.com
//***************************************************



#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QPainter>
#include<QPixmap>

#include"addpatientdlg.h"
#include"hospitalinfotable.h"
#include "appointmentdlg.h"
#include "appointinfotable.h"
#include"successaddappointmentdlg.h"
#include "failfindoutpatientdlg.h"
#include "failoutpatientfulldlg.h"
#include "creception.h"
#include "receptioninfotable.h"
#include"inquirereceptiondlg.h"
#include"logwidget.h"



QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);  //MainWindow的构造函数
    ~MainWindow();                          //MainWindow的析构函数

protected:
    void paintEvent(QPaintEvent *event) override;   //重载paintEvent函数

private slots:
    void on_pushButton_PatientInfo_clicked();   //“就诊人信息”的槽函数

    void on_pushButton_Appointment_clicked();   //“开始预约”的槽函数

    void on_pushButton_Reception_clicked();     //“查询预约”的槽函数

private:
    Ui::MainWindow *ui;
    QPixmap bgImage;    //用于储存背景图片
    LogWidget *m_log;   //登录界面类的对象作为指针
};
#endif // MAINWINDOW_H
