//***************************************************
//文件名 ：            warningdlg.h
//版本 ：                   5.0
//目的及主要功能 ：   显示密码错误警告对话框
//创建日期 ：            2024.08.26
//修改日期 ：            2024.09.11
//作者 ：                 Ada Cao
//联系方式 ：         2928588633@qq.com
//***************************************************



#ifndef WARNINGDLG_H
#define WARNINGDLG_H

#include <QDialog>

namespace Ui {
class WarningDlg;
}

class WarningDlg : public QDialog
{
    Q_OBJECT

public:
    explicit WarningDlg(QWidget *parent = nullptr); //WarningDlg的构造函数
    ~WarningDlg();                                  //WarningDlg的析构函数

private:
    Ui::WarningDlg *ui;
};

#endif // WARNINGDLG_H
