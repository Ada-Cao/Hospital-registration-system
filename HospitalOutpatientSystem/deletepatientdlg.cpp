//***************************************************
// 文件名 ：          deletepatientdlg.cpp
//版本 ：                   5.0
//目的及主要功能 ：    删除就诊人信息对话框
//创建日期 ：            2024.08.26
//修改日期 ：            2024.09.11
//作者 ：                 Ada Cao
//联系方式 ：         2928588633@qq.com
//***************************************************



#include "deletepatientdlg.h"
#include "ui_deletepatientdlg.h"

DeletePatientDlg::DeletePatientDlg(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DeletePatientDlg)
{
    ui->setupUi(this);

    HospitalInfoTable Hospinfo; //实例化HospitalInfoTable
    //计算文件中存放的就诊人个数
    QVector<CPatient>::size_type PatientNumber=Hospinfo.ReadPatientFromFile("ManagePatient").size();


    QString strFilePath;   //创建存放文件路径的QString变量
    strFilePath=qApp->applicationDirPath()+"/就诊人名单.csv";    //获取文件的路径
    //qApp->applicationDirPath()获取到当前.exe执行程序所在的路径


    //如果文件存在且不为空，则读取文件中存放的数据并显示在列表中
    if(Hospinfo.isFileExist(strFilePath))
    {
        //读取文件中保存的就诊人姓名，并将就诊人姓名显示在combobox中，供用户选择
        for(int i=0;i<PatientNumber;++i)
        {
            ui->comboBox_PatientName->addItem(Hospinfo.ReadPatientFromFile("ManagePatient")[i].GetPatientName());
        }
    }

}



/*******************************************
Name: ReturnDeleteIndex
Inputs: none
Return Value: int nPatientIndex - 就诊人编号
Description: 返回选择删除的就诊人编号
*******************************************/
int DeletePatientDlg::ReturnDeleteIndex()
{
    int nPatientIndex=ui->comboBox_PatientName->currentIndex(); //用int类型保存选择的就诊人编号
    return nPatientIndex;   //返回int类型的就诊人编号
}





/************************************
Name: DeleteItsReception
Inputs: none
Return Value: none
Description: 删除就诊人的同时删除其预约
************************************/
void DeletePatientDlg::DeleteItsReception()
{
    ReceptionInfoTable RecepInfo;   //实例化ReceptionInfoTable
    OutpatientInfotable OutInfo;    //实例化OutpatientInfotable

    //如果删除了该就诊人，则其预约信息一并消失
    QVector<CReception> Receptions=RecepInfo.ReadReceptionFromFile();   //创建Vector容器读取文件中保存的预约信息
    QVector<CReception>::size_type ReceptionNumber=Receptions.size();   //计算Vector容器中预约的个数

    QString strPatientName=ui->comboBox_PatientName->currentText();     //用QString类型变量保存删除的就诊人姓名

    QVector<int> DeleteReceptionIndexes;    //创建存放删除预约序号的Vector容器

    int ncorrect=0; //初始化校正变量为0


    //逐个检查预约信息中是否有 删除的就诊人 的预约信息
    for(int i=0;i<ReceptionNumber;++i)
    {
        //若预约信息中的就诊人姓名等于删除的就诊人姓名
        if(Receptions[i].GetPatientName()==strPatientName)
        {
            DeleteReceptionIndexes.append(i-ncorrect);  //将删除的预约序号记录在Vector容器中
            ncorrect++; //校正变量+1


            //创建QVector容器存放文件中读出的门诊类，并计算门诊的个数
            QVector<CHospitalOutpatient> Outpatients=OutInfo.ReadOutpatientFromFile("ManageOutpatient");
            QVector<CHospitalOutpatient>::size_type OutpatientNumber=Outpatients.size();

            //将该就诊人曾预约过的门诊容量+1
            for(int j=0;j<OutpatientNumber;++j)
            {
                //获取删除的预约所预约的门诊在门诊信息中的序号
                if(Receptions[i].GetOutpatientName()==Outpatients[j].GetOutpatientName())
                {
                    int nDeleteOutpatientIndex=j;   //记录门诊序号
                    OutInfo.PlusCapacity(nDeleteOutpatientIndex);   //该门诊容量+1
                    break;  //退出循环
                }

            }
        }

    }

    //计算一共有多少个需要删除的预约信息
    QVector<int>::size_type DeleteReceptionNumber=DeleteReceptionIndexes.size();
    //逐个删除预约信息
    for(int i=0;i<DeleteReceptionNumber;++i)
    {
        Receptions.erase(Receptions.begin()+DeleteReceptionIndexes[i]);
    }


    //再将新预约信息写入文件中前，先把文件中的旧数据清空
    QString strFilePath;   //创建QString类型的数据接收文件路径
    strFilePath=qApp->applicationDirPath()+"/预约信息.csv";  //获取文件的路径
    //qApp->applicationDirPath()获取到当前.exe执行程序所在的路径
    QString FILE_PATH(strFilePath);            //定义QString类型的变量FILE_PATH，并将其初始化为FilePath
    QFile ReceptionFile(FILE_PATH);    //创建QFile对象ReceptionFile，并将FILE_PATH作为构造函数的参数传入,初始化文件路径
    ReceptionFile.resize(0);           //清空文件中所有的信息

    //清空旧数据后，把新的预约信息逐个写入
    for(int i=0;i<ReceptionNumber-ncorrect;++i)
    {
        RecepInfo.SaveReceptionToFile(Receptions.at(i));
    }

}



DeletePatientDlg::~DeletePatientDlg()
{
    delete ui;
}
