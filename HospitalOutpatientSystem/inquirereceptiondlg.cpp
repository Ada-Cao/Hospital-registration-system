//***************************************************
//文件名 ：        inquirereceptiondlg.cpp
//版本 ：                   5.0
//目的及主要功能 ：      查询预约对话框
//创建日期 ：            2024.08.26
//修改日期 ：            2024.09.11
//作者 ：                 Ada Cao
//联系方式 ：         2928588633@qq.com
//***************************************************



#include "inquirereceptiondlg.h"
#include "ui_inquirereceptiondlg.h"

InquireReceptionDlg::InquireReceptionDlg(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::InquireReceptionDlg)
{
    ui->setupUi(this);


    //设置表格：使表格的每一列宽度相等，并占满表格宽度
    ui->tableWidget_Reception->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    //设置表格背景的颜色
    ui->tableWidget_Reception->setStyleSheet("QTableWidget{background-color:lightblue}");

    //设置表格表头背景颜色、字的颜色、字体样式
    ui->tableWidget_Reception->horizontalHeader()->setStyleSheet("QHeaderView::section{background-color:blue;color:white;font-weight:bold;}");

    //设置表格内容无法在外部被编辑
    ui->tableWidget_Reception->setEditTriggers(QAbstractItemView::NoEditTriggers);

    QString strFilePath;   //创建QString类型的数据接收文件路径
    strFilePath=qApp->applicationDirPath()+"/预约信息.csv";    //获取文件的路径
    //qApp->applicationDirPath()获取到当前.exe执行程序所在的路径


    ReceptionInfoTable Recepinfo;   //实例化ReceptionInfoTable

    //如果存放预约信息的文件存在、可以打开并不为空
    if(Recepinfo.isFileExist(strFilePath))
    {
        //计算文件中存放的预约个数
        QVector<CReception>::size_type ReceptionNumber=Recepinfo.ReadReceptionFromFile().size();

        //将文件中保存的预约信息逐个输出到表格中
        for(int i=0;i<ReceptionNumber;++i)
        {
            this->SetRowData(Recepinfo.ReadReceptionFromFile(),i);
        }
    }


    OutpatientInfotable Outinfo;    //实例化OutpatientInfotable

    //计算文件中存放的门诊个数
    QVector<CHospitalOutpatient>::size_type OutpatientNumber=Outinfo.ReadOutpatientFromFile("ManageOutpatient").size();

    if(OutpatientNumber!=0)
    {
        //将文件中保存的门诊逐个输出到表格中
        for(int i=0;i<OutpatientNumber;++i)
        {
            ui->comboBox_OutpatientName->addItem(Outinfo.ReadOutpatientFromFile("ManageOutpatient")[i].GetOutpatientName());
        }
    }

}




/************************************************
Name: ReturnSelectOutpatientName
Inputs: none
Return Value: QString strOutpatientName - 门诊名
Description: 返回输入的门诊名
************************************************/
QString InquireReceptionDlg::ReturnSelectOutpatientName()
{
    QString strOutpatientName=ui->comboBox_OutpatientName->currentText();   //用QString类型保存输入的门诊名称
    return strOutpatientName;   //返回QString类型的门诊名称
}


/**********************************************
Name: ReturnSelectReceptionDate
Inputs: none
Return Value: QDate dtReceptionDate - 接诊日期
Description: 返回输入的接诊日期
**********************************************/
QDate InquireReceptionDlg::ReturnSelectReceptionDate()
{
    QDate dtReceptionDate=ui->dateEdit_ReceptionDate->date();   //用QDate类型保存输入的接诊日期
    return dtReceptionDate;  //返回QDate类型的接诊日期
}


/*****************************
Name: ReturnSelectReceptionTime
Inputs: none
Return Value: QString strReceptionTime - 接诊时间
Description: 返回输入的接诊时间
*****************************/
QString InquireReceptionDlg::ReturnSelectReceptionTime()
{
    QString strReceptionTime=ui->comboBox_Receptiontime->currentText(); //用QString类型保存输入的接诊时间
    return strReceptionTime;    //返回QString类型的接诊时间
}


/************************************************
Name: ReturnSelectPatientName
Inputs: none
Return Value: QString strPatientName - 就诊人姓名
Description: 返回输入的就诊人姓名
************************************************/
QString InquireReceptionDlg::ReturnSelectPatientName()
{
    QString strPatientName=ui->textEdit_PatientName->toPlainText(); //用QString类型保存输入的就诊人姓名
    return strPatientName;  //返回QString类型的就诊人姓名
}


