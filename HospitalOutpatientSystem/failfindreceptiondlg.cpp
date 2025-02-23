//***************************************************
//文件名 ：        failfindreceptiondlg.cpp
//版本 ：                   5.0
//目的及主要功能 ：   提示未找到预约信息对话框
//创建日期 ：            2024.08.26
//修改日期 ：            2024.09.11
//作者 ：                 Ada Cao
//联系方式 ：         2928588633@qq.com
//***************************************************



#include "failfindreceptiondlg.h"
#include "ui_failfindreceptiondlg.h"

FailFindReceptionDlg::FailFindReceptionDlg(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::FailFindReceptionDlg)
{
    ui->setupUi(this);
}

FailFindReceptionDlg::~FailFindReceptionDlg()
{
    delete ui;
}
