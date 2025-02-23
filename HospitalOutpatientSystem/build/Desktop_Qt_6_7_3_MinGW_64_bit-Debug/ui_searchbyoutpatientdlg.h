/********************************************************************************
** Form generated from reading UI file 'searchbyoutpatientdlg.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHBYOUTPATIENTDLG_H
#define UI_SEARCHBYOUTPATIENTDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_SearchByOutpatientDlg
{
public:
    QDialogButtonBox *buttonBox;
    QTableWidget *tableWidget_OutpatientReception;
    QLabel *label_ReceptionInformation;

    void setupUi(QDialog *SearchByOutpatientDlg)
    {
        if (SearchByOutpatientDlg->objectName().isEmpty())
            SearchByOutpatientDlg->setObjectName("SearchByOutpatientDlg");
        SearchByOutpatientDlg->resize(800, 600);
        buttonBox = new QDialogButtonBox(SearchByOutpatientDlg);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(140, 530, 341, 32));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);
        tableWidget_OutpatientReception = new QTableWidget(SearchByOutpatientDlg);
        if (tableWidget_OutpatientReception->columnCount() < 4)
            tableWidget_OutpatientReception->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_OutpatientReception->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_OutpatientReception->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_OutpatientReception->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget_OutpatientReception->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        tableWidget_OutpatientReception->setObjectName("tableWidget_OutpatientReception");
        tableWidget_OutpatientReception->setGeometry(QRect(50, 70, 711, 441));
        label_ReceptionInformation = new QLabel(SearchByOutpatientDlg);
        label_ReceptionInformation->setObjectName("label_ReceptionInformation");
        label_ReceptionInformation->setGeometry(QRect(20, 10, 391, 61));
        QFont font;
        font.setFamilies({QString::fromUtf8("Modern No. 20")});
        font.setPointSize(16);
        label_ReceptionInformation->setFont(font);

        retranslateUi(SearchByOutpatientDlg);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, SearchByOutpatientDlg, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, SearchByOutpatientDlg, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(SearchByOutpatientDlg);
    } // setupUi

    void retranslateUi(QDialog *SearchByOutpatientDlg)
    {
        SearchByOutpatientDlg->setWindowTitle(QCoreApplication::translate("SearchByOutpatientDlg", "Dialog", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_OutpatientReception->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("SearchByOutpatientDlg", "\345\260\261\350\257\212\344\272\272\345\247\223\345\220\215", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_OutpatientReception->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("SearchByOutpatientDlg", "\345\260\261\350\257\212\344\272\272\346\200\247\345\210\253", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_OutpatientReception->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("SearchByOutpatientDlg", "\345\260\261\350\257\212\344\272\272\345\271\264\351\276\204", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_OutpatientReception->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("SearchByOutpatientDlg", "\345\260\261\350\257\212\344\272\272\350\201\224\347\263\273\346\226\271\345\274\217", nullptr));
        label_ReceptionInformation->setText(QCoreApplication::translate("SearchByOutpatientDlg", "\351\242\204\347\272\246\346\203\205\345\206\265\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SearchByOutpatientDlg: public Ui_SearchByOutpatientDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHBYOUTPATIENTDLG_H
