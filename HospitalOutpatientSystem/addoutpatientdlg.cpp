//***************************************************
//文件名 ：          addoutpatientdlg.cpp
//版本 ：                   5.0
//目的及主要功能 ：     添加门诊信息对话框
//创建日期 ：            2024.08.26
//修改日期 ：            2024.09.11
//作者 ：                 Ada Cao
//联系方式 ：         2928588633@qq.com
//***************************************************



#include "addoutpatientdlg.h"
#include "ui_addoutpatientdlg.h"

AddOutpatientDlg::AddOutpatientDlg(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddOutpatientDlg)
{
    ui->setupUi(this);

    //设置表格：使表格的每一列宽度相等，并占满表格宽度
    ui->tableWidget_Outpatient->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);



    //设置表格：调整“门诊号”“接诊时间”“容量”“门诊地址”的宽度，使内容可以完全展现
    //将tableWidget_Outpatient中的第一列设置为固定宽度，用户无法通过拖动表头来改变这一列的宽度
    ui->tableWidget_Outpatient->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Fixed);
    ui->tableWidget_Outpatient->setColumnWidth(0, 50);  //调整“门诊号”列宽度

    ui->tableWidget_Outpatient->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Fixed);
    ui->tableWidget_Outpatient->setColumnWidth(2, 100);  //调整“值班医生工号”列宽度

    ui->tableWidget_Outpatient->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Fixed);
    ui->tableWidget_Outpatient->setColumnWidth(3, 100);  //调整“接诊日期”列宽度

    ui->tableWidget_Outpatient->horizontalHeader()->setSectionResizeMode(4, QHeaderView::Fixed);
    ui->tableWidget_Outpatient->setColumnWidth(4, 60);  //调整“接诊时间”列宽度

    ui->tableWidget_Outpatient->horizontalHeader()->setSectionResizeMode(5, QHeaderView::Fixed);
    ui->tableWidget_Outpatient->setColumnWidth(5, 50);  //调整“容量”列宽度

    ui->tableWidget_Outpatient->horizontalHeader()->setSectionResizeMode(6, QHeaderView::Fixed);
    ui->tableWidget_Outpatient->setColumnWidth(6, 200);  //调整“门诊地址”列宽度



    //设置表格背景的颜色
    ui->tableWidget_Outpatient->setStyleSheet("QTableWidget{background-color:lightblue}");

    //设置表格表头背景颜色、字的颜色、字体样式
    ui->tableWidget_Outpatient->horizontalHeader()->setStyleSheet("QHeaderView::section{background-color:blue;color:white;font-weight:bold;}");


    HospitalInfoTable Hospinfo; //实例化HospitalInfoTable
    OutpatientInfotable Outinfo;    //实例化OutpatientInfoTable

    QString strFilePath;   //创建存放文件路径的QString变量
    strFilePath=qApp->applicationDirPath()+"/门诊信息.csv";    //获取文件的路径
    //qApp->applicationDirPath()获取到当前.exe执行程序所在的路径


    //如果文件存在且不为空，则读取文件中存放的数据并显示在列表中
    if(Hospinfo.isFileExist(strFilePath))
    {
        //计算文件中存放的门诊个数
        QVector<CHospitalOutpatient>::size_type OutpatientNumber=Outinfo.ReadOutpatientFromFile("ManageOutpatient").size();

        //将文件中保存的门诊逐个输出到表格中
        for(int i=0;i<OutpatientNumber;++i)
        {
            this->SetRowData(Outinfo.ReadOutpatientFromFile("ManageOutpatient"),i);
        }
    }
}




/****************************************
Name: ReturnOutpatientID
Inputs: none
Return Value: int nOutpatientID - 门诊号
Description:返回输入的门诊号
****************************************/
int AddOutpatientDlg::ReturnOutpatientID()
{
    QString strOutpatientID=ui->textEdit_OutpatientID->toPlainText();   //用QString类型保存输入的门诊号
    int nOutpatientID=strOutpatientID.toInt();  //将门诊号由QString类型转为int类型
    return nOutpatientID;   //返回int类型的门诊号
}


