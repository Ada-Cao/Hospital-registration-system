//***************************************************
//文件名 ：          addoutpatientdlg.h
//版本 ：                   5.0
//目的及主要功能 ：     添加门诊信息对话框
//创建日期 ：            2024.08.26
//修改日期 ：            2024.09.11
//作者 ：                 Ada Cao
//联系方式 ：         2928588633@qq.com
//***************************************************



#ifndef ADDOUTPATIENTDLG_H
#define ADDOUTPATIENTDLG_H

#include <QDialog>
#include<QString>
#include<QVector>
#include<QStringList>
#include<QFile>

#include "chospitaloutpatient.h"
#include"outpatientinfotable.h"
#include"hospitalinfotable.h"
#include "deleteoutpatientdlg.h"
#include "successdeleteoutpatientdlg.h"


namespace Ui {
class AddOutpatientDlg;
}

class AddOutpatientDlg : public QDialog
{
    Q_OBJECT

public:

    //成员函数
    explicit AddOutpatientDlg(QWidget *parent = nullptr);   //AddOutpatientQlg的构造函数
    ~AddOutpatientDlg();                                    //AddOutpatientQlg的析构函数

    int ReturnOutpatientID();           //返回管理者输入的门诊号
    QString ReturnOutpatientName();     //返回管理者输入的门诊名称
    int ReturnDoctorID();               //返回管理者输入的值班医生工号
    QDate ReturnReceptionDate();        //返回管理者输入的接诊日期
    QString ReturnReceptionTime();      //返回管理者输入的接诊时间
    int ReturnCapacity();               //返回管理者输入的容量
    QString ReturnOutpatientAddress();  //返回管理者输入的门诊地址
    QString ReturnOutpatientPhone();    //返回管理者输入的联系电话

    void SetRowData(QVector<CHospitalOutpatient> Outpatients,int index);    //将门诊信息显示在列表上
    void SaveTableToFile();     //将表格中的数据写入文件
    void ModifyReception();     //将修改的门诊信息同步至预约信息


    //成员属性
    QVector<CHospitalOutpatient> Outpatients;   //创建存放CHospitalOutpatient的Vector容器


private slots:
    void on_pushButton_DeleteOutpatient_clicked();

private:
    Ui::AddOutpatientDlg *ui;
};

#endif // ADDOUTPATIENTDLG_H
