/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionguahao;
    QWidget *centralwidget;
    QPushButton *pushButton_Appointment;
    QPushButton *pushButton_Reception;
    QPushButton *pushButton_PatientInfo;
    QMenuBar *menubar;
    QMenu *menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 510);
        QFont font;
        font.setPointSize(14);
        MainWindow->setFont(font);
        actionguahao = new QAction(MainWindow);
        actionguahao->setObjectName("actionguahao");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        pushButton_Appointment = new QPushButton(centralwidget);
        pushButton_Appointment->setObjectName("pushButton_Appointment");
        pushButton_Appointment->setGeometry(QRect(320, 340, 151, 61));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(false);
        pushButton_Appointment->setFont(font1);
        pushButton_Reception = new QPushButton(centralwidget);
        pushButton_Reception->setObjectName("pushButton_Reception");
        pushButton_Reception->setGeometry(QRect(570, 340, 151, 61));
        pushButton_Reception->setFont(font1);
        pushButton_PatientInfo = new QPushButton(centralwidget);
        pushButton_PatientInfo->setObjectName("pushButton_PatientInfo");
        pushButton_PatientInfo->setGeometry(QRect(60, 340, 151, 61));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_PatientInfo->sizePolicy().hasHeightForWidth());
        pushButton_PatientInfo->setSizePolicy(sizePolicy);
        pushButton_PatientInfo->setFont(font1);
        pushButton_PatientInfo->setStyleSheet(QString::fromUtf8(""));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 34));
        menu = new QMenu(menubar);
        menu->setObjectName("menu");
        menu->setGeometry(QRect(0, 0, 178, 74));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionguahao->setText(QCoreApplication::translate("MainWindow", "guahao ", nullptr));
        pushButton_Appointment->setText(QCoreApplication::translate("MainWindow", "\345\274\200\345\247\213\351\242\204\347\272\246", nullptr));
        pushButton_Reception->setText(QCoreApplication::translate("MainWindow", "\346\237\245\350\257\242\351\242\204\347\272\246\344\277\241\346\201\257", nullptr));
        pushButton_PatientInfo->setText(QCoreApplication::translate("MainWindow", "\345\260\261\350\257\212\344\272\272\344\277\241\346\201\257", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\345\214\273\351\231\242\351\227\250\350\257\212\346\214\202\345\217\267\347\256\241\347\220\206\347\263\273\347\273\237", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
