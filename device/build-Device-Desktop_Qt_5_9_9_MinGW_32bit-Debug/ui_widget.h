/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QHBoxLayout *horizontalLayout_2;
    QStackedWidget *stackedWidget;
    QWidget *loginPage;
    QLabel *label;
    QLabel *label_3;
    QLineEdit *loginIdEdit;
    QLineEdit *loginpwdEdit;
    QPushButton *loginButton;
    QWidget *registePage;
    QLineEdit *registepwdEdit;
    QPushButton *registeButton;
    QLabel *label_2;
    QLabel *label_4;
    QLineEdit *registeIdEdit;
    QLineEdit *lineEdit;
    QWidget *dispPage;
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *portLabel;
    QLineEdit *portLineEdit;
    QPushButton *startButton;
    QPushButton *sendButton;
    QPushButton *pushButton;
    QPushButton *stopButton;
    QTableView *tableView;
    QWidget *Wavewidget;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(800, 600);
        horizontalLayout_2 = new QHBoxLayout(Widget);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        stackedWidget = new QStackedWidget(Widget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        loginPage = new QWidget();
        loginPage->setObjectName(QStringLiteral("loginPage"));
        loginPage->setStyleSheet(QStringLiteral("background-color: rgb(85, 255, 255);"));
        label = new QLabel(loginPage);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(170, 130, 101, 41));
        label->setStyleSheet(QString::fromUtf8("font: 10pt \"\346\245\267\344\275\223\";"));
        label->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(loginPage);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(170, 200, 101, 41));
        label_3->setStyleSheet(QString::fromUtf8("font: 10pt \"\346\245\267\344\275\223\";"));
        label_3->setAlignment(Qt::AlignCenter);
        loginIdEdit = new QLineEdit(loginPage);
        loginIdEdit->setObjectName(QStringLiteral("loginIdEdit"));
        loginIdEdit->setGeometry(QRect(280, 130, 311, 31));
        loginIdEdit->setAlignment(Qt::AlignCenter);
        loginpwdEdit = new QLineEdit(loginPage);
        loginpwdEdit->setObjectName(QStringLiteral("loginpwdEdit"));
        loginpwdEdit->setGeometry(QRect(280, 210, 311, 31));
        loginpwdEdit->setEchoMode(QLineEdit::Password);
        loginpwdEdit->setAlignment(Qt::AlignCenter);
        loginButton = new QPushButton(loginPage);
        loginButton->setObjectName(QStringLiteral("loginButton"));
        loginButton->setGeometry(QRect(290, 290, 141, 41));
        stackedWidget->addWidget(loginPage);
        registePage = new QWidget();
        registePage->setObjectName(QStringLiteral("registePage"));
        registePage->setStyleSheet(QStringLiteral("background-color: rgb(85, 255, 127);"));
        registepwdEdit = new QLineEdit(registePage);
        registepwdEdit->setObjectName(QStringLiteral("registepwdEdit"));
        registepwdEdit->setGeometry(QRect(320, 230, 291, 31));
        registepwdEdit->setEchoMode(QLineEdit::Password);
        registepwdEdit->setAlignment(Qt::AlignCenter);
        registeButton = new QPushButton(registePage);
        registeButton->setObjectName(QStringLiteral("registeButton"));
        registeButton->setGeometry(QRect(320, 300, 141, 41));
        registeButton->setStyleSheet(QString::fromUtf8("font: 11pt \"\346\245\267\344\275\223\";"));
        label_2 = new QLabel(registePage);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(210, 170, 101, 41));
        label_2->setStyleSheet(QString::fromUtf8("font: 10pt \"\346\245\267\344\275\223\";"));
        label_2->setAlignment(Qt::AlignCenter);
        label_4 = new QLabel(registePage);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(210, 220, 101, 41));
        label_4->setStyleSheet(QString::fromUtf8("font: 10pt \"\346\245\267\344\275\223\";"));
        label_4->setAlignment(Qt::AlignCenter);
        registeIdEdit = new QLineEdit(registePage);
        registeIdEdit->setObjectName(QStringLiteral("registeIdEdit"));
        registeIdEdit->setGeometry(QRect(320, 170, 291, 31));
        registeIdEdit->setAlignment(Qt::AlignCenter);
        registeIdEdit->setReadOnly(true);
        lineEdit = new QLineEdit(registePage);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(180, 50, 461, 61));
        lineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 0, 0);\n"
