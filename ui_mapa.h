/********************************************************************************
** Form generated from reading UI file 'mapa.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAPA_H
#define UI_MAPA_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QTableWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mapa
{
public:
    QTableWidget *tableWidget;
    QPushButton *paso_amplitud;
    QLabel *label;
    QPushButton *Amplitud;
    QLabel *label_2;
    QPushButton *paso_A_Asterisco;
    QPushButton *A_Asterisco;
    QComboBox *ComboHeuristica;
    QLabel *label_3;
    QFrame *line;
    QFrame *line_2;
    QLabel *Solucion;
    QPushButton *btSalir;

    void setupUi(QWidget *mapa)
    {
        if (mapa->objectName().isEmpty())
            mapa->setObjectName(QString::fromUtf8("mapa"));
        mapa->setWindowModality(Qt::ApplicationModal);
        mapa->setEnabled(true);
        mapa->resize(674, 661);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(mapa->sizePolicy().hasHeightForWidth());
        mapa->setSizePolicy(sizePolicy);
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(85, 255, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(213, 255, 255, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(149, 255, 255, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(42, 127, 127, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(56, 170, 170, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush6(QColor(255, 255, 255, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        QBrush brush7(QColor(170, 255, 255, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush7);
        QBrush brush8(QColor(255, 255, 220, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        mapa->setPalette(palette);
        tableWidget = new QTableWidget(mapa);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(70, 190, 501, 461));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush7);
        palette1.setBrush(QPalette::Active, QPalette::Light, brush6);
        QBrush brush9(QColor(212, 255, 255, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Midlight, brush9);
        QBrush brush10(QColor(85, 127, 127, 255));
        brush10.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Dark, brush10);
        QBrush brush11(QColor(113, 170, 170, 255));
        brush11.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Mid, brush11);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        QBrush brush12(QColor(178, 255, 249, 255));
        brush12.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush12);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush7);
        palette1.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Active, QPalette::AlternateBase, brush9);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush7);
        palette1.setBrush(QPalette::Inactive, QPalette::Light, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::Midlight, brush9);
        palette1.setBrush(QPalette::Inactive, QPalette::Dark, brush10);
        palette1.setBrush(QPalette::Inactive, QPalette::Mid, brush11);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush12);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush7);
        palette1.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush9);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush10);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush7);
        palette1.setBrush(QPalette::Disabled, QPalette::Light, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::Midlight, brush9);
        palette1.setBrush(QPalette::Disabled, QPalette::Dark, brush10);
        palette1.setBrush(QPalette::Disabled, QPalette::Mid, brush11);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush10);
        palette1.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush10);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush7);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush7);
        palette1.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush7);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        tableWidget->setPalette(palette1);
        tableWidget->setAutoFillBackground(true);
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget->setTabKeyNavigation(false);
        tableWidget->setProperty("showDropIndicator", QVariant(false));
        tableWidget->setDragDropOverwriteMode(false);
        tableWidget->setTextElideMode(Qt::ElideMiddle);
        tableWidget->setGridStyle(Qt::SolidLine);
        tableWidget->setSortingEnabled(false);
        tableWidget->setCornerButtonEnabled(false);
        tableWidget->horizontalHeader()->setDefaultSectionSize(40);
        paso_amplitud = new QPushButton(mapa);
        paso_amplitud->setObjectName(QString::fromUtf8("paso_amplitud"));
        paso_amplitud->setEnabled(false);
        paso_amplitud->setGeometry(QRect(190, 120, 91, 31));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(paso_amplitud->sizePolicy().hasHeightForWidth());
        paso_amplitud->setSizePolicy(sizePolicy1);
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setItalic(false);
        font.setUnderline(false);
        font.setWeight(75);
        font.setStrikeOut(false);
        font.setKerning(true);
        paso_amplitud->setFont(font);
        paso_amplitud->setMouseTracking(false);
        QIcon icon;
        icon.addFile(QString::fromUtf8("../logos/step.png"), QSize(), QIcon::Normal, QIcon::Off);
        paso_amplitud->setIcon(icon);
        label = new QLabel(mapa);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(90, 30, 171, 41));
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        QFont font1;
        font1.setPointSize(9);
        font1.setBold(true);
        font1.setWeight(75);
        label->setFont(font1);
        Amplitud = new QPushButton(mapa);
        Amplitud->setObjectName(QString::fromUtf8("Amplitud"));
        Amplitud->setGeometry(QRect(40, 120, 121, 31));
        sizePolicy1.setHeightForWidth(Amplitud->sizePolicy().hasHeightForWidth());
        Amplitud->setSizePolicy(sizePolicy1);
        Amplitud->setFont(font);
        Amplitud->setMouseTracking(false);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("../logos/apply.png"), QSize(), QIcon::Normal, QIcon::Off);
        Amplitud->setIcon(icon1);
        label_2 = new QLabel(mapa);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(410, 30, 171, 41));
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);
        label_2->setFont(font1);
        paso_A_Asterisco = new QPushButton(mapa);
        paso_A_Asterisco->setObjectName(QString::fromUtf8("paso_A_Asterisco"));
        paso_A_Asterisco->setEnabled(false);
        paso_A_Asterisco->setGeometry(QRect(470, 120, 91, 31));
        sizePolicy1.setHeightForWidth(paso_A_Asterisco->sizePolicy().hasHeightForWidth());
        paso_A_Asterisco->setSizePolicy(sizePolicy1);
        paso_A_Asterisco->setFont(font);
        paso_A_Asterisco->setMouseTracking(false);
        paso_A_Asterisco->setIcon(icon);
        A_Asterisco = new QPushButton(mapa);
        A_Asterisco->setObjectName(QString::fromUtf8("A_Asterisco"));
        A_Asterisco->setGeometry(QRect(340, 120, 121, 31));
        sizePolicy1.setHeightForWidth(A_Asterisco->sizePolicy().hasHeightForWidth());
        A_Asterisco->setSizePolicy(sizePolicy1);
        A_Asterisco->setFont(font);
        A_Asterisco->setMouseTracking(false);
        A_Asterisco->setIcon(icon1);
        ComboHeuristica = new QComboBox(mapa);
        ComboHeuristica->setObjectName(QString::fromUtf8("ComboHeuristica"));
        ComboHeuristica->setGeometry(QRect(470, 80, 171, 31));
        sizePolicy1.setHeightForWidth(ComboHeuristica->sizePolicy().hasHeightForWidth());
        ComboHeuristica->setSizePolicy(sizePolicy1);
        label_3 = new QLabel(mapa);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(350, 70, 121, 41));
        sizePolicy1.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy1);
        QFont font2;
        font2.setPointSize(9);
        label_3->setFont(font2);
        line = new QFrame(mapa);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(320, 30, 16, 161));
        sizePolicy1.setHeightForWidth(line->sizePolicy().hasHeightForWidth());
        line->setSizePolicy(sizePolicy1);
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(mapa);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(240, 20, 181, 20));
        sizePolicy1.setHeightForWidth(line_2->sizePolicy().hasHeightForWidth());
        line_2->setSizePolicy(sizePolicy1);
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        Solucion = new QLabel(mapa);
        Solucion->setObjectName(QString::fromUtf8("Solucion"));
        Solucion->setGeometry(QRect(510, 150, 131, 31));
        btSalir = new QPushButton(mapa);
        btSalir->setObjectName(QString::fromUtf8("btSalir"));
        btSalir->setGeometry(QRect(280, 160, 86, 26));

        retranslateUi(mapa);

        QMetaObject::connectSlotsByName(mapa);
    } // setupUi

    void retranslateUi(QWidget *mapa)
    {
        mapa->setWindowTitle(QApplication::translate("mapa", "Mapa-UV", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        paso_amplitud->setToolTip(QApplication::translate("mapa", "Aplicar Paso a Paso", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        paso_amplitud->setText(QApplication::translate("mapa", "Paso A Paso", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("mapa", "     Busqueda No Informada\n"
"              Por Amplitud", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        Amplitud->setToolTip(QApplication::translate("mapa", "Amplitud", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        Amplitud->setText(QApplication::translate("mapa", "Aplicar Algoritmo", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("mapa", "     Busqueda  Informada\n"
"          A*", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        paso_A_Asterisco->setToolTip(QApplication::translate("mapa", "Aplicar Paso a Paso", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        paso_A_Asterisco->setText(QApplication::translate("mapa", "Paso A Paso", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        A_Asterisco->setToolTip(QApplication::translate("mapa", "Busqueda Informada", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        A_Asterisco->setText(QApplication::translate("mapa", "Aplicar Algoritmo", 0, QApplication::UnicodeUTF8));
        ComboHeuristica->clear();
        ComboHeuristica->insertItems(0, QStringList()
         << QApplication::translate("mapa", "Distancia Manhattan", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("mapa", "Distancia Linea Recta", 0, QApplication::UnicodeUTF8)
        );
        label_3->setText(QApplication::translate("mapa", "Seleccione Heuristica :", 0, QApplication::UnicodeUTF8));
        Solucion->setText(QString());
        btSalir->setText(QApplication::translate("mapa", "Cerrar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class mapa: public Ui_mapa {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAPA_H
