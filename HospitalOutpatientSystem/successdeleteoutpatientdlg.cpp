//***************************************************
//文件名 ：        successdeleteoutpatientdlg.h
//版本 ：                   5.0
//目的及主要功能 ：   显示成功删除门诊对话框
//创建日期 ：            2024.08.26
//修改日期 ：            2024.09.11
//作者 ：                 Ada Cao
//联系方式 ：         2928588633@qq.com
//***************************************************


#include "successdeleteoutpatientdlg.h"
#include "ui_successdeleteoutpatientdlg.h"

SuccessDeleteOutpatientDlg::SuccessDeleteOutpatientDlg(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SuccessDeleteOutpatientDlg)
{
    ui->setupUi(this);
}

SuccessDeleteOutpatientDlg::~SuccessDeleteOutpatientDlg()
{
    delete ui;
}
