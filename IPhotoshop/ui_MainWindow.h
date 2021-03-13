/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionRatation;
    QAction *actionCur;
    QAction *actionReset;
    QAction *actionNext;
    QAction *actionzz;
    QAction *actionsx;
    QAction *actionbc;
    QAction *actionOpen;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QStatusBar *statusBar;
    QToolBar *leftFrameTool;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1226, 680);
        actionRatation = new QAction(MainWindow);
        actionRatation->setObjectName(QStringLiteral("actionRatation"));
        actionCur = new QAction(MainWindow);
        actionCur->setObjectName(QStringLiteral("actionCur"));
        actionReset = new QAction(MainWindow);
        actionReset->setObjectName(QStringLiteral("actionReset"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/image/icon/zoomIn.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionReset->setIcon(icon);
        actionNext = new QAction(MainWindow);
        actionNext->setObjectName(QStringLiteral("actionNext"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/image/icon/zoomOut.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNext->setIcon(icon1);
        actionzz = new QAction(MainWindow);
        actionzz->setObjectName(QStringLiteral("actionzz"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/image/icon/drag.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionzz->setIcon(icon2);
        actionsx = new QAction(MainWindow);
        actionsx->setObjectName(QStringLiteral("actionsx"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/image/icon/drop.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionsx->setIcon(icon3);
        actionbc = new QAction(MainWindow);
        actionbc->setObjectName(QStringLiteral("actionbc"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/image/icon/saveproject.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionbc->setIcon(icon4);
        actionbc->setShortcutContext(Qt::WidgetShortcut);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionOpen->setCheckable(false);
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/image/icon/openproject.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen->setIcon(icon5);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1226, 23));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        leftFrameTool = new QToolBar(MainWindow);
        leftFrameTool->setObjectName(QStringLiteral("leftFrameTool"));
        leftFrameTool->setMinimumSize(QSize(30, 0));
        leftFrameTool->setOrientation(Qt::Vertical);
        MainWindow->addToolBar(Qt::LeftToolBarArea, leftFrameTool);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        toolBar->addAction(actionOpen);
        toolBar->addAction(actionbc);
        toolBar->addAction(actionsx);
        toolBar->addAction(actionzz);
        toolBar->addAction(actionReset);
        toolBar->addAction(actionNext);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionRatation->setText(QApplication::translate("MainWindow", "Ratation", nullptr));
        actionCur->setText(QApplication::translate("MainWindow", "Cur", nullptr));
        actionReset->setText(QString());
        actionNext->setText(QString());
        actionzz->setText(QString());
        actionsx->setText(QApplication::translate("MainWindow", "sx", nullptr));
        actionbc->setText(QApplication::translate("MainWindow", "bc", nullptr));
        actionOpen->setText(QApplication::translate("MainWindow", "Open", nullptr));
        leftFrameTool->setWindowTitle(QApplication::translate("MainWindow", "toolBar", nullptr));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
