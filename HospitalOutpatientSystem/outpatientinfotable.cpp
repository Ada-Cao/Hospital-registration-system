//***************************************************
//文件名 ：        outpatientinfotable.cpp
//版本 ：                   5.0
//目的及主要功能 ：     负责门诊信息存读的类
//创建日期 ：            2024.08.26
//修改日期 ：            2024.09.11
//作者 ：                 Ada Cao
//联系方式 ：         2928588633@qq.com
//***************************************************



#include "outpatientinfotable.h"

OutpatientInfotable::OutpatientInfotable() {}



/*************************************************
Name: SaveOutpatientToFile
Inputs: CHospitalOutpatient Outpatient - 门诊信息
        QString FileUse - 文件用途
Return Value: none
Description: 将门诊信息保存在文件中
*************************************************/
void OutpatientInfotable::SaveOutpatientToFile(CHospitalOutpatient Outpatient,QString FileUse)
{
    QString strFilePath;    //创建QString类型的数据接收文件路径

    //如果输入的文件用途是“ManageOutpatient”，则打开“门诊信息.csv”
    if(FileUse=="ManageOutpatient")
    {
        strFilePath=qApp->applicationDirPath()+"/门诊信息.csv";    //获取文件的路径
        //qApp->applicationDirPath()获取到当前.exe执行程序所在的路径
    }
    //如果输入的文件用途是“FindOutpatient”，则打开“temp个人预约查找.csv”
    else if(FileUse=="FindOutpatient")
    {
        strFilePath=qApp->applicationDirPath()+"/temp个人预约查找.csv";  //获取文件的路径
        //qApp->applicationDirPath()获取到当前.exe执行程序所在的路径
    }


    QFile OutpatientFile(strFilePath);//创建QFile对象OutpatientFile，并将strFilePath作为构造函数的参数传入,初始化文件路径


    //如果可以打开文件并向内追加写入信息
    if(OutpatientFile.open(QIODevice::Append|QIODevice::WriteOnly))//打开文件并向内追加写入信息
    {
        QTextStream stream(&OutpatientFile);    //创建QTextStream对象，并将其与打开的QFile对象关联起来

        //依次向文件中传输信息，并用逗号分隔开
        stream<<Outpatient.GetOutpatientID()<< ","           //输入门诊号
               <<Outpatient.GetOutpatientName()<< ","        //输入门诊名
               <<Outpatient.GetDoctorID()<< ","              //输入值班医生工号
               <<Outpatient.GetReceptionDate().toString("yyyy-MM-dd")<< ","  //输入接诊日期
               <<Outpatient.GetReceptionTime()<< ","         //输入接诊时间
               <<Outpatient.GetCapacity()<< ","              //输入容量
               <<Outpatient.GetOutpatientAddress()<< ","     //输入门诊地址
               <<Outpatient.GetOutpatientPhone()<< "\n" ;    //输入门诊联系电话并换行

        stream.flush(); //文件刷新
    }

    OutpatientFile.close(); //文件关闭
}




//在文件中读取保存的数据
/***********************************************************************
Name: ReadPatientFromFile
Inputs: QString FileUse - 文件用途
Return Value: QVector<CHospitalOutpatient> *p_OutpatientData - 门诊信息
Description: 将门诊信息从文件中读出
************************************************************************/
QVector<CHospitalOutpatient> OutpatientInfotable::ReadOutpatientFromFile(QString FileUse)//将门诊信息从文件中读出
{
    QString FilePath;   //创建QString类型的数据接收文件路径

    //如果输入的文件用途是“ManageOutpatient”，则打开“门诊信息.csv”
    if(FileUse=="ManageOutpatient")
    {
        FilePath=qApp->applicationDirPath()+"/门诊信息.csv";    //获取文件的路径
        //qApp->applicationDirPath()获取到当前.exe执行程序所在的路径
    }
    //如果输入的文件用途是“FindOutpatient”，则打开“temp个人预约查找.csv”
    else if(FileUse=="FindOutpatient")
    {
        FilePath=qApp->applicationDirPath()+"/temp个人预约查找.csv";  //获取文件的路径
        //qApp->applicationDirPath()获取到当前.exe执行程序所在的路径
    }

    QString FILE_PATH(FilePath);     //定义QString类型的变量FILE_PATH，并将其初始化为FilePath
    QFile OutpatientFile(FILE_PATH); //创建QFile对象OutpatientFile，并将FILE_PATH作为构造函数的参数传入,初始化文件路径
    QStringList OutpatientList;      //创建存放字符串的列表类QStringList
    OutpatientList.clear();          //清空OutpatientList列表中的所有元素

    //如果可以以读写的方式打开文件
    if(OutpatientFile.open(QIODevice::ReadWrite))
    {
        QTextStream stream(&OutpatientFile);     //创建QTextStream对象，并将其与打开的QFile对象关联起来


        //读取文件中的每一行数据到OutpatientList中，直至文件最后
        while(!stream.atEnd())
        {
            OutpatientList.push_back(stream.readLine());
        }

        OutpatientFile.close(); //关闭文件


        int nrow=OutpatientList.size();//创建int类型变量获取OutpatientList中行数

        //OutpatientList中存在元素时，将元素保存到QVector容器中
        if(!OutpatientList.empty())
        {
            //new一个地址，存放QVector，QVector中存放CHospitalOutpatient类型的数据
            QVector<CHospitalOutpatient> *p_OutpatientData=new QVector<CHospitalOutpatient>;

            //创建CHospitalOutpatient类型变量，用于临时储存读出来的数据
            CHospitalOutpatient Outpatient_temp;

            //逐行读出数据并将CHospitalOutpatient类型数据保存到QVector容器中
            for(int i=0;i<nrow;i++)
            {
                QString str=OutpatientList.at(i);   //读取第i行的数据
                QStringList qslist=str.split(",");  //去除分隔符号","

                Outpatient_temp.SetOutpatientID(qslist.at(0).toInt());  //读取第i行第1个数据
                Outpatient_temp.SetOutpatientName(qslist.at(1));        //读取第i行第2个数据
                Outpatient_temp.SetDoctorID(qslist.at(2).toInt());      //读取第i行第3个数据
                Outpatient_temp.SetReceptionDate(QDate::fromString(qslist.at(3),"yyyy-MM-dd")); //读取第i行第4个数据
                Outpatient_temp.SetReceptionTime(qslist.at(4));         //读取第i行第5个数据
                Outpatient_temp.SetCapacity(qslist.at(5).toInt());      //读取第i行第6个数据
                Outpatient_temp.SetOutpatientAddress(qslist.at(6));     //读取第i行第7个数据
                Outpatient_temp.SetOutpatientPhone(qslist.at(7));       //读取第i行第7个数据

                p_OutpatientData->append(Outpatient_temp);    //将CHospitalOutpatient数据保存至QVector容器中
            }

            return *p_OutpatientData;   //返回存放所有门诊信息的容器
        }
    }
}





/***********************************************************
Name: isFileExist
Inputs: const QString &filepath - 文件名称
Return Value: bool
Description: 判断想打开的文件是否存在、是否能打开、是否为空
************************************************************/
bool OutpatientInfotable::isFileExist(const QString &filepath)
{
    QString FILE_PATH(filepath);     //定义QString类型的变量FILE_PATH，并将其初始化为FilePath
    QFile OutpatientFile(FILE_PATH); //创建QFile对象PatientFile，并将FILE_PATH作为构造函数的参数传入,初始化文件路径


    //如果文件不存在，则返回false
    if(!OutpatientFile.exists())
    {
        return false;
    }

    //如果文件无法打开，则返回false
    if(!OutpatientFile.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        return false;
    }
    else//如果文件存在且可以打开，判断文件内内容是否为空
    {
        //若文件大小大于0，代表文件中有内容，则返回bool值true
        //若文件大小等于0，代表文件为空，则返回bool值true
        bool exist=(OutpatientFile.size()>0);
        OutpatientFile.close();  //关闭文件
        return exist;            //返回bool值exist，true代表文件中有内容，false代表文件为空
    }

}





/****************************
Name: MinusCapacity
Inputs: int index - 门诊序号
Return Value: bool
Description: 减少指定门诊容量
****************************/
void OutpatientInfotable::MinusCapacity(int index)
{
    //创建Vector容器存放文件中的所有门诊信息
    QVector<CHospitalOutpatient> Outpatients=this->ReadOutpatientFromFile("ManageOutpatient");

    //创建int类型变量储存指定门诊原容量
    int OldCapacity=Outpatients[index].GetCapacity();
    //创建int类型变量储存指定门诊现容量
    int NewCapacity=OldCapacity-1;
    //将门诊容量设置为现容量
    Outpatients[index].SetCapacity(NewCapacity);

    //计算Vector容器中门诊的个数
    QVector<CHospitalOutpatient>::size_type OutpatientNumber=this->ReadOutpatientFromFile("ManageOutpatient").size();

    QString FilePath;    //创建QString类型的数据接收文件路径
    FilePath=qApp->applicationDirPath()+"/门诊信息.csv";    //获取文件的路径
    //qApp->applicationDirPath()获取到当前.exe执行程序所在的路径

    QString FILE_PATH(FilePath);         //定义QString类型的变量FILE_PATH，并将其初始化为FilePath
    QFile FindPatientFile(FILE_PATH);    //创建QFile对象FindPatientFile，并将FILE_PATH作为构造函数的参数传入,初始化文件路径
    FindPatientFile.resize(0);           //将文件中保存的门诊信息清空

    //逐个将Vector容器中的门诊信息保存到文件中
    for(int i=0;i<OutpatientNumber;++i)
    {
       this->SaveOutpatientToFile(Outpatients.at(i),"ManageOutpatient");
    }
}



