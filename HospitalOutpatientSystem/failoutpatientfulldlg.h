//***************************************************
//文件名 ：        failoutpatientfulldlg.h
//版本 ：                   5.0
//目的及主要功能 ：     提示门诊已满对话框
//创建日期 ：            2024.08.26
//修改日期 ：            2024.09.11
//作者 ：                 Ada Cao
//联系方式 ：         2928588633@qq.com
//***************************************************



#ifndef FAILOUTPATIENTFULLDLG_H
#define FAILOUTPATIENTFULLDLG_H

#include <QDialog>

namespace Ui {
class FailOutpatientFullDlg;
}

class FailOutpatientFullDlg : public QDialog
{
    Q_OBJECT

public:
    explicit FailOutpatientFullDlg(QWidget *parent = nullptr);  //FailOutpatientFullDlg的构造函数
    ~FailOutpatientFullDlg();                                   //FailOutpatientFullDlg的析构函数

private:
    Ui::FailOutpatientFullDlg *ui;
};

#endif // FAILOUTPATIENTFULLDLG_H
