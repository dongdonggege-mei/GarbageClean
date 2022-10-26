/********************************************************************************
** Form generated from reading UI file 'Cleaner.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLEANER_H
#define UI_CLEANER_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CleanerClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QTreeView *treeView;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_3;
    QPushButton *start;
    QPushButton *stop;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLCDNumber *time;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QLCDNumber *fCountN;
    QSpacerItem *verticalSpacer_2;
    QVBoxLayout *verticalLayout_2;
    QPushButton *select_all;
    QPushButton *unselect;
    QPushButton *clear_all;
    QPushButton *unfold_all;
    QPushButton *fold_all;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *CleanerClass)
    {
        if (CleanerClass->objectName().isEmpty())
            CleanerClass->setObjectName(QString::fromUtf8("CleanerClass"));
        CleanerClass->resize(941, 747);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Cleaner/res/\345\236\203\345\234\276\346\270\205\347\220\206\345\233\276\346\240\207.png"), QSize(), QIcon::Normal, QIcon::Off);
        CleanerClass->setWindowIcon(icon);
        centralWidget = new QWidget(CleanerClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_3 = new QGridLayout(centralWidget);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setStyleSheet(QString::fromUtf8("background-color: rgb(209, 209, 209);"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        treeView = new QTreeView(groupBox);
        treeView->setObjectName(QString::fromUtf8("treeView"));

        verticalLayout->addWidget(treeView);

        verticalLayout->setStretch(0, 1);

        gridLayout->addLayout(verticalLayout, 0, 1, 1, 1);


        horizontalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setStyleSheet(QString::fromUtf8("background-color: rgb(209, 209, 209);"));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        start = new QPushButton(groupBox_2);
        start->setObjectName(QString::fromUtf8("start"));

        verticalLayout_3->addWidget(start);

        stop = new QPushButton(groupBox_2);
        stop->setObjectName(QString::fromUtf8("stop"));

        verticalLayout_3->addWidget(stop);


        gridLayout_2->addLayout(verticalLayout_3, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 1, 0, 1, 1);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_3->addWidget(label_2);

        time = new QLCDNumber(groupBox_2);
        time->setObjectName(QString::fromUtf8("time"));

        horizontalLayout_3->addWidget(time);

        horizontalLayout_3->setStretch(0, 1);
        horizontalLayout_3->setStretch(1, 2);

        verticalLayout_4->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_4->addWidget(label_3);

        fCountN = new QLCDNumber(groupBox_2);
        fCountN->setObjectName(QString::fromUtf8("fCountN"));

        horizontalLayout_4->addWidget(fCountN);

        horizontalLayout_4->setStretch(0, 1);
        horizontalLayout_4->setStretch(1, 2);

        verticalLayout_4->addLayout(horizontalLayout_4);


        gridLayout_2->addLayout(verticalLayout_4, 2, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_2, 3, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        select_all = new QPushButton(groupBox_2);
        select_all->setObjectName(QString::fromUtf8("select_all"));

        verticalLayout_2->addWidget(select_all);

        unselect = new QPushButton(groupBox_2);
        unselect->setObjectName(QString::fromUtf8("unselect"));

        verticalLayout_2->addWidget(unselect);

        clear_all = new QPushButton(groupBox_2);
        clear_all->setObjectName(QString::fromUtf8("clear_all"));

        verticalLayout_2->addWidget(clear_all);

        unfold_all = new QPushButton(groupBox_2);
        unfold_all->setObjectName(QString::fromUtf8("unfold_all"));

        verticalLayout_2->addWidget(unfold_all);

        fold_all = new QPushButton(groupBox_2);
        fold_all->setObjectName(QString::fromUtf8("fold_all"));

        verticalLayout_2->addWidget(fold_all);


        gridLayout_2->addLayout(verticalLayout_2, 4, 0, 1, 1);

        gridLayout_2->setRowStretch(0, 1);
        gridLayout_2->setRowStretch(1, 1);
        gridLayout_2->setRowStretch(2, 1);
        gridLayout_2->setRowStretch(3, 1);
        gridLayout_2->setRowStretch(4, 1);

        horizontalLayout->addWidget(groupBox_2);

        horizontalLayout->setStretch(0, 4);
        horizontalLayout->setStretch(1, 1);

        gridLayout_3->addLayout(horizontalLayout, 0, 0, 1, 1);

        CleanerClass->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(CleanerClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        CleanerClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(CleanerClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        CleanerClass->setStatusBar(statusBar);

        retranslateUi(CleanerClass);

        QMetaObject::connectSlotsByName(CleanerClass);
    } // setupUi

    void retranslateUi(QMainWindow *CleanerClass)
    {
        CleanerClass->setWindowTitle(QCoreApplication::translate("CleanerClass", "\345\236\203\345\234\276\346\270\205\347\220\206V1", nullptr));
        groupBox->setTitle(QCoreApplication::translate("CleanerClass", "\346\226\207\344\273\266\346\211\253\346\217\217\347\273\223\346\236\234", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("CleanerClass", "\346\223\215\344\275\234", nullptr));
        start->setText(QCoreApplication::translate("CleanerClass", "\345\274\200\345\247\213\346\211\253\346\217\217", nullptr));
        stop->setText(QCoreApplication::translate("CleanerClass", "\345\201\234\346\255\242\346\211\253\346\217\217", nullptr));
        label_2->setText(QCoreApplication::translate("CleanerClass", "\347\224\250\346\227\266", nullptr));
        label_3->setText(QCoreApplication::translate("CleanerClass", "\346\211\253\346\217\217\346\226\207\344\273\266\346\225\260\347\233\256", nullptr));
        select_all->setText(QCoreApplication::translate("CleanerClass", "\345\205\250\351\200\211", nullptr));
        unselect->setText(QCoreApplication::translate("CleanerClass", "\345\205\250\345\220\246", nullptr));
        clear_all->setText(QCoreApplication::translate("CleanerClass", "\345\210\240\351\231\244\351\200\211\344\270\255\346\226\207\344\273\266", nullptr));
        unfold_all->setText(QCoreApplication::translate("CleanerClass", "\345\205\250\351\203\250\345\261\225\345\274\200", nullptr));
        fold_all->setText(QCoreApplication::translate("CleanerClass", "\345\205\250\351\203\250\346\212\230\345\217\240", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CleanerClass: public Ui_CleanerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLEANER_H
