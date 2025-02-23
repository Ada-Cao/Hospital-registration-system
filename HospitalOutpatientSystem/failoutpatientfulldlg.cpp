//***************************************************
//文件名 ：        failoutpatientfulldlg.cpp
//版本 ：                   5.0
//目的及主要功能 ：     提示门诊已满对话框
//创建日期 ：            2024.08.26
//修改日期 ：            2024.09.11
//作者 ：                 Ada Cao
//联系方式 ：         2928588633@qq.com
//***************************************************




#include "failoutpatientfulldlg.h"
#include "ui_failoutpatientfulldlg.h"

FailOutpatientFullDlg::FailOutpatientFullDlg(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::FailOutpatientFullDlg)
{
    ui->setupUi(this);
}

FailOutpatientFullDlg::~FailOutpatientFullDlg()
{
    delete ui;
}
