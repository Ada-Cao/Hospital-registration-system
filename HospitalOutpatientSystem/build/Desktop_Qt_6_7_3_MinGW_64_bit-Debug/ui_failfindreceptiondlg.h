/********************************************************************************
** Form generated from reading UI file 'failfindreceptiondlg.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FAILFINDRECEPTIONDLG_H
#define UI_FAILFINDRECEPTIONDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_FailFindReceptionDlg
{
public:
    QLabel *label_warming;

    void setupUi(QDialog *FailFindReceptionDlg)
    {
        if (FailFindReceptionDlg->objectName().isEmpty())
            FailFindReceptionDlg->setObjectName("FailFindReceptionDlg");
        FailFindReceptionDlg->resize(350, 220);
        label_warming = new QLabel(FailFindReceptionDlg);
        label_warming->setObjectName("label_warming");
        label_warming->setGeometry(QRect(40, 50, 331, 91));
        QFont font;
        font.setPointSize(14);
        label_warming->setFont(font);

        retranslateUi(FailFindReceptionDlg);

        QMetaObject::connectSlotsByName(FailFindReceptionDlg);
    } // setupUi

    void retranslateUi(QDialog *FailFindReceptionDlg)
    {
        FailFindReceptionDlg->setWindowTitle(QCoreApplication::translate("FailFindReceptionDlg", "Dialog", nullptr));
        label_warming->setText(QCoreApplication::translate("FailFindReceptionDlg", "          \346\234\252\346\211\276\345\210\260\347\233\270\345\205\263\351\242\204\347\272\246\344\277\241\346\201\257\n"
"\345\217\257\350\203\275\346\230\257\350\276\223\345\205\245\344\277\241\346\201\257\346\234\211\350\257\257\346\210\226\346\227\240\351\242\204\347\272\246\344\277\241\346\201\257\n"
"                 \350\257\267\346\243\200\346\237\245\357\274\201\357\274\201\357\274\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FailFindReceptionDlg: public Ui_FailFindReceptionDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FAILFINDRECEPTIONDLG_H