/****************************
Name: PlusCapacity
Inputs: int index - 门诊序号
Return Value: bool
Description: 增加指定门诊容量
****************************/
void OutpatientInfotable::PlusCapacity(int index)
{
    //创建Vector容器存放文件中的所有门诊信息
    QVector<CHospitalOutpatient> Outpatients=this->ReadOutpatientFromFile("ManageOutpatient");

    //创建int类型变量储存指定门诊原容量
    int OldCapacity=Outpatients[index].GetCapacity();
    //创建int类型变量储存指定门诊现容量
    int NewCapacity=OldCapacity+1;
    //将门诊容量设置为现容量
    Outpatients[index].SetCapacity(NewCapacity);


    //计算Vector容器中门诊的个数
    QVector<CHospitalOutpatient>::size_type OutpatientNumber=this->ReadOutpatientFromFile("ManageOutpatient").size();

    QString FilePath;   //创建QString类型的数据接收文件路径
    FilePath=qApp->applicationDirPath()+"/门诊信息.csv";    //获取文件的路径
    //qApp->applicationDirPath()获取到当前.exe执行程序所在的路径

    QString FILE_PATH(FilePath);        //定义QString类型的变量FILE_PATH，并将其初始化为FilePath
    QFile FindPatientFile(FILE_PATH);   //创建QFile对象FindPatientFile，并将FILE_PATH作为构造函数的参数传入,初始化文件路径
    FindPatientFile.resize(0);          //将文件中保存的门诊信息清空

    //逐个将Vector容器中的门诊信息保存到文件中
    for(int i=0;i<OutpatientNumber;++i)
    {
        this->SaveOutpatientToFile(Outpatients.at(i),"ManageOutpatient");
    }
}




/***********************************************************
Name: SortOutpatients
Inputs: QString FileUse - 文件用途
Return Value: none
Description: 按接诊日期和时间的顺序调整预约信息的显示
************************************************************/
void OutpatientInfotable::SortOutpatients(QString FileUse)
{
    OutpatientInfotable OutInfo;   //实例化OutpatientInfotable
    //创建Vector容器存放文件中记录的门诊
    QVector<CHospitalOutpatient> Outpatients=OutInfo.ReadOutpatientFromFile(FileUse);
    //计算预约的个数
    QVector<CHospitalOutpatient>::size_type OutpatientNumber=Outpatients.size();

    //冒泡排序，将门诊信息按时间顺序排序
    for(int i=0;i<OutpatientNumber-1;++i)
    {
        for(int j=0;j<OutpatientNumber-1-i;++j)
        {
            //将QDate类型的年月日转换成int类型的数据，便于比较大小
            int Date_Previous=Outpatients[j].GetReceptionDate().year()*10000+Outpatients[j].GetReceptionDate().month()*100+Outpatients[j].GetReceptionDate().day();
            int Date_Last=Outpatients[j+1].GetReceptionDate().year()*10000+Outpatients[j+1].GetReceptionDate().month()*100+Outpatients[j+1].GetReceptionDate().day();

            //如果第j个门诊的时间比第j+1个数晚，则将二者的位置进行交换
            //如果第j个门诊的日期比第j+1个晚
            if(Date_Previous>Date_Last)
            {
                //交换
                CHospitalOutpatient temp_Outpatient=Outpatients[j];
                Outpatients[j]=Outpatients[j+1];
                Outpatients[j+1]=temp_Outpatient;
            }
            else if(Date_Previous==Date_Last)//如果两个门诊日期相同，则比较时间（上午、下午）
            {
                //如果前一个门诊的时间晚于后一个门诊的时间
                if(Outpatients[j].GetReceptionTime()=="下午" && Outpatients[j+1].GetReceptionTime()=="上午")
                {
                    //交换
                    CHospitalOutpatient temp_Outpatient=Outpatients[j];
                    Outpatients[j]=Outpatients[j+1];
                    Outpatients[j+1]=temp_Outpatient;
                }
            }
        }
    }


    //创建QString类型变量储存文件路径
    QString strFilePath;

    //若用途为管理门诊，则将文件路径设置为“门诊信息”
    if(FileUse=="ManageOutpatient")
    {
        strFilePath=qApp->applicationDirPath()+"/门诊信息.csv";
    }
    else if(FileUse=="FindOutpatient")//若用途为查找门诊，则将文件路径设置为“temp个人预约查找”
    {
        strFilePath=qApp->applicationDirPath()+"/temp个人预约查找.csv";
    }

    QFile OutpatientFile(strFilePath);  //将文件路径设置为strFilePath
    OutpatientFile.resize(0);           //清空储存在文件中的旧数据，方便新数据的导入


    //依次向文件中写入排好序的门诊信息
    for(int i=0;i<OutpatientNumber;++i)
    {
        this->SaveOutpatientToFile(Outpatients[i],FileUse);
    }

}
