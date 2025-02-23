//***************************************************
// 文件名 ：            creception.h
//版本 ：                   5.0
//目的及主要功能 ：     管理预约信息的类
//创建日期 ：            2024.08.26
//修改日期 ：            2024.09.11
//作者 ：                 Ada Cao
//联系方式 ：         2928588633@qq.com
//***************************************************



#ifndef CRECEPTION_H
#define CRECEPTION_H

#include<QString>
#include<QVector>
#include<QDate>


class CReception
{

//成员函数
public:
    CReception();//CReception的构造函数

    QString GetPatientName();       //获取就诊人姓名
    QString GetPatientGender();     //获取就诊人性别
    int GetPatientAge();            //获取就诊人年龄
    QString GetPatientPhone();      //获取就诊人联系方式
//******************************************************//
    int GetOutpatientID();          //获取门诊号
    QString GetOutpatientName();    //获取门诊名称
    int GetDoctorID();              //获取值班医生工号
    QDate GetReceptionDate();       //获取接诊日期
    QString GetReceptionTime();     //获取接诊时间
    int GetCapacity();              //获取容量
    QString GetOutpatientAddress(); //获取门诊地址
    QString GetOutpatientPhone();   //获取门诊联系电话


    void SetPatientName(QString Name);      //设置就诊人姓名
    void SetPatientGender(QString Gender);  //设置就诊人性别
    void SetPatientAge(int Age);            //设置就诊人年龄
    void SetPatientPhone(QString Phone);    //设置就诊人联系方式
//*******************************************************************//
    void SetOutpatientID(int OutpatientID);//设置门诊号
    void SetOutpatientName(QString OutpatientName);//设置门诊名称
    void SetDoctorID(int DoctorID);//设置值班医生工号
    void SetReceptionDate(QDate ReceptionDate);//设置接诊日期
    void SetReceptionTime(QString ReceptionTime);//设置接诊时间
    void SetCapacity(int Capacity);//设置容量
    void SetOutpatientAddress(QString OutpatientAddress);//设置门诊地址
    void SetOutpatientPhone(QString OutpatientPhone);//设置门诊联系电话


//成员属性（受保护的）
protected:
    QString m_strPatientName;   //就诊人姓名     QString
    QString m_strPatientGender; //就诊人性别     QString
    int m_nPatientAge;          //就诊人年龄     int
    QString m_strPatientPhone;  //就诊人联系方式  QString
//***************************************************//
    int m_nOutpatientID;            //门诊号        int
    QString m_strOutpatientName;    //门诊名称      QString
    int m_nDoctorID;                //值班医生工号   int
    QDate m_dtReceptionDate;        //接诊日期      QDate
    QString m_strReceptionTime;     //接诊时间      QString
    int m_nCapacity;                //容量          int
    QString m_strOutpatientAddress; //门诊地址      QString
    QString m_strOutpatientPhone;   //门诊联系电话   QString

};

#endif // CRECEPTION_H
