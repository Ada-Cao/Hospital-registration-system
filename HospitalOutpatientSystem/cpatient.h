//***************************************************
//文件名 ：             cpatient.h
//版本 ：                   5.0
//目的及主要功能 ：     管理就诊人信息的类
//创建日期 ：            2024.08.26
//修改日期 ：            2024.09.11
//作者 ：                 Ada Cao
//联系方式 ：         2928588633@qq.com
//***************************************************



#ifndef CPATIENT_H
#define CPATIENT_H

#include<QString>
#include <QApplication>

class CPatient
{

//成员函数
public:
    CPatient();//CPatient的构造函数

    QString GetPatientName();       //获取受保护的就诊人姓名
    QString GetPatientGender();     //获取受保护的就诊人性别
    int GetPatientAge();            //获取受保护的就诊人年龄
    QString GetPatientPhone();      //获取受保护的就诊人联系方式

    void SetPatientName(QString Name);      //设置受保护的就诊人姓名
    void SetPatientGender(QString Gender);  //设置受保护的就诊人性别
    void SetPatientAge(int Age);            //设置受保护的就诊人年龄
    void SetPatientPhone(QString Phone);    //设置受保护的就诊人联系方式


//成员属性（受保护）
protected:
    QString m_strPatientName;       //就诊人姓名     QString
    QString m_strPatientGender;     //就诊人性别     QString
    int m_nPatientAge;              //就诊人年龄     int
    QString m_strPatientPhone;      //就诊人联系方式  QString

};

#endif // CPATIENT_H
