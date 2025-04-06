#ifndef UI_TV_CONTROL_H
#define UI_TV_CONTROL_H

/********************************************************************************
** Form generated from reading UI file 'tv_control_panelEQXEJs.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef TV_CONTROL_PANELEQXEJS_H
#define TV_CONTROL_PANELEQXEJS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TVControlPanel
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QHBoxLayout *channels;
    QPushButton *ch_back;
    QPushButton *ch_forward;
    QHBoxLayout *volume;
    QPushButton *vol_low;
    QPushButton *vol_high;
    QLineEdit *display;
    QGridLayout *numbers;
    QPushButton *channel_1;
    QPushButton *channel_7;
    QPushButton *channel_8;
    QPushButton *channel_9;
    QPushButton *channel_5;
    QPushButton *channel_3;
    QPushButton *channel_2;
    QPushButton *channel_4;
    QPushButton *channel_6;
    QPushButton *channel_0;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *TVControlPanel)
    {
        if (TVControlPanel->objectName().isEmpty())
            TVControlPanel->setObjectName(QString::fromUtf8("TVControlPanel"));
        TVControlPanel->resize(240, 680);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(TVControlPanel->sizePolicy().hasHeightForWidth());
        TVControlPanel->setSizePolicy(sizePolicy);
        TVControlPanel->setMinimumSize(QSize(240, 680));
        TVControlPanel->setMaximumSize(QSize(240, 680));
        TVControlPanel->setStyleSheet(QString::fromUtf8("background-color: rgb(22, 33, 33);"));
        centralwidget = new QWidget(TVControlPanel);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        channels = new QHBoxLayout();
        channels->setObjectName(QString::fromUtf8("channels"));
        ch_back = new QPushButton(centralwidget);
        ch_back->setObjectName(QString::fromUtf8("ch_back"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(ch_back->sizePolicy().hasHeightForWidth());
        ch_back->setSizePolicy(sizePolicy1);
        QFont font;
        font.setPointSize(32);
        ch_back->setFont(font);
        ch_back->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 25, 0);"));
        ch_back->setText(QString::fromUtf8("<"));

        channels->addWidget(ch_back);

        ch_forward = new QPushButton(centralwidget);
        ch_forward->setObjectName(QString::fromUtf8("ch_forward"));
        sizePolicy1.setHeightForWidth(ch_forward->sizePolicy().hasHeightForWidth());
        ch_forward->setSizePolicy(sizePolicy1);
        ch_forward->setFont(font);
        ch_forward->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 25, 0);"));

        channels->addWidget(ch_forward);


        gridLayout->addLayout(channels, 1, 0, 1, 1);

        volume = new QHBoxLayout();
        volume->setObjectName(QString::fromUtf8("volume"));
        vol_low = new QPushButton(centralwidget);
        vol_low->setObjectName(QString::fromUtf8("vol_low"));
        sizePolicy1.setHeightForWidth(vol_low->sizePolicy().hasHeightForWidth());
        vol_low->setSizePolicy(sizePolicy1);
        vol_low->setFont(font);
        vol_low->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 34);"));

        volume->addWidget(vol_low);

        vol_high = new QPushButton(centralwidget);
        vol_high->setObjectName(QString::fromUtf8("vol_high"));
        sizePolicy1.setHeightForWidth(vol_high->sizePolicy().hasHeightForWidth());
        vol_high->setSizePolicy(sizePolicy1);
        vol_high->setFont(font);
        vol_high->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 34);"));

        volume->addWidget(vol_high);


        gridLayout->addLayout(volume, 2, 0, 1, 1);

        display = new QLineEdit(centralwidget);
        display->setObjectName(QString::fromUtf8("display"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(display->sizePolicy().hasHeightForWidth());
        display->setSizePolicy(sizePolicy2);
        QFont font1;
        font1.setPointSize(16);
        display->setFont(font1);
        display->setStyleSheet(QString::fromUtf8("background-color: rgb(28, 0, 43);\n"
"color: rgb(255, 255, 255);"));

        gridLayout->addWidget(display, 3, 0, 1, 1);

        numbers = new QGridLayout();
        numbers->setObjectName(QString::fromUtf8("numbers"));
        channel_1 = new QPushButton(centralwidget);
        channel_1->setObjectName(QString::fromUtf8("channel_1"));
        channel_1->setEnabled(true);
        sizePolicy2.setHeightForWidth(channel_1->sizePolicy().hasHeightForWidth());
        channel_1->setSizePolicy(sizePolicy2);
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        QBrush brush1(QColor(255, 255, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        QBrush brush2(QColor(120, 120, 120, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        channel_1->setPalette(palette);
        channel_1->setFont(font1);
        channel_1->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));

        numbers->addWidget(channel_1, 0, 0, 1, 1);

        channel_7 = new QPushButton(centralwidget);
        channel_7->setObjectName(QString::fromUtf8("channel_7"));
        sizePolicy2.setHeightForWidth(channel_7->sizePolicy().hasHeightForWidth());
        channel_7->setSizePolicy(sizePolicy2);
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::Button, brush);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush);
        channel_7->setPalette(palette1);
        channel_7->setFont(font1);
        channel_7->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));

        numbers->addWidget(channel_7, 6, 0, 1, 1);

        channel_8 = new QPushButton(centralwidget);
        channel_8->setObjectName(QString::fromUtf8("channel_8"));
        sizePolicy2.setHeightForWidth(channel_8->sizePolicy().hasHeightForWidth());
        channel_8->setSizePolicy(sizePolicy2);
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::Button, brush);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush);
        channel_8->setPalette(palette2);
        channel_8->setFont(font1);
        channel_8->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));

        numbers->addWidget(channel_8, 6, 1, 1, 1);

        channel_9 = new QPushButton(centralwidget);
        channel_9->setObjectName(QString::fromUtf8("channel_9"));
        sizePolicy2.setHeightForWidth(channel_9->sizePolicy().hasHeightForWidth());
        channel_9->setSizePolicy(sizePolicy2);
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::Button, brush);
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette3.setBrush(QPalette::Active, QPalette::Base, brush);
        palette3.setBrush(QPalette::Active, QPalette::Window, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::Window, brush);
        channel_9->setPalette(palette3);
        channel_9->setFont(font1);
        channel_9->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));

        numbers->addWidget(channel_9, 6, 2, 1, 1);

        channel_5 = new QPushButton(centralwidget);
        channel_5->setObjectName(QString::fromUtf8("channel_5"));
        sizePolicy2.setHeightForWidth(channel_5->sizePolicy().hasHeightForWidth());
        channel_5->setSizePolicy(sizePolicy2);
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::Button, brush);
        palette4.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette4.setBrush(QPalette::Active, QPalette::Base, brush);
        palette4.setBrush(QPalette::Active, QPalette::Window, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette4.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::Window, brush);
        channel_5->setPalette(palette4);
        channel_5->setFont(font1);
        channel_5->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));

        numbers->addWidget(channel_5, 3, 1, 1, 1);

        channel_3 = new QPushButton(centralwidget);
        channel_3->setObjectName(QString::fromUtf8("channel_3"));
        sizePolicy2.setHeightForWidth(channel_3->sizePolicy().hasHeightForWidth());
        channel_3->setSizePolicy(sizePolicy2);
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::Button, brush);
        palette5.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette5.setBrush(QPalette::Active, QPalette::Base, brush);
        palette5.setBrush(QPalette::Active, QPalette::Window, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette5.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette5.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::Window, brush);
        channel_3->setPalette(palette5);
        channel_3->setFont(font1);
        channel_3->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));

        numbers->addWidget(channel_3, 0, 2, 1, 1);

        channel_2 = new QPushButton(centralwidget);
        channel_2->setObjectName(QString::fromUtf8("channel_2"));
        sizePolicy2.setHeightForWidth(channel_2->sizePolicy().hasHeightForWidth());
        channel_2->setSizePolicy(sizePolicy2);
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::Button, brush);
        palette6.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette6.setBrush(QPalette::Active, QPalette::Base, brush);
        palette6.setBrush(QPalette::Active, QPalette::Window, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette6.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette6.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette6.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette6.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette6.setBrush(QPalette::Disabled, QPalette::Window, brush);
        channel_2->setPalette(palette6);
        channel_2->setFont(font1);
        channel_2->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));

        numbers->addWidget(channel_2, 0, 1, 1, 1);

        channel_4 = new QPushButton(centralwidget);
        channel_4->setObjectName(QString::fromUtf8("channel_4"));
        sizePolicy2.setHeightForWidth(channel_4->sizePolicy().hasHeightForWidth());
        channel_4->setSizePolicy(sizePolicy2);
        QPalette palette7;
        palette7.setBrush(QPalette::Active, QPalette::Button, brush);
        palette7.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette7.setBrush(QPalette::Active, QPalette::Base, brush);
        palette7.setBrush(QPalette::Active, QPalette::Window, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette7.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette7.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette7.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette7.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette7.setBrush(QPalette::Disabled, QPalette::Window, brush);
        channel_4->setPalette(palette7);
        channel_4->setFont(font1);
        channel_4->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));

        numbers->addWidget(channel_4, 3, 0, 1, 1);

        channel_6 = new QPushButton(centralwidget);
        channel_6->setObjectName(QString::fromUtf8("channel_6"));
        sizePolicy2.setHeightForWidth(channel_6->sizePolicy().hasHeightForWidth());
        channel_6->setSizePolicy(sizePolicy2);
        QPalette palette8;
        palette8.setBrush(QPalette::Active, QPalette::Button, brush);
        palette8.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette8.setBrush(QPalette::Active, QPalette::Base, brush);
        palette8.setBrush(QPalette::Active, QPalette::Window, brush);
        palette8.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette8.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette8.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette8.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette8.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette8.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette8.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette8.setBrush(QPalette::Disabled, QPalette::Window, brush);
        channel_6->setPalette(palette8);
        channel_6->setFont(font1);
        channel_6->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));

        numbers->addWidget(channel_6, 3, 2, 1, 1);

        channel_0 = new QPushButton(centralwidget);
        channel_0->setObjectName(QString::fromUtf8("channel_0"));
        sizePolicy2.setHeightForWidth(channel_0->sizePolicy().hasHeightForWidth());
        channel_0->setSizePolicy(sizePolicy2);
        channel_0->setFont(font1);
        channel_0->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 0);"));

        numbers->addWidget(channel_0, 7, 1, 1, 1);


        gridLayout->addLayout(numbers, 0, 0, 1, 1);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font2;
        font2.setPointSize(16);
        font2.setItalic(false);
        font2.setKerning(true);
        label->setFont(font2);
        label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 0);"));
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 4, 0, 1, 1);

        TVControlPanel->setCentralWidget(centralwidget);
        menubar = new QMenuBar(TVControlPanel);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 240, 21));
        TVControlPanel->setMenuBar(menubar);
        statusbar = new QStatusBar(TVControlPanel);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        TVControlPanel->setStatusBar(statusbar);

        retranslateUi(TVControlPanel);
        QObject::connect(channel_1, SIGNAL(clicked()), TVControlPanel, SLOT(ch1()));
        QObject::connect(channel_4, SIGNAL(clicked()), TVControlPanel, SLOT(ch4()));
        QObject::connect(channel_7, SIGNAL(clicked()), TVControlPanel, SLOT(ch7()));
        QObject::connect(channel_2, SIGNAL(clicked()), TVControlPanel, SLOT(ch2()));
        QObject::connect(channel_5, SIGNAL(clicked()), TVControlPanel, SLOT(ch5()));
        QObject::connect(channel_8, SIGNAL(clicked()), TVControlPanel, SLOT(ch8()));
        QObject::connect(channel_3, SIGNAL(clicked()), TVControlPanel, SLOT(ch3()));
        QObject::connect(channel_6, SIGNAL(clicked()), TVControlPanel, SLOT(ch6()));
        QObject::connect(channel_9, SIGNAL(clicked()), TVControlPanel, SLOT(ch9()));
        QObject::connect(channel_0, SIGNAL(clicked()), TVControlPanel, SLOT(ch0()));
        QObject::connect(ch_back, SIGNAL(clicked()), TVControlPanel, SLOT(chBack()));
        QObject::connect(ch_forward, SIGNAL(clicked()), TVControlPanel, SLOT(chForward()));
        QObject::connect(vol_low, SIGNAL(clicked()), TVControlPanel, SLOT(volLow()));
        QObject::connect(vol_high, SIGNAL(clicked()), TVControlPanel, SLOT(volHigh()));

        QMetaObject::connectSlotsByName(TVControlPanel);
    } // setupUi

    void retranslateUi(QMainWindow *TVControlPanel)
    {
        TVControlPanel->setWindowTitle(QApplication::translate("TVControlPanel", "MainWindow", nullptr));
        ch_forward->setText(QApplication::translate("TVControlPanel", ">", nullptr));
        vol_low->setText(QApplication::translate("TVControlPanel", "-", nullptr));
        vol_high->setText(QApplication::translate("TVControlPanel", "+", nullptr));
        channel_1->setText(QApplication::translate("TVControlPanel", "1", nullptr));
        channel_7->setText(QApplication::translate("TVControlPanel", "7", nullptr));
        channel_8->setText(QApplication::translate("TVControlPanel", "8", nullptr));
        channel_9->setText(QApplication::translate("TVControlPanel", "9", nullptr));
        channel_5->setText(QApplication::translate("TVControlPanel", "5", nullptr));
        channel_3->setText(QApplication::translate("TVControlPanel", "3", nullptr));
        channel_2->setText(QApplication::translate("TVControlPanel", "2", nullptr));
        channel_4->setText(QApplication::translate("TVControlPanel", "4", nullptr));
        channel_6->setText(QApplication::translate("TVControlPanel", "6", nullptr));
        channel_0->setText(QApplication::translate("TVControlPanel", "0", nullptr));
        label->setText(QApplication::translate("TVControlPanel", "TV  control panel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TVControlPanel: public Ui_TVControlPanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // TV_CONTROL_PANELEQXEJS_H


#endif // UI_TV_CONTROL_H
