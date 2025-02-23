//***************************************************
//文件名 ：          appointinfotable.cpp
//版本 ：                   5.0
//目的及主要功能 : 负责就诊人和门诊信息存读的类
//创建日期 ：            2024.08.26
//修改日期 ：            2024.09.11
//作者 ：                 Ada Cao
//联系方式 ：         2928588633@qq.com
//***************************************************


#include "appointinfotable.h"

AppointInfoTable::AppointInfoTable() {}



/***********************************************************
Name: ReadPatientFromFile
Inputs: none
Return Value: QVector<CPatient> *p_PatientData  - 就诊人信息
Description: 将病人信息从文件中读出
************************************************************/
QVector<CPatient> AppointInfoTable::ReadPatientFromFile()
{
    QString strFilePath;   //创建QString类型的数据接收文件路径
    strFilePath=qApp->applicationDirPath()+"/就诊人名单.csv";//获取文件的路径
    //qApp->applicationDirPath()获取到当前.exe执行程序所在的路径

    QString FILE_PATH(strFilePath);    //定义QString类型的变量FILE_PATH，并将其初始化为FilePath
    QFile PatientFile(FILE_PATH);   //创建QFile对象PatientFile，并将FILE_PATH作为构造函数的参数传入,初始化文件路径
    QStringList PatientList;        //创建存放字符串的列表类QStringList
    PatientList.clear();            //清空PatientList列表中的所有元素


    //如果可以以只读方式打开文件
    if(PatientFile.open(QIODevice::ReadOnly))
    {
        QTextStream stream(&PatientFile);   //创建QTextStream对象，并将其与打开的QFile对象关联起来


        //读取文件中的每一行数据到PatientList中,直至文件最后
        while(!stream.atEnd())
        {
            PatientList.push_back(stream.readLine());
        }

        PatientFile.close();    //关闭文件

        int nrow=PatientList.size();//创建int类型变量获取PatientList中行数

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




/***********************************************************************
Name: ReadOutpatientFromFile
Inputs: none
Return Value: QVector<CHospitalOutpatient> *p_OutpatientData  - 门诊信息
Description: 将门诊信息从文件中读出
************************************************************************/
QVector<CHospitalOutpatient> AppointInfoTable::ReadOutpatientFromFile()
{
    QString strFilePath;    //定义QString类型的变量FILE_PATH，并将其初始化为FilePath
    strFilePath=qApp->applicationDirPath()+"/门诊信息.csv";//获取文件的路径
    //qApp->applicationDirPath()获取到当前.exe执行程序所在的路径

    QString FILE_PATH(strFilePath);        //定义QString类型的变量FILE_PATH，并将其初始化为FilePath
    QFile OutpatientFile(FILE_PATH);    //创建QFile对象PatientFile，并将FILE_PATH作为构造函数的参数传入,初始化文件路径
    QStringList OutpatientList;         //创建存放字符串的列表类QStringList
    OutpatientList.clear();             //清空PatientList列表中的所有元素


     //如果可以以只读方式打开文件
    if(OutpatientFile.open(QIODevice::ReadOnly))
    {
        QTextStream stream(&OutpatientFile);   //创建QTextStream对象，并将其与打开的QFile对象关联起来


        //读取文件中的每一行数据到OutpatientList中,直至文件最后
        while(!stream.atEnd())
        {
            OutpatientList.push_back(stream.readLine());
        }

        OutpatientFile.close(); //关闭文件


        int nrow=OutpatientList.size();//创建int类型变量获取OutpatientList中行数

        //PatientList中存在元素时，将元素保存到QVector容器中
        if(!OutpatientList.empty())
        {
            //new一个地址，存放QVector，QVector中存放CHospitalOutpatient类型的数据
            QVector<CHospitalOutpatient> *p_OutpatientData=new QVector<CHospitalOutpatient>;

            //创建CHospitalOutpatient类型变量，用于临时储存读出来的数据
            CHospitalOutpatient Outpatient_temp;


            //逐行读出数据并将CPatient类型数据保存到QVector容器中
            for(int i=0;i<nrow;i++)
            {
                QString str=OutpatientList.at(i);   //读取第i行的数据
                QStringList qslist=str.split(",");  //去除分隔符号","

                Outpatient_temp.SetOutpatientID(qslist.at(0).toInt());                          //读取第i行第1个数据
                Outpatient_temp.SetOutpatientName(qslist.at(1));                                //读取第i行第2个数据
                Outpatient_temp.SetDoctorID(qslist.at(2).toInt());                              //读取第i行第3个数据
                Outpatient_temp.SetReceptionDate(QDate::fromString(qslist.at(3),"yyyy-MM-dd")); //读取第i行第4个数据
                Outpatient_temp.SetReceptionTime(qslist.at(4));                                 //读取第i行第5个数据
                Outpatient_temp.SetCapacity(qslist.at(5).toInt());                              //读取第i行第6个数据
                Outpatient_temp.SetOutpatientAddress(qslist.at(6));                             //读取第i行第7个数据
                Outpatient_temp.SetOutpatientPhone(qslist.at(7));                               //读取第i行第7个数据

                p_OutpatientData->append(Outpatient_temp);   //将CHospitalOutpatient数据保存至QVector容器中
            }

            return *p_OutpatientData;  //返回存放所有门诊信息的容器
        }
    }
}
