//***************************************************
//文件名 ：          deletepatientdlg.h
//版本 ：                   5.0
//目的及主要功能 ：    删除就诊人信息对话框
//创建日期 ：            2024.08.26
//修改日期 ：            2024.09.11
//作者 ：                 Ada Cao
//联系方式 ：         2928588633@qq.com
//***************************************************



#ifndef DELETEPATIENTDLG_H
#define DELETEPATIENTDLG_H

#include <QDialog>
#include"cpatient.h"
#include"hospitalinfotable.h"
#include "outpatientinfotable.h"
#include "receptioninfotable.h"

namespace Ui {
class DeletePatientDlg;
}

class DeletePatientDlg : public QDialog
{
    Q_OBJECT

//成员函数
public:
    explicit DeletePatientDlg(QWidget *parent = nullptr);   //DeletePatientDlg的构造函数
    ~DeletePatientDlg();                                    //DeletePatientDlg的析构函数

    int ReturnDeleteIndex();    //返回选择删除的就诊人编号
    void DeleteItsReception();  //删除该就诊人的预约信息

private:
    Ui::DeletePatientDlg *ui;
};

#endif // DELETEPATIENTDLG_H