/***************************************************
Name: ReturnSelectPatientPhone
Inputs: none
Return Value: QString strPatientName - 就诊人联系方式
Description: 返回输入的就诊人联系方式
***************************************************/
QString InquireReceptionDlg::ReturnSelectPatientPhone()
{
    QString strPatientPhone=ui->textEdit_PatientPhone->toPlainText();    //用QString类型保存输入的就诊联系方式
    return strPatientPhone; //返回QString类型的就诊人联系方式
}





/*********************************************************************************
Name: ReturnPatientsbyOutpatient
Inputs: none
Return Value: QVector<CPatient> PatientsbyOutpatient - 根据门诊信息查询出的就诊人信息
Description: 根据门诊信息查询出该门诊预约的就诊人信息
*********************************************************************************/
QVector<CPatient> InquireReceptionDlg::ReturnPatientsbyOutpatient()
{
    ReceptionInfoTable Recepinfo;   //实例化ReceptionInfoTable
    //计算存放的预约个数
    QVector<CReception>::size_type ReceptionNumber=Recepinfo.ReadReceptionFromFile().size();

    //创建存放就诊人信息的Vector容器
    QVector<CPatient> PatientsbyOutpatient;

    //将文件中保存的预约与选择的预约逐个验证是否相同
    for(int i=0;i<ReceptionNumber;++i)
    {
        //创建预约类变量，接收文件中的第i个预约信息
        CReception Reception=Recepinfo.ReadReceptionFromFile().at(i);

        //如果门诊名相同
        if(this->ReturnSelectOutpatientName()==Reception.GetOutpatientName())
        {
            //如果接诊日期相同
            if(this->ReturnSelectReceptionDate()==Reception.GetReceptionDate())
            {
                //如果接诊时间相同
                if(this->ReturnSelectReceptionTime()==Reception.GetReceptionTime())
                {
                    //创建就诊人类的临时变量
                    CPatient temp_Patient;
                    temp_Patient.SetPatientName(Reception.GetPatientName());    //将该条预约信息的就诊人姓名保存至临时变量中
                    temp_Patient.SetPatientGender(Reception.GetPatientGender());//将该条预约信息的就诊人性别保存至临时变量中
                    temp_Patient.SetPatientAge(Reception.GetPatientAge());      //将该条预约信息的就诊人年龄保存至临时变量中
                    temp_Patient.SetPatientPhone(Reception.GetPatientPhone());  //将该条预约信息的就诊人联系方式保存至临时变量中

                    PatientsbyOutpatient.append(temp_Patient);  //将就诊人类保存至Vector容器中
                }
            }
        }
    }

    return PatientsbyOutpatient;    //返回保存相应门诊下预约的就诊人信息的Vector容器
}




/*************************************************
Name: SetRowData
Inputs: QVector<CReception> Receptions - 预约信息
        int index - QVector容器中的索引下标
Return Value: none
Description: 将预约信息显示在表格上
*************************************************/
void InquireReceptionDlg::SetRowData(QVector<CReception> Receptions,int index)
{

    //创建一个用于存放门诊信息的QStringList类型的dalaList
    QStringList dataList;
    dataList.append(Receptions[index].GetPatientName());                            //向datalist中有序添加就诊人姓名
    dataList.append(Receptions[index].GetPatientGender());                          //向datalist中有序添加就诊人性别
    dataList.append(QString::number(Receptions[index].GetPatientAge()));            //向datalist中有序添加就诊人年龄
    dataList.append(Receptions[index].GetPatientPhone());                           //向datalist中有序添加就诊人电话
    dataList.append(Receptions[index].GetOutpatientName());                         //向datalist中有序添加门诊名称
    dataList.append(Receptions[index].GetReceptionDate().toString("yyyy-MM-dd"));   //向datalist中有序添加接诊日期
    dataList.append(Receptions[index].GetReceptionTime());                          //向datalist中有序添加接诊时间
    dataList.append(Receptions[index].GetOutpatientAddress());                      //向datalist中有序添加门诊地址



    int row=ui->tableWidget_Reception->rowCount();  //获取tableWidgt当前行数，并储存在row中
    ui->tableWidget_Reception->insertRow(row);      //根据获取的行数row,在表格末尾插入一行

    //将datalist中每个元素插入新插入的一行中的对应列
    for(int column=0;column<dataList.size();++column)
    {
        QTableWidgetItem *pItem=new QTableWidgetItem(dataList[column]);  //创建新的单元格项QTableWidgetItem并初始化
        ui->tableWidget_Reception->setItem(row,column,pItem);            //将创建的QTableWidgetItem对象插入到刚才插入的行的对应列中
    }

}





