//***************************************************
//文件名 ：             logwidget.cpp
//版本 ：                   5.0
//目的及主要功能 ：      查询预约对话框
//创建日期 ：            2024.08.26
//修改日期 ：            2024.09.11
//作者 ：                 Ada Cao
//联系方式 ：         2928588633@qq.com
//***************************************************


#include "logwidget.h"
#include "ui_logwidget.h"

LogWidget::LogWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LogWidget)
{
    ui->setupUi(this);


    //connect 3个信号槽
    //触发登录按钮的信号槽连接
    connect(ui->pushbotton_log,SIGNAL(clicked()),this,SLOT(pushbotton_log_clicked()));
    //触发重置按钮的信号槽连接
    connect(ui->pushbutton_clear,SIGNAL(clicked()),this,SLOT(pushbutton_clear_clicked()));
    //发出信号后关闭登录窗口的信号槽连接
    connect(this,SIGNAL(close_window()),this,SLOT(close()));


    //输入的时候就显示圆点，隐藏密码
    ui->lineedit_password->setEchoMode(QLineEdit::Password);
    this->m_strUsername = "User";    //设置用户名
    this->m_strPassword = "123456";   //设置密码

    this->ReadJson();   //读取Json文件,读取用户是否选择记住用户名和密码
}



/************************
Name: ReadJson
Inputs: none
Return Value: none
Description: 读取Json文件
************************/
void LogWidget::ReadJson()
{
    //用strFilePath读取Json文件的路径
    QString strFilePath=qApp->applicationDirPath()+"/RememberMessage.json";
    //将RememberFile的路径设置为strFilePath
    QFile RememberFile(strFilePath);

    //如果文件可以以只读的方式打开，则打开文件
    if(RememberFile.open(QIODevice::ReadOnly))
    {
        //读取Json文件中的所有内容，并将Json字符串转换为QJsonDocument对象
        QJsonDocument JsonDocu(QJsonDocument::fromJson(RememberFile.readAll()));
        //从QJsonDocument中提取出Json数据的结构
        QJsonObject JsonObj=JsonDocu.object();
        //从JsonObj中获取“SAVENAME”键的值，用QString类型保存
        QString strNameSaveFlag=JsonObj.value("SAVENAME").toString();
        //从JsonObj中获取“SAVEPASSWORD”键的值，用QString类型保存
        QString strPasswordSaveFlag=JsonObj.value("SAVEPASSWORD").toString();
        //将提取的值传入初始化函数，判断是否保存用户名和密码
        InitialMessage(strNameSaveFlag,strPasswordSaveFlag);
    }
}



/******************************
Name: WriteJson
Inputs: none
Return Value: none
Description: 向Json文件中写入信息
******************************/
void LogWidget::WriteJson()
{
    //用strFilePath读取Json文件的路径
    QString strFilePath=qApp->applicationDirPath()+"/RememberMessage.json";
    //将RememberFile的路径设置为strFilePath
    QFile RememberFile(strFilePath);
    //创建一个空的QJsonObject对象，用来存储将要写入JSON文件的数据
    QJsonObject JsonObj;

    //如果可以以写入的形式打开Json文件，则打开文件
    if(RememberFile.open(QIODevice::WriteOnly))
    {
        //用bool值记录用户是否勾选“记住用户名”，勾选则为true，未勾选则为false
        bool bFlagName=ui->checkbox_remembername->isChecked();
        //用bool值记录用户是否勾选“记住密码”，勾选则为true，未勾选则为false
        bool bFlagPassword=ui->checkbox_rememberpassward->isChecked();

        //如果勾选“记住用户名”
        if(bFlagName)
        {
            JsonObj["SAVENAME"]="1";    //将Json文件中“SAVENAME”键的值改为1
        }
        else//如果没有勾选“记住用户名”
        {
            JsonObj["SAVENAME"]="0";    //将Json文件中“SAVENAME”键的值改为0
        }

        //如果勾选“记住密码”
        if(bFlagPassword)
        {
            JsonObj["SAVEPASSWORD"]="1";    //将Json文件中“SAVEPASSWORD”键的值改为1
        }
        else//如果没有勾选“记住密码”
        {
            JsonObj["SAVEPASSWORD"]="0";    //将Json文件中“SAVEPASSWORD”键的值改为0
        }

        //使用JsonObj创建一个QJsonDocument对象
        QJsonDocument JsonDocu(JsonObj);
        //将JsonObj转换为Json格式的文本
        RememberFile.write(JsonDocu.toJson());
        //刷新文件
        RememberFile.flush();
    }

}




/*************************************************
Name: InitialMessage
Inputs: QString FlagName - 用户名信号
        QString FlagPassword - 密码信号
Return Value: none
Description: 根据Json文件中记录的内容决定是否填充输入框
*************************************************/
void LogWidget::InitialMessage(QString FlagName,QString FlagPassword)
{
    //如果FlagName为1，则在输入框中填充保存的用户名
    if(FlagName=="1")
    {
        //在输入框中填充保存的用户名
        ui->lineedit_name->setText("User");
        //保持“记住用户名”被勾选
        ui->checkbox_remembername->setChecked(true);
    }

    //如果FlagPassword为1，则在输入框中填充保存的用户名
    if(FlagPassword=="1")
    {
        //在输入框中填充保存的密码
        ui->lineedit_password->setText("123456");
        //保持“记住密码”被勾选
        ui->checkbox_rememberpassward->setChecked(true);
    }

}




/*******************************
Name: on_pushbotton_log_clicked
Inputs: none
Return Value: none
Description: “登录”按钮的槽函数
*******************************/
void LogWidget::on_pushbotton_log_clicked()
{
    QString strUsername=ui->lineedit_name->text();      //获取用户输入的用户名
    QString strPassword=ui->lineedit_password->text();  //获取用户输入的密码

    //如果输入的账号密码正确
    if(strUsername==this->m_strUsername && strPassword==this->m_strPassword)
    {
        emit(login());          //发出登录信号
        WriteJson();            //向Json中写入数据
        emit(close_window());   //发出关闭窗口信号
    }
    else//账号密码输入错误
    {
        //弹出警告对话框
        QMessageBox::information(this,"警告","用户名或密码输入错误");
    }

}




/***************************************
Name: on_pushbutton_clear_clicked
Inputs: none
Return Value: none
Description: “重置”按钮的槽函数，清空输入栏
***************************************/
void LogWidget::on_pushbutton_clear_clicked()
{
    ui->lineedit_name->clear();     //清除输入框中的用户名
    ui->lineedit_password->clear(); //清除输入框中的密码
}




LogWidget::~LogWidget()
{
    delete ui;
}
