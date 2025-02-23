//***************************************************
//文件名 ：          appointinfotable.h
//版本 ：                   5.0
//目的及主要功能 : 负责就诊人和门诊信息存读的类
//创建日期 ：            2024.08.26
//修改日期 ：            2024.09.11
//作者 ：                 Ada Cao
//联系方式 ：         2928588633@qq.com
//***************************************************




#ifndef APPOINTINFOTABLE_H
#define APPOINTINFOTABLE_H


#include<QVector>
#include<QString>
#include<QStringList>
#include<QFile>

#include"cpatient.h"
#include"chospitaloutpatient.h"


class AppointInfoTable
{
public:
    AppointInfoTable();     //AppointInfoTable的构造函数

    //成员属性
    QVector<CPatient> ReadPatientFromFile();                //将病人信息从文件中读出
    QVector<CHospitalOutpatient> ReadOutpatientFromFile();  //将门诊信息从文件中读出


};

#endif // APPOINTINFOTABLE_H
