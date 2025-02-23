//***************************************************
//文件名 ：        failfindoutpatientdlg.cpp
//版本 ：                   5.0
//目的及主要功能 ：   提示未找到相应门诊对话框
//创建日期 ：            2024.08.26
//修改日期 ：            2024.09.11
//作者 ：                 Ada Cao
//联系方式 ：         2928588633@qq.com
//***************************************************



#include "failfindoutpatientdlg.h"
#include "ui_failfindoutpatientdlg.h"

FailFindOutpatientDlg::FailFindOutpatientDlg(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::FailFindOutpatientDlg)
{
    ui->setupUi(this);
}

FailFindOutpatientDlg::~FailFindOutpatientDlg()
{
    delete ui;
}
