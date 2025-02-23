//***************************************************
//文件名 ：        failfindreceptiondlg.h
//版本 ：                   5.0
//目的及主要功能 ：   提示未找到预约信息对话框
//创建日期 ：            2024.08.26
//修改日期 ：            2024.09.11
//作者 ：                 Ada Cao
//联系方式 ：         2928588633@qq.com
//***************************************************



#ifndef FAILFINDRECEPTIONDLG_H
#define FAILFINDRECEPTIONDLG_H

#include <QDialog>

namespace Ui {
class FailFindReceptionDlg;
}

class FailFindReceptionDlg : public QDialog
{
    Q_OBJECT

public:
    explicit FailFindReceptionDlg(QWidget *parent = nullptr);   //FailFindReceptionDlg的构造函数
    ~FailFindReceptionDlg();                                    //FailFindReceptionDlg的析构函数

private:
    Ui::FailFindReceptionDlg *ui;
};

#endif // FAILFINDRECEPTIONDLG_H