"font: 12pt \"\346\245\267\344\275\223\";"));
        lineEdit->setAlignment(Qt::AlignCenter);
        stackedWidget->addWidget(registePage);
        dispPage = new QWidget();
        dispPage->setObjectName(QStringLiteral("dispPage"));
        dispPage->setStyleSheet(QLatin1String("\n"
"background-color: rgb(255, 255, 255);"));
        verticalLayout = new QVBoxLayout(dispPage);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        widget = new QWidget(dispPage);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setStyleSheet(QStringLiteral("background-color: rgb(170, 255, 255);"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        portLabel = new QLabel(widget);
        portLabel->setObjectName(QStringLiteral("portLabel"));
        portLabel->setStyleSheet(QStringLiteral("font: 12pt \"Courier New\";"));

        horizontalLayout->addWidget(portLabel);

        portLineEdit = new QLineEdit(widget);
        portLineEdit->setObjectName(QStringLiteral("portLineEdit"));

        horizontalLayout->addWidget(portLineEdit);

        startButton = new QPushButton(widget);
        startButton->setObjectName(QStringLiteral("startButton"));
        startButton->setStyleSheet(QString::fromUtf8("font: 12pt \"\346\245\267\344\275\223\";"));

        horizontalLayout->addWidget(startButton);

        sendButton = new QPushButton(widget);
        sendButton->setObjectName(QStringLiteral("sendButton"));
        sendButton->setStyleSheet(QString::fromUtf8("font: 12pt \"\346\245\267\344\275\223\";"));

        horizontalLayout->addWidget(sendButton);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setStyleSheet(QString::fromUtf8("font: 12pt \"\346\245\267\344\275\223\";\n"
""));

        horizontalLayout->addWidget(pushButton);

        stopButton = new QPushButton(widget);
        stopButton->setObjectName(QStringLiteral("stopButton"));
        stopButton->setEnabled(false);
        stopButton->setStyleSheet(QString::fromUtf8("font: 12pt \"\346\245\267\344\275\223\";"));

        horizontalLayout->addWidget(stopButton);


        verticalLayout->addWidget(widget);

        tableView = new QTableView(dispPage);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setLayoutDirection(Qt::LeftToRight);
        tableView->setStyleSheet(QString::fromUtf8("background-color: rgb(184, 255, 222);\n"
"font: 12pt \"\346\245\267\344\275\223\";\n"
"color: rgb(0, 0, 0);"));
        tableView->setGridStyle(Qt::DashDotLine);

        verticalLayout->addWidget(tableView);

        Wavewidget = new QWidget(dispPage);
        Wavewidget->setObjectName(QStringLiteral("Wavewidget"));
        Wavewidget->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));

        verticalLayout->addWidget(Wavewidget);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 2);
        verticalLayout->setStretch(2, 10);
        stackedWidget->addWidget(dispPage);

        horizontalLayout_2->addWidget(stackedWidget);


        retranslateUi(Widget);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));
        label->setText(QApplication::translate("Widget", "\350\256\276\345\244\207\345\272\217\345\210\227\345\217\267\357\274\232", Q_NULLPTR));
        label_3->setText(QApplication::translate("Widget", "\345\257\206\347\240\201\357\274\232", Q_NULLPTR));
        loginIdEdit->setPlaceholderText(QApplication::translate("Widget", "\350\257\267\350\276\223\345\205\245\345\272\217\345\210\227\345\217\267", Q_NULLPTR));
        loginpwdEdit->setPlaceholderText(QApplication::translate("Widget", "\350\257\267\350\276\223\345\205\245\345\257\206\347\240\201", Q_NULLPTR));
        loginButton->setText(QApplication::translate("Widget", "\347\231\273\351\231\206", Q_NULLPTR));
        registepwdEdit->setPlaceholderText(QApplication::translate("Widget", "\350\276\223\345\205\245\346\202\250\347\232\204\345\257\206\347\240\201", Q_NULLPTR));
        registeButton->setText(QApplication::translate("Widget", "\346\263\250\345\206\214", Q_NULLPTR));
        label_2->setText(QApplication::translate("Widget", "\350\256\276\345\244\207\345\272\217\345\210\227\345\217\267\357\274\232", Q_NULLPTR));
        label_4->setText(QApplication::translate("Widget", "\345\257\206\347\240\201\357\274\232", Q_NULLPTR));
        registeIdEdit->setPlaceholderText(QApplication::translate("Widget", "\350\257\267\350\276\223\345\205\245\345\272\217\345\210\227\345\217\267", Q_NULLPTR));
        lineEdit->setText(QApplication::translate("Widget", "\350\256\276\345\244\207\344\270\215\345\255\230\345\234\250\357\274\214\350\257\267\346\202\250\346\263\250\345\206\214\357\274\201", Q_NULLPTR));
        portLabel->setText(QApplication::translate("Widget", "Port:", Q_NULLPTR));
        startButton->setText(QApplication::translate("Widget", "\345\220\257\345\212\250", Q_NULLPTR));
        sendButton->setText(QApplication::translate("Widget", "\345\217\221\351\200\201\346\225\260\346\215\256", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Widget", "\344\277\235\345\255\230\346\225\260\346\215\256", Q_NULLPTR));
        stopButton->setText(QApplication::translate("Widget", "\347\273\210\346\255\242", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
