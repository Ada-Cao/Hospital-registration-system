//***************************************************
//文件名 ：         receptioninfotable.h
//版本 ：                   5.0
//目的及主要功能 ：    负责预约信息存读的类
//创建日期 ：            2024.08.26
//修改日期 ：            2024.09.11
//作者 ：                 Ada Cao
//联系方式 ：         2928588633@qq.com
//***************************************************



#ifndef RECEPTIONINFOTABLE_H
#define RECEPTIONINFOTABLE_H

#include<QApplication>
#include<QVector>
#include<QString>
#include<QStringList>
#include<QFile>

#include"creception.h"
#include"cpatient.h"



class ReceptionInfoTable
{

//成员函数
public:
    ReceptionInfoTable();   //ReceptionInfoTable的构造函数

    void SaveReceptionToFile(CReception Reception); //将预约信息保存在文件中
    QVector<CReception> ReadReceptionFromFile();    //将预约信息从文件中读出
    bool isFileExist(const QString &filepath);      //判断文件是否为空

};

#endif // RECEPTIONINFOTABLE_H
