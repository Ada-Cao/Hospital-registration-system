//***************************************************
//文件名 ：         deletereceptiondlg.h
//版本 ：                   5.0
//目的及主要功能 ：     取消预约信息对话框
//创建日期 ：            2024.08.26
//修改日期 ：            2024.09.11
//作者 ：                 Ada Cao
//联系方式 ：         2928588633@qq.com
//***************************************************



#ifndef DELETERECEPTIONDLG_H
#define DELETERECEPTIONDLG_H

#include <QDialog>

#include"outpatientinfotable.h"
#include"hospitalinfotable.h"
#include "receptioninfotable.h"
#include"cpatient.h"
#include"chospitaloutpatient.h"



namespace Ui {
class DeleteReceptionDlg;
}

class DeleteReceptionDlg : public QDialog
{
    Q_OBJECT

public:
    explicit DeleteReceptionDlg(QWidget *parent = nullptr); //DeleteReceptionDlg的构造函数
    ~DeleteReceptionDlg();                                  //DeleteReceptionDlg的析构函数

    //成员函数
    QString ReturnSelectOutpatientName();   //返回用户删除的门诊名称
    QDate ReturnSelectReceptionDate();      //返回用户删除的就诊日期
    QString ReturnSelectReceptionTime();    //返回用户删除的就诊时间
    QString ReturnSelectPatientName();      //返回用户删除的就诊人

    //成员属性
    int SelectReceptionTrue();  //确定用户删除的门诊日期时间存在相应的预约，并找到其在Vector容器中的编号

private:
    Ui::DeleteReceptionDlg *ui;
};

#endif // DELETERECEPTIONDLG_H
