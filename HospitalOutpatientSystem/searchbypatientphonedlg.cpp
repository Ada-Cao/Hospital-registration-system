//***************************************************
// 文件名 ：        searchbypatientphonedlg.cpp
//版本 ：                   5.0
//目的及主要功能 ：根据输入就诊人电话查询预约情况对话框
//创建日期 ：            2024.08.26
//修改日期 ：            2024.09.11
//作者 ：                 Ada Cao
//联系方式 ：         2928588633@qq.com
//***************************************************



#include "searchbypatientphonedlg.h"
#include "ui_searchbypatientphonedlg.h"

SearchByPatientPhoneDlg::SearchByPatientPhoneDlg(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SearchByPatientPhoneDlg)
{
    ui->setupUi(this);


    //设置表格：使表格的每一列宽度相等，并占满表格宽度
    ui->tableWidget_PatientReception->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    //设置表格背景的颜色
    ui->tableWidget_PatientReception->setStyleSheet("QTableWidget{background-color:lightblue}");

    //设置表格表头背景颜色、字的颜色、字体样式
    ui->tableWidget_PatientReception->horizontalHeader()->setStyleSheet("QHeaderView::section{background-color:blue;color:white;font-weight:bold;}");

    //设置表格内容无法在外部被编辑
    ui->tableWidget_PatientReception->setEditTriggers(QAbstractItemView::NoEditTriggers);


    OutpatientInfotable Outinfo;    //实例化OutpatientInfotable
    Outinfo.SortOutpatients("FindOutpatient");      //将个人预约的门诊信息按时间顺序排序

    //计算存放的门诊个数
    QVector<CHospitalOutpatient>::size_type FindOutpatientNumber=Outinfo.ReadOutpatientFromFile("FindOutpatient").size();

    //将文件中保存的门诊信息逐个输出到表格中
    for(int i=0;i<FindOutpatientNumber;++i)
    {
        this->SetRowData(Outinfo.ReadOutpatientFromFile("FindOutpatient"),i);
    }


    QString strFilePath;    //创建QString类型的数据接收文件路径
    strFilePath=qApp->applicationDirPath()+"/temp个人预约查找.csv";  //获取文件的路径
    //qApp->applicationDirPath()获取到当前.exe执行程序所在的路径
    QFile FindPatientFile(strFilePath);   //创建QFile对象FindOutpatientFile，并将strFilePath作为构造函数的参数传入,初始化文件路径
    FindPatientFile.resize(0);          //清空文件中所有的信息
}




/***********************************************************
Name: SetRowData
Inputs: QVector<CHospitalOutpatient> Outpatients - 门诊信息
        int index - QVector容器中的索引下标
Return Value: none
Description: 将门诊信息显示在表格上
***********************************************************/
void SearchByPatientPhoneDlg::SetRowData(QVector<CHospitalOutpatient> Outpatients,int index)
{
    //创建一个用于存放门诊信息的QStringList类型的dalaList
    QStringList dataList;
    dataList.append(QString::number(Outpatients[index].GetOutpatientID()));         //向datalist中有序添加门诊号
    dataList.append(Outpatients[index].GetOutpatientName());                        //向datalist中有序添加门诊名
    dataList.append(QString::number(Outpatients[index].GetDoctorID()));             //向datalist中有序添加值班医生工号
    dataList.append(Outpatients[index].GetReceptionDate().toString("yyyy-MM-dd"));  //向datalist中有序添加接诊日期
    dataList.append(Outpatients[index].GetReceptionTime());                         //向datalist中有序添加接诊时间
    dataList.append(QString::number(Outpatients[index].GetCapacity()));             //向datalist中有序添加容量
    dataList.append(Outpatients[index].GetOutpatientAddress());                     //向datalist中有序添加门诊地址
    dataList.append(Outpatients[index].GetOutpatientPhone());                       //向datalist中有序添加门诊联系电话


    int nrow=ui->tableWidget_PatientReception->rowCount();   //获取tableWidgt当前行数，并储存在row中
    ui->tableWidget_PatientReception->insertRow(nrow);       //根据获取的行数row,在表格末尾插入一行

    //将datalist中每个元素插入新插入的一行中的对应列
    for(int ncolumn=0;ncolumn<dataList.size();++ncolumn)
    {
        //创建新的单元格项QTableWidgetItem并初始化
        QTableWidgetItem *pItem=new QTableWidgetItem(dataList[ncolumn]);
        //将创建的QTableWidgetItem对象插入到刚才插入的行的对应列中
        ui->tableWidget_PatientReception->setItem(nrow,ncolumn,pItem);
    }

}


SearchByPatientPhoneDlg::~SearchByPatientPhoneDlg()
{
    delete ui;
}
