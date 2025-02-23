//***************************************************
//文件名 ：      successaddappointmentdlg.h
//版本 ：                   5.0
//目的及主要功能 ：     显示成功预约对话框
//创建日期 ：            2024.08.26
//修改日期 ：            2024.09.11
//作者 ：                 Ada Cao
//联系方式 ：         2928588633@qq.com
//***************************************************



#ifndef SUCCESSADDAPPOINTMENTDLG_H
#define SUCCESSADDAPPOINTMENTDLG_H

#include <QDialog>

namespace Ui {
class SuccessAddAppointmentDlg;
}

class SuccessAddAppointmentDlg : public QDialog
{
    Q_OBJECT

public:
    explicit SuccessAddAppointmentDlg(QWidget *parent = nullptr);   //SuccessAddAppointmentDlg的构造函数
    ~SuccessAddAppointmentDlg();                                    //SuccessAddAppointmentDlg的析构函数

private:
    Ui::SuccessAddAppointmentDlg *ui;
};

#endif // SUCCESSADDAPPOINTMENTDLG_H
