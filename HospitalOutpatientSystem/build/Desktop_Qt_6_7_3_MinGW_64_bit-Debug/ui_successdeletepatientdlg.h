/********************************************************************************
** Form generated from reading UI file 'successdeletepatientdlg.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUCCESSDELETEPATIENTDLG_H
#define UI_SUCCESSDELETEPATIENTDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_SuccessDeletePatientDlg
{
public:
    QLabel *label;

    void setupUi(QDialog *SuccessDeletePatientDlg)
    {
        if (SuccessDeletePatientDlg->objectName().isEmpty())
            SuccessDeletePatientDlg->setObjectName("SuccessDeletePatientDlg");
        SuccessDeletePatientDlg->resize(300, 200);
        label = new QLabel(SuccessDeletePatientDlg);
        label->setObjectName("label");
        label->setGeometry(QRect(50, 50, 251, 91));
        QFont font;
        font.setPointSize(14);
        label->setFont(font);

        retranslateUi(SuccessDeletePatientDlg);

        QMetaObject::connectSlotsByName(SuccessDeletePatientDlg);
    } // setupUi

    void retranslateUi(QDialog *SuccessDeletePatientDlg)
    {
        SuccessDeletePatientDlg->setWindowTitle(QCoreApplication::translate("SuccessDeletePatientDlg", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("SuccessDeletePatientDlg", "\346\202\250\345\267\262\346\210\220\345\212\237\345\210\240\351\231\244\350\257\245\345\260\261\350\257\212\344\272\272\357\274\201\357\274\201\357\274\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SuccessDeletePatientDlg: public Ui_SuccessDeletePatientDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUCCESSDELETEPATIENTDLG_H
