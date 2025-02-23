//***************************************************
//文件名 ：           appointmentdlg.cpp
//版本 ：                   5.0
//目的及主要功能 ：     添加预约信息对话框
//创建日期 ：            2024.08.26
//修改日期 ：            2024.09.11
//作者 ：                 Ada Cao
//联系方式 ：         2928588633@qq.com
//***************************************************



#include "appointmentdlg.h"
#include "ui_appointmentdlg.h"

AppointmentDlg::AppointmentDlg(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AppointmentDlg)
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

    //设置表格内容无法在外部被编辑
    ui->tableWidget_Outpatient->setEditTriggers(QAbstractItemView::NoEditTriggers);


    HospitalInfoTable Hospinfo;     //实例化HospitalInfoTable
    OutpatientInfotable Outinfo;    //实例化OutpatientInfotable
    AppointInfoTable AppInfo;       //实例化AppointInfoTable

    QString FilePath;   //创建QString类型的数据接收文件路径
    FilePath=qApp->applicationDirPath()+"/门诊信息.csv";    //获取文件的路径
    //qApp->applicationDirPath()获取到当前.exe执行程序所在的路径

    //如果文件存在且不为空，则读取文件中存放的数据并显示在列表中
    if(Hospinfo.isFileExist(FilePath))
    {
        //计算存放的门诊的个数
        QVector<CHospitalOutpatient>::size_type OutpatientNumber=Outinfo.ReadOutpatientFromFile("ManageOutpatient").size();
        //计算存放的就诊人的个数
        QVector<CPatient>::size_type PatientNumber=AppInfo.ReadPatientFromFile().size();

        //将文件中保存的门诊信息逐个输出到表格中
        for(int i=0;i<OutpatientNumber;++i)
        {
            this->SetRowData(Outinfo.ReadOutpatientFromFile("ManageOutpatient"),i);
        }

        //读取文件中保存的就诊人姓名，并将就诊人姓名显示在combobox中，供用户选择
        for(int i=0;i<PatientNumber;++i)
        {
            ui->comboBox_PatientName->addItem(AppInfo.ReadPatientFromFile()[i].GetPatientName());
        }

        //读取文件中保存的门诊名，并将门诊名显示在combobox中，供用户选择
        for(int i=0;i<OutpatientNumber;++i)
        {
            ui->comboBox_OutpatientName->addItem(AppInfo.ReadOutpatientFromFile()[i].GetOutpatientName());
        }
    }

}



/********************************************
Name: on_pushButton_ManageOutPatient_clicked
Inputs: none
Return Value: none
Description: “管理门诊”的槽函数
********************************************/
void AppointmentDlg::on_pushButton_ManageOutPatient_clicked()
{
    this->close();  //点击“管理门诊”按钮后，关闭“门诊预约”对话框

    PassWordDlg PasswordEnter(this);    //实例化PassWordDlg
    PasswordEnter.exec();               //以模态方式显示对话框
}


/***********************************************
Name: ReturnSelectOutpatientName
Inputs: none
Return Value: QString strOutpatientName - 门诊名
Description: 返回用户选择的门诊名称
***********************************************/
QString AppointmentDlg::ReturnSelectOutpatientName()
{
    QString strOutpatientName=ui->comboBox_OutpatientName->currentText();   //用QString类型保存选择的门诊名
    return  strOutpatientName;  //返回QString类型的门诊名
}


/***********************************************
Name: ReturnSelectReceptionDate
Inputs: none
Return Value: QDate strReceptionDate - 就诊日期
Description: 返回用户选择的就诊日期
***********************************************/
QDate AppointmentDlg::ReturnSelectReceptionDate()
{
    QDate strReceptionDate=ui->dateEdit_Date->date();    //用QDate类型保存输入的就诊日期
    return  strReceptionDate;   //返回QDate类型的就诊日期
}


/***********************************************
Name: ReturnSelectReceptionTime
Inputs: none
Return Value: QString strReceptionTime - 就诊时间
Description: 返回用户选择的就诊时间
***********************************************/
QString AppointmentDlg::ReturnSelectReceptionTime()
{
    QString strReceptionTime=ui->comboBox_Time->currentText();   //用QString类型保存输入的就诊时间
    return  strReceptionTime;   //返回QString类型的就诊时间
}


