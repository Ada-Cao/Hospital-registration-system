//***************************************************
//文件名 ：             logwidget.h
//版本 ：                   5.0
//目的及主要功能 ：      查询预约对话框
//创建日期 ：            2024.08.26
//修改日期 ：            2024.09.11
//作者 ：                 Ada Cao
//联系方式 ：         2928588633@qq.com
//***************************************************


#ifndef LOGWIDGET_H
#define LOGWIDGET_H

#include <QWidget>
#include<QMessageBox>
#include<QJsonDocument>
#include<QJsonObject>
#include<QFile>
#include<QByteArray>



namespace Ui {
class LogWidget;
}

class LogWidget : public QWidget
{
    Q_OBJECT

//成员函数
public:
    explicit LogWidget(QWidget *parent = nullptr);  //LogWidget的构造函数
    ~LogWidget();   //LogWidget的析构函数

    void ReadJson();    //读取Json文件中的内容
    void WriteJson();   //向Json文件中写入内容
    void InitialMessage(QString FlagName,QString FlagPassword);   //根据Json文件中的内容决定是否填充输入框

signals:
    void login();       //登陆主界面信号
    void close_window(); //关闭主界面信号

private slots:
    void on_pushbotton_log_clicked();   //登录按钮按下后触发的事件
    void on_pushbutton_clear_clicked(); //重置按钮按下后触发的事件

private:
    Ui::LogWidget *ui;

//成员属性
    QString m_strUsername;  //自己设定的账号
    QString m_strPassword;  //自己设定的密码
};

#endif // LOGWIDGET_H
