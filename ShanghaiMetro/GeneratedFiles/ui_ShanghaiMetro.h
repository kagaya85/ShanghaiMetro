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
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ShanghaiMetroClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_5;
    QSpacerItem *horizontalSpacer;
    QPushButton *clear;
    QSpacerItem *horizontalSpacer_3;
    QGraphicsView *map;
    QLabel *dest;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer;
    QLabel *start;
    QPushButton *addStation;
    QSpacerItem *verticalSpacer_5;
    QLineEdit *startInput;
    QLineEdit *destInput;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ShanghaiMetroClass)
    {
        if (ShanghaiMetroClass->objectName().isEmpty())
            ShanghaiMetroClass->setObjectName(QStringLiteral("ShanghaiMetroClass"));
        ShanghaiMetroClass->resize(1105, 847);
        centralWidget = new QWidget(ShanghaiMetroClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_3 = new QGridLayout(centralWidget);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        pushButton_5 = new QPushButton(centralWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));

        horizontalLayout_2->addWidget(pushButton_5);

        horizontalSpacer = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        clear = new QPushButton(centralWidget);
        clear->setObjectName(QStringLiteral("clear"));

        horizontalLayout_2->addWidget(clear);

        horizontalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);


        gridLayout_3->addLayout(horizontalLayout_2, 5, 0, 1, 4);

        map = new QGraphicsView(centralWidget);
        map->setObjectName(QStringLiteral("map"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(map->sizePolicy().hasHeightForWidth());
        map->setSizePolicy(sizePolicy);
        map->setMinimumSize(QSize(800, 800));

        gridLayout_3->addWidget(map, 0, 4, 9, 1);

        dest = new QLabel(centralWidget);
        dest->setObjectName(QStringLiteral("dest"));

        gridLayout_3->addWidget(dest, 3, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_3, 8, 2, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_3->addItem(verticalSpacer_4, 4, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_3->addItem(verticalSpacer_2, 2, 2, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_3->addItem(verticalSpacer, 0, 2, 1, 1);

        start = new QLabel(centralWidget);
        start->setObjectName(QStringLiteral("start"));

        gridLayout_3->addWidget(start, 1, 0, 1, 1);

        addStation = new QPushButton(centralWidget);
        addStation->setObjectName(QStringLiteral("addStation"));

        gridLayout_3->addWidget(addStation, 7, 0, 1, 4);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_3->addItem(verticalSpacer_5, 6, 2, 1, 1);

        startInput = new QLineEdit(centralWidget);
        startInput->setObjectName(QStringLiteral("startInput"));

        gridLayout_3->addWidget(startInput, 1, 1, 1, 3);

        destInput = new QLineEdit(centralWidget);
        destInput->setObjectName(QStringLiteral("destInput"));

        gridLayout_3->addWidget(destInput, 3, 1, 1, 3);

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
        pushButton_5->setText(QApplication::translate("ShanghaiMetroClass", "\346\237\245\350\257\242", nullptr));
        clear->setText(QApplication::translate("ShanghaiMetroClass", "\346\270\205\351\231\244", nullptr));
        dest->setText(QApplication::translate("ShanghaiMetroClass", "\347\233\256\347\232\204\345\234\260\357\274\232", nullptr));
        start->setText(QApplication::translate("ShanghaiMetroClass", "\345\207\272\345\217\221\345\234\260\357\274\232", nullptr));
        addStation->setText(QApplication::translate("ShanghaiMetroClass", "\346\267\273\345\212\240\347\253\231\347\202\271", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ShanghaiMetroClass: public Ui_ShanghaiMetroClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHANGHAIMETRO_H
