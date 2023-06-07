/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGraphicsView *graphicsView;
    QLCDNumber *lcdScore;
    QLCDNumber *lcdTime;
    QLabel *puntos;
    QLabel *tiempo;
    QLabel *facil;
    QLabel *dificil;
    QLabel *medio;
    QPushButton *pushButton_facil;
    QPushButton *pushButton_medio;
    QPushButton *pushButton_dificil;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(1115, 723);
        QFont font;
        font.setFamilies({QString::fromUtf8("Berlin Sans FB Demi")});
        font.setPointSize(18);
        font.setBold(true);
        MainWindow->setFont(font);
        MainWindow->setAnimated(true);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setEnabled(true);
        graphicsView->setGeometry(QRect(11, 11, 1085, 613));
        graphicsView->viewport()->setProperty("cursor", QVariant(QCursor(Qt::ArrowCursor)));
        lcdScore = new QLCDNumber(centralwidget);
        lcdScore->setObjectName(QString::fromUtf8("lcdScore"));
        lcdScore->setGeometry(QRect(260, 560, 91, 51));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Consolas")});
        font1.setPointSize(18);
        font1.setBold(true);
        font1.setKerning(false);
        lcdScore->setFont(font1);
        lcdScore->setLayoutDirection(Qt::RightToLeft);
        lcdScore->setFrameShape(QFrame::NoFrame);
        lcdScore->setFrameShadow(QFrame::Sunken);
        lcdScore->setSmallDecimalPoint(false);
        lcdScore->setSegmentStyle(QLCDNumber::Flat);
        lcdTime = new QLCDNumber(centralwidget);
        lcdTime->setObjectName(QString::fromUtf8("lcdTime"));
        lcdTime->setGeometry(QRect(870, 560, 91, 51));
        lcdTime->setFont(font1);
        lcdTime->setLayoutDirection(Qt::RightToLeft);
        lcdTime->setFrameShape(QFrame::NoFrame);
        lcdTime->setFrameShadow(QFrame::Sunken);
        lcdTime->setSmallDecimalPoint(false);
        lcdTime->setSegmentStyle(QLCDNumber::Flat);
        puntos = new QLabel(centralwidget);
        puntos->setObjectName(QString::fromUtf8("puntos"));
        puntos->setGeometry(QRect(210, 565, 101, 41));
        tiempo = new QLabel(centralwidget);
        tiempo->setObjectName(QString::fromUtf8("tiempo"));
        tiempo->setGeometry(QRect(800, 565, 121, 41));
        facil = new QLabel(centralwidget);
        facil->setObjectName(QString::fromUtf8("facil"));
        facil->setGeometry(QRect(520, 550, 91, 51));
        dificil = new QLabel(centralwidget);
        dificil->setObjectName(QString::fromUtf8("dificil"));
        dificil->setGeometry(QRect(520, 550, 111, 51));
        medio = new QLabel(centralwidget);
        medio->setObjectName(QString::fromUtf8("medio"));
        medio->setGeometry(QRect(520, 550, 101, 51));
        pushButton_facil = new QPushButton(centralwidget);
        pushButton_facil->setObjectName(QString::fromUtf8("pushButton_facil"));
        pushButton_facil->setGeometry(QRect(220, 270, 101, 41));
        pushButton_medio = new QPushButton(centralwidget);
        pushButton_medio->setObjectName(QString::fromUtf8("pushButton_medio"));
        pushButton_medio->setGeometry(QRect(330, 350, 101, 41));
        pushButton_dificil = new QPushButton(centralwidget);
        pushButton_dificil->setObjectName(QString::fromUtf8("pushButton_dificil"));
        pushButton_dificil->setGeometry(QRect(450, 420, 101, 41));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1115, 39));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        puntos->setText(QCoreApplication::translate("MainWindow", "SCORE", nullptr));
        tiempo->setText(QCoreApplication::translate("MainWindow", "TIEMPO", nullptr));
        facil->setText(QCoreApplication::translate("MainWindow", "F\303\201CIL", nullptr));
        dificil->setText(QCoreApplication::translate("MainWindow", "DIF\303\215CIL", nullptr));
        medio->setText(QCoreApplication::translate("MainWindow", "MEDIO", nullptr));
        pushButton_facil->setText(QCoreApplication::translate("MainWindow", "F\303\241cil", nullptr));
        pushButton_medio->setText(QCoreApplication::translate("MainWindow", "Medio", nullptr));
        pushButton_dificil->setText(QCoreApplication::translate("MainWindow", "Dif\303\255cil", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
