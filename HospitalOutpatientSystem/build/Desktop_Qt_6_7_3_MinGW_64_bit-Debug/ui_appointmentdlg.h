/********************************************************************************
** Form generated from reading UI file 'appointmentdlg.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APPOINTMENTDLG_H
#define UI_APPOINTMENTDLG_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_AppointmentDlg
{
public:
    QDialogButtonBox *buttonBox;
    QTableWidget *tableWidget_Outpatient;
    QPushButton *pushButton_ManageOutPatient;
    QLabel *labe_Appointment;
    QComboBox *comboBox_PatientName;
    QLabel *label_PatientName;
    QComboBox *comboBox_OutpatientName;
    QLabel *label_OutpatientName;
    QComboBox *comboBox_Time;
    QLabel *label_Time;
    QLabel *label_Date;
    QDateEdit *dateEdit_Date;
    QLabel *label_Image;

    void setupUi(QDialog *AppointmentDlg)
    {
        if (AppointmentDlg->objectName().isEmpty())
            AppointmentDlg->setObjectName("AppointmentDlg");
        AppointmentDlg->resize(1000, 700);
        buttonBox = new QDialogButtonBox(AppointmentDlg);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(390, 640, 181, 51));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);
        tableWidget_Outpatient = new QTableWidget(AppointmentDlg);
        if (tableWidget_Outpatient->columnCount() < 8)
            tableWidget_Outpatient->setColumnCount(8);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_Outpatient->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_Outpatient->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_Outpatient->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget_Outpatient->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget_Outpatient->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget_Outpatient->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget_Outpatient->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget_Outpatient->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        tableWidget_Outpatient->setObjectName("tableWidget_Outpatient");
        tableWidget_Outpatient->setGeometry(QRect(40, 70, 881, 381));
        pushButton_ManageOutPatient = new QPushButton(AppointmentDlg);
        pushButton_ManageOutPatient->setObjectName("pushButton_ManageOutPatient");
        pushButton_ManageOutPatient->setGeometry(QRect(860, 640, 100, 50));
        labe_Appointment = new QLabel(AppointmentDlg);
        labe_Appointment->setObjectName("labe_Appointment");
        labe_Appointment->setGeometry(QRect(90, 10, 151, 61));
        QFont font;
        font.setFamilies({QString::fromUtf8("Modern No. 20")});
        font.setPointSize(16);
        labe_Appointment->setFont(font);
        comboBox_PatientName = new QComboBox(AppointmentDlg);
        comboBox_PatientName->setObjectName("comboBox_PatientName");
        comboBox_PatientName->setGeometry(QRect(680, 490, 131, 41));
        QFont font1;
        font1.setPointSize(11);
        comboBox_PatientName->setFont(font1);
        label_PatientName = new QLabel(AppointmentDlg);
        label_PatientName->setObjectName("label_PatientName");
        label_PatientName->setGeometry(QRect(580, 490, 81, 31));
        QFont font2;
        font2.setPointSize(12);
        label_PatientName->setFont(font2);
        comboBox_OutpatientName = new QComboBox(AppointmentDlg);
        comboBox_OutpatientName->setObjectName("comboBox_OutpatientName");
        comboBox_OutpatientName->setGeometry(QRect(210, 490, 191, 41));
        comboBox_OutpatientName->setFont(font1);
        label_OutpatientName = new QLabel(AppointmentDlg);
        label_OutpatientName->setObjectName("label_OutpatientName");
        label_OutpatientName->setGeometry(QRect(100, 490, 81, 31));
        label_OutpatientName->setFont(font2);
        comboBox_Time = new QComboBox(AppointmentDlg);
        comboBox_Time->addItem(QString());
        comboBox_Time->addItem(QString());
        comboBox_Time->setObjectName("comboBox_Time");
        comboBox_Time->setGeometry(QRect(680, 580, 131, 41));
        comboBox_Time->setFont(font1);
        label_Time = new QLabel(AppointmentDlg);
        label_Time->setObjectName("label_Time");
        label_Time->setGeometry(QRect(580, 580, 81, 31));
        label_Time->setFont(font2);
        label_Date = new QLabel(AppointmentDlg);
        label_Date->setObjectName("label_Date");
        label_Date->setGeometry(QRect(100, 580, 81, 31));
        label_Date->setFont(font2);
        dateEdit_Date = new QDateEdit(AppointmentDlg);
        dateEdit_Date->setObjectName("dateEdit_Date");
        dateEdit_Date->setGeometry(QRect(220, 570, 131, 51));
        dateEdit_Date->setFont(font1);
        dateEdit_Date->setDateTime(QDateTime(QDate(2024, 9, 10), QTime(0, 0, 0)));
        dateEdit_Date->setDate(QDate(2024, 9, 10));
        label_Image = new QLabel(AppointmentDlg);
        label_Image->setObjectName("label_Image");
        label_Image->setGeometry(QRect(20, 10, 69, 51));
        label_Image->setStyleSheet(QString::fromUtf8("image: url(:/Outpatient.png);"));

        retranslateUi(AppointmentDlg);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, AppointmentDlg, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, AppointmentDlg, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(AppointmentDlg);
    } // setupUi

    void retranslateUi(QDialog *AppointmentDlg)
    {
        AppointmentDlg->setWindowTitle(QCoreApplication::translate("AppointmentDlg", "Dialog", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_Outpatient->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("AppointmentDlg", "\351\227\250\350\257\212\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_Outpatient->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("AppointmentDlg", "\351\227\250\350\257\212\345\220\215\347\247\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_Outpatient->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("AppointmentDlg", "\345\200\274\347\217\255\345\214\273\347\224\237\345\267\245\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_Outpatient->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("AppointmentDlg", "\346\216\245\350\257\212\346\227\245\346\234\237", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget_Outpatient->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("AppointmentDlg", "\346\216\245\350\257\212\346\227\266\351\227\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget_Outpatient->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("AppointmentDlg", "\345\256\271\351\207\217", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget_Outpatient->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("AppointmentDlg", "\351\227\250\350\257\212\345\234\260\345\235\200", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget_Outpatient->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("AppointmentDlg", "\351\227\250\350\257\212\350\201\224\347\263\273\347\224\265\350\257\235", nullptr));
        pushButton_ManageOutPatient->setText(QCoreApplication::translate("AppointmentDlg", "\347\256\241\347\220\206\351\227\250\350\257\212", nullptr));
        labe_Appointment->setText(QCoreApplication::translate("AppointmentDlg", "\351\242\204\347\272\246\351\227\250\350\257\212\357\274\232", nullptr));
        label_PatientName->setText(QCoreApplication::translate("AppointmentDlg", "\345\260\261\350\257\212\344\272\272", nullptr));
        label_OutpatientName->setText(QCoreApplication::translate("AppointmentDlg", "\351\242\204\347\272\246\347\247\221\345\256\244", nullptr));
        comboBox_Time->setItemText(0, QCoreApplication::translate("AppointmentDlg", "\344\270\212\345\215\210", nullptr));
        comboBox_Time->setItemText(1, QCoreApplication::translate("AppointmentDlg", "\344\270\213\345\215\210", nullptr));

        label_Time->setText(QCoreApplication::translate("AppointmentDlg", "\345\260\261\350\257\212\346\227\266\351\227\264", nullptr));
        label_Date->setText(QCoreApplication::translate("AppointmentDlg", "\345\260\261\350\257\212\346\227\245\346\234\237", nullptr));
        label_Image->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class AppointmentDlg: public Ui_AppointmentDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APPOINTMENTDLG_H
