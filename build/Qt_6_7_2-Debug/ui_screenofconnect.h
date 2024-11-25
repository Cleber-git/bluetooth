/********************************************************************************
** Form generated from reading UI file 'screenofconnect.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCREENOFCONNECT_H
#define UI_SCREENOFCONNECT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_screenOfConnect
{
public:
    QComboBox *cmb_connectado;
    QPushButton *pushButton;
    QComboBox *cmb_proximos;
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton_2;

    void setupUi(QWidget *screenOfConnect)
    {
        if (screenOfConnect->objectName().isEmpty())
            screenOfConnect->setObjectName("screenOfConnect");
        screenOfConnect->resize(383, 447);
        screenOfConnect->setStyleSheet(QString::fromUtf8("background-color: rgb(59, 59, 59);"));
        cmb_connectado = new QComboBox(screenOfConnect);
        cmb_connectado->setObjectName("cmb_connectado");
        cmb_connectado->setGeometry(QRect(230, 50, 121, 28));
        pushButton = new QPushButton(screenOfConnect);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(140, 370, 111, 41));
        cmb_proximos = new QComboBox(screenOfConnect);
        cmb_proximos->setObjectName("cmb_proximos");
        cmb_proximos->setGeometry(QRect(229, 110, 121, 28));
        label = new QLabel(screenOfConnect);
        label->setObjectName("label");
        label->setGeometry(QRect(159, 55, 71, 20));
        label_2 = new QLabel(screenOfConnect);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(169, 115, 51, 20));
        pushButton_2 = new QPushButton(screenOfConnect);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(355, 115, 15, 15));
        pushButton_2->setStyleSheet(QString::fromUtf8("border-image: url(:/img/refresh1.png) ;\n"
"background: rgb(255, 255, 255);"));

        retranslateUi(screenOfConnect);

        QMetaObject::connectSlotsByName(screenOfConnect);
    } // setupUi

    void retranslateUi(QWidget *screenOfConnect)
    {
        screenOfConnect->setWindowTitle(QCoreApplication::translate("screenOfConnect", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("screenOfConnect", "Atualize", nullptr));
        label->setText(QCoreApplication::translate("screenOfConnect", "Conectados:", nullptr));
        label_2->setText(QCoreApplication::translate("screenOfConnect", "P\303\263ximos:", nullptr));
        pushButton_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class screenOfConnect: public Ui_screenOfConnect {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCREENOFCONNECT_H
