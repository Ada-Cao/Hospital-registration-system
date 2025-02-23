//***************************************************
//文件名 ：        successdeletereeptiondlg.cpp
//版本 ：                   5.0
//目的及主要功能 ：   显示成功取消预约对话框
//创建日期 ：            2024.08.26
//修改日期 ：            2024.09.11
//作者 ：                 Ada Cao
//联系方式 ：         2928588633@qq.com
//***************************************************




#include "successdeletereeptiondlg.h"
#include "ui_successdeletereeptiondlg.h"

SuccessDeleteReeptionDlg::SuccessDeleteReeptionDlg(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SuccessDeleteReeptionDlg)
{
    ui->setupUi(this);
}

SuccessDeleteReeptionDlg::~SuccessDeleteReeptionDlg()
{
    delete ui;
}
