/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QGridLayout *gridLayout;
    QWidget *down;
    QLineEdit *userLineEdit;
    QLineEdit *pwLineEdit;
    QCheckBox *rememberPw;
    QCheckBox *autoLogin;
    QLabel *usrname_label;
    QLabel *password_label;
    QPushButton *login_bt;
    QHBoxLayout *up;
    QSpacerItem *horizontalSpacer;
    QPushButton *mini_bt;
    QPushButton *close_bt;
    QVBoxLayout *middle;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QLabel *title_label;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QStringLiteral("Login"));
        Login->resize(410, 584);
        gridLayout = new QGridLayout(Login);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        down = new QWidget(Login);
        down->setObjectName(QStringLiteral("down"));
        userLineEdit = new QLineEdit(down);
        userLineEdit->setObjectName(QStringLiteral("userLineEdit"));
        userLineEdit->setGeometry(QRect(120, 20, 171, 31));
        userLineEdit->setStyleSheet(QStringLiteral("border: 1px solid rgb(209 , 209 , 209);"));
        pwLineEdit = new QLineEdit(down);
        pwLineEdit->setObjectName(QStringLiteral("pwLineEdit"));
        pwLineEdit->setGeometry(QRect(120, 60, 171, 31));
        pwLineEdit->setStyleSheet(QStringLiteral("border: 1px solid rgb(209 , 209 , 209);"));
        rememberPw = new QCheckBox(down);
        rememberPw->setObjectName(QStringLiteral("rememberPw"));
        rememberPw->setGeometry(QRect(120, 110, 91, 16));
        rememberPw->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        autoLogin = new QCheckBox(down);
        autoLogin->setObjectName(QStringLiteral("autoLogin"));
        autoLogin->setGeometry(QRect(220, 110, 91, 16));
        autoLogin->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        usrname_label = new QLabel(down);
        usrname_label->setObjectName(QStringLiteral("usrname_label"));
        usrname_label->setGeometry(QRect(300, 25, 54, 21));
        usrname_label->setStyleSheet(QLatin1String("color:rgb(0, 191 , 255);\n"
"background-color:transparent;"));
        password_label = new QLabel(down);
        password_label->setObjectName(QStringLiteral("password_label"));
        password_label->setGeometry(QRect(300, 61, 54, 31));
        password_label->setStyleSheet(QLatin1String("color:rgb(0 , 191 , 255);\n"
"background-color:transparent;"));
        login_bt = new QPushButton(down);
        login_bt->setObjectName(QStringLiteral("login_bt"));
        login_bt->setGeometry(QRect(120, 140, 171, 31));
        login_bt->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	background-color: transparent;                                            	color:  rgb(85, 255, 255); \n"
"	font: bold 20pt \345\215\216\346\226\207\350\241\214\346\245\267;  \n"
"	border-radius: 10px; \n"
"	border: 2px groove rgb(85, 255, 255);\n"
"	border-style: outset;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"	background-color:white; 	\n"
"	color: blue;\n"
"	border: 2px groove rgb(85, 255, 255);\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background-color: white;\n"
"	color: rgb(0, 255, 127);\n"
"	border: 2px groove rgb(0, 255, 127);\n"
"}"));

        gridLayout->addWidget(down, 2, 0, 1, 1);

        up = new QHBoxLayout();
        up->setObjectName(QStringLiteral("up"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        up->addItem(horizontalSpacer);

        mini_bt = new QPushButton(Login);
        mini_bt->setObjectName(QStringLiteral("mini_bt"));
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(mini_bt->sizePolicy().hasHeightForWidth());
        mini_bt->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(15);
        font.setBold(true);
        font.setWeight(75);
        mini_bt->setFont(font);
        mini_bt->setStyleSheet(QLatin1String("QPushButton{background-color: transparent;\n"
"color: rgb(255, 255, 255);}\n"
"\n"
"QPushButton:hover{color: rgb(85, 255, 255); \n"
"border: 2px groove rgb(85, 255, 255);}\n"
"\n"
"QPushButton:pressed{color: rgb(85, 255, 0); \n"
"border: 2px groove rgb(85, 255, 0); }"));
        mini_bt->setFlat(true);

        up->addWidget(mini_bt);

        close_bt = new QPushButton(Login);
        close_bt->setObjectName(QStringLiteral("close_bt"));
        sizePolicy.setHeightForWidth(close_bt->sizePolicy().hasHeightForWidth());
        close_bt->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setPointSize(17);
        font1.setBold(true);
        font1.setWeight(75);
        close_bt->setFont(font1);
        close_bt->setStyleSheet(QLatin1String("QPushButton{background-color: transparent;\n"
"color: rgb(255, 255, 255);}\n"
"\n"
"QPushButton:hover{color: rgb(85, 255, 255); \n"
"border: 2px groove rgb(85, 255, 255);}\n"
"\n"
"QPushButton:pressed{color: rgb(85, 255, 0); \n"
"border: 2px groove rgb(85, 255, 0); }"));
        close_bt->setFlat(true);

        up->addWidget(close_bt);

        up->setStretch(0, 8);
        up->setStretch(1, 1);
        up->setStretch(2, 1);

        gridLayout->addLayout(up, 0, 0, 1, 1);

        middle = new QVBoxLayout();
        middle->setObjectName(QStringLiteral("middle"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        middle->addItem(verticalSpacer_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        title_label = new QLabel(Login);
        title_label->setObjectName(QStringLiteral("title_label"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(title_label->sizePolicy().hasHeightForWidth());
        title_label->setSizePolicy(sizePolicy1);
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\215\216\346\226\207\350\241\214\346\245\267"));
        font2.setPointSize(22);
        title_label->setFont(font2);
        title_label->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(title_label);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 6);
        horizontalLayout->setStretch(2, 1);

        middle->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        middle->addItem(verticalSpacer);

        middle->setStretch(0, 1);
        middle->setStretch(1, 1);
        middle->setStretch(2, 1);

        gridLayout->addLayout(middle, 1, 0, 1, 1);

        gridLayout->setRowStretch(0, 1);
        gridLayout->setRowStretch(1, 10);
        gridLayout->setRowStretch(2, 9);

        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QDialog *Login)
    {
        Login->setWindowTitle(QApplication::translate("Login", "Dialog", Q_NULLPTR));
        rememberPw->setText(QApplication::translate("Login", "\350\256\260\344\275\217\345\257\206\347\240\201", Q_NULLPTR));
        autoLogin->setText(QApplication::translate("Login", "\350\207\252\345\212\250\347\231\273\351\231\206", Q_NULLPTR));
        usrname_label->setText(QApplication::translate("Login", "<html><head/><body><p align=\"center\"><span style=\" font-size:11pt;\">\350\264\246\345\217\267</span></p></body></html>", Q_NULLPTR));
        password_label->setText(QApplication::translate("Login", "<html><head/><body><p align=\"center\"><span style=\" font-size:11pt;\">\345\257\206\347\240\201</span></p></body></html>", Q_NULLPTR));
        login_bt->setText(QApplication::translate("Login", "\347\231\273    \351\231\206", Q_NULLPTR));
        mini_bt->setText(QApplication::translate("Login", "\342\224\201", Q_NULLPTR));
        close_bt->setText(QApplication::translate("Login", "X", Q_NULLPTR));
        title_label->setText(QApplication::translate("Login", "<html><head/><body><p align=\"center\"><span style=\" color:#ffffff;\">\346\231\272 \350\203\275 \350\275\246 \350\276\206 \350\257\206 \345\210\253 \347\263\273 \347\273\237</span></p></body></html>", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
