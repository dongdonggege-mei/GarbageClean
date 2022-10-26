/********************************************************************************
** Form generated from reading UI file 'TreeView.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TREEVIEW_H
#define UI_TREEVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TreeViewClass
{
public:
    QWidget *centralWidget;
    QTreeView *treeView;
    QPushButton *start;
    QPushButton *deleteFile;
    QPushButton *updateList;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *TreeViewClass)
    {
        if (TreeViewClass->objectName().isEmpty())
            TreeViewClass->setObjectName(QString::fromUtf8("TreeViewClass"));
        TreeViewClass->resize(600, 400);
        centralWidget = new QWidget(TreeViewClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        treeView = new QTreeView(centralWidget);
        treeView->setObjectName(QString::fromUtf8("treeView"));
        treeView->setGeometry(QRect(40, 20, 201, 271));
        start = new QPushButton(centralWidget);
        start->setObjectName(QString::fromUtf8("start"));
        start->setGeometry(QRect(370, 50, 75, 23));
        deleteFile = new QPushButton(centralWidget);
        deleteFile->setObjectName(QString::fromUtf8("deleteFile"));
        deleteFile->setGeometry(QRect(370, 110, 75, 23));
        updateList = new QPushButton(centralWidget);
        updateList->setObjectName(QString::fromUtf8("updateList"));
        updateList->setGeometry(QRect(370, 180, 75, 23));
        TreeViewClass->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(TreeViewClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        TreeViewClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(TreeViewClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        TreeViewClass->setStatusBar(statusBar);

        retranslateUi(TreeViewClass);

        QMetaObject::connectSlotsByName(TreeViewClass);
    } // setupUi

    void retranslateUi(QMainWindow *TreeViewClass)
    {
        TreeViewClass->setWindowTitle(QCoreApplication::translate("TreeViewClass", "TreeView", nullptr));
        start->setText(QCoreApplication::translate("TreeViewClass", "\345\274\200\345\247\213\346\211\253\346\217\217", nullptr));
        deleteFile->setText(QCoreApplication::translate("TreeViewClass", "\345\210\240\351\231\244\346\226\207\344\273\266", nullptr));
        updateList->setText(QCoreApplication::translate("TreeViewClass", "\346\233\264\346\226\260\345\210\227\350\241\250", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TreeViewClass: public Ui_TreeViewClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TREEVIEW_H