/*******************************************************************************************
Name: ReturnOutpatientsbyPatient
Inputs: QString SearchBy - 查询方式
Return Value: QVector<CHospitalOutpatient> OutpatientsbyPatient- 根据就诊人信息查询出的门诊信息
Description: 根据就诊人姓名或联系电话查询出其预约过的门诊信息
*******************************************************************************************/
QVector<CHospitalOutpatient> InquireReceptionDlg::ReturnOutpatientsbyPatient(QString SearchBy)
{
    ReceptionInfoTable Recepinfo;   //实例化ReceptionInfoTable
    //计算存放的预约个数
    QVector<CReception>::size_type ReceptionNumber=Recepinfo.ReadReceptionFromFile().size();

    //创建存放门诊信息的Vector容器
    QVector<CHospitalOutpatient> OutpatientsbyPatient;

    //如果是通过就诊人姓名进行查询
    if(SearchBy=="PatientName")
    {
        //将文件中保存的预约中的就诊人姓名与选择的就诊人姓名逐个验证是否相同
        for(int i=0;i<ReceptionNumber;++i)
        {
            //创建预约类变量，接收文件中的第i个预约信息
            CReception Reception=Recepinfo.ReadReceptionFromFile().at(i);

            //如果就诊人姓名相同
            if(this->ReturnSelectPatientName()==Reception.GetPatientName())
            {
                //创建门诊类的临时变量
                CHospitalOutpatient temp_Outpatient;
                temp_Outpatient.SetOutpatientID(Reception.GetOutpatientID());           //将该条预约信息的门诊号保存至临时变量中
                temp_Outpatient.SetOutpatientName(Reception.GetOutpatientName());       //将该条预约信息的门诊名保存至临时变量中
                temp_Outpatient.SetDoctorID(Reception.GetDoctorID());                   //将该条预约信息的值班医生工号保存至临时变量中
                temp_Outpatient.SetReceptionDate(Reception.GetReceptionDate());         //将该条预约信息的接诊日期保存至临时变量中
                temp_Outpatient.SetReceptionTime(Reception.GetReceptionTime());         //将该条预约信息的接诊时间保存至临时变量中
                temp_Outpatient.SetCapacity(Reception.GetCapacity());                   //将该条预约信息的容量保存至临时变量中
                temp_Outpatient.SetOutpatientAddress(Reception.GetOutpatientAddress()); //将该条预约信息的门诊地址保存至临时变量中
                temp_Outpatient.SetOutpatientPhone(Reception.GetOutpatientPhone());     //将该条预约信息的门诊联系电话保存至临时变量中

                OutpatientsbyPatient.append(temp_Outpatient);    //将门诊类保存至Vector容器中

            }
        }
    }


    //如果是通过就诊人联系方式进行查询
    if(SearchBy=="PatientPhone")
    {
        //将文件中保存的预约中的就诊人电话与选择的就诊人电话逐个验证是否相同
        for(int i=0;i<ReceptionNumber;++i)
        {
            //创建预约类变量，接收文件中的第i个预约信息
            CReception Reception=Recepinfo.ReadReceptionFromFile().at(i);

            //如果就诊人电话相同
            if(this->ReturnSelectPatientPhone()==Reception.GetPatientPhone())
            {
                //创建门诊类的临时变量
                CHospitalOutpatient temp_Outpatient;
                temp_Outpatient.SetOutpatientID(Reception.GetOutpatientID());           //将该条预约信息的门诊号保存至临时变量中
                temp_Outpatient.SetOutpatientName(Reception.GetOutpatientName());       //将该条预约信息的门诊名保存至临时变量中
                temp_Outpatient.SetDoctorID(Reception.GetDoctorID());                   //将该条预约信息的值班医生工号保存至临时变量中
                temp_Outpatient.SetReceptionDate(Reception.GetReceptionDate());         //将该条预约信息的接诊日期保存至临时变量中
                temp_Outpatient.SetReceptionTime(Reception.GetReceptionTime());         //将该条预约信息的接诊时间保存至临时变量中
                temp_Outpatient.SetCapacity(Reception.GetCapacity());                   //将该条预约信息的容量保存至临时变量中
                temp_Outpatient.SetOutpatientAddress(Reception.GetOutpatientAddress()); //将该条预约信息的门诊地址保存至临时变量中
                temp_Outpatient.SetOutpatientPhone(Reception.GetOutpatientPhone());     //将该条预约信息的门诊联系电话保存至临时变量中

                OutpatientsbyPatient.append(temp_Outpatient);   //将门诊类保存至Vector容器中

            }
        }
    }

    return OutpatientsbyPatient;    //返回保存就诊人预约的门诊信息的Vector容器
}




