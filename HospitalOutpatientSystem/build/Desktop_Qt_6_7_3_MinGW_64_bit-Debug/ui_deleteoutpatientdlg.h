/********************************************************************************
** Form generated from reading UI file 'deleteoutpatientdlg.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DELETEOUTPATIENTDLG_H
#define UI_DELETEOUTPATIENTDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_DeleteOutpatientDlg
{
public:
    QDialogButtonBox *buttonBox;
    QComboBox *comboBox_OutpatientName;
    QLabel *label_DeleteInformation;
    QLabel *label_OutpatientName;

    void setupUi(QDialog *DeleteOutpatientDlg)
    {
        if (DeleteOutpatientDlg->objectName().isEmpty())
            DeleteOutpatientDlg->setObjectName("DeleteOutpatientDlg");
        DeleteOutpatientDlg->resize(400, 250);
        buttonBox = new QDialogButtonBox(DeleteOutpatientDlg);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(100, 180, 181, 32));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);
        comboBox_OutpatientName = new QComboBox(DeleteOutpatientDlg);
        comboBox_OutpatientName->setObjectName("comboBox_OutpatientName");
        comboBox_OutpatientName->setGeometry(QRect(170, 96, 171, 41));
        QFont font;
        font.setPointSize(11);
        comboBox_OutpatientName->setFont(font);
        label_DeleteInformation = new QLabel(DeleteOutpatientDlg);
        label_DeleteInformation->setObjectName("label_DeleteInformation");
        label_DeleteInformation->setGeometry(QRect(40, 10, 341, 61));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Modern No. 20")});
        font1.setPointSize(16);
        label_DeleteInformation->setFont(font1);
        label_OutpatientName = new QLabel(DeleteOutpatientDlg);
        label_OutpatientName->setObjectName("label_OutpatientName");
        label_OutpatientName->setGeometry(QRect(70, 100, 81, 31));
        QFont font2;
        font2.setPointSize(12);
        label_OutpatientName->setFont(font2);

        retranslateUi(DeleteOutpatientDlg);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, DeleteOutpatientDlg, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, DeleteOutpatientDlg, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(DeleteOutpatientDlg);
    } // setupUi

    void retranslateUi(QDialog *DeleteOutpatientDlg)
    {
        DeleteOutpatientDlg->setWindowTitle(QCoreApplication::translate("DeleteOutpatientDlg", "Dialog", nullptr));
        label_DeleteInformation->setText(QCoreApplication::translate("DeleteOutpatientDlg", "\350\257\267\351\200\211\346\213\251\350\246\201\345\210\240\351\231\244\347\232\204\351\227\250\350\257\212\344\277\241\346\201\257\357\274\232", nullptr));
        label_OutpatientName->setText(QCoreApplication::translate("DeleteOutpatientDlg", "\351\242\204\347\272\246\347\247\221\345\256\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DeleteOutpatientDlg: public Ui_DeleteOutpatientDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELETEOUTPATIENTDLG_H
