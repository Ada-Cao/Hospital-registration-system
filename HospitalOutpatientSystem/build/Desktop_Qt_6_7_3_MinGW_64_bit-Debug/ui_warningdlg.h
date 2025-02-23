/********************************************************************************
** Form generated from reading UI file 'warningdlg.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WARNINGDLG_H
#define UI_WARNINGDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_WarningDlg
{
public:
    QLabel *label_warming;

    void setupUi(QDialog *WarningDlg)
    {
        if (WarningDlg->objectName().isEmpty())
            WarningDlg->setObjectName("WarningDlg");
        WarningDlg->resize(300, 200);
        label_warming = new QLabel(WarningDlg);
        label_warming->setObjectName("label_warming");
        label_warming->setGeometry(QRect(40, 50, 251, 91));
        QFont font;
        font.setPointSize(14);
        label_warming->setFont(font);

        retranslateUi(WarningDlg);

        QMetaObject::connectSlotsByName(WarningDlg);
    } // setupUi

    void retranslateUi(QDialog *WarningDlg)
    {
        WarningDlg->setWindowTitle(QCoreApplication::translate("WarningDlg", "Dialog", nullptr));
        label_warming->setText(QCoreApplication::translate("WarningDlg", "\346\202\250\350\276\223\345\205\245\347\232\204\345\257\206\347\240\201\351\224\231\350\257\257\357\274\201\357\274\201\357\274\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WarningDlg: public Ui_WarningDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WARNINGDLG_H
