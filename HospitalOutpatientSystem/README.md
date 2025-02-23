# Hospital-registration-system
This is a student assignment about a hospital outpatient appointment management system based on Qt and C++.
These are the whole component of the project.

主函数文件：
 main.cpp 
普通类文件：
 cpatient.h cpatient.cpp （就诊人类）
 chospitaloutpatient.h chospitaloutpatient.cpp （门诊类）
 creception.h creception.cpp （预约类）
对话框+控件文件：
 logwidget.h logwidget.cpp logwidget.ui （登录界面）
 mainwindow.h mainwindow.cpp mainwindow.ui （主对话框）
 addpatientdlg.h addpatientdlg.cpp addpatientdlg.ui （添加就诊人）
 deletepatientdlg.h deletepatientdlg.cpp deletepatientdlg.ui （删除就诊人）
 addoutpatientdlg.h addoutpatientdlg.cpp addoutpatientdlg.ui （添加门诊）
 deleteoutpatientdlg.h deleteoutpatientdlg.cpp deleteoutpatientdlg.ui （删除门诊）
 appointmentdlg.h appointmentdlg.cpp appointmentdlg.ui （预约门诊）
 deletereceptiondlg.h deletereceptiondlg.cpp deletereceptiondlg.ui （取消预约）
 inquirereceptiondlg.h inquirereceptiondlg.cpp inquirereceptiondlg.ui （查询预约总界面）
 searchbyoutpatientdlg.h searchbyoutpatientdlg.cpp searchbyoutpatientdlg.ui 
（按门诊查询预约）
 searchbypatientnamedlg.h searchbypatientnamedlg.cpp searchbypatientnamedlg.ui 
 （按就诊人姓名查询预约）
 searchbypatientphonedlg.h searchbypatientphonedlg.cpp searchbypatientphonedlg.ui 
 （按就诊人联系方式查询预约）
 passworddlg.h passworddlg.cpp passworddlg.ui （密码输入界面）
单纯提示框文件：
 failfindoutpatientdlg.h failfindoutpatientdlg.cpp failfindoutpatientdlg.ui 
（提示未找到门诊）
 failoutpatientfulldlg.h failoutpatientfulldlg.cpp failoutpatientfulldlg.ui 
（提示想预约门诊已满）
 failfindreceptiondlg.h failfindreceptiondlg.cpp failfindreceptiondlg.ui 
（提示未找到预约）
 successaddappointmentdlg.h successaddappointmentdlg.cpp successaddappointmentdlg.ui 
（提示成功添加预约）
 successdeletepatientdlg.h successdeletepatientdlg.cpp successdeletepatientdlg.ui 
（提示成功删除就诊人）
 successdeleteoutpatientdlg.h successdeleteoutpatientdlg.cpp successdeleteoutpatientdlg.ui
（提示成功删除门诊）
 successdeletereeptiondlg.h successdeletereeptiondlg.cpp successdeletereeptiondlg.ui 
（提示成功删除预约）
 warningdlg.h warningdlg.cpp warningdlg.ui 
（提示密码输入错误）

功能函数调用类：
 hospitalinfotable.h hospitalinfotable.cpp hospitalinfotable.ui （负责就诊人信息存读）
 outpatientinfotable.h outpatientinfotable.cpp outpatientinfotable.ui（负责门诊信息存读）
 appointinfotable.h appointinfotable.cpp appointinfotable.ui （负责门诊信息存读）
 receptioninfotable.h receptioninfotable.cpp receptioninfotable.ui （负责预约信息存读）

图片资源：
 HospitalImage.qrc 

类对象：
 CPatient——就诊人
成员属性：
QString m_strPatientName; //就诊人姓名 
QString m_strPatientGender; //就诊人性别 
int m_nPatientAge; //就诊人年龄 
QString m_strPatientPhone; //就诊人联系方式 
 COutpatient——门诊
成员属性：
int m_nOutpatientID; //门诊号 
QString m_strOutpatientName; //门诊名称 
int m_nDoctorID; //值班医生工号 
QDate m_dtReceptionDate; //接诊日期 
QString m_strReceptionTime; //接诊时间 
int m_nCapacity; //容量 
QString m_strOutpatientAddress; //门诊地址 
QString m_strOutpatientPhone; //门诊联系电话 
 CReception——预约
成员属性：
QString m_strPatientName; //就诊人姓名 
QString m_strPatientGender; //就诊人性别 
int m_nPatientAge; //就诊人年龄 
QString m_strPatientPhone; //就诊人联系方式 
int m_nOutpatientID; //门诊号 
QString m_strOutpatientName; //门诊名称 
int m_nDoctorID; //值班医生工号 
QDate m_dtReceptionDate; //接诊日期 
QString m_strReceptionTime; //接诊时间 
int m_nCapacity; //容量 
QString m_strOutpatientAddress; //门诊地址 
QString m_strOutpatientPhone; //门诊联系电话
