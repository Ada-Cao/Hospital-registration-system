//***************************************************
//文件名 ：        chospitaloutpatient.h
//版本 ：                   5.0
//目的及主要功能 ：     管理门诊信息的类
//创建日期 ：            2024.08.26
//修改日期 ：            2024.09.11
//作者 ：                 Ada Cao
//联系方式 ：         2928588633@qq.com
//***************************************************



#ifndef CHOSPITALOUTPATIENT_H
#define CHOSPITALOUTPATIENT_H

#include<QString>
#include<QDate>


class CHospitalOutpatient
{

//成员函数
public:
    CHospitalOutpatient();//CHospitalOutpatient的构造函数

    int GetOutpatientID();          //获取受保护的门诊号
    QString GetOutpatientName();    //获取受保护的门诊名称
    int GetDoctorID();              //获取受保护的班医生工号
    QDate GetReceptionDate();       //获取受保护的接诊日期
    QString GetReceptionTime();     //获取受保护的接诊时间
    int GetCapacity();              //获取受保护的容量
    QString GetOutpatientAddress(); //获取受保护的门诊地址
    QString GetOutpatientPhone();   //获取受保护的门诊联系电话

    void SetOutpatientID(int OutpatientID);                 //设置受保护的门诊号
    void SetOutpatientName(QString OutpatientName);         //设置受保护的门诊名称
    void SetDoctorID(int DoctorID);                         //设置受保护的值班医生工号
    void SetReceptionDate(QDate ReceptionDate);             //设置受保护的接诊日期
    void SetReceptionTime(QString ReceptionTime);           //设置受保护的接诊时间
    void SetCapacity(int Capacity);                         //设置受保护的容量
    void SetOutpatientAddress(QString OutpatientAddress);   //设置受保护的门诊地址
    void SetOutpatientPhone(QString OutpatientPhone);       //设置受保护的门诊联系电话


//成员属性（受保护）
protected:
    int m_nOutpatientID;            //门诊号       int
    QString m_strOutpatientName;    //门诊名称     QString
    int m_nDoctorID;                //值班医生工号  int
    QDate m_dtReceptionDate;        //接诊日期     QDate
    QString m_strReceptionTime;     //接诊时间     QString
    int m_nCapacity;                //容量        int
    QString m_strOutpatientAddress; //门诊地址     QString
    QString m_strOutpatientPhone;   //门诊联系电话  QString

};

#endif // CHOSPITALOUTPATIENT_H
