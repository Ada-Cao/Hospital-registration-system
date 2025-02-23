//***************************************************
// 文件名 ：            creception.cpp
//版本 ：                   5.0
//目的及主要功能 ：     管理预约信息的类
//创建日期 ：            2024.08.26
//修改日期 ：            2024.09.11
//作者 ：                 Ada Cao
//联系方式 ：         2928588633@qq.com
//***************************************************



#include "creception.h"

CReception::CReception() {}




//获取预约类里受保护的成员属性
/************************************************
Name: GetPatientName
Inputs: none
Return Value: this->m_strPatientName - 就诊人姓名
Description: 获取就诊人姓名
************************************************/
QString CReception::GetPatientName()//获取就诊人姓名
{
    return this->m_strPatientName;  //返回就诊人姓名
}


/***************************************************
Name: GetPatientGender
Inputs: none
Return Value: this->m_strPatientGender - 就诊人性别
Description: 获取就诊人性别
***************************************************/
QString CReception::GetPatientGender()//获取就诊人性别
{
    return this->m_strPatientGender;     //返回就诊人性别
}


/********************************************
Name: GetPatientAge
Inputs: none
Return Value:this->m_nPatientAge - 就诊人年龄
Description: 获取就诊人年龄
********************************************/
int CReception::GetPatientAge()
{
    return this->m_nPatientAge; //返回就诊人年龄
}


/*****************************************************
Name: GetPatientPhone
Inputs: none
Return Value: this->m_strPatientPhone - 就诊人联系方式
Description: 获取就诊人联系方式
*****************************************************/
QString CReception::GetPatientPhone()
{
    return this->m_strPatientPhone; //返回就诊人联系方式
}


/*********************************************
Name: GetOutpatientID
Inputs: none
Return Value:   this->m_nOutpatientID - 门诊号
Description: 获取门诊号
*********************************************/
int CReception::GetOutpatientID()
{
    return this->m_nOutpatientID;   //返回门诊号
}


/**************************************************
Name: GetOutpatientName
Inputs: none
Return Value: this->m_strOutpatientName - 门诊名称
Description: 获取门诊名称
**************************************************/
QString CReception::GetOutpatientName()
{
    return this->m_strOutpatientName;    //返回门诊名
}


/*********************************************
Name: GetDoctorID
Inputs: none
Return Value: this->m_nDoctorID - 值班医生工号
Description: 获取值班医生工号
*********************************************/
int CReception::GetDoctorID()
{
    return this->m_nDoctorID;   //返回值班医生工号
}


/************************************************
Name: GetReceptionDate
Inputs: none
Return Value: this->m_dtReceptionDate - 就诊日期
Description: 获取就诊日期
************************************************/
QDate CReception::GetReceptionDate()
{
    return this->m_dtReceptionDate;  //返回就诊日期
}


/************************************************
Name: GetReceptionTime
Inputs: none
Return Value: this->m_strReceptionTime - 就诊时间
Description: 获取就诊时间
************************************************/
QString CReception::GetReceptionTime()
{
    return this->m_strReceptionTime;     //返回就诊时间
}


/**************************************
Name: GetCapacity
Inputs: none
Return Value: this->m_nCapacity - 容量
Description: 获取容量
**************************************/
int CReception::GetCapacity()
{
    return this->m_nCapacity;  //返回门诊容量
}


/****************************************************
Name: GetOutpatientAddress
Inputs: none
Return Value: this->m_strOutpatientAddress - 门诊地址
Description: 获取门诊地址
****************************************************/
QString CReception::GetOutpatientAddress()
{
    return this->m_strOutpatientAddress;    //返回门诊地址
}


/******************************************************
Name: GetOutpatientPhone
Inputs: none
Return Value: this->m_strOutpatientPhone - 门诊联系电话
Description: 获取门诊联系电话
******************************************************/
QString CReception::GetOutpatientPhone()
{
    return this->m_strOutpatientPhone;  //返回门诊联系电话
}





