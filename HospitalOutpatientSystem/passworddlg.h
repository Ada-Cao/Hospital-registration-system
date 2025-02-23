//***************************************************
//文件名 ：            passworddlg.h
//版本 ：                   5.0
//目的及主要功能 ：      输入密码对话框
//创建日期 ：            2024.08.26
//修改日期 ：            2024.09.11
//作者 ：                 Ada Cao
//联系方式 ：         2928588633@qq.com
//***************************************************



#ifndef PASSWORDDLG_H
#define PASSWORDDLG_H

#include <QDialog>
#include<QString>
#include<QKeyEvent>
#include<QTextEdit>


#include "addoutpatientdlg.h"
#include "chospitaloutpatient.h"
#include"outpatientinfotable.h"
#include "warningdlg.h"

namespace Ui {
class PassWordDlg;
}

class PassWordDlg : public QDialog
{
    Q_OBJECT

//成员函数
public:
    explicit PassWordDlg(QWidget *parent = nullptr);    //PassWordDlg的构造函数
    ~PassWordDlg();                                     //PassWordDlg的析构函数

    QString ReturnPassword();   //返回用户输入的密码
    QString GetPassword();      //获取密码


//成员属性（受保护）
protected:
    QString m_strPassword="123456";   //管理门诊的密码  int


private slots:
    void on_pushButton_enter_clicked(); //“Enter”的槽函数

private:
    Ui::PassWordDlg *ui;
};

#endif // PASSWORDDLG_H
