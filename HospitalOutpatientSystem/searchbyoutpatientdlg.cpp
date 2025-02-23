//***************************************************
//文件名 ：        searchbyoutpatientdlg.cpp
//版本 ：                   5.0
//目的及主要功能 ：根据输入门诊信息查询预约情况对话框
//创建日期 ：            2024.08.26
//修改日期 ：            2024.09.11
//作者 ：                 Ada Cao
//联系方式 ：         2928588633@qq.com
//***************************************************



#include "searchbyoutpatientdlg.h"
#include "ui_searchbyoutpatientdlg.h"

SearchByOutpatientDlg::SearchByOutpatientDlg(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SearchByOutpatientDlg)
{
    ui->setupUi(this);

    //设置表格：使表格的每一列宽度相等，并占满表格宽度
    ui->tableWidget_OutpatientReception->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    //设置表格背景的颜色
    ui->tableWidget_OutpatientReception->setStyleSheet("QTableWidget{background-color:lightblue}");

    //设置表格表头背景颜色、字的颜色、字体样式
    ui->tableWidget_OutpatientReception->horizontalHeader()->setStyleSheet("QHeaderView::section{background-color:blue;color:white;font-weight:bold;}");

    //设置表格内容无法在外部被编辑
    ui->tableWidget_OutpatientReception->setEditTriggers(QAbstractItemView::NoEditTriggers);

    HospitalInfoTable Hospinfo; //实例化HospitalInfoTable

    //计算存放的就诊人个数
    QVector<CPatient>::size_type FindPatientNumber=Hospinfo.ReadPatientFromFile("FindPatient").size();

    //将文件中保存的就诊人信息逐个输出到表格中
    for(int i=0;i<FindPatientNumber;++i)
    {
        this->SetRowData(Hospinfo.ReadPatientFromFile("FindPatient"),i);
    }



    QString strFilePath;   //创建QString类型的数据接收文件路径
    strFilePath=qApp->applicationDirPath()+"/temp预约信息查找.csv";  //获取文件的路径
    //qApp->applicationDirPath()获取到当前.exe执行程序所在的路径
    QFile FindPatientFile(strFilePath);   //创建QFile对象FindPatientFile，并将strFilePath作为构造函数的参数传入,初始化文件路径
    FindPatientFile.resize(0);          //清空文件中所有的信息

}





/**********************************************
Name: SetRowData
Inputs: QVector<CPatient> Patients - 就诊人信息
        int index - QVector容器中的索引下标
Return Value: none
Description: 将就诊人信息显示在表格上
***********************************************/
void SearchByOutpatientDlg::SetRowData(QVector<CPatient> Patients,int index)
{

    //创建一个用于存放门诊信息的QStringList类型的dalaList
    QStringList dataList;
    dataList.append(Patients[index].GetPatientName());                  //向datalist中有序添加就诊人姓名
    dataList.append(Patients[index].GetPatientGender());                //向datalist中有序添加就诊人性别
    dataList.append(QString::number(Patients[index].GetPatientAge()));  //向datalist中有序添加就诊人年龄
    dataList.append(Patients[index].GetPatientPhone());                 //向datalist中有序添加就诊人联系方式


    int nrow=ui->tableWidget_OutpatientReception->rowCount();    //获取tableWidgt当前行数，并储存在row中
    ui->tableWidget_OutpatientReception->insertRow(nrow);         //根据获取的行数row,在表格末尾插入一行

    //将datalist中每个元素插入新插入的一行中的对应列
    for(int ncolumn=0;ncolumn<dataList.size();++ncolumn)
    {
        //创建新的单元格项QTableWidgetItem并初始化
        QTableWidgetItem *pItem=new QTableWidgetItem(dataList[ncolumn]);
        //将创建的QTableWidgetItem对象插入到刚才插入的行的对应列中
        ui->tableWidget_OutpatientReception->setItem(nrow,ncolumn,pItem);
    }

}


SearchByOutpatientDlg::~SearchByOutpatientDlg()
{
    delete ui;
}