/*************************************************
Name: ReturnOutpatientName
Inputs: none
Return Value: QString strOutpatientName - 门诊名称
Description: 返回输入的门诊名称
*************************************************/
QString AddOutpatientDlg::ReturnOutpatientName()
{
    QString strOutpatientName=ui->textEdit_OutpatientName->toPlainText();   //用QString类型保存输入的门诊名称
    return  strOutpatientName;  //返回QString类型的门诊名称
}


/*****************************************
Name: ReturnDoctorID
Inputs: none
Return Value: int nDoctorID - 值班医生工号
Description: 返回输入的值班医生工号
*****************************************/
int AddOutpatientDlg::ReturnDoctorID()
{
    QString strDoctorID=ui->textEdit_DoctorID->toPlainText();   //用QString类型保存输入的值班医生工号
    int nDoctorID=strDoctorID.toInt();  //将值班医生工号由QString类型转为int类型
    return nDoctorID;   //返回int类型的值班医生工号
}


/*********************************************
Name: ReturnReceptionDate
Inputs: none
Return Value: QDate dtReceptionDate - 接诊日期
Description: 返回输入的接诊日期
*********************************************/
QDate AddOutpatientDlg::ReturnReceptionDate()
{
    QDate dtReceptionDate=ui->dateEdit_ReceptionDate->date();   //用QDate类型保存输入的接诊日期
    return dtReceptionDate; //返回QDate类型的接诊日期
}


/************************************************
Name: ReturnReceptionTime
Inputs: none
Return Value: QString strReceptionTime - 接诊时间
Description: 返回输入的接诊时间
************************************************/
QString AddOutpatientDlg::ReturnReceptionTime()
{
    QString strReceptionTime=ui->comboBox_Receptiontime->currentText(); //用QString类型保存输入的接诊时间
    return strReceptionTime;  //返回QString类型的接诊时间
}


/**************************************
Name: ReturnCapacity
Inputs: none
Return Value: int nCapacity - 门诊容量
Description: 返回输入的容量
**************************************/
int AddOutpatientDlg::ReturnCapacity()
{
    QString strCapacity=ui->spinBox_Capacity->text();   //用QString类型保存输入的容量
    int nCapacity=strCapacity.toInt();  //将容量由QString类型转为int类型
    return nCapacity;   //返回int类型的门诊容量
}


/****************************************************
Name: ReturnOutpatientAddress
Inputs: none
Return Value: QString strOutpatientAddress - 门诊地址
Description: 返回输入的门诊地址
****************************************************/
QString AddOutpatientDlg::ReturnOutpatientAddress()
{
    QString strOutpatientAddress=ui->comboBox_OutpatientAddress->currentText(); //用QString类型保存输入的门诊地址
    return strOutpatientAddress;    //返回QString类型的门诊地址
}


/******************************************************
Name: ReturnOutpatientPhone
Inputs: none
Return Value: QString strOutpatientPhone - 门诊联系电话
Description: 返回输入的门诊联系电话
******************************************************/
QString AddOutpatientDlg::ReturnOutpatientPhone()
{
    QString strOutpatientPhone=ui->textEdit_OutpatientPhone->toPlainText(); //用QString类型保存输入的门诊联系方式
    return strOutpatientPhone;  //返回QString类型的门诊联系电话
}




