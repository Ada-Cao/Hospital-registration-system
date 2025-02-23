//***************************************************
//文件名 ：         receptioninfotable.cpp
//版本 ：                   5.0
//目的及主要功能 ：    负责预约信息存读的类
//创建日期 ：            2024.08.26
//修改日期 ：            2024.09.11
//作者 ：                 Ada Cao
//联系方式 ：         2928588633@qq.com
//***************************************************



#include "receptioninfotable.h"

ReceptionInfoTable::ReceptionInfoTable() {}




/**************************************
Name: SaveReceptionToFile
Inputs:CReception Reception - 预约信息
Return Value: none
Description: 将输入的预约信息保存在文件中
**************************************/
void ReceptionInfoTable::SaveReceptionToFile(CReception Reception)
{
    QString strFilePath;   //创建QString类型的数据接收文件路径
    strFilePath=qApp->applicationDirPath()+"/预约信息.csv";    //获取文件的路径
    //qApp->applicationDirPath()获取到当前.exe执行程序所在的路径

    QString FILE_PATH(strFilePath);     //定义QString类型的变量FILE_PATH，并将其初始化为FilePath
    QFile ReceptionFile(FILE_PATH);  //创建QFile对象ReceptionFile，并将FILE_PATH作为构造函数的参数传入,初始化文件路径


    //如果可以打开文件并向内追加写入信息
    if(ReceptionFile.open(QIODevice::Append|QIODevice::WriteOnly))
    {
        QTextStream stream(&ReceptionFile); //创建QTextStream对象，并将其与打开的QFile对象关联起来

        //依次向文件中传输信息，并用逗号分隔开
        stream<<Reception.GetPatientName()<< ","        //输入就诊人姓名
               <<Reception.GetPatientGender()<< ","     //输入就诊人性别
               <<Reception.GetPatientAge()<< ","        //输入就诊人年龄
               <<Reception.GetPatientPhone()<<","       //输入就诊人联系方式
               <<Reception.GetOutpatientID()<<","       //输入门诊号
               <<Reception.GetOutpatientName()<<","     //输入门诊名
               <<Reception.GetDoctorID()<<","           //输入值班医生工号
               <<Reception.GetReceptionDate().toString("yyyy-MM-dd")<<","  //输入接诊日期
               <<Reception.GetReceptionTime()<<","      //输入接诊时间
               <<Reception.GetCapacity()<<","           //输入容量
               <<Reception.GetOutpatientAddress()<<","  //输入门诊地址
               <<Reception.GetOutpatientPhone()<<"\n";  //输入门诊联系电话并换行

        stream.flush(); //文件刷新
    }

    ReceptionFile.close();  //文件关闭
}





//在文件中读取保存的数据
/***********************************************************************
Name: ReadReceptionFromFile
Inputs: none
Return Value: QVector<CReception> return *p_ReceptionData - 预约信息
Description: 将预约信息从文件中读出
************************************************************************/
QVector<CReception> ReceptionInfoTable::ReadReceptionFromFile()
{
    QString strFilePath;   //创建QString类型的数据接收文件路径
    strFilePath=qApp->applicationDirPath()+"/预约信息.csv";    //获取文件的路径
    //qApp->applicationDirPath()获取到当前.exe执行程序所在的路径

    QString FILE_PATH(strFilePath);    //定义QString类型的变量FILE_PATH，并将其初始化为FilePath
    QFile ReceptionFile(FILE_PATH); //创建QFile对象ReceptionFile，并将FILE_PATH作为构造函数的参数传入,初始化文件路径
    QStringList ReceptionList;      //创建存放字符串的列表类QStringList
    ReceptionList.clear();          //清空ReceptionList列表中的所有元素


    //如果可以以读写的方式打开文件
    if(ReceptionFile.open(QIODevice::ReadWrite))
    {
        QTextStream stream(&ReceptionFile); //创建QTextStream对象，并将其与打开的QFile对象关联起来


        //读取文件中的每一行数据到ReceptionList中，直至文件最后
        while(!stream.atEnd())
        {
            ReceptionList.push_back(stream.readLine());
        }

        ReceptionFile.close();  //关闭文件


        int nrow=ReceptionList.size();//创建int类型变量获取ReceptionList中行数

        //ReceptionList中存在元素时，将元素保存到QVector容器中
        if(!ReceptionList.empty())
        {
            //new一个地址，存放QVector，QVector中存放CReception类型的数据
            QVector<CReception> *p_ReceptionData=new QVector<CReception>;

            //创建CReception类型变量，用于临时储存读出来的数据
            CReception Reception_temp;

             //逐行读出数据并将CReception类型数据保存到QVector容器中
            for(int i=0;i<nrow;i++)
            {
                QString str=ReceptionList.at(i);    //读取第i行的数据
                QStringList qslist=str.split(",");  //去除分隔符号","

                Reception_temp.SetPatientName(qslist.at(0));            //读取第i行第1个数据
                Reception_temp.SetPatientGender(qslist.at(1));          //读取第i行第2个数据
                Reception_temp.SetPatientAge(qslist.at(2).toInt());     //读取第i行第3个数据
                Reception_temp.SetPatientPhone(qslist.at(3));           //读取第i行第4个数据
                /////////////////////////////////////////////////////
                Reception_temp.SetOutpatientID(qslist.at(4).toInt());   //读取第i行第5个数据
                Reception_temp.SetOutpatientName(qslist.at(5));         //读取第i行第6个数据
                Reception_temp.SetDoctorID(qslist.at(6).toInt());       //读取第i行第7个数据
                Reception_temp.SetReceptionDate(QDate::fromString(qslist.at(7),"yyyy-MM-dd"));  //读取第i行第8个数据
                Reception_temp.SetReceptionTime(qslist.at(8));          //读取第i行第9个数据
                Reception_temp.SetCapacity(qslist.at(9).toInt());       //读取第i行第10个数据
                Reception_temp.SetOutpatientAddress(qslist.at(10));     //读取第i行第11个数据
                Reception_temp.SetOutpatientPhone(qslist.at(11));       //读取第i行第12个数据

                p_ReceptionData->append(Reception_temp);    //将CReception数据保存至QVector容器中
            }

            return *p_ReceptionData;    //返回存放所有预约信息的容器
        }
    }
}




/***********************************************************
Name: isFileExist
Inputs: const QString &filepath - 文件名称
Return Value: bool
Description: 判断想打开的文件是否存在、是否能打开、是否为空
************************************************************/
bool ReceptionInfoTable::isFileExist(const QString &filepath)
{
    QString FILE_PATH(filepath);    //定义QString类型的变量FILE_PATH，并将其初始化为FilePath
    QFile ReceptionFile(FILE_PATH); //创建QFile对象ReceptionFile，并将FILE_PATH作为构造函数的参数传入,初始化文件路径


    //如果文件不存在，则返回false
    if(!ReceptionFile.exists())
    {
        return false;
    }

    //如果文件无法打开，则返回false
    if(!ReceptionFile.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        return false;
    }
    else//如果文件存在且可以打开，判断文件内内容是否为空
    {
        //若文件大小大于0，代表文件中有内容，则返回bool值true
        //若文件大小等于0，代表文件为空，则返回bool值true
        bool bexist=(ReceptionFile.size()>0);
        ReceptionFile.close();  //关闭文件
        return bexist;           //返回bool值exist，true代表文件中有内容，false代表文件为空
    }

}
