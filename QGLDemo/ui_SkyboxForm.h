/********************************************************************************
** Form generated from reading UI file 'SkyboxForm.ui'
**
** Created by: Qt User Interface Compiler version 5.12.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SKYBOXFORM_H
#define UI_SKYBOXFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SkyboxForm
{
public:

    void setupUi(QWidget *SkyboxForm)
    {
        if (SkyboxForm->objectName().isEmpty())
            SkyboxForm->setObjectName(QString::fromUtf8("SkyboxForm"));
        SkyboxForm->resize(400, 300);

        retranslateUi(SkyboxForm);

        QMetaObject::connectSlotsByName(SkyboxForm);
    } // setupUi

    void retranslateUi(QWidget *SkyboxForm)
    {
        SkyboxForm->setWindowTitle(QApplication::translate("SkyboxForm", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SkyboxForm: public Ui_SkyboxForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SKYBOXFORM_H
