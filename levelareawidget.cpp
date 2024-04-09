#include "levelareawidget.h"

#include <QtWidgets>

LevelAreaWidget::LevelAreaWidget(QWidget *parent)
    : QWidget{parent}
{
    widthSelect = new QComboBox(this);
    widthSelect->addItems(QStringList({"3", "4", "5", "6", "7", "8", "9", "10"}));
    widthSelect->setCurrentIndex(0);

    heightSelect = new QComboBox(this);
    heightSelect->addItems(QStringList({"3", "4", "5", "6", "7", "8", "9", "10"}));
    heightSelect->setCurrentIndex(0);

    QBoxLayout* layout = new QVBoxLayout(this);

    QBoxLayout* statsLayout = new QHBoxLayout;
    statsLayout->addWidget(widthSelect, 1);
    statsLayout->addWidget(heightSelect, 1);

    layout->addLayout(statsLayout);

    setLayout(layout);
}

