//***************************************************
//文件名 ：            passworddlg.cpp
//版本 ：                   5.0
//目的及主要功能 ：      输入密码对话框
//创建日期 ：            2024.08.26
//修改日期 ：            2024.09.11
//作者 ：                 Ada Cao
//联系方式 ：         2928588633@qq.com
//***************************************************




#include "passworddlg.h"
#include "ui_passworddlg.h"

PassWordDlg::PassWordDlg(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::PassWordDlg)
{
    ui->setupUi(this);

    ui->lineEdit_Password->setEchoMode(QLineEdit::Password);   //输入密码的时候显示圆点
}



/************************************************
Name: ReturnPassword
Inputs: none
Return Value: QString strPassword - 管理员密码
Description:返回输入的管理员密码
*************************************************/
QString PassWordDlg::ReturnPassword()
{
    QString strPassword=ui->lineEdit_Password->text();
    return strPassword;
}



/*********************************************
Name: GetPassword
Inputs: none
Return Value: QString strPassword - 管理员密码
Description:获取正确的管理员密码
**********************************************/
QString PassWordDlg::GetPassword()
{
    return m_strPassword;
}



/*********************************
Name: on_pushButton_enter_clicked
Inputs: none
Return Value: none
Description: “Enter”的槽函数
*********************************/
void PassWordDlg::on_pushButton_enter_clicked()
{
    //如果用户输入的密码和设置的密码一致
    if(this->ReturnPassword()==this->GetPassword())
    {
        this->close();  //点击“Enter”按钮后，关闭“密码输入”对话框

        AddOutpatientDlg OutpatientAdd(this);   //实例化AddOutpatientDlg
        int ret =OutpatientAdd.exec();  //以模态方式显示对话框

        if(ret==QDialog::Accepted)  //OK按钮被按下
        {
            OutpatientAdd.ModifyReception();   //在预约信息中同步修改门诊信息
            OutpatientAdd.SaveTableToFile();   //将现在表格中的信息保存到文件中，用于修改门诊

            //如果用户没有在textedit中输入内容，则不要新添加门诊信息
            if(OutpatientAdd.ReturnOutpatientName().isEmpty()||OutpatientAdd.ReturnOutpatientPhone().isEmpty())
            {
                OutpatientInfotable Outinfo;    //实例化OutpatientInfotable
                Outinfo.SortOutpatients("ManageOutpatient");      //将门诊信息按时间先后排序
                return;
            }

            //如果用户在textedit中输入内容，则新添加门诊信息
            //创建门诊类，用于临时保存门诊信息
            CHospitalOutpatient tempOutpatient;
            tempOutpatient.SetOutpatientID(OutpatientAdd.ReturnOutpatientID());             //将输入的门诊号保存至临时门诊类中
            tempOutpatient.SetOutpatientName(OutpatientAdd.ReturnOutpatientName());         //将输入的门诊名保存至临时门诊类中
            tempOutpatient.SetDoctorID(OutpatientAdd.ReturnDoctorID());                     //将输入的保存值班医生工号至临时门诊类中
            tempOutpatient.SetReceptionDate(OutpatientAdd.ReturnReceptionDate());           //将输入的保存接诊日期至临时门诊类中
            tempOutpatient.SetReceptionTime(OutpatientAdd.ReturnReceptionTime());           //将输入的保存接诊时间至临时门诊类中
            tempOutpatient.SetCapacity(OutpatientAdd.ReturnCapacity());                     //将输入的保存容量至临时门诊类中
            tempOutpatient.SetOutpatientAddress(OutpatientAdd.ReturnOutpatientAddress());   //将输入的保存门诊地址至临时门诊类中
            tempOutpatient.SetOutpatientPhone(OutpatientAdd.ReturnOutpatientPhone());       //将输入的保存门诊联系电话至临时门诊类中

            //将临时门诊信息保存到Vector容器中
            OutpatientAdd.Outpatients.append(tempOutpatient);
            //将保存的门诊信息显示在表格中
            OutpatientAdd.SetRowData(OutpatientAdd.Outpatients,0);

            OutpatientInfotable Outinfo;    //实例化OutpatientInfotable
            //将临时门诊类中的门诊信息保存到文件中
            Outinfo.SaveOutpatientToFile(tempOutpatient,"ManageOutpatient");

            //将门诊信息按时间先后排序
            Outinfo.SortOutpatients("ManageOutpatient");

        }

    }
    else//如果用户输入的密码和设置的密码不一致
    {
        //显示对话框，提示密码输入错误
        WarningDlg Warning(this);   //实例化WarningDlg
        Warning.exec(); //以模态方式显示对话框
    }

}

PassWordDlg::~PassWordDlg()
{
    delete ui;
}