/**********************************************
Name: on_pushButton_SearchByOutpatient_clicked
Inputs: none
Return Value: none
Description: “按照门诊信息查询”的槽函数
**********************************************/
void InquireReceptionDlg::on_pushButton_SearchByOutpatient_clicked()
{
    HospitalInfoTable Hospinfo; //实例化HospitalInfoTable
    //计算存放的就诊人的个数
    QVector<CPatient>::size_type FindPatientNumber=this->ReturnPatientsbyOutpatient().size();

    //如果该门诊挂号人数为0，则提示没有预约信息
    if(FindPatientNumber==0)
    {
        //弹出对话框，提示用户没有预约信息
        FailFindReceptionDlg FailFind(this);    //实例化FailFindReceptionDlg
        FailFind.exec();    //以模态方式显示对话框
    }
    else//如果该门诊挂号人数不为0，则显示该门诊的预约信息
    {
        //逐个输出预约该门诊的就诊人信息
        for(int i =0;i<FindPatientNumber;++i)
        {
            Hospinfo.SavePatientToFile(this->ReturnPatientsbyOutpatient().at(i),"FindPatient");
        }

        //弹出对话框，展示该门诊的预约信息
        SearchByOutpatientDlg OutpatientSearch(this);   //实例化SearchByOutpatientDlg
        OutpatientSearch.exec();    //以模态方式显示对话框
    }
}



/**********************************************
Name: on_pushButton_SearchByPatientName_clicked
Inputs: none
Return Value: none
Description: “按照就诊人姓名查询”的槽函数
**********************************************/
void InquireReceptionDlg::on_pushButton_SearchByPatientName_clicked()
{
    OutpatientInfotable Outinfo;     //实例化OutpatientInfotable

    //计算存放的门诊的个数
    QVector<CHospitalOutpatient>::size_type FindOutpatientNumber=this->ReturnOutpatientsbyPatient("PatientName").size();

    //如果该就诊人未挂号，则提示没有预约信息
    if(FindOutpatientNumber==0)
    {
        //弹出对话框，提示用户没有预约信息
        FailFindReceptionDlg FailFind(this);     //实例化FailFindReceptionDlg
        FailFind.exec();     //以模态方式显示对话框
    }
    else//如果该就诊人挂号了，则显示该就诊人的预约信息
    {
        //逐个输出就诊人预约的门诊信息
        for(int i =0;i<FindOutpatientNumber;++i)
        {
            Outinfo.SaveOutpatientToFile(this->ReturnOutpatientsbyPatient("PatientName").at(i),"FindOutpatient");
        }

        //弹出对话框，展示该门诊的预约信息
        SearchByPatientNameDlg PatientNameSearch(this); //实例化SearchByPatientNameDlg
        PatientNameSearch.exec();   //以模态方式显示对话框
    }
}



/*************************************************
Name: on_pushButton_SearchByPatientPhone_clicked
Inputs: none
Return Value: none
Description: “按照就诊人电话查询”的槽函数
*************************************************/
void InquireReceptionDlg::on_pushButton_SearchByPatientPhone_clicked()
{
    OutpatientInfotable Outinfo;    //实例化OutpatientInfotable

    //计算存放的门诊的个数
    QVector<CHospitalOutpatient>::size_type FindOutpatientNumber=this->ReturnOutpatientsbyPatient("PatientPhone").size();

    //如果该就诊人未挂号，则提示没有预约信息
    if(FindOutpatientNumber==0)
    {
        //弹出对话框，提示用户没有预约信息
        FailFindReceptionDlg FailFind(this);    //实例化FailFindReceptionDlg
        FailFind.exec();    //以模态方式显示对话框
    }
    else//如果该就诊人挂号了，则显示该就诊人的预约信息
    {
        //逐个输出就诊人预约的门诊信息
        for(int i =0;i<FindOutpatientNumber;++i)
        {
            Outinfo.SaveOutpatientToFile(this->ReturnOutpatientsbyPatient("PatientPhone").at(i),"FindOutpatient");
        }

        //弹出对话框，展示该门诊的预约信息
        SearchByPatientNameDlg PatientNameSearch(this); //实例化SearchByPatientNameDlg
        PatientNameSearch.exec();   //以模态方式显示对话框
    }
}




