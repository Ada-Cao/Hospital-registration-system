//***************************************************
// 文件名 ：            mainwindow.cpp
//版本 ：                   5.0
//目的及主要功能 ：        主对话框
//创建日期 ：            2024.08.26
//修改日期 ：            2024.09.11
//作者 ：                 Ada Cao
//联系方式 ：         2928588633@qq.com
//***************************************************



#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //设置窗口的背景图片
    QString FilePath;   //创建QString类型的数据接收图片路径
    FilePath=qApp->applicationDirPath()+"/Hospital.jpg";    //获取图片的路径
    bgImage.load(FilePath);     // 加载背景图片

    //通过指针创建登录界面类的对象
    m_log=new LogWidget;
    //调用登录窗口，显示登录界面
    m_log->show();
    //建立信号槽，接收到登录界面的登录信号后，调出主窗口
    connect(m_log,SIGNAL(login()),this,SLOT(show()));
}



/********************************
Name: paintEvent
Inputs: QPaintEvent *event
Return Value: none
Description: //重载paintEvent函数
********************************/
void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    //计算目标矩形和源矩形
    QRect targetRect(0, 0, width(), height());                  //目标矩形为窗口大小
    QRect sourceRect(0, 0, bgImage.width(), bgImage.height());  //源矩形为图片大小

    //保持宽高比的缩放
    QSize scaledSize = bgImage.size();                          //获取原始图像大小
    scaledSize.scale(targetRect.size(), Qt::KeepAspectRatio);   //按窗口大小调整

    //计算源矩形的中心位置
    QRect scaledRect(QPoint(0, 0), scaledSize); //创建缩放矩形，初始位置在 (0, 0)
    scaledRect.moveCenter(sourceRect.center()); //将缩放矩形的中心点对齐到源矩形的中心点

    //绘制背景图片
    painter.drawPixmap(targetRect, bgImage, scaledRect);
}



/*************************************************
Name: on_pushButton_PatientInfo_clicked
Inputs: none
Return Value: none
Description: “就诊人信息”的槽函数
*************************************************/
void MainWindow::on_pushButton_PatientInfo_clicked()
{
    AddpatientDlg PatientAdd(this);     //实例化AddpatientDlg
    int ret =PatientAdd.exec();         //以模态方式显示对话框

    if(ret==QDialog::Accepted)//OK按钮被按下
    {

        PatientAdd.ModifyReception();   //在预约信息中同步修改就诊人信息
        PatientAdd.SaveTableToFile();   //将现在表格中的信息保存到文件中，用于修改就诊人

        //如果用户没有在textedit中输入内容，则不要新添加就诊人信息
        if(PatientAdd.ReturnPatientName().isEmpty()||PatientAdd.ReturnPatientAge()==0||PatientAdd.ReturnPatientPhone().isEmpty())
        {
            return;
        }

        //如果用户在textedit中输入内容，则新添加就诊人信息
        //创建保存就诊人信息的临时变量
        CPatient tempPatient;
        tempPatient.SetPatientName(PatientAdd.ReturnPatientName());     //将输入的就诊人姓名保存到临时就诊人类中
        tempPatient.SetPatientGender(PatientAdd.ReturnPatientGender()); //将输入的就诊人性别保存到临时就诊人类中
        tempPatient.SetPatientAge(PatientAdd.ReturnPatientAge());       //将输入的就诊人年龄保存到临时就诊人类中
        tempPatient.SetPatientPhone(PatientAdd.ReturnPatientPhone());   //将输入的就诊人电话保存到临时就诊人类中

        PatientAdd.Patients.append(tempPatient);        //将就诊人信息保存到Vector容器中
        PatientAdd.SetRowData(PatientAdd.Patients,0);   //将保存的就诊人信息展示到表格中

        HospitalInfoTable Hospinfo; //实例化HospitalInfoTable
        Hospinfo.SavePatientToFile(tempPatient,"ManagePatient");    //将就诊人信息保存到文件中
    }

}



