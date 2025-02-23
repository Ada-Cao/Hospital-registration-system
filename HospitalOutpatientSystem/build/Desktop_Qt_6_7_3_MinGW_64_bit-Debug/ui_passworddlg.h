/********************************************************************************
** Form generated from reading UI file 'passworddlg.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PASSWORDDLG_H
#define UI_PASSWORDDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_PassWordDlg
{
public:
    QLabel *label_passwordinformation;
    QPushButton *pushButton_enter;
    QLineEdit *lineEdit_Password;

    void setupUi(QDialog *PassWordDlg)
    {
        if (PassWordDlg->objectName().isEmpty())
            PassWordDlg->setObjectName("PassWordDlg");
        PassWordDlg->resize(400, 300);
        label_passwordinformation = new QLabel(PassWordDlg);
        label_passwordinformation->setObjectName("label_passwordinformation");
        label_passwordinformation->setGeometry(QRect(20, 10, 391, 61));
        QFont font;
        font.setFamilies({QString::fromUtf8("Modern No. 20")});
        font.setPointSize(16);
        label_passwordinformation->setFont(font);
        pushButton_enter = new QPushButton(PassWordDlg);
        pushButton_enter->setObjectName("pushButton_enter");
        pushButton_enter->setGeometry(QRect(140, 220, 101, 41));
        lineEdit_Password = new QLineEdit(PassWordDlg);
        lineEdit_Password->setObjectName("lineEdit_Password");
        lineEdit_Password->setGeometry(QRect(80, 110, 231, 61));
        QFont font1;
        font1.setPointSize(20);
        lineEdit_Password->setFont(font1);

        retranslateUi(PassWordDlg);

        QMetaObject::connectSlotsByName(PassWordDlg);
    } // setupUi

    void retranslateUi(QDialog *PassWordDlg)
    {
        PassWordDlg->setWindowTitle(QCoreApplication::translate("PassWordDlg", "Dialog", nullptr));
        label_passwordinformation->setText(QCoreApplication::translate("PassWordDlg", "\350\257\267\350\276\223\345\205\245\347\256\241\347\220\206\345\221\230\345\257\206\347\240\201\357\274\232", nullptr));
        pushButton_enter->setText(QCoreApplication::translate("PassWordDlg", "Enter", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PassWordDlg: public Ui_PassWordDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PASSWORDDLG_H
