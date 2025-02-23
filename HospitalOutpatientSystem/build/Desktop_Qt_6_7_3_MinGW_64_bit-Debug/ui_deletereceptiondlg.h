/********************************************************************************
** Form generated from reading UI file 'deletereceptiondlg.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DELETERECEPTIONDLG_H
#define UI_DELETERECEPTIONDLG_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_DeleteReceptionDlg
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label_DeleteInformation;
    QDateEdit *dateEdit_Date;
    QComboBox *comboBox_OutpatientName;
    QLabel *label_OutpatientName;
    QComboBox *comboBox_PatientName;
    QLabel *label_Date;
    QLabel *label_PatientName;
    QComboBox *comboBox_Time;
    QLabel *label_Time;

    void setupUi(QDialog *DeleteReceptionDlg)
    {
        if (DeleteReceptionDlg->objectName().isEmpty())
            DeleteReceptionDlg->setObjectName("DeleteReceptionDlg");
        DeleteReceptionDlg->resize(600, 400);
        DeleteReceptionDlg->setCursor(QCursor(Qt::CursorShape::ArrowCursor));
        buttonBox = new QDialogButtonBox(DeleteReceptionDlg);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(210, 330, 181, 32));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);
        label_DeleteInformation = new QLabel(DeleteReceptionDlg);
        label_DeleteInformation->setObjectName("label_DeleteInformation");
        label_DeleteInformation->setGeometry(QRect(40, 20, 341, 61));
        QFont font;
        font.setFamilies({QString::fromUtf8("Modern No. 20")});
        font.setPointSize(16);
        label_DeleteInformation->setFont(font);
        dateEdit_Date = new QDateEdit(DeleteReceptionDlg);
        dateEdit_Date->setObjectName("dateEdit_Date");
        dateEdit_Date->setGeometry(QRect(160, 220, 131, 51));
        QFont font1;
        font1.setPointSize(11);
        dateEdit_Date->setFont(font1);
        dateEdit_Date->setDateTime(QDateTime(QDate(2024, 9, 10), QTime(0, 0, 0)));
        dateEdit_Date->setDate(QDate(2024, 9, 10));
        comboBox_OutpatientName = new QComboBox(DeleteReceptionDlg);
        comboBox_OutpatientName->setObjectName("comboBox_OutpatientName");
        comboBox_OutpatientName->setGeometry(QRect(140, 116, 171, 41));
        comboBox_OutpatientName->setFont(font1);
        label_OutpatientName = new QLabel(DeleteReceptionDlg);
        label_OutpatientName->setObjectName("label_OutpatientName");
        label_OutpatientName->setGeometry(QRect(40, 120, 81, 31));
        QFont font2;
        font2.setPointSize(12);
        label_OutpatientName->setFont(font2);
        comboBox_PatientName = new QComboBox(DeleteReceptionDlg);
        comboBox_PatientName->setObjectName("comboBox_PatientName");
        comboBox_PatientName->setGeometry(QRect(430, 120, 131, 41));
        comboBox_PatientName->setFont(font1);
        label_Date = new QLabel(DeleteReceptionDlg);
        label_Date->setObjectName("label_Date");
        label_Date->setGeometry(QRect(40, 230, 81, 31));
        label_Date->setFont(font2);
        label_PatientName = new QLabel(DeleteReceptionDlg);
        label_PatientName->setObjectName("label_PatientName");
        label_PatientName->setGeometry(QRect(330, 120, 81, 31));
        label_PatientName->setFont(font2);
        comboBox_Time = new QComboBox(DeleteReceptionDlg);
        comboBox_Time->addItem(QString());
        comboBox_Time->addItem(QString());
        comboBox_Time->setObjectName("comboBox_Time");
        comboBox_Time->setGeometry(QRect(430, 220, 131, 41));
        comboBox_Time->setFont(font1);
        label_Time = new QLabel(DeleteReceptionDlg);
        label_Time->setObjectName("label_Time");
        label_Time->setGeometry(QRect(330, 230, 81, 31));
        label_Time->setFont(font2);

        retranslateUi(DeleteReceptionDlg);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, DeleteReceptionDlg, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, DeleteReceptionDlg, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(DeleteReceptionDlg);
    } // setupUi

    void retranslateUi(QDialog *DeleteReceptionDlg)
    {
        DeleteReceptionDlg->setWindowTitle(QCoreApplication::translate("DeleteReceptionDlg", "Dialog", nullptr));
        label_DeleteInformation->setText(QCoreApplication::translate("DeleteReceptionDlg", "\350\257\267\351\200\211\346\213\251\350\246\201\345\210\240\351\231\244\347\232\204\351\242\204\347\272\246\344\277\241\346\201\257\357\274\232", nullptr));
        label_OutpatientName->setText(QCoreApplication::translate("DeleteReceptionDlg", "\351\242\204\347\272\246\347\247\221\345\256\244", nullptr));
        label_Date->setText(QCoreApplication::translate("DeleteReceptionDlg", "\345\260\261\350\257\212\346\227\245\346\234\237", nullptr));
        label_PatientName->setText(QCoreApplication::translate("DeleteReceptionDlg", "\345\260\261\350\257\212\344\272\272", nullptr));
        comboBox_Time->setItemText(0, QCoreApplication::translate("DeleteReceptionDlg", "\344\270\212\345\215\210", nullptr));
        comboBox_Time->setItemText(1, QCoreApplication::translate("DeleteReceptionDlg", "\344\270\213\345\215\210", nullptr));

        label_Time->setText(QCoreApplication::translate("DeleteReceptionDlg", "\345\260\261\350\257\212\346\227\266\351\227\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DeleteReceptionDlg: public Ui_DeleteReceptionDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELETERECEPTIONDLG_H