/*************************************************
Name: on_pushButton_Appointment_clicked
Inputs: none
Return Value: none
Description: “开始预约”的槽函数
*************************************************/
void MainWindow::on_pushButton_Appointment_clicked()
{
    AppointInfoTable Appinfo;   //实例化AppointInfoTable
    OutpatientInfotable Outinfo;//实例化OutpatientInfotable

    AppointmentDlg Appointment(this);   //实例化AppointmentDlg
    int ret=Appointment.exec(); //以模态方式显示对话框

    if(ret==QDialog::Accepted)  //OK按钮被按下
    {
        //如果选择预约的门诊存在
        if(Appointment.SelectOutpatientTrue()>=0)
        {
            //如果预约的门诊容量未满
            if(!Appointment.SelectOutpatientFull())
            {
                //创建int类型变量，返回就诊人在QVector容器中的序号
                int nPatientIndex=Appointment.SelectPatient();
                //创建就诊人类保存选中的就诊人类
                CPatient SelectPatient=Appinfo.ReadPatientFromFile().at(nPatientIndex);

                //创建int类型变量，返回门诊在QVector容器中的序号
                int nOutpatientIndex=Appointment.SelectOutpatientTrue();
                //创建门诊类保存所选的门诊类
                CHospitalOutpatient SelectOutpatient=Appinfo.ReadOutpatientFromFile().at(nOutpatientIndex);

                //创建预约类，用于临时保存预约信息
                CReception tempReception;
                tempReception.SetPatientName(SelectPatient.GetPatientName());           //将该条预约信息的就诊人名字保存至临时变量中
                tempReception.SetPatientGender(SelectPatient.GetPatientGender());       //将该条预约信息的就诊人性别保存至临时变量中
                tempReception.SetPatientAge(SelectPatient.GetPatientAge());             //将该条预约信息的就诊人年龄保存至临时变量中
                tempReception.SetPatientPhone(SelectPatient.GetPatientPhone());         //将该条预约信息的就诊人联系方式保存至临时变量中
                //***************************************************************//
                tempReception.SetOutpatientID(SelectOutpatient.GetOutpatientID());      //将该条预约信息的门诊号保存至临时变量中
                tempReception.SetOutpatientName(SelectOutpatient.GetOutpatientName());  //将该条预约信息的门诊名保存至临时变量中
                tempReception.SetDoctorID(SelectOutpatient.GetDoctorID());              //将该条预约信息的值班医生工号保存至临时变量中
                tempReception.SetReceptionDate(SelectOutpatient.GetReceptionDate());    //将该条预约信息的接诊日期保存至临时变量中
                tempReception.SetReceptionTime(SelectOutpatient.GetReceptionTime());    //将该条预约信息的接诊时间保存至临时变量中
                tempReception.SetCapacity(SelectOutpatient.GetCapacity());              //将该条预约信息的容量保存至临时变量中
                tempReception.SetOutpatientAddress(SelectOutpatient.GetOutpatientAddress());//将该条预约信息的门诊地址保存至临时变量中
                tempReception.SetOutpatientPhone(SelectOutpatient.GetOutpatientPhone());//将该条预约信息的门诊联系电话保存至临时变量中

                ReceptionInfoTable RecepInfo;   //实例化ReceptionInfoTable
                RecepInfo.SaveReceptionToFile(tempReception);   //将临时预约类中的预约信息保存到文件中

                Outinfo.MinusCapacity(nOutpatientIndex);    //预约成功后，将预约门诊的容量-1

                //弹出对话框，提示预约成功
                SuccessAddAppointmentDlg SuccessAdd(this);  //实例化SuccessAddAppointmentDlg
                SuccessAdd.exec();  //以模态方式显示对话框
            }
            else
            {
                //弹出对话框，提示该门诊预约已满
                FailOutpatientFullDlg FailFull(this);   //实例化FailOutpatientFullDlg
                FailFull.exec();    //以模态方式显示对话框
            }
        }
        else//如果选择预约的门诊不存在，则提示未找到相应门诊信息
        {
            //弹出对话框，提示用户预约的门诊不存在
            FailFindOutpatientDlg FailFind(this);   //实例化FailFindOutpatientDlg
            FailFind.exec();    //以模态方式显示对话框
        }
    }

}



/*************************************************
Name: on_pushButton_Reception_clicked
Inputs: none
Return Value: none
Description: “查询预约信息”的槽函数
*************************************************/
void MainWindow::on_pushButton_Reception_clicked()
{
    InquireReceptionDlg ReceptionInquire(this); //实例化InquireReceptionDlg
    ReceptionInquire.exec();    //以模态方式显示对话框
}

MainWindow::~MainWindow()
{
    delete ui;
}







