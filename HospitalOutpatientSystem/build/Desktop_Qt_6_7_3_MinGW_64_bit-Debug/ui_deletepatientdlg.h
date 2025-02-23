/********************************************************************************
** Form generated from reading UI file 'deletepatientdlg.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DELETEPATIENTDLG_H
#define UI_DELETEPATIENTDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_DeletePatientDlg
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label_DeleteInformation;
    QComboBox *comboBox_PatientName;

    void setupUi(QDialog *DeletePatientDlg)
    {
        if (DeletePatientDlg->objectName().isEmpty())
            DeletePatientDlg->setObjectName("DeletePatientDlg");
        DeletePatientDlg->resize(400, 250);
        buttonBox = new QDialogButtonBox(DeletePatientDlg);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(100, 200, 181, 32));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);
        label_DeleteInformation = new QLabel(DeletePatientDlg);
        label_DeleteInformation->setObjectName("label_DeleteInformation");
        label_DeleteInformation->setGeometry(QRect(40, 20, 341, 61));
        QFont font;
        font.setFamilies({QString::fromUtf8("Modern No. 20")});
        font.setPointSize(16);
        label_DeleteInformation->setFont(font);
        comboBox_PatientName = new QComboBox(DeletePatientDlg);
        comboBox_PatientName->setObjectName("comboBox_PatientName");
        comboBox_PatientName->setGeometry(QRect(130, 100, 131, 41));

        retranslateUi(DeletePatientDlg);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, DeletePatientDlg, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, DeletePatientDlg, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(DeletePatientDlg);
    } // setupUi

    void retranslateUi(QDialog *DeletePatientDlg)
    {
        DeletePatientDlg->setWindowTitle(QCoreApplication::translate("DeletePatientDlg", "Dialog", nullptr));
        label_DeleteInformation->setText(QCoreApplication::translate("DeletePatientDlg", "\350\257\267\351\200\211\346\213\251\345\210\240\351\231\244\347\232\204\345\260\261\350\257\212\344\272\272\345\247\223\345\220\215", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DeletePatientDlg: public Ui_DeletePatientDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELETEPATIENTDLG_H
