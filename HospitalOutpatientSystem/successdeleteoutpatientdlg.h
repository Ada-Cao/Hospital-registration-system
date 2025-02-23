//***************************************************
//文件名 ：        successdeleteoutpatientdlg.h
//版本 ：                   5.0
//目的及主要功能 ：   显示成功删除门诊对话框
//创建日期 ：            2024.08.26
//修改日期 ：            2024.09.11
//作者 ：                 Ada Cao
//联系方式 ：         2928588633@qq.com
//***************************************************



#ifndef SUCCESSDELETEOUTPATIENTDLG_H
#define SUCCESSDELETEOUTPATIENTDLG_H

#include <QDialog>

namespace Ui {
class SuccessDeleteOutpatientDlg;
}

class SuccessDeleteOutpatientDlg : public QDialog
{
    Q_OBJECT

public:
    explicit SuccessDeleteOutpatientDlg(QWidget *parent = nullptr);
    ~SuccessDeleteOutpatientDlg();

private:
    Ui::SuccessDeleteOutpatientDlg *ui;
};

#endif // SUCCESSDELETEOUTPATIENTDLG_H
