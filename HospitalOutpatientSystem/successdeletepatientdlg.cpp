//***************************************************
//文件名 ：        successdeletepatientdlg.cpp
//版本 ：                   5.0
//目的及主要功能 ：   显示成功删除就诊人对话框
//创建日期 ：            2024.08.26
//修改日期 ：            2024.09.11
//作者 ：                 Ada Cao
//联系方式 ：         2928588633@qq.com
//***************************************************



#include "successdeletepatientdlg.h"
#include "ui_successdeletepatientdlg.h"

SuccessDeletePatientDlg::SuccessDeletePatientDlg(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SuccessDeletePatientDlg)
{
    ui->setupUi(this);
}

SuccessDeletePatientDlg::~SuccessDeletePatientDlg()
{
    delete ui;
}
