/********************************************************************************
** Form generated from reading UI file 'fileshow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILESHOW_H
#define UI_FILESHOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_FileShow
{
public:
    QTextEdit *FirstProg;
    QTextEdit *SecondProg;
    QPushButton *EqualBtn;
    QPushButton *InequalBtn;

    void setupUi(QDialog *FileShow)
    {
        if (FileShow->objectName().isEmpty())
            FileShow->setObjectName(QString::fromUtf8("FileShow"));
        FileShow->resize(800, 600);
        FirstProg = new QTextEdit(FileShow);
        FirstProg->setObjectName(QString::fromUtf8("FirstProg"));
        FirstProg->setGeometry(QRect(10, 10, 391, 531));
        FirstProg->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        FirstProg->setLineWrapMode(QTextEdit::NoWrap);
        SecondProg = new QTextEdit(FileShow);
        SecondProg->setObjectName(QString::fromUtf8("SecondProg"));
        SecondProg->setGeometry(QRect(410, 10, 381, 531));
        SecondProg->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        SecondProg->setLineWrapMode(QTextEdit::NoWrap);
        EqualBtn = new QPushButton(FileShow);
        EqualBtn->setObjectName(QString::fromUtf8("EqualBtn"));
        EqualBtn->setGeometry(QRect(80, 560, 89, 25));
        InequalBtn = new QPushButton(FileShow);
        InequalBtn->setObjectName(QString::fromUtf8("InequalBtn"));
        InequalBtn->setGeometry(QRect(650, 560, 89, 25));

        retranslateUi(FileShow);

        QMetaObject::connectSlotsByName(FileShow);
    } // setupUi

    void retranslateUi(QDialog *FileShow)
    {
        FileShow->setWindowTitle(QCoreApplication::translate("FileShow", "Dialog", nullptr));
        EqualBtn->setText(QCoreApplication::translate("FileShow", "\347\255\211\344\273\267", nullptr));
        InequalBtn->setText(QCoreApplication::translate("FileShow", "\344\270\215\347\255\211\344\273\267", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FileShow: public Ui_FileShow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILESHOW_H
