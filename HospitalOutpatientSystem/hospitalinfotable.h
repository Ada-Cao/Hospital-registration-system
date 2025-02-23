//***************************************************
//文件名 ：         hospitalinfotable.h
//版本 ：                   5.0
//目的及主要功能 ：   负责就诊人信息存读的类
//创建日期 ：            2024.08.26
//修改日期 ：            2024.09.11
//作者 ：                 Ada Cao
//联系方式 ：         2928588633@qq.com
//***************************************************



#ifndef HOSPITALINFOTABLE_H
#define HOSPITALINFOTABLE_H

#include<QVector>
#include<QString>
#include<QStringList>
#include<QFile>

#include"cpatient.h"

//存读就诊人信息
class HospitalInfoTable
{

//成员函数
public:
    HospitalInfoTable();        //HospitalInfoTable的构造函数

    void SavePatientToFile(CPatient patient,QString FileUse);   //将病人信息保存在文件中
    QVector<CPatient> ReadPatientFromFile(QString FileUse);     //将病人信息从文件中读出
    bool isFileExist(const QString &filepath);                  //判断文件是否存在或文件是否为空
};

#endif // HOSPITALINFOTABLE_H
