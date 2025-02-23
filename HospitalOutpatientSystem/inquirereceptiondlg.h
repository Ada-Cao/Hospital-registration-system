//***************************************************
//文件名 ：        inquirereceptiondlg.h
//版本 ：                   5.0
//目的及主要功能 ：      查询预约对话框
//创建日期 ：            2024.08.26
//修改日期 ：            2024.09.11
//作者 ：                 Ada Cao
//联系方式 ：         2928588633@qq.com
//***************************************************



#ifndef INQUIRERECEPTIONDLG_H
#define INQUIRERECEPTIONDLG_H

#include <QDialog>

#include "addpatientdlg.h"
#include "hospitalinfotable.h"
#include "outpatientinfotable.h"
#include "receptioninfotable.h"
#include "searchbyoutpatientdlg.h"
#include "searchbypatientnamedlg.h"
#include"deletereceptiondlg.h"
#include "failfindreceptiondlg.h"
#include "successdeletereeptiondlg.h"


namespace Ui {
class InquireReceptionDlg;
}

class InquireReceptionDlg : public QDialog
{
    Q_OBJECT

//成员函数
public:
    explicit InquireReceptionDlg(QWidget *parent = nullptr);    //InquireReceptionDlg的构造函数
    ~InquireReceptionDlg();                                     //InquireReceptionDlg的析构函数

    QString ReturnSelectOutpatientName();   //返回用户选择的门诊名称
    QDate ReturnSelectReceptionDate();      //返回用户选择的就诊日期
    QString ReturnSelectReceptionTime();    //返回用户选择的就诊时间
    QString ReturnSelectPatientName();      //返回用户选择的就诊人姓名
    QString ReturnSelectPatientPhone();     //返回用户选择的就诊人联系电话

    void SetRowData(QVector<CReception> Receptioins,int index);     //将预约信息显示在列表上


//成员属性
    QVector<CPatient> ReturnPatientsbyOutpatient();                             //创建存放CPatient的Vector容器
    QVector<CHospitalOutpatient> ReturnOutpatientsbyPatient(QString SearchBy);  //创建存放CHospitalOutpatient的Vector容器


private slots:
    void on_pushButton_SearchByOutpatient_clicked();    //“按门诊信息查询”的槽函数

    void on_pushButton_SearchByPatientName_clicked();   //“按就诊人姓名查询”的槽函数

    void on_pushButton_SearchByPatientPhone_clicked();  //“按就诊人电话”的槽函数

    void on_pushButton_DeleteReception_clicked();       //“取消预约”的槽函数

private:
    Ui::InquireReceptionDlg *ui;
};

#endif // INQUIRERECEPTIONDLG_H
