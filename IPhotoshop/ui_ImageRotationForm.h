/********************************************************************************
** Form generated from reading UI file 'ImageRotationForm.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGEROTATIONFORM_H
#define UI_IMAGEROTATIONFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ImageRotationForm
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSlider *horizontalSlider;
    QSpinBox *spinBox;

    void setupUi(QWidget *ImageRotationForm)
    {
        if (ImageRotationForm->objectName().isEmpty())
            ImageRotationForm->setObjectName(QStringLiteral("ImageRotationForm"));
        ImageRotationForm->resize(300, 40);
        ImageRotationForm->setMinimumSize(QSize(300, 40));
        ImageRotationForm->setMaximumSize(QSize(300, 40));
        verticalLayout = new QVBoxLayout(ImageRotationForm);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(ImageRotationForm);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        horizontalSlider = new QSlider(ImageRotationForm);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setMaximum(360);
        horizontalSlider->setOrientation(Qt::Horizontal);
        horizontalSlider->setTickPosition(QSlider::TicksBelow);

        horizontalLayout->addWidget(horizontalSlider);

        spinBox = new QSpinBox(ImageRotationForm);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setMaximum(360);

        horizontalLayout->addWidget(spinBox);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(ImageRotationForm);

        QMetaObject::connectSlotsByName(ImageRotationForm);
    } // setupUi

    void retranslateUi(QWidget *ImageRotationForm)
    {
        ImageRotationForm->setWindowTitle(QApplication::translate("ImageRotationForm", "Form", nullptr));
        label->setText(QApplication::translate("ImageRotationForm", "\350\247\222\345\272\246\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ImageRotationForm: public Ui_ImageRotationForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGEROTATIONFORM_H
