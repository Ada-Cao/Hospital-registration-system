//***************************************************
//文件名 ：           appointmentdlg.h
//版本 ：                   5.0
//目的及主要功能 ：     添加预约信息对话框
//创建日期 ：            2024.08.26
//修改日期 ：            2024.09.11
//作者 ：                 Ada Cao
//联系方式 ：         2928588633@qq.com
//***************************************************



#ifndef APPOINTMENTDLG_H
#define APPOINTMENTDLG_H

#include <QDialog>
#include<QVector>
#include<QString>
#include<QStringList>
#include<QFile>

#include"chospitaloutpatient.h"
#include"outpatientinfotable.h"
#include"hospitalinfotable.h"
#include "appointinfotable.h"
#include "passworddlg.h"
#include"creception.h"




namespace Ui {
class AppointmentDlg;
}

class AppointmentDlg : public QDialog
{
    Q_OBJECT

public:

    //成员函数
    explicit AppointmentDlg(QWidget *parent = nullptr); //AppointmentDlg的构造函数
    ~AppointmentDlg();                                  //AppointmentDlg的析构函数

    QString ReturnSelectOutpatientName();   //返回用户选择的门诊名称
    QDate ReturnSelectReceptionDate();      //返回用户选择的就诊日期
    QString ReturnSelectReceptionTime();    //返回用户选择的就诊时间
    QString ReturnSelectPatientName();      //返回用户选择的就诊人

    int SelectOutpatientTrue();     //确定用户选择的门诊日期时间存在相应的门诊，并找到其在Vector容器中的编号
    int SelectPatient();            //返回用户选择的就诊人信息序号
    bool SelectOutpatientFull();    //预约失败原因之一：相应门诊容量已满
    void SetRowData(QVector<CHospitalOutpatient> Outpatients,int index);    //将门诊信息显示在列表上


    //成员属性
    QVector<CHospitalOutpatient> Outpatients;   //创建存放CHospitalOutpatient的Vector容器
    QVector<CReception> Receptions;             //创建存放CReception的Vector容器

private slots:
    void on_pushButton_ManageOutPatient_clicked();  //“管理门诊”的槽函数

private:
    Ui::AppointmentDlg *ui;
};

#endif // APPOINTMENTDLG_H
