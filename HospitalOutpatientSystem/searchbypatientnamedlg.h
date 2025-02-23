//***************************************************
//文件名 ：      searchbypatientnamedlg.h
//版本 ：                   5.0
//目的及主要功能 ：根据输入就诊人姓名查询预约情况对话框
//创建日期 ：            2024.08.26
//修改日期 ：            2024.09.11
//作者 ：                 Ada Cao
//联系方式 ：         2928588633@qq.com
//***************************************************



#ifndef SEARCHBYPATIENTNAMEDLG_H
#define SEARCHBYPATIENTNAMEDLG_H

#include <QDialog>
#include"outpatientinfotable.h"
#include"receptioninfotable.h"

namespace Ui {
class SearchByPatientNameDlg;
}

class SearchByPatientNameDlg : public QDialog
{
    Q_OBJECT

//成员函数
public:
    explicit SearchByPatientNameDlg(QWidget *parent = nullptr);     //SearchByPatientNameDlg的构造函数
    ~SearchByPatientNameDlg();                                      //SearchByPatientNameDlg的析构函数

    void SetRowData(QVector<CHospitalOutpatient> Outpatients,int index);    //将门诊信息显示在列表上

private:
    Ui::SearchByPatientNameDlg *ui;
};

#endif // SEARCHBYPATIENTNAMEDLG_H
