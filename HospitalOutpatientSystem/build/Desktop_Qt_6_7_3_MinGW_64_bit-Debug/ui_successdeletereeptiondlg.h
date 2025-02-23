/********************************************************************************
** Form generated from reading UI file 'successdeletereeptiondlg.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUCCESSDELETEREEPTIONDLG_H
#define UI_SUCCESSDELETEREEPTIONDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_SuccessDeleteReeptionDlg
{
public:
    QLabel *label;

    void setupUi(QDialog *SuccessDeleteReeptionDlg)
    {
        if (SuccessDeleteReeptionDlg->objectName().isEmpty())
            SuccessDeleteReeptionDlg->setObjectName("SuccessDeleteReeptionDlg");
        SuccessDeleteReeptionDlg->resize(300, 200);
        label = new QLabel(SuccessDeleteReeptionDlg);
        label->setObjectName("label");
        label->setGeometry(QRect(40, 50, 251, 91));
        QFont font;
        font.setPointSize(14);
        label->setFont(font);

        retranslateUi(SuccessDeleteReeptionDlg);

        QMetaObject::connectSlotsByName(SuccessDeleteReeptionDlg);
    } // setupUi

    void retranslateUi(QDialog *SuccessDeleteReeptionDlg)
    {
        SuccessDeleteReeptionDlg->setWindowTitle(QCoreApplication::translate("SuccessDeleteReeptionDlg", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("SuccessDeleteReeptionDlg", "\346\202\250\345\267\262\346\210\220\345\212\237\345\217\226\346\266\210\351\242\204\347\272\246\357\274\201\357\274\201\357\274\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SuccessDeleteReeptionDlg: public Ui_SuccessDeleteReeptionDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUCCESSDELETEREEPTIONDLG_H
