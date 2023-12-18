/********************************************************************************
** Form generated from reading UI file 'pomodoro.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POMODORO_H
#define UI_POMODORO_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_pomodoro
{
public:
    QWidget *centralwidget;
    QPushButton *startButton;
    QLineEdit *timerLabel;
    QPushButton *adjustTimeButton;
    QPushButton *pauseButton;
    QMenuBar *menubar;
    QMenu *menuJust_Do_It;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *pomodoro)
    {
        if (pomodoro->objectName().isEmpty())
            pomodoro->setObjectName("pomodoro");
        pomodoro->resize(361, 191);
        centralwidget = new QWidget(pomodoro);
        centralwidget->setObjectName("centralwidget");
        startButton = new QPushButton(centralwidget);
        startButton->setObjectName("startButton");
        startButton->setGeometry(QRect(0, 100, 81, 31));
        timerLabel = new QLineEdit(centralwidget);
        timerLabel->setObjectName("timerLabel");
        timerLabel->setGeometry(QRect(0, 0, 361, 91));
        QFont font;
        font.setFamilies({QString::fromUtf8("Consolas")});
        font.setPointSize(50);
        font.setBold(true);
        timerLabel->setFont(font);
        timerLabel->setReadOnly(true);
        adjustTimeButton = new QPushButton(centralwidget);
        adjustTimeButton->setObjectName("adjustTimeButton");
        adjustTimeButton->setGeometry(QRect(90, 100, 81, 31));
        pauseButton = new QPushButton(centralwidget);
        pauseButton->setObjectName("pauseButton");
        pauseButton->setGeometry(QRect(180, 100, 91, 31));
        pomodoro->setCentralWidget(centralwidget);
        menubar = new QMenuBar(pomodoro);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 361, 21));
        menuJust_Do_It = new QMenu(menubar);
        menuJust_Do_It->setObjectName("menuJust_Do_It");
        pomodoro->setMenuBar(menubar);
        statusbar = new QStatusBar(pomodoro);
        statusbar->setObjectName("statusbar");
        pomodoro->setStatusBar(statusbar);

        menubar->addAction(menuJust_Do_It->menuAction());

        retranslateUi(pomodoro);

        QMetaObject::connectSlotsByName(pomodoro);
    } // setupUi

    void retranslateUi(QMainWindow *pomodoro)
    {
        pomodoro->setWindowTitle(QCoreApplication::translate("pomodoro", "pomodoro", nullptr));
        startButton->setText(QCoreApplication::translate("pomodoro", "INICIAR", nullptr));
        timerLabel->setText(QString());
        adjustTimeButton->setText(QCoreApplication::translate("pomodoro", "TEMPO", nullptr));
        pauseButton->setText(QCoreApplication::translate("pomodoro", "PAUSAR", nullptr));
        menuJust_Do_It->setTitle(QCoreApplication::translate("pomodoro", "Just Do It", nullptr));
    } // retranslateUi

};

namespace Ui {
    class pomodoro: public Ui_pomodoro {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POMODORO_H
