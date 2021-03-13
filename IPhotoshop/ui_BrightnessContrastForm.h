/********************************************************************************
** Form generated from reading UI file 'BrightnessContrastForm.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BRIGHTNESSCONTRASTFORM_H
#define UI_BRIGHTNESSCONTRASTFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BrightnessContrastForm
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QSlider *horizontalSlider_2;
    QSlider *horizontalSlider;
    QLabel *label_2;
    QSpinBox *spinBox;
    QSpinBox *spinBox1;

    void setupUi(QWidget *BrightnessContrastForm)
    {
        if (BrightnessContrastForm->objectName().isEmpty())
            BrightnessContrastForm->setObjectName(QStringLiteral("BrightnessContrastForm"));
        BrightnessContrastForm->resize(299, 96);
        BrightnessContrastForm->setMaximumSize(QSize(300, 96));
        gridLayout = new QGridLayout(BrightnessContrastForm);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(BrightnessContrastForm);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 2);

        horizontalSlider_2 = new QSlider(BrightnessContrastForm);
        horizontalSlider_2->setObjectName(QStringLiteral("horizontalSlider_2"));
        horizontalSlider_2->setMinimum(1);
        horizontalSlider_2->setOrientation(Qt::Horizontal);
        horizontalSlider_2->setTickPosition(QSlider::TicksBelow);

        gridLayout->addWidget(horizontalSlider_2, 1, 1, 1, 2);

        horizontalSlider = new QSlider(BrightnessContrastForm);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setMinimum(0);
        horizontalSlider->setOrientation(Qt::Horizontal);
        horizontalSlider->setTickPosition(QSlider::TicksBelow);
        horizontalSlider->setTickInterval(0);

        gridLayout->addWidget(horizontalSlider, 0, 2, 1, 1);

        label_2 = new QLabel(BrightnessContrastForm);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        spinBox = new QSpinBox(BrightnessContrastForm);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setMinimum(0);

        gridLayout->addWidget(spinBox, 0, 3, 1, 1);

        spinBox1 = new QSpinBox(BrightnessContrastForm);
        spinBox1->setObjectName(QStringLiteral("spinBox1"));
        spinBox1->setMinimum(1);

        gridLayout->addWidget(spinBox1, 1, 3, 1, 1);


        retranslateUi(BrightnessContrastForm);

        QMetaObject::connectSlotsByName(BrightnessContrastForm);
    } // setupUi

    void retranslateUi(QWidget *BrightnessContrastForm)
    {
        BrightnessContrastForm->setWindowTitle(QApplication::translate("BrightnessContrastForm", "Form", nullptr));
        label->setText(QApplication::translate("BrightnessContrastForm", "Brightness:", nullptr));
        label_2->setText(QApplication::translate("BrightnessContrastForm", "Contatst :", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BrightnessContrastForm: public Ui_BrightnessContrastForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BRIGHTNESSCONTRASTFORM_H
