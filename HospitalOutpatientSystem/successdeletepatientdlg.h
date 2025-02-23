//***************************************************
//文件名 ：        successdeletepatientdlg.h
//版本 ：                   5.0
//目的及主要功能 ：   显示成功删除就诊人对话框
//创建日期 ：            2024.08.26
//修改日期 ：            2024.09.11
//作者 ：                 Ada Cao
//联系方式 ：         2928588633@qq.com
//***************************************************




#ifndef SUCCESSDELETEPATIENTDLG_H
#define SUCCESSDELETEPATIENTDLG_H

#include <QDialog>

namespace Ui {
class SuccessDeletePatientDlg;
}

class SuccessDeletePatientDlg : public QDialog
{
    Q_OBJECT

public:
    explicit SuccessDeletePatientDlg(QWidget *parent = nullptr);    //SuccessDeletePatientDlg的构造函数
    ~SuccessDeletePatientDlg();     //SuccessDeletePatientDlg的析构函数

private:
    Ui::SuccessDeletePatientDlg *ui;
};

#endif // SUCCESSDELETEPATIENTDLG_H
