/********************************************************************************
** Form generated from reading UI file 'successaddappointmentdlg.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUCCESSADDAPPOINTMENTDLG_H
#define UI_SUCCESSADDAPPOINTMENTDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_SuccessAddAppointmentDlg
{
public:
    QLabel *label_warming;

    void setupUi(QDialog *SuccessAddAppointmentDlg)
    {
        if (SuccessAddAppointmentDlg->objectName().isEmpty())
            SuccessAddAppointmentDlg->setObjectName("SuccessAddAppointmentDlg");
        SuccessAddAppointmentDlg->resize(300, 200);
        label_warming = new QLabel(SuccessAddAppointmentDlg);
        label_warming->setObjectName("label_warming");
        label_warming->setGeometry(QRect(60, 50, 251, 91));
        QFont font;
        font.setPointSize(14);
        label_warming->setFont(font);

        retranslateUi(SuccessAddAppointmentDlg);

        QMetaObject::connectSlotsByName(SuccessAddAppointmentDlg);
    } // setupUi

    void retranslateUi(QDialog *SuccessAddAppointmentDlg)
    {
        SuccessAddAppointmentDlg->setWindowTitle(QCoreApplication::translate("SuccessAddAppointmentDlg", "Dialog", nullptr));
        label_warming->setText(QCoreApplication::translate("SuccessAddAppointmentDlg", "\346\202\250\345\267\262\346\210\220\345\212\237\351\242\204\347\272\246\357\274\201\357\274\201\357\274\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SuccessAddAppointmentDlg: public Ui_SuccessAddAppointmentDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUCCESSADDAPPOINTMENTDLG_H
