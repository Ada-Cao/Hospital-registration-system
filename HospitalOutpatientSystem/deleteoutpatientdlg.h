//***************************************************
//文件名 ：         deleteoutpatientdlg.h
//版本 ：                   5.0
//目的及主要功能 ：    删除门诊信息对话框
//创建日期 ：            2024.08.26
//修改日期 ：            2024.09.11
//作者 ：                 Ada Cao
//联系方式 ：         2928588633@qq.com
//***************************************************



#ifndef DELETEOUTPATIENTDLG_H
#define DELETEOUTPATIENTDLG_H

#include <QDialog>
#include"outpatientinfotable.h"
#include"hospitalinfotable.h"
#include"receptioninfotable.h"

namespace Ui {
class DeleteOutpatientDlg;
}

class DeleteOutpatientDlg : public QDialog
{
    Q_OBJECT


//成员函数
public:
    explicit DeleteOutpatientDlg(QWidget *parent = nullptr);    //DeleteOutpatientDlg的构造函数
    ~DeleteOutpatientDlg(); //DeleteOutpatientDlg的析构函数

    int ReturnDeleteIndex();    //返回选择删除的门诊编号
    void DeleteItsReception();  //删除门诊的同时删除其预约


private:
    Ui::DeleteOutpatientDlg *ui;
};

#endif // DELETEOUTPATIENTDLG_H