/***********************************************************
Name: SetRowData
Inputs: QVector<CHospitalOutpatient> Outpatients - 门诊信息
        int index - QVector容器中的索引下标
Return Value: none
Description: 将门诊信息显示在表格上
***********************************************************/
void AddOutpatientDlg::SetRowData(QVector<CHospitalOutpatient> Outpatients,int index)
{

    //创建一个用于存放门诊信息的QStringList类型的dalaList
    QStringList dataList;
    dataList.append(QString::number(Outpatients[index].GetOutpatientID()));         //向datalist中有序添加门诊号
    dataList.append(Outpatients[index].GetOutpatientName());                        //向datalist中有序添加门诊名称
    dataList.append(QString::number(Outpatients[index].GetDoctorID()));             //向datalist中有序添加值班医生工号
    dataList.append(Outpatients[index].GetReceptionDate().toString("yyyy-MM-dd"));  //向datalist中有序添加接诊日期
    dataList.append(Outpatients[index].GetReceptionTime());                         //向datalist中有序添加接诊时间
    dataList.append(QString::number(Outpatients[index].GetCapacity()));             //向datalist中有序添加门诊容量
    dataList.append(Outpatients[index].GetOutpatientAddress());                     //向datalist中有序添加门诊地址
    dataList.append(Outpatients[index].GetOutpatientPhone());                       //向datalist中有序添加门诊联系电话


    int nrow=ui->tableWidget_Outpatient->rowCount(); //获取tableWidgt当前行数，并储存在row中
    ui->tableWidget_Outpatient->insertRow(nrow);     //根据获取的行数row,在表格末尾插入一行

    //将datalist中每个元素插入新插入的一行中的对应列
    for(int ncolumn=0;ncolumn<dataList.size();++ncolumn)
    {
        QTableWidgetItem *pItem=new QTableWidgetItem(dataList[ncolumn]); //创建新的单元格项QTableWidgetItem并初始化
        ui->tableWidget_Outpatient->setItem(nrow,ncolumn,pItem);          //将创建的QTableWidgetItem对象插入到刚才插入的行的对应列中
    }

}




/********************************
Name: SaveTableToFile
Inputs: none
Return Value: none
Description: 将表格中的数据写入文件
********************************/
void AddOutpatientDlg::SaveTableToFile()
{
    QString strFilePath;   //创建QString类型的数据接收文件路径
    strFilePath=qApp->applicationDirPath()+"/门诊信息.csv";//获取文件的路径
    //qApp->applicationDirPath()获取到当前.exe执行程序所在的路径
    QString FILE_PATH(strFilePath);    //定义QString类型的变量FILE_PATH，并将其初始化为FilePath
    QFile OutpatientFile(FILE_PATH);   //创建QFile对象OutpatientFile，并将FILE_PATH作为构造函数的参数传入,初始化文件路径

    int nrow=ui->tableWidget_Outpatient->rowCount();    //用int类型变量nrow储存表格的行数

    QVector<CHospitalOutpatient> Outpatients; //创建一个储存门诊类的Vector容器
    Outpatients.resize(nrow);      //将该Vector容器的大小设置为行数，即已添加门诊个数

    //逐行将现在表格中的信息存放Vector容器中
    for(int i=0;i<nrow;++i)
    {
        Outpatients[i].SetOutpatientID(ui->tableWidget_Outpatient->item(i,0)->text().toInt());  //保存第i行第1个单元格中的内容
        Outpatients[i].SetOutpatientName(ui->tableWidget_Outpatient->item(i,1)->text());        //保存第i行第2个单元格中的内容
        Outpatients[i].SetDoctorID(ui->tableWidget_Outpatient->item(i,2)->text().toInt());      //保存第i行第3个单元格中的内容
        Outpatients[i].SetReceptionDate(QDate::fromString(ui->tableWidget_Outpatient->item(i,3)->text(),"yyyy-MM-dd")); //保存第i行第4个单元格中的内容
        Outpatients[i].SetReceptionTime(ui->tableWidget_Outpatient->item(i,4)->text());         //保存第i行第5个单元格中的内容
        Outpatients[i].SetCapacity(ui->tableWidget_Outpatient->item(i,5)->text().toInt());      //保存第i行第6个单元格中的内容
        Outpatients[i].SetOutpatientAddress(ui->tableWidget_Outpatient->item(i,6)->text());     //保存第i行第7个单元格中的内容
        Outpatients[i].SetOutpatientPhone(ui->tableWidget_Outpatient->item(i,7)->text());       //保存第i行第8个单元格中的内容

    }

    OutpatientInfotable Outinfo; //实例化OutpatientInfotable
    OutpatientFile.resize(0);      //将原本文件中的数据清除，便于后续新数据的写入，以免重复

    //逐个将Vector容器中的数据保存至文件中
    for(int i=0;i<nrow;++i)
    {
        Outinfo.SaveOutpatientToFile(Outpatients.at(i),"ManageOutpatient");
    }

}





