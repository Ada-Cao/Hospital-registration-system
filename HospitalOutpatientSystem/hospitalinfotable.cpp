//***************************************************
//文件名 ：         hospitalinfotable.cpp
//版本 ：                   5.0
//目的及主要功能 ：   负责就诊人信息存读的类
//创建日期 ：            2024.08.26
//修改日期 ：            2024.09.11
//作者 ：                 Ada Cao
//联系方式 ：         2928588633@qq.com
//***************************************************



#include "hospitalinfotable.h"

HospitalInfoTable::HospitalInfoTable() {}



/**************************************
Name: SavePatientToFile
Inputs: CPatient patient - 就诊人信息
        QString FileUse - 文件用途
Return Value: none
Description: 将输入的就诊人数据保存至文件
**************************************/
void HospitalInfoTable::SavePatientToFile(CPatient patient,QString FileUse)
{
    QString strFilePath;    //创建QString类型的数据接收文件路径

    //如果输入的文件用途是“ManagePatient”，则打开“就诊人名单.csv”
    if(FileUse=="ManagePatient")
    {
        strFilePath=qApp->applicationDirPath()+"/就诊人名单.csv";   //获取文件的路径
        //qApp->applicationDirPath()获取到当前.exe执行程序所在的路径
    }
    //如果输入的文件用途是“FindPatient”，则打开“temp预约信息查找.csv”
    else if(FileUse=="FindPatient")
    {
        strFilePath=qApp->applicationDirPath()+"/temp预约信息查找.csv";  //获取文件的路径
        //qApp->applicationDirPath()获取到当前.exe执行程序所在的路径
    }


    QString FILE_PATH(strFilePath);    //定义QString类型的变量FILE_PATH，并将其初始化为FilePath
    QFile PatientFile(FILE_PATH);   //创建QFile对象PatientFile，并将FILE_PATH作为构造函数的参数传入,初始化文件路径


    //如果可以打开文件并向内追加写入信息
    if(PatientFile.open(QIODevice::Append|QIODevice::WriteOnly))
    {
        QTextStream stream(&PatientFile);   //创建QTextStream对象，并将其与打开的QFile对象关联起来

        //依次向文件中传输信息，并用逗号分隔开
        stream<<patient.GetPatientName()<< ","      //输入就诊人姓名
               <<patient.GetPatientGender()<< ","   //输入就诊人性别
               <<patient.GetPatientAge()<< ","      //输入就诊人年龄
               <<patient.GetPatientPhone()<< "\n" ; //输入就诊人联系方式并换行

        stream.flush();     //文件刷新
    }

    PatientFile.close();    //文件关闭
}




//在文件中读取保存的数据
/***********************************************************
Name: ReadPatientFromFile
Inputs: QString FileUse - 文件用途
Return Value: QVector<CPatient> *p_PatientData - 就诊人信息
Description: 将病人信息从文件中读出
************************************************************/
QVector<CPatient> HospitalInfoTable::ReadPatientFromFile(QString FileUse)
{
    QString strFilePath;   //创建QString类型的数据接收文件路径

    //如果输入的文件用途是“ManagePatient”，则打开“就诊人名单.csv”
    if(FileUse=="ManagePatient")
    {
        strFilePath=qApp->applicationDirPath()+"/就诊人名单.csv";   //获取文件的路径
        //qApp->applicationDirPath()获取到当前.exe执行程序所在的路径
    }
    //如果输入的文件用途是“FindPatient”，则打开“temp预约信息查找.csv”
    else if(FileUse=="FindPatient")
    {
        strFilePath=qApp->applicationDirPath()+"/temp预约信息查找.csv";  //获取文件的路径
        //qApp->applicationDirPath()获取到当前.exe执行程序所在的路径
    }


    QString FILE_PATH(strFilePath);    //定义QString类型的变量FILE_PATH，并将其初始化为FilePath
    QFile PatientFile(FILE_PATH);   //创建QFile对象PatientFile，并将FILE_PATH作为构造函数的参数传入,初始化文件路径
    QStringList PatientList;        //创建存放字符串的列表类QStringList
    PatientList.clear();            //清空PatientList列表中的所有元素

    //如果可以以读写的方式打开文件
    if(PatientFile.open(QIODevice::ReadWrite))
    {
        QTextStream stream(&PatientFile);    //创建QTextStream对象，并将其与打开的QFile对象关联起来


        //读取文件中的每一行数据到PatientList中，直至文件最后
        while(!stream.atEnd())
        {
            PatientList.push_back(stream.readLine());
        }

        PatientFile.close();    //关闭文件


        int nrow=PatientList.size();    //创建int类型变量获取PatientList中行数

        //PatientList中存在元素时，将元素保存到QVector容器中
        if(!PatientList.empty())
        {
            //new一个地址，存放QVector，QVector中存放CPatient类型的数据
            QVector<CPatient> *p_PatientData=new QVector<CPatient>;

            //创建CPatient类型变量，用于临时储存读出来的数据
            CPatient Patient_temp;

            //逐行读出数据并将CPatient类型数据保存到QVector容器中
            for(int i=0;i<nrow;i++)
            {
                QString str=PatientList.at(i);      //读取第i行的数据
                QStringList qslist=str.split(",");  //去除分隔符号","

                Patient_temp.SetPatientName(qslist.at(0));          //读取第i行第1个数据
                Patient_temp.SetPatientGender(qslist.at(1));        //读取第i行第2个数据
                Patient_temp.SetPatientAge(qslist.at(2).toInt());   //读取第i行第3个数据
                Patient_temp.SetPatientPhone(qslist.at(3));         //读取第i行第4个数据

                p_PatientData->append(Patient_temp);    //将CPatient数据保存至QVector容器中
            }

            return *p_PatientData;  //返回存放所有就诊人信息的容器
        }
    }
}




/***********************************************************
Name: isFileExist
Inputs: const QString &filepath - 文件名称
Return Value: bool
Description: 判断想打开的文件是否存在、是否能打开、是否为空
************************************************************/
bool HospitalInfoTable::isFileExist(const QString &filepath)
{
    QString FILE_PATH(filepath);    //定义QString类型的变量FILE_PATH，并将其初始化为FilePath
    QFile PatientFile(FILE_PATH);    //创建QFile对象PatientFile，并将FILE_PATH作为构造函数的参数传入,初始化文件路径


    //如果文件不存在，则返回false
    if(!PatientFile.exists())
    {
        return false;
    }

    //如果文件无法打开，则返回false
    if(!PatientFile.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        return false;
    }
    else//如果文件存在且可以打开，判断文件内内容是否为空
    {
        //若文件大小大于0，代表文件中有内容，则返回bool值true
        //若文件大小等于0，代表文件为空，则返回bool值true
        bool exist=(PatientFile.size()>0);
        PatientFile.close();    //关闭文件
        return exist;           //返回bool值exist，true代表文件中有内容，false代表文件为空
    }

}

