//***************************************************
//文件名 ：             cpatient.cpp
//版本 ：                   5.0
//目的及主要功能 ：     管理就诊人信息的类
//创建日期 ：            2024.08.26
//修改日期 ：            2024.09.11
//作者 ：                 Ada Cao
//联系方式 ：         2928588633@qq.com
//***************************************************



#include "cpatient.h"

CPatient::CPatient() {}



//获取就诊人类里受保护的成员属性
/************************************************
Name: GetPatientName
Inputs: none
Return Value: this->m_strPatientName - 就诊人姓名
Description: 获取就诊人姓名
************************************************/
QString CPatient::GetPatientName()
{
    return this->m_strPatientName;  //返回就诊人姓名
}


/***************************************************
Name: GetPatientGender
Inputs: none
Return Value: this->m_strPatientGender - 就诊人性别
Description: 获取就诊人性别
***************************************************/
QString CPatient::GetPatientGender()
{
    return this->m_strPatientGender;    //返回就诊人性别
}


/********************************************
Name: GetPatientAge
Inputs: none
Return Value:this->m_nPatientAge - 就诊人年龄
Description: 获取就诊人年龄
********************************************/
int CPatient::GetPatientAge()
{
    return this->m_nPatientAge; //返回就诊人年龄
}


/*****************************************************
Name: GetPatientPhone
Inputs: none
Return Value: this->m_strPatientPhone - 就诊人联系方式
Description: 获取就诊人联系方式
*****************************************************/
QString CPatient::GetPatientPhone()
{
    return this->m_strPatientPhone; //返回就诊人联系方式
}






//设置就诊人类里里受保护的成员属性
/************************************
Name: SetPatientName
Inputs: QString strName - 就诊人姓名
Return Value: none
Description: 设置就诊人姓名
************************************/
void CPatient::SetPatientName(QString strName)
{
    this->m_strPatientName=strName; //将成员属性中的就诊人姓名赋值为输入的就诊人姓名
}


/*************************************
Name: SetPatientGender
Inputs: QString strGender - 就诊人性别
Return Value: none
Description: 设置就诊人性别
*************************************/
void CPatient::SetPatientGender(QString strGender)
{
    this->m_strPatientGender=strGender; //将成员属性中的就诊人性别赋值为输入的就诊人性别
}


/*****************************
Name: SetPatientAge
Inputs: int nAge - 就诊人年龄
Return Value: none
Description: 设置就诊人年龄
*****************************/
void CPatient::SetPatientAge(int nAge)
{
    this->m_nPatientAge=nAge;   //将成员属性中的就诊人年龄赋值为输入的就诊人年龄
}


/***************************************
Name: SetPatientPhone
Inputs: QString strPhone - 就诊人联系方式
Return Value: none
Description: 设置就诊人联系方式
***************************************/
void CPatient::SetPatientPhone(QString strPhone)
{
    this->m_strPatientPhone=strPhone;   //将成员属性中的就诊人联系方式赋值为输入的就诊人联系方式
}
