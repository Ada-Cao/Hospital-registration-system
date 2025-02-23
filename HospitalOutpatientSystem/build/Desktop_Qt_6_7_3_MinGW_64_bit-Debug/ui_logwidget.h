/********************************************************************************
** Form generated from reading UI file 'logwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGWIDGET_H
#define UI_LOGWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LogWidget
{
public:
    QLabel *label;
    QPushButton *pushbotton_log;
    QCheckBox *checkbox_rememberpassward;
    QPushButton *pushbutton_clear;
    QCheckBox *checkbox_remembername;
    QGroupBox *groupBox;
    QLabel *label_name;
    QLineEdit *lineedit_name;
    QLabel *label_password;
    QLineEdit *lineedit_password;
    QLabel *label_IMG;

    void setupUi(QWidget *LogWidget)
    {
        if (LogWidget->objectName().isEmpty())
            LogWidget->setObjectName("LogWidget");
        LogWidget->resize(450, 350);
        label = new QLabel(LogWidget);
        label->setObjectName("label");
        label->setGeometry(QRect(170, 20, 201, 31));
        QFont font;
        font.setPointSize(14);
        label->setFont(font);
        pushbotton_log = new QPushButton(LogWidget);
        pushbotton_log->setObjectName("pushbotton_log");
        pushbotton_log->setGeometry(QRect(110, 280, 93, 28));
        QFont font1;
        font1.setPointSize(10);
        pushbotton_log->setFont(font1);
        checkbox_rememberpassward = new QCheckBox(LogWidget);
        checkbox_rememberpassward->setObjectName("checkbox_rememberpassward");
        checkbox_rememberpassward->setGeometry(QRect(250, 220, 111, 19));
        QFont font2;
        font2.setPointSize(12);
        checkbox_rememberpassward->setFont(font2);
        pushbutton_clear = new QPushButton(LogWidget);
        pushbutton_clear->setObjectName("pushbutton_clear");
        pushbutton_clear->setGeometry(QRect(250, 280, 93, 28));
        pushbutton_clear->setFont(font1);
        checkbox_remembername = new QCheckBox(LogWidget);
        checkbox_remembername->setObjectName("checkbox_remembername");
        checkbox_remembername->setGeometry(QRect(90, 220, 111, 20));
        checkbox_remembername->setFont(font2);
        groupBox = new QGroupBox(LogWidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(80, 70, 281, 111));
        label_name = new QLabel(groupBox);
        label_name->setObjectName("label_name");
        label_name->setGeometry(QRect(20, 20, 72, 21));
        label_name->setFont(font2);
        lineedit_name = new QLineEdit(groupBox);
        lineedit_name->setObjectName("lineedit_name");
        lineedit_name->setGeometry(QRect(110, 20, 113, 31));
        label_password = new QLabel(groupBox);
        label_password->setObjectName("label_password");
        label_password->setGeometry(QRect(20, 70, 72, 31));
        label_password->setFont(font2);
        lineedit_password = new QLineEdit(groupBox);
        lineedit_password->setObjectName("lineedit_password");
        lineedit_password->setGeometry(QRect(110, 70, 113, 31));
        label_IMG = new QLabel(LogWidget);
        label_IMG->setObjectName("label_IMG");
        label_IMG->setGeometry(QRect(80, 10, 91, 51));
        label_IMG->setStyleSheet(QString::fromUtf8("image: url(:/SmallHospital.png);"));

        retranslateUi(LogWidget);

        QMetaObject::connectSlotsByName(LogWidget);
    } // setupUi

    void retranslateUi(QWidget *LogWidget)
    {
        LogWidget->setWindowTitle(QCoreApplication::translate("LogWidget", "Form", nullptr));
        label->setText(QCoreApplication::translate("LogWidget", "\345\214\273\351\231\242\351\227\250\350\257\212\347\256\241\347\220\206\347\263\273\347\273\237", nullptr));
        pushbotton_log->setText(QCoreApplication::translate("LogWidget", "\347\231\273\345\275\225", nullptr));
        checkbox_rememberpassward->setText(QCoreApplication::translate("LogWidget", "\350\256\260\344\275\217\345\257\206\347\240\201", nullptr));
        pushbutton_clear->setText(QCoreApplication::translate("LogWidget", "\351\207\215\347\275\256", nullptr));
        checkbox_remembername->setText(QCoreApplication::translate("LogWidget", "\350\256\260\344\275\217\350\264\246\345\217\267", nullptr));
        groupBox->setTitle(QString());
        label_name->setText(QCoreApplication::translate("LogWidget", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        label_password->setText(QCoreApplication::translate("LogWidget", "\345\257\206 \347\240\201\357\274\232", nullptr));
        label_IMG->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class LogWidget: public Ui_LogWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGWIDGET_H
