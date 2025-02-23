/********************************************************************************
** Form generated from reading UI file 'failoutpatientfulldlg.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FAILOUTPATIENTFULLDLG_H
#define UI_FAILOUTPATIENTFULLDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_FailOutpatientFullDlg
{
public:
    QLabel *label_warming;

    void setupUi(QDialog *FailOutpatientFullDlg)
    {
        if (FailOutpatientFullDlg->objectName().isEmpty())
            FailOutpatientFullDlg->setObjectName("FailOutpatientFullDlg");
        FailOutpatientFullDlg->resize(300, 200);
        label_warming = new QLabel(FailOutpatientFullDlg);
        label_warming->setObjectName("label_warming");
        label_warming->setGeometry(QRect(80, 50, 221, 91));
        QFont font;
        font.setPointSize(14);
        label_warming->setFont(font);

        retranslateUi(FailOutpatientFullDlg);

        QMetaObject::connectSlotsByName(FailOutpatientFullDlg);
    } // setupUi

    void retranslateUi(QDialog *FailOutpatientFullDlg)
    {
        FailOutpatientFullDlg->setWindowTitle(QCoreApplication::translate("FailOutpatientFullDlg", "Dialog", nullptr));
        label_warming->setText(QCoreApplication::translate("FailOutpatientFullDlg", "\350\257\245\351\227\250\350\257\212\351\242\204\347\272\246\345\267\262\346\273\241\n"
"      \346\227\240\346\263\225\351\242\204\347\272\246\n"
"         \357\274\201\357\274\201\357\274\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FailOutpatientFullDlg: public Ui_FailOutpatientFullDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FAILOUTPATIENTFULLDLG_H
