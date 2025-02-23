//***************************************************
//文件名 ：         deletereceptiondlg.cpp
//版本 ：                   5.0
//目的及主要功能 ：     取消预约信息对话框
//创建日期 ：            2024.08.26
//修改日期 ：            2024.09.11
//作者 ：                 Ada Cao
//联系方式 ：         2928588633@qq.com
//***************************************************




#include "deletereceptiondlg.h"
#include "ui_deletereceptiondlg.h"

DeleteReceptionDlg::DeleteReceptionDlg(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DeleteReceptionDlg)
{
    ui->setupUi(this);

    HospitalInfoTable Hospinfo;     //实例化HospitalInfoTable
    OutpatientInfotable Outinfo;    //实例化OutpatientInfotable

    //用Vector容器存放文件中保存的就诊人信息
    QVector<CPatient> Patients=Hospinfo.ReadPatientFromFile("ManagePatient");
    //用Vector容器存放文件中保存的门诊信息
    QVector<CHospitalOutpatient> Outpatients=Outinfo.ReadOutpatientFromFile("ManageOutpatient");

    //计算文件中存放的门诊个数
    QVector<CHospitalOutpatient>::size_type OutpatientNumber=Outpatients.size();
    //计算文件中存放的就诊人个数
    QVector<CPatient>::size_type PatientNumber=Patients.size();


    QString FilePathPatient;   //创建存放文件路径的QString变量
    FilePathPatient=qApp->applicationDirPath()+"/就诊人名单.csv";    //获取文件的路径
    //qApp->applicationDirPath()获取到当前.exe执行程序所在的路径

    QString FilePathOutpatient;   //创建存放文件路径的QString变量
    FilePathOutpatient=qApp->applicationDirPath()+"/门诊信息.csv";    //获取文件的路径
    //qApp->applicationDirPath()获取到当前.exe执行程序所在的路径


    //如果文件存在且不为空，则读取文件中存放的数据并显示在列表中
    if(Hospinfo.isFileExist(FilePathPatient))
    {
        //读取文件中保存的就诊人姓名，并将就诊人姓名显示在combobox中，供用户选择
        for(int i=0;i<PatientNumber;++i)
        {
            ui->comboBox_PatientName->addItem(Patients[i].GetPatientName());
        }
    }


    //如果文件存在且不为空，则读取文件中存放的数据并显示在列表中
    if(Outinfo.isFileExist(FilePathOutpatient))
    {
        //读取文件中保存的门诊名，并将门诊名显示在combobox中，供用户选择
        for(int i=0;i<OutpatientNumber;++i)
        {
            ui->comboBox_OutpatientName->addItem(Outpatients[i].GetOutpatientName());
        }
    }

}



/******************************************************
Name：ReturnSelectOutpatientName
Inputs: none
Return Value: QString strOutpatientName - 删除的门诊名称
Description: 返回用户删除的门诊名称
*******************************************************/
QString DeleteReceptionDlg::ReturnSelectOutpatientName()
{
    QString strDeleteOutpatientName=ui->comboBox_OutpatientName->currentText(); //用QString类型保存删除的门诊名称
    return strDeleteOutpatientName; //返回QString类型的门诊名称
}


/********************************************************
Name: ReturnSelectReceptionDate
Inputs: none
Return Value: QDate dtDeleteReceptionDate - 删除的就诊日期
Description: 返回用户删除的就诊日期
********************************************************/
QDate DeleteReceptionDlg::ReturnSelectReceptionDate()
{
    QDate dtDeleteReceptionDate=ui->dateEdit_Date->date();
    return dtDeleteReceptionDate;
}


/************************************************************
Name: ReturnSelectReceptionTime
Inputs: none
Return Value: QString strDeleteReceptionTime - 删除的就诊时间
Description: 返回用户删除的就诊时间
************************************************************/
QString DeleteReceptionDlg::ReturnSelectReceptionTime()
{
    QString strDeleteReceptionTime=ui->comboBox_Time->currentText();
    return strDeleteReceptionTime;
}


/*******************************************************
Name: ReturnSelectPatientName
Inputs: none
Return Value: QString strDeletePatientName - 删除的就诊人
Description: 返回用户删除的就诊人
*******************************************************/
QString DeleteReceptionDlg::ReturnSelectPatientName()
{
    QString strDeletePatientName=ui->comboBox_PatientName->currentText();
    return strDeletePatientName;
}





/****************************************************************************
Name: SelectReceptionTrue
Inputs: none
Return Value: int index - 删除的就诊人
Description: //确定用户删除的门诊日期时间存在相应的预约，并找到其在Vector容器中的编号
****************************************************************************/
int DeleteReceptionDlg::SelectReceptionTrue()
{
    ReceptionInfoTable Recepinfo;   //实例化ReceptionInfoTable
    //计算文件中存放的预约个数
    QVector<CReception>::size_type ReceptionNumber=Recepinfo.ReadReceptionFromFile().size();
    int index=0;    //创建int类型变量index，用于记录预约在Vector容器中的编号


    //将文件中保存的预约与选择的预约逐个验证是否相同
    for(int i=0;i<ReceptionNumber;++i)
    {
        //创建预约类变量，接收文件中的第i个预约信息
        CReception ReceptionClass=Recepinfo.ReadReceptionFromFile().at(i);

        //如果就诊人姓名相同
        if(this->ReturnSelectPatientName()==ReceptionClass.GetPatientName())
        {
            //如果门诊名相同
            if(this->ReturnSelectOutpatientName()==ReceptionClass.GetOutpatientName())
            {
                //如果接诊日期相同
                if(this->ReturnSelectReceptionDate()==ReceptionClass.GetReceptionDate())
                {
                    //如果接诊时间相同
                    if(this->ReturnSelectReceptionTime()==ReceptionClass.GetReceptionTime())
                    {
                        index=i;        //将选择的预约序号赋值为i
                        return index;   //返回预约序号index
                    }
                }
            }
        }

    }

    //所有预约信息验证完后，若无相应预约信息存在，则返回-1
    return -1;
}




DeleteReceptionDlg::~DeleteReceptionDlg()
{
    delete ui;
}
