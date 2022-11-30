/********************************************************************************
** Form generated from reading UI file 'confgui.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFGUI_H
#define UI_CONFGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ConfGui
{
public:
    QWidget *centralwidget;

    void setupUi(QMainWindow *ConfGui)
    {
        if (ConfGui->objectName().isEmpty())
            ConfGui->setObjectName(QString::fromUtf8("ConfGui"));
        ConfGui->resize(251, 271);
        centralwidget = new QWidget(ConfGui);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        ConfGui->setCentralWidget(centralwidget);

        retranslateUi(ConfGui);

        QMetaObject::connectSlotsByName(ConfGui);
    } // setupUi

    void retranslateUi(QMainWindow *ConfGui)
    {
        ConfGui->setWindowTitle(QCoreApplication::translate("ConfGui", "ConfGui", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ConfGui: public Ui_ConfGui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFGUI_H
