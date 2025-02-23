/********************************************************************************
** Form generated from reading UI file 'failfindoutpatientdlg.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FAILFINDOUTPATIENTDLG_H
#define UI_FAILFINDOUTPATIENTDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_FailFindOutpatientDlg
{
public:
    QLabel *label_warming;

    void setupUi(QDialog *FailFindOutpatientDlg)
    {
        if (FailFindOutpatientDlg->objectName().isEmpty())
            FailFindOutpatientDlg->setObjectName("FailFindOutpatientDlg");
        FailFindOutpatientDlg->resize(300, 200);
        label_warming = new QLabel(FailFindOutpatientDlg);
        label_warming->setObjectName("label_warming");
        label_warming->setGeometry(QRect(40, 60, 261, 91));
        QFont font;
        font.setPointSize(14);
        label_warming->setFont(font);

        retranslateUi(FailFindOutpatientDlg);

        QMetaObject::connectSlotsByName(FailFindOutpatientDlg);
    } // setupUi

    void retranslateUi(QDialog *FailFindOutpatientDlg)
    {
        FailFindOutpatientDlg->setWindowTitle(QCoreApplication::translate("FailFindOutpatientDlg", "Dialog", nullptr));
        label_warming->setText(QCoreApplication::translate("FailFindOutpatientDlg", "\346\234\252\346\211\276\345\210\260\346\202\250\346\203\263\350\246\201\351\242\204\347\272\246\347\232\204\351\227\250\350\257\212\n"
"           \350\257\267\351\207\215\346\226\260\351\242\204\347\272\246\n"
"              \357\274\201\357\274\201\357\274\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FailFindOutpatientDlg: public Ui_FailFindOutpatientDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FAILFINDOUTPATIENTDLG_H
