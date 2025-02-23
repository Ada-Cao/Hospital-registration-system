/********************************************************************************
** Form generated from reading UI file 'inquirereceptiondlg.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INQUIRERECEPTIONDLG_H
#define UI_INQUIRERECEPTIONDLG_H

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
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_InquireReceptionDlg
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *labe_ReceptionInformation;
    QDateEdit *dateEdit_ReceptionDate;
    QLabel *label_RecptionDate;
    QTableWidget *tableWidget_Reception;
    QLabel *label_OutpatientName;
    QLabel *label_ReceptionTime;
    QComboBox *comboBox_Receptiontime;
    QTextEdit *textEdit_PatientPhone;
    QLabel *label_PatientPhone;
    QComboBox *comboBox_OutpatientName;
    QPushButton *pushButton_SearchByOutpatient;
    QLabel *label_PatientName;
    QPushButton *pushButton_SearchByPatientName;
    QTextEdit *textEdit_PatientName;
    QPushButton *pushButton_SearchByPatientPhone;
    QPushButton *pushButton_DeleteReception;
    QLabel *label_image;

    void setupUi(QDialog *InquireReceptionDlg)
    {
        if (InquireReceptionDlg->objectName().isEmpty())
            InquireReceptionDlg->setObjectName("InquireReceptionDlg");
        InquireReceptionDlg->resize(1000, 700);
        buttonBox = new QDialogButtonBox(InquireReceptionDlg);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(390, 660, 181, 32));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);
        labe_ReceptionInformation = new QLabel(InquireReceptionDlg);
        labe_ReceptionInformation->setObjectName("labe_ReceptionInformation");
        labe_ReceptionInformation->setGeometry(QRect(100, 0, 151, 61));
        QFont font;
        font.setFamilies({QString::fromUtf8("Modern No. 20")});
        font.setPointSize(16);
        labe_ReceptionInformation->setFont(font);
        dateEdit_ReceptionDate = new QDateEdit(InquireReceptionDlg);
        dateEdit_ReceptionDate->setObjectName("dateEdit_ReceptionDate");
        dateEdit_ReceptionDate->setGeometry(QRect(400, 430, 141, 41));
        QFont font1;
        font1.setPointSize(12);
        dateEdit_ReceptionDate->setFont(font1);
        dateEdit_ReceptionDate->setDateTime(QDateTime(QDate(2024, 9, 10), QTime(0, 0, 0)));
        dateEdit_ReceptionDate->setDate(QDate(2024, 9, 10));
        label_RecptionDate = new QLabel(InquireReceptionDlg);
        label_RecptionDate->setObjectName("label_RecptionDate");
        label_RecptionDate->setGeometry(QRect(310, 440, 81, 31));
        label_RecptionDate->setFont(font1);
        tableWidget_Reception = new QTableWidget(InquireReceptionDlg);
        if (tableWidget_Reception->columnCount() < 8)
            tableWidget_Reception->setColumnCount(8);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_Reception->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_Reception->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_Reception->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget_Reception->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget_Reception->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget_Reception->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget_Reception->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget_Reception->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        tableWidget_Reception->setObjectName("tableWidget_Reception");
        tableWidget_Reception->setGeometry(QRect(60, 60, 881, 351));
        label_OutpatientName = new QLabel(InquireReceptionDlg);
        label_OutpatientName->setObjectName("label_OutpatientName");
        label_OutpatientName->setGeometry(QRect(30, 440, 81, 31));
        label_OutpatientName->setFont(font1);
        label_ReceptionTime = new QLabel(InquireReceptionDlg);
        label_ReceptionTime->setObjectName("label_ReceptionTime");
        label_ReceptionTime->setGeometry(QRect(590, 440, 81, 31));
        label_ReceptionTime->setFont(font1);
        comboBox_Receptiontime = new QComboBox(InquireReceptionDlg);
        comboBox_Receptiontime->addItem(QString());
        comboBox_Receptiontime->addItem(QString());
        comboBox_Receptiontime->setObjectName("comboBox_Receptiontime");
        comboBox_Receptiontime->setGeometry(QRect(690, 430, 101, 41));
        comboBox_Receptiontime->setFont(font1);
        textEdit_PatientPhone = new QTextEdit(InquireReceptionDlg);
        textEdit_PatientPhone->setObjectName("textEdit_PatientPhone");
        textEdit_PatientPhone->setGeometry(QRect(210, 600, 181, 41));
        textEdit_PatientPhone->setFont(font1);
        label_PatientPhone = new QLabel(InquireReceptionDlg);
        label_PatientPhone->setObjectName("label_PatientPhone");
        label_PatientPhone->setGeometry(QRect(30, 600, 141, 31));
        label_PatientPhone->setFont(font1);
        comboBox_OutpatientName = new QComboBox(InquireReceptionDlg);
        comboBox_OutpatientName->setObjectName("comboBox_OutpatientName");
        comboBox_OutpatientName->setGeometry(QRect(120, 430, 181, 41));
        comboBox_OutpatientName->setFont(font1);
        pushButton_SearchByOutpatient = new QPushButton(InquireReceptionDlg);
        pushButton_SearchByOutpatient->setObjectName("pushButton_SearchByOutpatient");
        pushButton_SearchByOutpatient->setGeometry(QRect(820, 420, 161, 51));
        pushButton_SearchByOutpatient->setFont(font1);
        label_PatientName = new QLabel(InquireReceptionDlg);
        label_PatientName->setObjectName("label_PatientName");
        label_PatientName->setGeometry(QRect(30, 520, 101, 31));
        label_PatientName->setFont(font1);
        pushButton_SearchByPatientName = new QPushButton(InquireReceptionDlg);
        pushButton_SearchByPatientName->setObjectName("pushButton_SearchByPatientName");
        pushButton_SearchByPatientName->setGeometry(QRect(330, 510, 171, 51));
        pushButton_SearchByPatientName->setFont(font1);
        textEdit_PatientName = new QTextEdit(InquireReceptionDlg);
        textEdit_PatientName->setObjectName("textEdit_PatientName");
        textEdit_PatientName->setGeometry(QRect(160, 520, 111, 41));
        textEdit_PatientName->setFont(font1);
        pushButton_SearchByPatientPhone = new QPushButton(InquireReceptionDlg);
        pushButton_SearchByPatientPhone->setObjectName("pushButton_SearchByPatientPhone");
        pushButton_SearchByPatientPhone->setGeometry(QRect(450, 590, 171, 51));
        pushButton_SearchByPatientPhone->setFont(font1);
        pushButton_DeleteReception = new QPushButton(InquireReceptionDlg);
        pushButton_DeleteReception->setObjectName("pushButton_DeleteReception");
        pushButton_DeleteReception->setGeometry(QRect(850, 590, 121, 51));
        QFont font2;
        font2.setPointSize(11);
        font2.setBold(true);
        font2.setItalic(false);
        font2.setUnderline(true);
        font2.setStrikeOut(false);
        font2.setKerning(false);
        pushButton_DeleteReception->setFont(font2);
        label_image = new QLabel(InquireReceptionDlg);
        label_image->setObjectName("label_image");
        label_image->setGeometry(QRect(20, 10, 69, 41));
        label_image->setStyleSheet(QString::fromUtf8("image: url(:/Reception.png);"));

        retranslateUi(InquireReceptionDlg);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, InquireReceptionDlg, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, InquireReceptionDlg, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(InquireReceptionDlg);
    } // setupUi

    void retranslateUi(QDialog *InquireReceptionDlg)
    {
        InquireReceptionDlg->setWindowTitle(QCoreApplication::translate("InquireReceptionDlg", "Dialog", nullptr));
        labe_ReceptionInformation->setText(QCoreApplication::translate("InquireReceptionDlg", "\351\242\204\347\272\246\344\277\241\346\201\257\357\274\232", nullptr));
        label_RecptionDate->setText(QCoreApplication::translate("InquireReceptionDlg", "\346\216\245\350\257\212\346\227\245\346\234\237", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_Reception->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("InquireReceptionDlg", "\345\260\261\350\257\212\344\272\272\345\247\223\345\220\215", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_Reception->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("InquireReceptionDlg", "\345\260\261\350\257\212\344\272\272\346\200\247\345\210\253", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_Reception->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("InquireReceptionDlg", "\345\260\261\350\257\212\344\272\272\345\271\264\351\276\204", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_Reception->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("InquireReceptionDlg", "\345\260\261\350\257\212\344\272\272\350\201\224\347\263\273\347\224\265\350\257\235", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget_Reception->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("InquireReceptionDlg", "\351\227\250\350\257\212\345\220\215\347\247\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget_Reception->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("InquireReceptionDlg", "\346\216\245\350\257\212\346\227\245\346\234\237", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget_Reception->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("InquireReceptionDlg", "\346\216\245\350\257\212\346\227\266\351\227\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget_Reception->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("InquireReceptionDlg", "\351\227\250\350\257\212\345\234\260\345\235\200", nullptr));
        label_OutpatientName->setText(QCoreApplication::translate("InquireReceptionDlg", "\351\227\250\350\257\212\345\220\215\347\247\260", nullptr));
        label_ReceptionTime->setText(QCoreApplication::translate("InquireReceptionDlg", "\346\216\245\350\257\212\346\227\266\351\227\264", nullptr));
        comboBox_Receptiontime->setItemText(0, QCoreApplication::translate("InquireReceptionDlg", "\344\270\212\345\215\210", nullptr));
        comboBox_Receptiontime->setItemText(1, QCoreApplication::translate("InquireReceptionDlg", "\344\270\213\345\215\210", nullptr));

        label_PatientPhone->setText(QCoreApplication::translate("InquireReceptionDlg", "\345\260\261\350\257\212\344\272\272\350\201\224\347\263\273\347\224\265\350\257\235", nullptr));
        pushButton_SearchByOutpatient->setText(QCoreApplication::translate("InquireReceptionDlg", "\346\214\211\351\227\250\350\257\212\344\277\241\346\201\257\346\237\245\350\257\242", nullptr));
        label_PatientName->setText(QCoreApplication::translate("InquireReceptionDlg", "\345\260\261\350\257\212\344\272\272\345\247\223\345\220\215", nullptr));
        pushButton_SearchByPatientName->setText(QCoreApplication::translate("InquireReceptionDlg", "\346\214\211\345\260\261\350\257\212\344\272\272\345\247\223\345\220\215\346\237\245\350\257\242", nullptr));
        pushButton_SearchByPatientPhone->setText(QCoreApplication::translate("InquireReceptionDlg", "\346\214\211\345\260\261\350\257\212\344\272\272\347\224\265\350\257\235\346\237\245\350\257\242", nullptr));
        pushButton_DeleteReception->setText(QCoreApplication::translate("InquireReceptionDlg", "\345\217\226\346\266\210\351\242\204\347\272\246", nullptr));
        label_image->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class InquireReceptionDlg: public Ui_InquireReceptionDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INQUIRERECEPTIONDLG_H
