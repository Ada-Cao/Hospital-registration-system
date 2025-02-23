/********************************************************************************
** Form generated from reading UI file 'addpatientdlg.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDPATIENTDLG_H
#define UI_ADDPATIENTDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_AddpatientDlg
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label_Gender;
    QLabel *label_Age;
    QLabel *label_Phone;
    QTextEdit *textEdit_Phone;
    QTextEdit *textEdit_Age;
    QTextEdit *textEdit_Name;
    QLabel *label_Name;
    QLabel *label_Year;
    QLabel *labe_AddInformation;
    QRadioButton *radioButton_Male;
    QTableWidget *tableWidgetPatient;
    QRadioButton *radioButton_Female;
    QPushButton *pushButton_DeletePatient;
    QLabel *label_Image;

    void setupUi(QDialog *AddpatientDlg)
    {
        if (AddpatientDlg->objectName().isEmpty())
            AddpatientDlg->setObjectName("AddpatientDlg");
        AddpatientDlg->resize(835, 548);
        buttonBox = new QDialogButtonBox(AddpatientDlg);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(140, 480, 341, 32));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);
        label_Gender = new QLabel(AddpatientDlg);
        label_Gender->setObjectName("label_Gender");
        label_Gender->setGeometry(QRect(460, 340, 51, 31));
        QFont font;
        font.setPointSize(12);
        label_Gender->setFont(font);
        label_Age = new QLabel(AddpatientDlg);
        label_Age->setObjectName("label_Age");
        label_Age->setGeometry(QRect(460, 410, 61, 31));
        label_Age->setFont(font);
        label_Phone = new QLabel(AddpatientDlg);
        label_Phone->setObjectName("label_Phone");
        label_Phone->setGeometry(QRect(100, 410, 121, 31));
        label_Phone->setFont(font);
        textEdit_Phone = new QTextEdit(AddpatientDlg);
        textEdit_Phone->setObjectName("textEdit_Phone");
        textEdit_Phone->setGeometry(QRect(230, 410, 161, 41));
        textEdit_Phone->setFont(font);
        textEdit_Age = new QTextEdit(AddpatientDlg);
        textEdit_Age->setObjectName("textEdit_Age");
        textEdit_Age->setEnabled(true);
        textEdit_Age->setGeometry(QRect(540, 410, 101, 41));
        textEdit_Age->setFont(font);
        textEdit_Name = new QTextEdit(AddpatientDlg);
        textEdit_Name->setObjectName("textEdit_Name");
        textEdit_Name->setGeometry(QRect(230, 340, 161, 41));
        textEdit_Name->setFont(font);
        label_Name = new QLabel(AddpatientDlg);
        label_Name->setObjectName("label_Name");
        label_Name->setGeometry(QRect(100, 340, 121, 31));
        label_Name->setFont(font);
        label_Year = new QLabel(AddpatientDlg);
        label_Year->setObjectName("label_Year");
        label_Year->setGeometry(QRect(670, 410, 121, 31));
        QFont font1;
        font1.setPointSize(10);
        label_Year->setFont(font1);
        labe_AddInformation = new QLabel(AddpatientDlg);
        labe_AddInformation->setObjectName("labe_AddInformation");
        labe_AddInformation->setGeometry(QRect(100, 10, 391, 61));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Modern No. 20")});
        font2.setPointSize(16);
        labe_AddInformation->setFont(font2);
        radioButton_Male = new QRadioButton(AddpatientDlg);
        radioButton_Male->setObjectName("radioButton_Male");
        radioButton_Male->setGeometry(QRect(560, 340, 51, 23));
        tableWidgetPatient = new QTableWidget(AddpatientDlg);
        tableWidgetPatient->setObjectName("tableWidgetPatient");
        tableWidgetPatient->setGeometry(QRect(60, 90, 711, 221));
        radioButton_Female = new QRadioButton(AddpatientDlg);
        radioButton_Female->setObjectName("radioButton_Female");
        radioButton_Female->setGeometry(QRect(660, 340, 51, 23));
        radioButton_Female->setChecked(true);
        pushButton_DeletePatient = new QPushButton(AddpatientDlg);
        pushButton_DeletePatient->setObjectName("pushButton_DeletePatient");
        pushButton_DeletePatient->setGeometry(QRect(700, 470, 101, 51));
        label_Image = new QLabel(AddpatientDlg);
        label_Image->setObjectName("label_Image");
        label_Image->setGeometry(QRect(20, 20, 69, 41));
        label_Image->setStyleSheet(QString::fromUtf8("image: url(:/Patient.png);"));

        retranslateUi(AddpatientDlg);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, AddpatientDlg, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, AddpatientDlg, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(AddpatientDlg);
    } // setupUi

    void retranslateUi(QDialog *AddpatientDlg)
    {
        AddpatientDlg->setWindowTitle(QCoreApplication::translate("AddpatientDlg", "Dialog", nullptr));
        label_Gender->setText(QCoreApplication::translate("AddpatientDlg", "\346\200\247\345\210\253", nullptr));
        label_Age->setText(QCoreApplication::translate("AddpatientDlg", "\345\271\264\351\276\204", nullptr));
        label_Phone->setText(QCoreApplication::translate("AddpatientDlg", "\350\201\224\347\263\273\347\224\265\350\257\235", nullptr));
        label_Name->setText(QCoreApplication::translate("AddpatientDlg", "\345\260\261\350\257\212\344\272\272\345\247\223\345\220\215", nullptr));
        label_Year->setText(QCoreApplication::translate("AddpatientDlg", "\345\262\201", nullptr));
        labe_AddInformation->setText(QCoreApplication::translate("AddpatientDlg", "\350\257\267\346\267\273\345\212\240\346\226\260\345\260\261\350\257\212\344\272\272\344\277\241\346\201\257\357\274\232", nullptr));
        radioButton_Male->setText(QCoreApplication::translate("AddpatientDlg", "\347\224\267", nullptr));
        radioButton_Female->setText(QCoreApplication::translate("AddpatientDlg", "\345\245\263", nullptr));
        pushButton_DeletePatient->setText(QCoreApplication::translate("AddpatientDlg", "\345\210\240\351\231\244\345\260\261\350\257\212\344\272\272", nullptr));
        label_Image->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class AddpatientDlg: public Ui_AddpatientDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDPATIENTDLG_H
