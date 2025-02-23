/********************************************************************************
** Form generated from reading UI file 'addoutpatientdlg.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDOUTPATIENTDLG_H
#define UI_ADDOUTPATIENTDLG_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_AddOutpatientDlg
{
public:
    QDialogButtonBox *buttonBox;
    QTableWidget *tableWidget_Outpatient;
    QLabel *labe_AddInformation;
    QLabel *label_OutpatientID;
    QTextEdit *textEdit_OutpatientID;
    QLabel *label_OutpatientName;
    QTextEdit *textEdit_OutpatientName;
    QLabel *label_DoctorID;
    QTextEdit *textEdit_DoctorID;
    QLabel *label_RecptionDate;
    QLabel *label_ReceptionTime;
    QDateEdit *dateEdit_ReceptionDate;
    QComboBox *comboBox_Receptiontime;
    QLabel *label_Capacity;
    QSpinBox *spinBox_Capacity;
    QLabel *label_OutpatientAddress;
    QComboBox *comboBox_OutpatientAddress;
    QLabel *label_OutpatientPhone;
    QTextEdit *textEdit_OutpatientPhone;
    QPushButton *pushButton_DeleteOutpatient;
    QLabel *label_Image;

    void setupUi(QDialog *AddOutpatientDlg)
    {
        if (AddOutpatientDlg->objectName().isEmpty())
            AddOutpatientDlg->setObjectName("AddOutpatientDlg");
        AddOutpatientDlg->resize(1000, 700);
        buttonBox = new QDialogButtonBox(AddOutpatientDlg);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(260, 650, 341, 32));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);
        tableWidget_Outpatient = new QTableWidget(AddOutpatientDlg);
        if (tableWidget_Outpatient->columnCount() < 8)
            tableWidget_Outpatient->setColumnCount(8);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_Outpatient->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_Outpatient->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_Outpatient->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget_Outpatient->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget_Outpatient->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget_Outpatient->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget_Outpatient->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget_Outpatient->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        tableWidget_Outpatient->setObjectName("tableWidget_Outpatient");
        tableWidget_Outpatient->setGeometry(QRect(60, 60, 881, 341));
        labe_AddInformation = new QLabel(AddOutpatientDlg);
        labe_AddInformation->setObjectName("labe_AddInformation");
        labe_AddInformation->setGeometry(QRect(100, 0, 151, 61));
        QFont font;
        font.setFamilies({QString::fromUtf8("Modern No. 20")});
        font.setPointSize(16);
        labe_AddInformation->setFont(font);
        label_OutpatientID = new QLabel(AddOutpatientDlg);
        label_OutpatientID->setObjectName("label_OutpatientID");
        label_OutpatientID->setGeometry(QRect(60, 420, 81, 31));
        QFont font1;
        font1.setPointSize(12);
        label_OutpatientID->setFont(font1);
        textEdit_OutpatientID = new QTextEdit(AddOutpatientDlg);
        textEdit_OutpatientID->setObjectName("textEdit_OutpatientID");
        textEdit_OutpatientID->setGeometry(QRect(150, 420, 111, 41));
        textEdit_OutpatientID->setFont(font1);
        label_OutpatientName = new QLabel(AddOutpatientDlg);
        label_OutpatientName->setObjectName("label_OutpatientName");
        label_OutpatientName->setGeometry(QRect(320, 420, 81, 31));
        label_OutpatientName->setFont(font1);
        textEdit_OutpatientName = new QTextEdit(AddOutpatientDlg);
        textEdit_OutpatientName->setObjectName("textEdit_OutpatientName");
        textEdit_OutpatientName->setGeometry(QRect(440, 420, 181, 41));
        textEdit_OutpatientName->setFont(font1);
        label_DoctorID = new QLabel(AddOutpatientDlg);
        label_DoctorID->setObjectName("label_DoctorID");
        label_DoctorID->setGeometry(QRect(670, 420, 131, 31));
        label_DoctorID->setFont(font1);
        textEdit_DoctorID = new QTextEdit(AddOutpatientDlg);
        textEdit_DoctorID->setObjectName("textEdit_DoctorID");
        textEdit_DoctorID->setGeometry(QRect(810, 420, 141, 41));
        textEdit_DoctorID->setFont(font1);
        label_RecptionDate = new QLabel(AddOutpatientDlg);
        label_RecptionDate->setObjectName("label_RecptionDate");
        label_RecptionDate->setGeometry(QRect(60, 500, 81, 31));
        label_RecptionDate->setFont(font1);
        label_ReceptionTime = new QLabel(AddOutpatientDlg);
        label_ReceptionTime->setObjectName("label_ReceptionTime");
        label_ReceptionTime->setGeometry(QRect(320, 500, 81, 31));
        label_ReceptionTime->setFont(font1);
        dateEdit_ReceptionDate = new QDateEdit(AddOutpatientDlg);
        dateEdit_ReceptionDate->setObjectName("dateEdit_ReceptionDate");
        dateEdit_ReceptionDate->setGeometry(QRect(150, 500, 141, 41));
        dateEdit_ReceptionDate->setFont(font1);
        dateEdit_ReceptionDate->setDateTime(QDateTime(QDate(2024, 9, 10), QTime(16, 0, 0)));
        dateEdit_ReceptionDate->setDate(QDate(2024, 9, 10));
        comboBox_Receptiontime = new QComboBox(AddOutpatientDlg);
        comboBox_Receptiontime->addItem(QString());
        comboBox_Receptiontime->addItem(QString());
        comboBox_Receptiontime->setObjectName("comboBox_Receptiontime");
        comboBox_Receptiontime->setGeometry(QRect(440, 496, 101, 41));
        label_Capacity = new QLabel(AddOutpatientDlg);
        label_Capacity->setObjectName("label_Capacity");
        label_Capacity->setGeometry(QRect(670, 500, 81, 31));
        label_Capacity->setFont(font1);
        spinBox_Capacity = new QSpinBox(AddOutpatientDlg);
        spinBox_Capacity->setObjectName("spinBox_Capacity");
        spinBox_Capacity->setGeometry(QRect(810, 490, 71, 41));
        spinBox_Capacity->setMaximum(200);
        spinBox_Capacity->setValue(40);
        label_OutpatientAddress = new QLabel(AddOutpatientDlg);
        label_OutpatientAddress->setObjectName("label_OutpatientAddress");
        label_OutpatientAddress->setGeometry(QRect(60, 580, 81, 31));
        label_OutpatientAddress->setFont(font1);
        comboBox_OutpatientAddress = new QComboBox(AddOutpatientDlg);
        comboBox_OutpatientAddress->addItem(QString());
        comboBox_OutpatientAddress->addItem(QString());
        comboBox_OutpatientAddress->addItem(QString());
        comboBox_OutpatientAddress->addItem(QString());
        comboBox_OutpatientAddress->setObjectName("comboBox_OutpatientAddress");
        comboBox_OutpatientAddress->setGeometry(QRect(150, 580, 371, 41));
        QFont font2;
        font2.setPointSize(11);
        comboBox_OutpatientAddress->setFont(font2);
        label_OutpatientPhone = new QLabel(AddOutpatientDlg);
        label_OutpatientPhone->setObjectName("label_OutpatientPhone");
        label_OutpatientPhone->setGeometry(QRect(590, 580, 121, 31));
        label_OutpatientPhone->setFont(font1);
        textEdit_OutpatientPhone = new QTextEdit(AddOutpatientDlg);
        textEdit_OutpatientPhone->setObjectName("textEdit_OutpatientPhone");
        textEdit_OutpatientPhone->setGeometry(QRect(730, 580, 181, 41));
        textEdit_OutpatientPhone->setFont(font1);
        pushButton_DeleteOutpatient = new QPushButton(AddOutpatientDlg);
        pushButton_DeleteOutpatient->setObjectName("pushButton_DeleteOutpatient");
        pushButton_DeleteOutpatient->setGeometry(QRect(890, 650, 80, 40));
        label_Image = new QLabel(AddOutpatientDlg);
        label_Image->setObjectName("label_Image");
        label_Image->setGeometry(QRect(30, 0, 69, 51));
        label_Image->setStyleSheet(QString::fromUtf8("image: url(:/Outpatient.png);"));

        retranslateUi(AddOutpatientDlg);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, AddOutpatientDlg, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, AddOutpatientDlg, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(AddOutpatientDlg);
    } // setupUi

    void retranslateUi(QDialog *AddOutpatientDlg)
    {
        AddOutpatientDlg->setWindowTitle(QCoreApplication::translate("AddOutpatientDlg", "Dialog", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_Outpatient->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("AddOutpatientDlg", "\351\227\250\350\257\212\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_Outpatient->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("AddOutpatientDlg", "\351\227\250\350\257\212\345\220\215\347\247\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_Outpatient->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("AddOutpatientDlg", "\345\200\274\347\217\255\345\214\273\347\224\237\345\267\245\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_Outpatient->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("AddOutpatientDlg", "\346\216\245\350\257\212\346\227\245\346\234\237", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget_Outpatient->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("AddOutpatientDlg", "\346\216\245\350\257\212\346\227\266\351\227\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget_Outpatient->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("AddOutpatientDlg", "\345\256\271\351\207\217", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget_Outpatient->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("AddOutpatientDlg", "\351\227\250\350\257\212\345\234\260\345\235\200", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget_Outpatient->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("AddOutpatientDlg", "\351\227\250\350\257\212\350\201\224\347\263\273\347\224\265\350\257\235", nullptr));
        labe_AddInformation->setText(QCoreApplication::translate("AddOutpatientDlg", "\351\227\250\350\257\212\344\277\241\346\201\257\357\274\232", nullptr));
        label_OutpatientID->setText(QCoreApplication::translate("AddOutpatientDlg", "\351\227\250\350\257\212\345\217\267", nullptr));
        label_OutpatientName->setText(QCoreApplication::translate("AddOutpatientDlg", "\351\227\250\350\257\212\345\220\215\347\247\260", nullptr));
        label_DoctorID->setText(QCoreApplication::translate("AddOutpatientDlg", "\345\200\274\347\217\255\345\214\273\347\224\237\345\267\245\345\217\267", nullptr));
        label_RecptionDate->setText(QCoreApplication::translate("AddOutpatientDlg", "\346\216\245\350\257\212\346\227\245\346\234\237", nullptr));
        label_ReceptionTime->setText(QCoreApplication::translate("AddOutpatientDlg", "\346\216\245\350\257\212\346\227\266\351\227\264", nullptr));
        comboBox_Receptiontime->setItemText(0, QCoreApplication::translate("AddOutpatientDlg", "\344\270\212\345\215\210", nullptr));
        comboBox_Receptiontime->setItemText(1, QCoreApplication::translate("AddOutpatientDlg", "\344\270\213\345\215\210", nullptr));

        label_Capacity->setText(QCoreApplication::translate("AddOutpatientDlg", "\345\256\271\351\207\217", nullptr));
        label_OutpatientAddress->setText(QCoreApplication::translate("AddOutpatientDlg", "\351\227\250\350\257\212\345\234\260\345\235\200", nullptr));
        comboBox_OutpatientAddress->setItemText(0, QCoreApplication::translate("AddOutpatientDlg", "\345\215\227\344\272\254\345\270\202\351\274\223\346\245\274\345\214\272\344\270\201\345\256\266\346\241\24587\345\217\267", nullptr));
        comboBox_OutpatientAddress->setItemText(1, QCoreApplication::translate("AddOutpatientDlg", "\345\215\227\344\272\254\345\270\202\351\274\223\346\245\274\345\214\272\346\271\226\345\215\227\350\267\25718\345\217\267", nullptr));
        comboBox_OutpatientAddress->setItemText(2, QCoreApplication::translate("AddOutpatientDlg", "\345\215\227\344\272\254\345\270\202\351\274\223\346\245\274\345\214\272\346\226\260\346\250\241\350\214\203\351\251\254\350\267\2573\345\217\267", nullptr));
        comboBox_OutpatientAddress->setItemText(3, QCoreApplication::translate("AddOutpatientDlg", "\345\215\227\344\272\254\345\270\202\346\261\237\345\214\227\346\226\260\345\214\272\345\201\245\346\260\221\350\267\257211\345\217\267", nullptr));

        label_OutpatientPhone->setText(QCoreApplication::translate("AddOutpatientDlg", "\351\227\250\350\257\212\350\201\224\347\263\273\347\224\265\350\257\235", nullptr));
        pushButton_DeleteOutpatient->setText(QCoreApplication::translate("AddOutpatientDlg", "\345\210\240\351\231\244\351\227\250\350\257\212", nullptr));
        label_Image->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class AddOutpatientDlg: public Ui_AddOutpatientDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDOUTPATIENTDLG_H
