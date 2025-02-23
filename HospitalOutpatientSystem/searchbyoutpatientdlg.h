//***************************************************
//文件名 ：        searchbyoutpatientdlg.h
//版本 ：                   5.0
//目的及主要功能 ：根据输入门诊信息查询预约情况对话框
//创建日期 ：            2024.08.26
//修改日期 ：            2024.09.11
//作者 ：                 Ada Cao
//联系方式 ：         2928588633@qq.com
//***************************************************



#ifndef SEARCHBYOUTPATIENTDLG_H
#define SEARCHBYOUTPATIENTDLG_H

#include <QDialog>

#include "inquirereceptiondlg.h"


namespace Ui {
class SearchByOutpatientDlg;
}

class SearchByOutpatientDlg : public QDialog
{
    Q_OBJECT

//成员函数
public:
    explicit SearchByOutpatientDlg(QWidget *parent = nullptr);  //SearchByOutpatientDlg的构造函数
    ~SearchByOutpatientDlg();                                   //SearchByOutpatientDlg的析构函数

    void SetRowData(QVector<CPatient> Patients,int index);      //将病人信息显示在列表上

private:
    Ui::SearchByOutpatientDlg *ui;
};

#endif // SEARCHBYOUTPATIENTDLG_H
