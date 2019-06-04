/********************************************************************************
** Form generated from reading UI file 'FirstQt.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FIRSTQT_H
#define UI_FIRSTQT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FirstQtClass
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QTextEdit *textEdit;
    QLabel *label;
    QTextEdit *textEdit_2;
    QLabel *label_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *FirstQtClass)
    {
        if (FirstQtClass->objectName().isEmpty())
            FirstQtClass->setObjectName(QStringLiteral("FirstQtClass"));
        FirstQtClass->resize(293, 236);
        centralWidget = new QWidget(FirstQtClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(190, 120, 71, 34));
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(90, 20, 171, 31));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 30, 45, 21));
        textEdit_2 = new QTextEdit(centralWidget);
        textEdit_2->setObjectName(QStringLiteral("textEdit_2"));
        textEdit_2->setGeometry(QRect(90, 60, 171, 31));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 70, 45, 21));
        FirstQtClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(FirstQtClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 293, 30));
        FirstQtClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(FirstQtClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        FirstQtClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(FirstQtClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        FirstQtClass->setStatusBar(statusBar);

        retranslateUi(FirstQtClass);

        QMetaObject::connectSlotsByName(FirstQtClass);
    } // setupUi

    void retranslateUi(QMainWindow *FirstQtClass)
    {
        FirstQtClass->setWindowTitle(QApplication::translate("FirstQtClass", "FirstQt", Q_NULLPTR));
        pushButton->setText(QApplication::translate("FirstQtClass", "\347\241\256\345\256\232", Q_NULLPTR));
        label->setText(QApplication::translate("FirstQtClass", "<html><head/><body><p align=\"right\">\345\220\215\347\247\260:</p></body></html>", Q_NULLPTR));
        label_2->setText(QApplication::translate("FirstQtClass", "<html><head/><body><p align=\"right\">\347\224\265\350\257\235:</p></body></html>", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class FirstQtClass: public Ui_FirstQtClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FIRSTQT_H
