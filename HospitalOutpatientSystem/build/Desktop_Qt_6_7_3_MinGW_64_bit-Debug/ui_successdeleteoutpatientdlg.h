/********************************************************************************
** Form generated from reading UI file 'successdeleteoutpatientdlg.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUCCESSDELETEOUTPATIENTDLG_H
#define UI_SUCCESSDELETEOUTPATIENTDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_SuccessDeleteOutpatientDlg
{
public:
    QLabel *label;

    void setupUi(QDialog *SuccessDeleteOutpatientDlg)
    {
        if (SuccessDeleteOutpatientDlg->objectName().isEmpty())
            SuccessDeleteOutpatientDlg->setObjectName("SuccessDeleteOutpatientDlg");
        SuccessDeleteOutpatientDlg->resize(300, 200);
        label = new QLabel(SuccessDeleteOutpatientDlg);
        label->setObjectName("label");
        label->setGeometry(QRect(50, 50, 251, 91));
        QFont font;
        font.setPointSize(14);
        label->setFont(font);

        retranslateUi(SuccessDeleteOutpatientDlg);

        QMetaObject::connectSlotsByName(SuccessDeleteOutpatientDlg);
    } // setupUi

    void retranslateUi(QDialog *SuccessDeleteOutpatientDlg)
    {
        SuccessDeleteOutpatientDlg->setWindowTitle(QCoreApplication::translate("SuccessDeleteOutpatientDlg", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("SuccessDeleteOutpatientDlg", "\346\202\250\345\267\262\346\210\220\345\212\237\345\210\240\351\231\244\350\257\245\351\227\250\350\257\212\357\274\201\357\274\201\357\274\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SuccessDeleteOutpatientDlg: public Ui_SuccessDeleteOutpatientDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUCCESSDELETEOUTPATIENTDLG_H
