//***************************************************
//文件名 ：        failfindoutpatientdlg.h
//版本 ：                   5.0
//目的及主要功能 ：   提示未找到相应门诊对话框
//创建日期 ：            2024.08.26
//修改日期 ：            2024.09.11
//作者 ：                 Ada Cao
//联系方式 ：         2928588633@qq.com
//***************************************************



#ifndef FAILFINDOUTPATIENTDLG_H
#define FAILFINDOUTPATIENTDLG_H

#include <QDialog>

namespace Ui {
class FailFindOutpatientDlg;
}

class FailFindOutpatientDlg : public QDialog
{
    Q_OBJECT

public:
    explicit FailFindOutpatientDlg(QWidget *parent = nullptr);  //FailFindOutpatientDlg的构造函数
    ~FailFindOutpatientDlg();                                   //FailFindOutpatientDlg的析构函数

private:
    Ui::FailFindOutpatientDlg *ui;
};

#endif // FAILFINDOUTPATIENTDLG_H
