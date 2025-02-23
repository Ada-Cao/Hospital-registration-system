/********************************************************************************
** Form generated from reading UI file 'searchbypatientnamedlg.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHBYPATIENTNAMEDLG_H
#define UI_SEARCHBYPATIENTNAMEDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_SearchByPatientNameDlg
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label_ReceptionInformation;
    QTableWidget *tableWidget_PatientReception;

    void setupUi(QDialog *SearchByPatientNameDlg)
    {
        if (SearchByPatientNameDlg->objectName().isEmpty())
            SearchByPatientNameDlg->setObjectName("SearchByPatientNameDlg");
        SearchByPatientNameDlg->resize(800, 600);
        buttonBox = new QDialogButtonBox(SearchByPatientNameDlg);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(300, 540, 181, 32));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);
        label_ReceptionInformation = new QLabel(SearchByPatientNameDlg);
        label_ReceptionInformation->setObjectName("label_ReceptionInformation");
        label_ReceptionInformation->setGeometry(QRect(20, 10, 131, 61));
        QFont font;
        font.setFamilies({QString::fromUtf8("Modern No. 20")});
        font.setPointSize(16);
        label_ReceptionInformation->setFont(font);
        tableWidget_PatientReception = new QTableWidget(SearchByPatientNameDlg);
        if (tableWidget_PatientReception->columnCount() < 8)
            tableWidget_PatientReception->setColumnCount(8);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_PatientReception->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_PatientReception->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_PatientReception->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget_PatientReception->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget_PatientReception->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget_PatientReception->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget_PatientReception->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget_PatientReception->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        tableWidget_PatientReception->setObjectName("tableWidget_PatientReception");
        tableWidget_PatientReception->setGeometry(QRect(20, 70, 761, 441));

        retranslateUi(SearchByPatientNameDlg);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, SearchByPatientNameDlg, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, SearchByPatientNameDlg, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(SearchByPatientNameDlg);
    } // setupUi

    void retranslateUi(QDialog *SearchByPatientNameDlg)
    {
        SearchByPatientNameDlg->setWindowTitle(QCoreApplication::translate("SearchByPatientNameDlg", "Dialog", nullptr));
        label_ReceptionInformation->setText(QCoreApplication::translate("SearchByPatientNameDlg", "\351\242\204\347\272\246\346\203\205\345\206\265\357\274\232", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_PatientReception->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("SearchByPatientNameDlg", "\351\227\250\350\257\212\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_PatientReception->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("SearchByPatientNameDlg", "\351\227\250\350\257\212\345\220\215", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_PatientReception->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("SearchByPatientNameDlg", "\345\200\274\347\217\255\345\214\273\347\224\237\345\267\245\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_PatientReception->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("SearchByPatientNameDlg", "\345\260\261\350\257\212\346\227\245\346\234\237", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget_PatientReception->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("SearchByPatientNameDlg", "\345\260\261\350\257\212\346\227\266\351\227\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget_PatientReception->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("SearchByPatientNameDlg", "\345\256\271\351\207\217", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget_PatientReception->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("SearchByPatientNameDlg", "\351\227\250\350\257\212\345\234\260\345\235\200", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget_PatientReception->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("SearchByPatientNameDlg", "\351\227\250\350\257\212\350\201\224\347\263\273\347\224\265\350\257\235", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SearchByPatientNameDlg: public Ui_SearchByPatientNameDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHBYPATIENTNAMEDLG_H
