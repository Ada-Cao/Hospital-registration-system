//***************************************************
// 文件名 ：        searchbypatientphonedlg.h
//版本 ：                   5.0
//目的及主要功能 ：根据输入就诊人电话查询预约情况对话框
//创建日期 ：            2024.08.26
//修改日期 ：            2024.09.11
//作者 ：                 Ada Cao
//联系方式 ：         2928588633@qq.com
//***************************************************



#ifndef SEARCHBYPATIENTPHONEDLG_H
#define SEARCHBYPATIENTPHONEDLG_H

#include <QDialog>
#include"outpatientinfotable.h"
#include"receptioninfotable.h"


namespace Ui {
class SearchByPatientPhoneDlg;
}

class SearchByPatientPhoneDlg : public QDialog
{
    Q_OBJECT

//成员函数
public:
    explicit SearchByPatientPhoneDlg(QWidget *parent = nullptr);    //SearchByPatientPhoneDlg的构造函数
    ~SearchByPatientPhoneDlg();                                     //SearchByPatientPhoneDlg的析构函数

    void SetRowData(QVector<CHospitalOutpatient> Outpatients,int index);    //将门诊信息显示在列表上

private:
    Ui::SearchByPatientPhoneDlg *ui;
};

#endif // SEARCHBYPATIENTPHONEDLG_H
