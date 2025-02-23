//***************************************************
//文件名 ：        outpatientinfotable.h
//版本 ：                   5.0
//目的及主要功能 ：     负责门诊信息存读的类
//创建日期 ：            2024.08.26
//修改日期 ：            2024.09.11
//作者 ：                 Ada Cao
//联系方式 ：         2928588633@qq.com
//***************************************************



#ifndef OUTPATIENTINFOTABLE_H
#define OUTPATIENTINFOTABLE_H

#include<QApplication>
#include<QVector>
#include<QString>
#include<QStringList>
#include<QFile>

#include"chospitaloutpatient.h"

//存读门诊信息
class OutpatientInfotable
{

//成员函数
public:
    OutpatientInfotable();      //OutpatientInfotable的构造函数

    void SaveOutpatientToFile(CHospitalOutpatient Outpatient,QString FileUse);  //将门诊信息保存在文件中
    QVector<CHospitalOutpatient> ReadOutpatientFromFile(QString FileUse);       //将门诊信息从文件中读出
    bool isFileExist(const QString &filepath);                                  //判断文件是否存在或文件中是否有内容

    void MinusCapacity(int index);  //就诊人预约成功后，减少预约的门诊容量
    void PlusCapacity(int index);   //就诊人取消预约后，增加预约的门诊容量
    void SortOutpatients(QString FileUse);    //将门诊按时间排序

};

#endif // OUTPATIENTINFOTABLE_H
