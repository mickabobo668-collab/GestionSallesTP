/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *btnAjouter;
    QPushButton *btnSupprimer;
    QPushButton *btnModifier;
    QLineEdit *txtNom;
    QLineEdit *txtPrenom;
    QLineEdit *txtEmail;
    QPushButton *btnActualiser;
    QTableWidget *tableEnseignants;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 10, 49, 16));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(270, 10, 49, 16));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(20, 80, 49, 16));
        btnAjouter = new QPushButton(centralwidget);
        btnAjouter->setObjectName("btnAjouter");
        btnAjouter->setGeometry(QRect(20, 150, 80, 24));
        btnSupprimer = new QPushButton(centralwidget);
        btnSupprimer->setObjectName("btnSupprimer");
        btnSupprimer->setGeometry(QRect(200, 150, 80, 24));
        btnModifier = new QPushButton(centralwidget);
        btnModifier->setObjectName("btnModifier");
        btnModifier->setGeometry(QRect(110, 150, 80, 24));
        txtNom = new QLineEdit(centralwidget);
        txtNom->setObjectName("txtNom");
        txtNom->setGeometry(QRect(20, 40, 113, 24));
        txtPrenom = new QLineEdit(centralwidget);
        txtPrenom->setObjectName("txtPrenom");
        txtPrenom->setGeometry(QRect(280, 40, 113, 24));
        txtEmail = new QLineEdit(centralwidget);
        txtEmail->setObjectName("txtEmail");
        txtEmail->setGeometry(QRect(20, 110, 113, 24));
        btnActualiser = new QPushButton(centralwidget);
        btnActualiser->setObjectName("btnActualiser");
        btnActualiser->setGeometry(QRect(290, 150, 80, 24));
        tableEnseignants = new QTableWidget(centralwidget);
        if (tableEnseignants->columnCount() < 4)
            tableEnseignants->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableEnseignants->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableEnseignants->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableEnseignants->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableEnseignants->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        tableEnseignants->setObjectName("tableEnseignants");
        tableEnseignants->setGeometry(QRect(10, 191, 461, 201));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Nom", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Pr\303\251nom", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Email", nullptr));
        btnAjouter->setText(QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
        btnSupprimer->setText(QCoreApplication::translate("MainWindow", "Supprimer", nullptr));
        btnModifier->setText(QCoreApplication::translate("MainWindow", "Modifier", nullptr));
        txtNom->setText(QString());
        txtPrenom->setText(QString());
        txtEmail->setText(QString());
        btnActualiser->setText(QCoreApplication::translate("MainWindow", "Actualiser", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableEnseignants->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableEnseignants->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableEnseignants->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Pr\303\251nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableEnseignants->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Email", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
