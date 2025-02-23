//***************************************************
// 文件名 ：            addpatientdlg.cpp
//版本 ：                   5.0
//目的及主要功能 :     添加就诊人信息对话框
//创建日期 ：            2024.08.26
//修改日期 ：            2024.09.11
//作者 ：                 Ada Cao
//联系方式 ：         2928588633@qq.com
//***************************************************



#include "addpatientdlg.h"
#include "ui_addpatientdlg.h"



AddpatientDlg::AddpatientDlg(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddpatientDlg)
{
    ui->setupUi(this);

    //初始化就诊人信息的表格表头信息
    QStringList headerList;
    headerList<<QStringLiteral("姓名")
               <<QStringLiteral("性别")
               <<QStringLiteral("年龄")
               <<QStringLiteral("联系方式");

    //将tableWidget和headerlist关联起来
    ui->tableWidgetPatient->setColumnCount(headerList.size());
    ui->tableWidgetPatient->setHorizontalHeaderLabels(headerList);


    //设置表格：使表格的每一列宽度相等，并占满表格宽度
    ui->tableWidgetPatient->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    //设置表格背景的颜色
    ui->tableWidgetPatient->setStyleSheet("QTableWidget{background-color:lightblue}");

    //设置表格表头背景颜色、字的颜色、字体样式
    ui->tableWidgetPatient->horizontalHeader()->setStyleSheet("QHeaderView::section{background-color:blue;color:white;font-weight:bold;}");


    //设置单选按钮，默认性别为男
    ui->radioButton_Male->setChecked(true);


    QString strFilePath;   //创建QString类型的数据接收文件路径
    strFilePath=qApp->applicationDirPath()+"/就诊人名单.csv";//获取文件的路径
    //qApp->applicationDirPath()获取到当前.exe执行程序所在的路径

    HospitalInfoTable Hospinfo; //实例化HospitalInfoTable


    //如果文件存在且不为空，则读取文件中存放的数据并显示在列表中
    if(Hospinfo.isFileExist(strFilePath))
    {
        QVector<CPatient>::size_type PatientNumber=Hospinfo.ReadPatientFromFile("ManagePatient").size();    //计算存放的就诊人的个数

        //将文件中保存的就诊人信息逐个输出到表格中
        for(int i=0;i<PatientNumber;++i)
        {
            this->SetRowData(Hospinfo.ReadPatientFromFile("ManagePatient"),i);
        }
    }
}


/************************************************
Name: ReturnPatientName
Inputs: none
Return Value: QString strPatientName - 就诊人姓名
Description: 返回输入的就诊人姓名
************************************************/
QString AddpatientDlg::ReturnPatientName()
{
    QString strPatientName=ui->textEdit_Name->toPlainText();    //用QString类型保存输入的就诊人姓名
    return strPatientName;  //返回QString类型的就诊人姓名
}


/*******************************************
Name: ReturnPatientGender
Inputs: none
Return Value: QString strGender - 就诊人性别
Description: 返回输入的就诊人性别
******************************************/
QString AddpatientDlg::ReturnPatientGender()
{
    bool bSelectGenderMale=ui->radioButton_Male->isChecked();   //用bool类型表示“男”选项是否被选

    //如果bSelectGenderMale为true，则返回“男”
    if(bSelectGenderMale)
    {
        return "男";
    }

    //如果bSelectGenderMale不为true，则返回“女”
    return  "女";
}


/**********************************
Name: ReturnPatientAge
Inputs: none
Return Value: int nAge - 就诊人年龄
Description: 返回输入的就诊人年龄
**********************************/
int AddpatientDlg::ReturnPatientAge()
{
    QString strAge=ui->textEdit_Age->toPlainText(); //用QString类型保存输入的就诊人年龄
    int nAge=strAge.toInt();    //将就诊人年龄由QString类型转为int类型
    return nAge;    //返回int类型的就诊人年龄
}


/***************************************************
Name: ReturnPatientPhone
Inputs: none
Return Value: QString strPatientName - 就诊人联系方式
Description: 返回输入的就诊人联系方式
***************************************************/
QString AddpatientDlg::ReturnPatientPhone()
{
    QString strPatientPhone=ui->textEdit_Phone->toPlainText();  //用QString类型保存输入的就诊联系方式
    return strPatientPhone; //返回QString类型的就诊人联系方式
}



/***********************************************************
Name: SetRowData
Inputs: QVector<CPatient> Patients - 就诊人信息
        int index - QVector容器中的索引下标
Return Value: none
Description: 将就诊人信息显示在表格上
***********************************************************/
void AddpatientDlg::SetRowData(QVector<CPatient> Patients,int index)
{
    //创建一个用于存放门诊信息的QStringList类型的dalaList
    QStringList dataList;
    dataList.append(Patients[index].GetPatientName());                  //向datalist中有序添加就诊人姓名
    dataList.append(Patients[index].GetPatientGender());                //向datalist中有序添加就诊人性别
    dataList.append(QString::number(Patients[index].GetPatientAge()));  //向datalist中有序添加就诊人年龄
    dataList.append(Patients[index].GetPatientPhone());                 //向datalist中有序添加就诊人联系方式


    int nrow=ui->tableWidgetPatient->rowCount(); //获取tableWidgt当前行数，并储存在row中
    ui->tableWidgetPatient->insertRow(nrow);     //根据获取的行数row,在表格末尾插入一行

    //将datalist中每个元素插入新插入的一行中的对应列
    for(int ncolumn=0;ncolumn<dataList.size();++ncolumn)
    {
        QTableWidgetItem *pItem=new QTableWidgetItem(dataList[ncolumn]); //创建新的单元格项QTableWidgetItem并初始化
        ui->tableWidgetPatient->setItem(nrow,ncolumn,pItem);              //将创建的QTableWidgetItem对象插入到刚才插入的行的对应列中
    }

}


/********************************
Name: SaveTableToFile
Inputs: none
Return Value: none
Description: 将表格中的数据写入文件
********************************/
void AddpatientDlg::SaveTableToFile()
{
    QString strFilePath;   //创建QString类型的数据接收文件路径
    strFilePath=qApp->applicationDirPath()+"/就诊人名单.csv";//获取文件的路径
    //qApp->applicationDirPath()获取到当前.exe执行程序所在的路径
    QString FILE_PATH(strFilePath);    //定义QString类型的变量FILE_PATH，并将其初始化为FilePath
    QFile PatientFile(FILE_PATH);   //创建QFile对象PatientFile，并将FILE_PATH作为构造函数的参数传入,初始化文件路径

    int nrow=ui->tableWidgetPatient->rowCount();    //用int类型变量nrow储存表格的行数

    QVector<CPatient> Patients; //创建一个储存就诊人类的Vector容器
    Patients.resize(nrow);      //将该Vector容器的大小设置为行数，即已添加就诊人个数

    //逐行将现在表格中的信息存放Vector容器中
    for(int i=0;i<nrow;++i)
    {
        Patients[i].SetPatientName(ui->tableWidgetPatient->item(i,0)->text());          //保存第i行第1个单元格中的内容
        Patients[i].SetPatientGender(ui->tableWidgetPatient->item(i,1)->text());        //保存第i行第2个单元格中的内容
        Patients[i].SetPatientAge(ui->tableWidgetPatient->item(i,2)->text().toInt());   //保存第i行第3个单元格中的内容
        Patients[i].SetPatientPhone(ui->tableWidgetPatient->item(i,3)->text());         //保存第i行第4个单元格中的内容
    }

    HospitalInfoTable Hospinfo; //实例化HospitalInfoTable
    PatientFile.resize(0);      //将原本文件中的数据清除，便于后续新数据的写入，以免重复

    //逐个将Vector容器中的数据保存至文件中
    for(int i=0;i<nrow;++i)
    {
        Hospinfo.SavePatientToFile(Patients.at(i),"ManagePatient");
    }

}




/****************************************
Name: ModifyReception
Inputs: none
Return Value: none
Description: 将修改的就诊人信息同步至预约信息
****************************************/
void AddpatientDlg::ModifyReception()
{
    int nrow=ui->tableWidgetPatient->rowCount();    //用int类型变量nrow储存表格的行数

    QVector<CPatient> NewPatients; //创建一个储存新就诊人类的Vector容器
    NewPatients.resize(nrow);      //将该Vector容器的大小设置为行数，即已添加就诊人个数

    //逐行将现在表格中的信息存放Vector容器中
    for(int i=0;i<nrow;++i)
    {
        NewPatients[i].SetPatientName(ui->tableWidgetPatient->item(i,0)->text());          //保存第i行第1个单元格中的内容
        NewPatients[i].SetPatientGender(ui->tableWidgetPatient->item(i,1)->text());        //保存第i行第2个单元格中的内容
        NewPatients[i].SetPatientAge(ui->tableWidgetPatient->item(i,2)->text().toInt());   //保存第i行第3个单元格中的内容
        NewPatients[i].SetPatientPhone(ui->tableWidgetPatient->item(i,3)->text());         //保存第i行第4个单元格中的内容
    }

    HospitalInfoTable HospInfo;     //实例化HospitalInfoTable
    //读取文件中储存的旧的就诊人信息
    QVector<CPatient> OldPatients=HospInfo.ReadPatientFromFile("ManagePatient");

    QVector<int> PatientIndexes;    //创建储存序号的Vector容器

    //逐个对新旧就诊人信息进行比较，并保存修改的行数
    for(int i=0;i<nrow;++i)
    {
        if(NewPatients[i].GetPatientName().compare(OldPatients[i].GetPatientName())!=0||NewPatients[i].GetPatientGender().compare(OldPatients[i].GetPatientGender())!=0||NewPatients[i].GetPatientAge()!=OldPatients[i].GetPatientAge()||NewPatients[i].GetPatientPhone().compare(OldPatients[i].GetPatientPhone())!=0)
        {
            PatientIndexes.append(i);
        }
    }

    ReceptionInfoTable RecepInfo;   //实例化ReceptionInfoTable
    //将文件中的预约信息读到Vector容器中
    QVector<CReception> Receptions=RecepInfo.ReadReceptionFromFile();
    //计算预约信息的个数
    QVector<CReception>::size_type ReceptionNumber=Receptions.size();
    QVector<int>::size_type ModifyNumber=PatientIndexes.size();


    //如果并未进行修改，则直接返回
    if(PatientIndexes.isEmpty())
    {
        return;
    }

    for(int i=0;i<ReceptionNumber;++i)
    {
        for(int j=0;j<ModifyNumber;++j)
        {
            if(Receptions[i].GetPatientName()==OldPatients[PatientIndexes[j]].GetPatientName())
            {
                Receptions[i].SetPatientName(NewPatients[PatientIndexes[j]].GetPatientName());
                Receptions[i].SetPatientGender(NewPatients[PatientIndexes[j]].GetPatientGender());
                Receptions[i].SetPatientAge(NewPatients[PatientIndexes[j]].GetPatientAge());
                Receptions[i].SetPatientPhone(NewPatients[PatientIndexes[j]].GetPatientPhone());

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




/***********************************************************
Name: on_pushButton_DeletePatient_clicked
Inputs: none
Return Value: none
Description: “删除就诊人”按钮的槽函数
***********************************************************/
void AddpatientDlg::on_pushButton_DeletePatient_clicked()
{
    DeletePatientDlg PatientDelete(this);   //实例化DeletePatientDlg
    int ret=PatientDelete.exec();           //以模态方式显示对话框

    HospitalInfoTable Hospinfo;             //实例化HospitalInfoTable

    if(ret==QDialog::Accepted)//OK按钮被按下
    {
        int nDeleteIndex=PatientDelete.ReturnDeleteIndex();  //用nDeleteIndex接收需要删除的就诊人序号

        QVector<CPatient> Patients=Hospinfo.ReadPatientFromFile("ManagePatient");   //从文件中读出保存的就诊人信息，并用Vector容器存放

        Patients.erase(Patients.begin()+nDeleteIndex);  //删除Patients中第nDeleteIndex个就诊人信息，后续信息向前移，并调整Vector容器的大小
        QVector<CPatient>::size_type NewPatientNumber=Patients.size();  //计算删除后就诊人的个数

        QString strFilePath;   //创建QString类型的数据接收文件路径
        strFilePath=qApp->applicationDirPath()+"/就诊人名单.csv";   //获取文件的路径
        //qApp->applicationDirPath()获取到当前.exe执行程序所在的路径

        QString FILE_PATH(strFilePath);    //定义QString类型的变量FILE_PATH，并将其初始化为FilePath
        QFile PatientFile(FILE_PATH);   //创建QFile对象PatientFile，并将FILE_PATH作为构造函数的参数传入,初始化文件路径
        PatientFile.resize(0);          //清空PatientFile中原先的就诊人数据

        //将存放新就诊人信息的Vector容器中的元素逐一写入文件
        for(int i=0;i<NewPatientNumber;++i)
        {
            Hospinfo.SavePatientToFile(Patients.at(i),"ManagePatient");
        }

        PatientDelete.DeleteItsReception(); //删除就诊人的同时，删除他的预约

        this->close();  //点击“OK”按钮后，关闭“就诊人信息”对话框

        SuccessDeletePatientDlg SuccessDelete(this);    //实例化SuccessDeletePatientDlg
        SuccessDelete.exec();   //以模态方式显示对话框
    }
}



AddpatientDlg::~AddpatientDlg()
{
    delete ui;
}



