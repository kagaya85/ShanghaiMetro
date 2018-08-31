/********************************************************************************
** Form generated from reading UI file 'ShanghaiMetro.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHANGHAIMETRO_H
#define UI_SHANGHAIMETRO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "mapView.h"

QT_BEGIN_NAMESPACE

class Ui_ShanghaiMetroClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_3;
    QLabel *dest;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_4;
    QLabel *start;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *search;
    QSpacerItem *horizontalSpacer;
    QPushButton *clear;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer_5;
    QLineEdit *startInput;
    QLineEdit *destInput;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *addStation;
    QSpacerItem *horizontalSpacer_5;
    MapView *map;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ShanghaiMetroClass)
    {
        if (ShanghaiMetroClass->objectName().isEmpty())
            ShanghaiMetroClass->setObjectName(QStringLiteral("ShanghaiMetroClass"));
        ShanghaiMetroClass->resize(1605, 947);
        centralWidget = new QWidget(ShanghaiMetroClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_3 = new QGridLayout(centralWidget);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        dest = new QLabel(centralWidget);
        dest->setObjectName(QStringLiteral("dest"));

        gridLayout_3->addWidget(dest, 3, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_3->addItem(verticalSpacer, 0, 2, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_3->addItem(verticalSpacer_4, 4, 2, 1, 1);

        start = new QLabel(centralWidget);
        start->setObjectName(QStringLiteral("start"));

        gridLayout_3->addWidget(start, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        search = new QPushButton(centralWidget);
        search->setObjectName(QStringLiteral("search"));

        horizontalLayout_2->addWidget(search);

        horizontalSpacer = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        clear = new QPushButton(centralWidget);
        clear->setObjectName(QStringLiteral("clear"));

        horizontalLayout_2->addWidget(clear);

        horizontalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);


        gridLayout_3->addLayout(horizontalLayout_2, 5, 0, 1, 4);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_3->addItem(verticalSpacer_5, 6, 2, 1, 1);

        startInput = new QLineEdit(centralWidget);
        startInput->setObjectName(QStringLiteral("startInput"));

        gridLayout_3->addWidget(startInput, 1, 1, 1, 3);

        destInput = new QLineEdit(centralWidget);
        destInput->setObjectName(QStringLiteral("destInput"));

        gridLayout_3->addWidget(destInput, 3, 1, 1, 3);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_3, 11, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_3->addItem(verticalSpacer_2, 2, 2, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_4 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        addStation = new QPushButton(centralWidget);
        addStation->setObjectName(QStringLiteral("addStation"));

        horizontalLayout->addWidget(addStation);

        horizontalSpacer_5 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);


        gridLayout_3->addLayout(horizontalLayout, 8, 0, 1, 4);

        map = new MapView(centralWidget);
        map->setObjectName(QStringLiteral("map"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(map->sizePolicy().hasHeightForWidth());
        map->setSizePolicy(sizePolicy);
        map->setMinimumSize(QSize(1200, 900));

        gridLayout_3->addWidget(map, 0, 4, 12, 1);

        ShanghaiMetroClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(ShanghaiMetroClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        ShanghaiMetroClass->setStatusBar(statusBar);

        retranslateUi(ShanghaiMetroClass);

        QMetaObject::connectSlotsByName(ShanghaiMetroClass);
    } // setupUi

    void retranslateUi(QMainWindow *ShanghaiMetroClass)
    {
        ShanghaiMetroClass->setWindowTitle(QApplication::translate("ShanghaiMetroClass", "ShanghaiMetro", nullptr));
        dest->setText(QApplication::translate("ShanghaiMetroClass", "\347\233\256\347\232\204\345\234\260\357\274\232", nullptr));
        start->setText(QApplication::translate("ShanghaiMetroClass", "\345\207\272\345\217\221\345\234\260\357\274\232", nullptr));
        search->setText(QApplication::translate("ShanghaiMetroClass", "\346\237\245\350\257\242", nullptr));
        clear->setText(QApplication::translate("ShanghaiMetroClass", "\346\270\205\351\231\244", nullptr));
        addStation->setText(QApplication::translate("ShanghaiMetroClass", "\346\267\273\345\212\240\350\267\257\347\272\277", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ShanghaiMetroClass: public Ui_ShanghaiMetroClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHANGHAIMETRO_H