/****************************************
Name: ModifyReception
Inputs: none
Return Value: none
Description: 将修改的门诊信息同步至预约信息
****************************************/
void AddOutpatientDlg::ModifyReception()
{
    int nrow=ui->tableWidget_Outpatient->rowCount();    //用int类型变量nrow储存表格的行数

    QVector<CHospitalOutpatient> NewOutpatients; //创建一个储存新门诊类的Vector容器
    NewOutpatients.resize(nrow);      //将该Vector容器的大小设置为行数，即已添加门诊个数

    //逐行将现在表格中的信息存放Vector容器中
    for(int i=0;i<nrow;++i)
    {
        NewOutpatients[i].SetOutpatientID(ui->tableWidget_Outpatient->item(i,0)->text().toInt());   //保存第i行第1个单元格中的内容
        NewOutpatients[i].SetOutpatientName(ui->tableWidget_Outpatient->item(i,1)->text());         //保存第i行第2个单元格中的内容
        NewOutpatients[i].SetDoctorID(ui->tableWidget_Outpatient->item(i,2)->text().toInt());       //保存第i行第3个单元格中的内容
        NewOutpatients[i].SetReceptionDate(QDate::fromString(ui->tableWidget_Outpatient->item(i,3)->text(),"yyyy-MM-dd"));  //保存第i行第4个单元格中的内容
        NewOutpatients[i].SetReceptionTime(ui->tableWidget_Outpatient->item(i,4)->text());          //保存第i行第5个单元格中的内容
        NewOutpatients[i].SetCapacity(ui->tableWidget_Outpatient->item(i,5)->text().toInt());       //保存第i行第6个单元格中的内容
        NewOutpatients[i].SetOutpatientAddress(ui->tableWidget_Outpatient->item(i,6)->text());      //保存第i行第7个单元格中的内容
        NewOutpatients[i].SetOutpatientPhone(ui->tableWidget_Outpatient->item(i,7)->text());        //保存第i行第8个单元格中的内容
    }

    OutpatientInfotable Outinfo;     //实例化OutpatientInfotable
    //读取文件中储存的旧的门诊信息
    QVector<CHospitalOutpatient> OldOutpatients=Outinfo.ReadOutpatientFromFile("ManageOutpatient");

    QVector<int> OutpatientIndexes;    //创建储存序号的Vector容器

    //逐个对新旧门诊信息进行比较，并保存修改的行数
    for(int i=0;i<nrow;++i)
    {
        if(NewOutpatients[i].GetOutpatientID()!=OldOutpatients[i].GetOutpatientID()||
            NewOutpatients[i].GetOutpatientName().compare(OldOutpatients[i].GetOutpatientName())!=0||
            NewOutpatients[i].GetDoctorID()!=OldOutpatients[i].GetDoctorID()||
            NewOutpatients[i].GetReceptionDate().toString().compare(OldOutpatients[i].GetReceptionDate().toString())!=0||
            NewOutpatients[i].GetReceptionTime().compare(OldOutpatients[i].GetReceptionTime())!=0||
            NewOutpatients[i].GetCapacity()!=OldOutpatients[i].GetCapacity()||
            NewOutpatients[i].GetOutpatientAddress().compare(OldOutpatients[i].GetOutpatientAddress())!=0||
            NewOutpatients[i].GetOutpatientPhone().compare(OldOutpatients[i].GetOutpatientPhone())!=0)

        {
            OutpatientIndexes.append(i);
        }
    }

    ReceptionInfoTable RecepInfo;   //实例化ReceptionInfoTable
    //将文件中的预约信息读到Vector容器中
    QVector<CReception> Receptions=RecepInfo.ReadReceptionFromFile();
    //计算预约信息的个数
    QVector<CReception>::size_type ReceptionNumber=Receptions.size();
    QVector<int>::size_type ModifyNumber=OutpatientIndexes.size();


    //如果并未进行修改，则直接返回
    if(OutpatientIndexes.isEmpty())
    {
        return;
    }

    for(int i=0;i<ReceptionNumber;++i)
    {
        for(int j=0;j<ModifyNumber;++j)
        {
            if(Receptions[i].GetOutpatientName()==OldOutpatients[OutpatientIndexes[j]].GetOutpatientName())
            {
                Receptions[i].SetOutpatientID(NewOutpatients[OutpatientIndexes[j]].GetOutpatientID());
                Receptions[i].SetOutpatientName(NewOutpatients[OutpatientIndexes[j]].GetOutpatientName());
                Receptions[i].SetDoctorID(NewOutpatients[OutpatientIndexes[j]].GetDoctorID());
                Receptions[i].SetReceptionDate(NewOutpatients[OutpatientIndexes[j]].GetReceptionDate());
                Receptions[i].SetReceptionTime(NewOutpatients[OutpatientIndexes[j]].GetReceptionTime());
                Receptions[i].SetCapacity(NewOutpatients[OutpatientIndexes[j]].GetCapacity());
                Receptions[i].SetOutpatientAddress(NewOutpatients[OutpatientIndexes[j]].GetOutpatientAddress());
                Receptions[i].SetOutpatientPhone(NewOutpatients[OutpatientIndexes[j]].GetOutpatientPhone());

                break;
            }
        }
    }


    QString strFilePath;   //创建QString类型的数据接收文件路径
    strFilePath=qApp->applicationDirPath()+"/预约信息.csv";//获取文件的路径
    //qApp->applicationDirPath()获取到当前.exe执行程序所在的路径
    QString FILE_PATH(strFilePath);    //定义QString类型的变量FILE_PATH，并将其初始化为FilePath
    QFile ReceptionFile(FILE_PATH);   //创建QFile对象ReceptionFile，并将FILE_PATH作为构造函数的参数传入,初始化文件路径

    ReceptionFile.resize(0);    //将原本文件中的数据清除，便于后续新数据的写入，以免重复
    //将新的预约信息依次保存到文件中
    for(int i=0;i<ReceptionNumber;++i)
    {
        RecepInfo.SaveReceptionToFile(Receptions.at(i));
    }

}



