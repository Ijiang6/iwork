/********************************************************************************
** Form generated from reading UI file 'ImageCroppingForm.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGECROPPINGFORM_H
#define UI_IMAGECROPPINGFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ImageCroppingForm
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QToolButton *toolButton_2;
    QToolButton *toolButton;
    QPushButton *pushButton;
    QToolButton *toolButton_3;
    QToolButton *toolButton_4;
    QToolButton *toolButton_5;

    void setupUi(QWidget *ImageCroppingForm)
    {
        if (ImageCroppingForm->objectName().isEmpty())
            ImageCroppingForm->setObjectName(QStringLiteral("ImageCroppingForm"));
        ImageCroppingForm->resize(300, 126);
        ImageCroppingForm->setMinimumSize(QSize(300, 126));
        ImageCroppingForm->setMaximumSize(QSize(300, 126));
        verticalLayout = new QVBoxLayout(ImageCroppingForm);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        toolButton_2 = new QToolButton(ImageCroppingForm);
        toolButton_2->setObjectName(QStringLiteral("toolButton_2"));
        toolButton_2->setMinimumSize(QSize(80, 50));
        toolButton_2->setMaximumSize(QSize(80, 50));

        gridLayout->addWidget(toolButton_2, 0, 2, 1, 1);

        toolButton = new QToolButton(ImageCroppingForm);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        toolButton->setMinimumSize(QSize(80, 50));
        toolButton->setMaximumSize(QSize(80, 50));

        gridLayout->addWidget(toolButton, 0, 0, 1, 1);

        pushButton = new QPushButton(ImageCroppingForm);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMinimumSize(QSize(80, 50));
        pushButton->setMaximumSize(QSize(80, 50));

        gridLayout->addWidget(pushButton, 0, 1, 1, 1);

        toolButton_3 = new QToolButton(ImageCroppingForm);
        toolButton_3->setObjectName(QStringLiteral("toolButton_3"));
        toolButton_3->setMinimumSize(QSize(80, 50));
        toolButton_3->setMaximumSize(QSize(80, 50));

        gridLayout->addWidget(toolButton_3, 1, 0, 1, 1);

        toolButton_4 = new QToolButton(ImageCroppingForm);
        toolButton_4->setObjectName(QStringLiteral("toolButton_4"));
        toolButton_4->setMinimumSize(QSize(80, 50));
        toolButton_4->setMaximumSize(QSize(80, 50));

        gridLayout->addWidget(toolButton_4, 1, 1, 1, 1);

        toolButton_5 = new QToolButton(ImageCroppingForm);
        toolButton_5->setObjectName(QStringLiteral("toolButton_5"));
        toolButton_5->setMinimumSize(QSize(80, 50));
        toolButton_5->setMaximumSize(QSize(80, 50));

        gridLayout->addWidget(toolButton_5, 1, 2, 1, 1);


        verticalLayout->addLayout(gridLayout);


        retranslateUi(ImageCroppingForm);

        QMetaObject::connectSlotsByName(ImageCroppingForm);
    } // setupUi

    void retranslateUi(QWidget *ImageCroppingForm)
    {
        ImageCroppingForm->setWindowTitle(QApplication::translate("ImageCroppingForm", "Form", nullptr));
        toolButton_2->setText(QApplication::translate("ImageCroppingForm", "customize", nullptr));
        toolButton->setText(QApplication::translate("ImageCroppingForm", "rect", nullptr));
        pushButton->setText(QApplication::translate("ImageCroppingForm", "circle", nullptr));
        toolButton_3->setText(QApplication::translate("ImageCroppingForm", "reset", nullptr));
        toolButton_4->setText(QApplication::translate("ImageCroppingForm", "select", nullptr));
        toolButton_5->setText(QApplication::translate("ImageCroppingForm", "cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ImageCroppingForm: public Ui_ImageCroppingForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGECROPPINGFORM_H
