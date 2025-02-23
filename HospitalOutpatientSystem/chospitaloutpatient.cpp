//***************************************************
//文件名 ：        chospitaloutpatient.cpp
//版本 ：                   5.0
//目的及主要功能 ：     管理门诊信息的类
//创建日期 ：            2024.08.26
//修改日期 ：            2024.09.11
//作者 ：                 Ada Cao
//联系方式 ：         2928588633@qq.com
//***************************************************



#include "chospitaloutpatient.h"

CHospitalOutpatient::CHospitalOutpatient() {}//构造函数



//获取门诊类里受保护的成员属性
/*********************************************
Name: GetOutpatientID
Inputs: none
Return Value:   this->m_nOutpatientID - 门诊号
Description: 获取门诊号
*********************************************/
int CHospitalOutpatient::GetOutpatientID()
{
    return this->m_nOutpatientID;   //返回门诊号
}


/**************************************************
Name: GetOutpatientName
Inputs: none
Return Value: this->m_strOutpatientName - 门诊名称
Description: 获取门诊名称
**************************************************/
QString CHospitalOutpatient::GetOutpatientName()
{
    return this->m_strOutpatientName;   //返回门诊名
}


/*********************************************
Name: GetDoctorID
Inputs: none
Return Value: this->m_nDoctorID - 值班医生工号
Description: 获取值班医生工号
*********************************************/
int CHospitalOutpatient::GetDoctorID()
{
    return this->m_nDoctorID;   //返回值班医生工号
}


/************************************************
Name: GetReceptionDate
Inputs: none
Return Value: this->m_dtReceptionDate - 接诊日期
Description: 获取接诊日期
************************************************/
QDate CHospitalOutpatient::GetReceptionDate()
{
    return this->m_dtReceptionDate; //返回就诊日期
}


/************************************************
Name: GetReceptionTime
Inputs: none
Return Value: this->m_strReceptionTime - 接诊时间
Description: 获取接诊时间
************************************************/
QString CHospitalOutpatient::GetReceptionTime()
{
    return this->m_strReceptionTime;    //返回接诊时间
}


/**************************************
Name: GetCapacity
Inputs: none
Return Value: this->m_nCapacity - 容量
Description: 获取容量
**************************************/
int CHospitalOutpatient::GetCapacity()
{
    return this->m_nCapacity;   //返回门诊容量
}


/****************************************************
Name: GetOutpatientAddress
Inputs: none
Return Value: this->m_strOutpatientAddress - 门诊地址
Description: 获取门诊地址
****************************************************/
QString CHospitalOutpatient::GetOutpatientAddress()
{
    return this->m_strOutpatientAddress;    //返回门诊地址
}


/******************************************************
Name: GetOutpatientPhone
Inputs: none
Return Value: this->m_strOutpatientPhone - 门诊联系电话
Description: 获取门诊联系电话
******************************************************/
QString CHospitalOutpatient::GetOutpatientPhone()
{
    return this->m_strOutpatientPhone;  //返回门诊联系电话
}




//设置门诊类里里受保护的成员属性
/************************************
Name: SetOutpatientID
Inputs: int nOutpatientID - 门诊号
Return Value: none
Description: 设置门诊号
*************************************/
void CHospitalOutpatient::SetOutpatientID(int nOutpatientID)
{
    this->m_nOutpatientID=nOutpatientID;    //将成员属性中的门诊号赋值为输入的门诊号
}


/********************************************
Name: SetOutpatientName
Inputs: QString strOutpatientName - 门诊名称
Return Value: none
Description: 设置门诊名称
********************************************/
void CHospitalOutpatient::SetOutpatientName(QString strOutpatientName)
{
    this->m_strOutpatientName=strOutpatientName;    //将成员属性中的门诊名称赋值为输入的门诊名称
}


/********************************************
Name: SetDoctorID
Inputs: int nDoctorID - 值班医生工号
Return Value: none
Description: 设置值班医生工号
********************************************/
void CHospitalOutpatient::SetDoctorID(int nDoctorID)
{
    this->m_nDoctorID=nDoctorID;     //将成员属性中的值班医生工号赋值为输入的值班医生工号
}


/*****************************************
Name: SetReceptionDate
Inputs: QDate dtReceptionDate - 接诊日期
Return Value: none
Description: 设置接诊日期
*****************************************/
void CHospitalOutpatient::SetReceptionDate(QDate dtReceptionDate)
{
    this->m_dtReceptionDate=dtReceptionDate;    //将成员属性中的接诊日期赋值为输入的接诊日期
}


/********************************************
Name: SetReceptionTime
Inputs: QString strReceptionTime - 接诊时间
Return Value: none
Description: 设置接诊时间
********************************************/
void CHospitalOutpatient::SetReceptionTime(QString strReceptionTime)
{
    this->m_strReceptionTime=strReceptionTime;  //将成员属性中的接诊时间赋值为输入的接诊时间
}


/*******************************
Name: SetCapacity
Inputs: int nCapacity - 容量
Return Value: none
Description: 设置容量
********************************/
void CHospitalOutpatient::SetCapacity(int nCapacity)
{
    this->m_nCapacity=nCapacity;    //将成员属性中的容量赋值为输入的容量
}


/***********************************************
Name: SetOutpatientAddress
Inputs: QString strOutpatientAddress - 门诊地址
Return Value: none
Description: 设置门诊地址
***********************************************/
void CHospitalOutpatient::SetOutpatientAddress(QString strOutpatientAddress)
{
    this->m_strOutpatientAddress=strOutpatientAddress;  //将成员属性中的门诊地址赋值为输入的门诊地址
}


/************************************************
Name: SetOutpatientPhone
Inputs: QString strOutpatientPhone - 门诊联系电话
Return Value: none
Description: 设置联门诊系电话
************************************************/
void CHospitalOutpatient::SetOutpatientPhone(QString strOutpatientPhone)
{
    this->m_strOutpatientPhone=strOutpatientPhone;  //将成员属性中的门诊联系电话赋值为输入的门诊联系电话
}