//设置预约类里里受保护的成员属性
/************************************
Name: SetPatientName
Inputs: QString strName - 就诊人姓名
Return Value: none
Description: 设置就诊人姓名
************************************/
void CReception::SetPatientName(QString Name)
{
    this->m_strPatientName=Name;    //将成员属性中的就诊人姓名赋值为输入的就诊人姓名
}


/*************************************
Name: SetPatientGender
Inputs: QString strGender - 就诊人性别
Return Value: none
Description: 设置就诊人性别
*************************************/
void CReception::SetPatientGender(QString Gender)
{
    this->m_strPatientGender=Gender;    //将成员属性中的就诊人性别赋值为输入的就诊人性别
}


/*****************************
Name: SetPatientAge
Inputs: int nAge - 就诊人年龄
Return Value: none
Description: 设置就诊人年龄
*****************************/
void CReception::SetPatientAge(int Age)
{
    this->m_nPatientAge=Age;    //将成员属性中的就诊人年龄赋值为输入的就诊人年龄
}


/***************************************
Name: SetPatientPhone
Inputs: QString strPhone - 就诊人联系方式
Return Value: none
Description: 设置就诊人联系方式
***************************************/
void CReception::SetPatientPhone(QString Phone)
{
    this->m_strPatientPhone=Phone;   //将成员属性中的就诊人联系方式赋值为输入的就诊人联系方式
}



/************************************
Name: SetOutpatientID
Inputs: int nOutpatientID - 门诊号
Return Value: none
Description: 设置门诊号
*************************************/
void CReception::SetOutpatientID(int OutpatientID)
{
    this->m_nOutpatientID=OutpatientID; //将成员属性中的门诊号赋值为输入的门诊号
}



/********************************************
Name: SetOutpatientName
Inputs: QString strOutpatientName - 门诊名称
Return Value: none
Description: 设置门诊名称
********************************************/
void CReception::SetOutpatientName(QString OutpatientName)
{
    this->m_strOutpatientName=OutpatientName;   //将成员属性中的门诊名称赋值为输入的门诊名称
}


/********************************************
Name: SetDoctorID
Inputs: int nDoctorID - 值班医生工号
Return Value: none
Description: 设置值班医生工号
********************************************/
void CReception::SetDoctorID(int DoctorID)
{
    this->m_nDoctorID=DoctorID; //将成员属性中的值班医生工号赋值为输入的值班医生工号
}


/*****************************************
Name: SetReceptionDate
Inputs: QDate dtReceptionDate - 接诊日期
Return Value: none
Description: 设置接诊日期
*****************************************/
void CReception::SetReceptionDate(QDate ReceptionDate)
{
    this->m_dtReceptionDate=ReceptionDate;   //将成员属性中的接诊日期赋值为输入的接诊日期
}


/********************************************
Name: SetReceptionTime
Inputs: QString strReceptionTime - 接诊时间
Return Value: none
Description: 设置接诊时间
********************************************/
void CReception::SetReceptionTime(QString ReceptionTime)
{
    this->m_strReceptionTime=ReceptionTime; //将成员属性中的接诊时间赋值为输入的接诊时间
}


/*******************************
Name: SetCapacity
Inputs: int nCapacity - 容量
Return Value: none
Description: 设置容量
********************************/
void CReception::SetCapacity(int Capacity)
{
    this->m_nCapacity=Capacity; //将成员属性中的容量赋值为输入的容量
}


/***********************************************
Name: SetOutpatientAddress
Inputs: QString strOutpatientAddress - 门诊地址
Return Value: none
Description: 设置门诊地址
***********************************************/
void CReception::SetOutpatientAddress(QString OutpatientAddress)
{
    this->m_strOutpatientAddress=OutpatientAddress;  //将成员属性中的门诊地址赋值为输入的门诊地址
}


/************************************************
Name: SetOutpatientPhone
Inputs: QString strOutpatientPhone - 门诊联系电话
Return Value: none
Description: 设置联门诊系电话
************************************************/
void CReception::SetOutpatientPhone(QString OutpatientPhone)
{
    this->m_strOutpatientPhone=OutpatientPhone; //将成员属性中的门诊联系电话赋值为输入的门诊联系电话
}
