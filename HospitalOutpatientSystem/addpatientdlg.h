//***************************************************
// 文件名 ：            addpatientdlg.h
//版本 ：                   5.0
//目的及主要功能 :     添加就诊人信息对话框
//创建日期 ：            2024.08.26
//修改日期 ：            2024.09.11
//作者 ：                 Ada Cao
//联系方式 ：         2928588633@qq.com
//***************************************************



#ifndef ADDPATIENTDLG_H
#define ADDPATIENTDLG_H

#include <QDialog>
#include<QString>
#include<QVector>
#include<QStringList>
#include<QFile>


#include"cpatient.h"
#include"hospitalinfotable.h"
#include "deletepatientdlg.h"
#include "successdeletepatientdlg.h"


namespace Ui {
class AddpatientDlg;
}

class AddpatientDlg : public QDialog
{
    Q_OBJECT

public:

    //成员函数
    explicit AddpatientDlg(QWidget *parent = nullptr);  //AddpatientDlg的构造函数
    ~AddpatientDlg();                                   //AddpatientDlg的析构函数

    QString ReturnPatientName();        //返回用户输入的就诊人姓名
    QString ReturnPatientGender();      //返回用户输入的就诊人性别
    int ReturnPatientAge();             //返回用户输入的就诊人年龄
    QString ReturnPatientPhone();       //返回用户输入的就诊人联系方式
    CPatient ReturnPatients();          //返回存放输入的就诊人信息的类

    void SetRowData(QVector<CPatient> Patients,int index);  //将病人信息显示在列表上
    void SaveTableToFile(); //将表格中的数据写入文件
    void ModifyReception();  //将修改的就诊人信息同步至预约信息

    //成员属性
    QVector<CPatient> Patients;         //创建存放CPatient的Vector容器

private slots:
    void on_pushButton_DeletePatient_clicked();

private:
    Ui::AddpatientDlg *ui;
};

#endif // ADDPATIENTDLG_H