/*************************************************
Name: on_pushButton_DeleteReception_clicked
Inputs: none
Return Value: none
Description: “取消预约”的槽函数
*************************************************/
void InquireReceptionDlg::on_pushButton_DeleteReception_clicked()
{
    //弹出对话框，展示取消预约界面
    DeleteReceptionDlg ReceptionDelete(this);   //实例化DeleteReceptionDlg
    int ret=ReceptionDelete.exec(); //以模态方式显示对话框

    //OK按钮被按下
    if(ret==QDialog::Accepted)
    {
        //如果想要取消的预约信息存在
        if(ReceptionDelete.SelectReceptionTrue()>=0)
        {
            //创建int类型变量储存取消预约的序号
            int nDeleteIndex=ReceptionDelete.SelectReceptionTrue();
            ReceptionInfoTable Recepinfo;   //实例化ReceptionInfoTable

            //创建存放预约信息的Vector变量
            QVector<CReception> Receptions=Recepinfo.ReadReceptionFromFile();

            //创建QString类型变量保存要预约的门诊名称
            QString strDeleteOutpatientName=Receptions[nDeleteIndex].GetOutpatientName();

            //删除Receptions中第nDeleteIndex个就诊人信息，后续信息向前移，并调整Vector容器的大小
            Receptions.erase(Receptions.begin()+nDeleteIndex);

            //计算删除后预约信息的个数
            QVector<CReception>::size_type NewReceptionNumber=Receptions.size();


            QString FilePath;    //创建QString类型的数据接收文件路径
            FilePath=qApp->applicationDirPath()+"/预约信息.csv";  //获取文件的路径
            //qApp->applicationDirPath()获取到当前.exe执行程序所在的路径

            QString FILE_PATH(FilePath);    //定义QString类型的变量FILE_PATH，并将其初始化为FilePath
            QFile ReceptionFile(FILE_PATH); //创建QFile对象ReceptionFile，并将FILE_PATH作为构造函数的参数传入,初始化文件路径
            ReceptionFile.resize(0);        //将ReceptionFile中所有数据清空

            //将存放新预约信息的Vector容器中的元素逐一写入文件
            for(int i=0;i<NewReceptionNumber;++i)
            {
                Recepinfo.SaveReceptionToFile(Receptions.at(i));
            }



            OutpatientInfotable Outinfo;    //实例化OutpatientInfotable
            //创建Vector容器保存文件中的预约信息
            QVector<CHospitalOutpatient> Outpatients=Outinfo.ReadOutpatientFromFile("ManageOutpatient");
            //计算文件中门诊信息的个数
            QVector<CHospitalOutpatient>::size_type OutpatientNumber=Outpatients.size();


            //创建int类型变量存放删除预约的序号，并将其初始化为0
            int nDeleteOutpatientIndex=0;
            //逐一对比文件中保存的门诊名和选择删除的门诊名是否相同
            for(int i=0;i<OutpatientNumber;++i)
            {
                //若文件中保存的门诊名和选择删除的门诊名相同
                if(Outpatients[i].GetOutpatientName()==strDeleteOutpatientName)
                {
                    nDeleteOutpatientIndex=i;   //将nDeleteOutpatientIndex赋值为i
                    break;                      //退出循环
                }
            }

            Outinfo.PlusCapacity(nDeleteOutpatientIndex);   //取消预约后，该门诊容量+1

            this->close();  //点击“OK”按钮后，关闭“查询预约信息”对话框

            //弹出对话框，提示成功取消预约
            SuccessDeleteReeptionDlg SuccessDelete(this);   //实例化SuccessDeleteReeptionDlg
            SuccessDelete.exec();   //以模态方式显示对话框
        }
        else//如果想要取消的预约信息不存在
        {
            //弹出对话框，提示未找到该预约
            FailFindReceptionDlg FailFind(this);    //实例化FailFindReceptionDlg
            FailFind.exec();    //以模态方式显示对话框
        }

    }

}


InquireReceptionDlg::~InquireReceptionDlg()
{
    delete ui;
}