/***********************************************
Name: ReturnSelectPatientName
Inputs: none
Return Value: QString strPatientName - 就诊人
Description: 返回用户选择的就诊人
***********************************************/
QString AppointmentDlg::ReturnSelectPatientName()
{
    QString strPatientName=ui->comboBox_PatientName->currentText(); //用QString类型保存输入的就诊人
    return  strPatientName; //返回QString类型的就诊人
}



/***********************************************
Name: SelectOutpatientTrue
Inputs: none
Return Value: int index - 门诊序号
Description: 确定用户选择的门诊日期时间存在相应的门诊
***********************************************/
int AppointmentDlg::SelectOutpatientTrue()
{
    AppointInfoTable Appinfo;   //实例化AppointInfoTable
    //计算文件中存放的门诊个数
    QVector<CHospitalOutpatient>::size_type OutpatientNumber=Appinfo.ReadOutpatientFromFile().size();
    int index=0;    //创建int类型变量，用于存放选择的门诊编号


    //将文件中保存的门诊与选择的门诊逐个验证是否相同
    for(int i=0;i<OutpatientNumber;++i)
    {
        //创建门诊类变量，接收文件中的第i个门诊信息
        CHospitalOutpatient OutpatientClass=Appinfo.ReadOutpatientFromFile().at(i);

        //如果门诊名相同
        if(this->ReturnSelectOutpatientName()==OutpatientClass.GetOutpatientName())
        {
            //如果接诊日期相同
            if(this->ReturnSelectReceptionDate()==OutpatientClass.GetReceptionDate())
            {
                //如果接诊时间相同
                if(this->ReturnSelectReceptionTime()==OutpatientClass.GetReceptionTime())
                {
                    index=i;        //将门诊序号赋值为i
                    return index;   //返回门诊序号index
                }
            }
        }

    }

    return -1;  //若未找到与选择的门诊信息相同的门诊，则返回-1
}


/************************************
Name: SelectPatient
Inputs: none
Return Value: int index - 就诊人序号
Description: 返回用户选择的
*************************************/
int AppointmentDlg::SelectPatient()
{
    int index=ui->comboBox_PatientName->currentIndex(); //用QString类型保存选择的就诊人序号
    return index;   //返回int类型的就诊人序号
}



/***********************************************
Name: SelectOutpatientFull
Inputs: none
Return Value: bool
Description: 预约失败原因之一：相应门诊容量已满
***********************************************/
bool AppointmentDlg::SelectOutpatientFull()
{
    AppointInfoTable Appinfo;   //实例化AppointInfoTable

    int index=this->SelectOutpatientTrue(); //用int类型变量储存用户选择的门诊序号，>=0为存在，=-1则不存在

    //创建门诊类变量，接收文件中的第index个门诊信息
    CHospitalOutpatient OutpatientClass=Appinfo.ReadOutpatientFromFile().at(index);

    //若第index个门诊信息中门诊容量为0，则返回true，表示该门诊预约已满
    if(OutpatientClass.GetCapacity()==0)
    {
        return true;
    }

    //若第index个门诊信息中门诊容量不为0，则返回false，表示该门诊可预约
    return false;
}


/**********************************************************
Name: SetRowData
Inputs: QVector<CHospitalOutpatient> Outpatients - 门诊信息
        int index - QVector容器中的索引下标
Return Value: none
Description: 将门诊信息显示在表格上
**********************************************************/
void AppointmentDlg::SetRowData(QVector<CHospitalOutpatient> Outpatients,int index)
{
    //创建一个用于存放门诊信息的QStringList类型的dalaList
    QStringList dataList;
    dataList.append(QString::number(Outpatients[index].GetOutpatientID()));         //向datalist中有序添加门诊号
    dataList.append(Outpatients[index].GetOutpatientName());                        //向datalist中有序添加门诊名称
    dataList.append(QString::number(Outpatients[index].GetDoctorID()));             //向datalist中有序添加值班医生工号值班医生工号
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


AppointmentDlg::~AppointmentDlg()
{
    delete ui;
}