/********************************************
Name: on_pushButton_DeleteOutpatient_clicked
Inputs: none
Return Value: none
Description: “删除门诊”的槽函数
********************************************/
void AddOutpatientDlg::on_pushButton_DeleteOutpatient_clicked()
{
    DeleteOutpatientDlg OutpatientDelete(this); //实例化DeleteOutpatientDlg
    int ret=OutpatientDelete.exec();    //以模态方式显示对话框

    OutpatientInfotable Outinfo;    //实例化OutpatientInfotable

    if(ret==QDialog::Accepted)  //OK按钮被按下
    {
        //用nDeleteIndex接收需要删除的门诊序号
        int nDeleteIndex=OutpatientDelete.ReturnDeleteIndex();

        //从文件中读出保存的门诊信息，并用Vector容器存放
        QVector<CHospitalOutpatient> Outpatients=Outinfo.ReadOutpatientFromFile("ManageOutpatient");
        //删除Outpatients中第nDeleteIndex个门诊信息，后续信息向前移，并调整Vector容器的大小
        Outpatients.erase(Outpatients.begin()+nDeleteIndex);
        //计算删除后门诊的个数
        QVector<CHospitalOutpatient>::size_type NewOutpatientNumber=Outpatients.size();

        QString strFilePath;   //创建QString类型的数据接收文件路径
        strFilePath=qApp->applicationDirPath()+"/门诊信息.csv";   //获取文件的路径
        //qApp->applicationDirPath()获取到当前.exe执行程序所在的路径
        QString FILE_PATH(strFilePath);    //定义QString类型的变量FILE_PATH，并将其初始化为FilePath
        QFile OutpatientFile(FILE_PATH);   //创建QFile对象OutpatientFile，并将FILE_PATH作为构造函数的参数传入,初始化文件路径

        OutpatientFile.resize(0);          //清空OutpatientFile中原先的就诊人数据

        //将存放门诊信息的Vector容器中的元素逐一写入文件
        for(int i=0;i<NewOutpatientNumber;++i)
        {
            Outinfo.SaveOutpatientToFile(Outpatients.at(i),"ManageOutpatient");
        }

        OutpatientDelete.DeleteItsReception();  //删除门诊的同时，删除他的预约

        SuccessDeleteOutpatientDlg SuccessDelete(this); //实例化SuccessDeleteOutpatientDlg
        SuccessDelete.exec();   //以模态方式显示对话框
        this->close();  //成功删除门诊后关闭界面

    }
}



AddOutpatientDlg::~AddOutpatientDlg()
{
    delete ui;
}
