#include "levelareawidget.h"

#include <QtWidgets>

LevelAreaWidget::LevelAreaWidget(QWidget *parent)
    : QWidget{parent}
{
    levelArea = new QGridLayout;

    widthSelect = new QComboBox(this);
    widthSelect->addItems(QStringList({"3", "4", "5", "6", "7", "8", "9", "10"}));
    widthSelect->setCurrentIndex(0);

    heightSelect = new QComboBox(this);
    heightSelect->addItems(QStringList({"3", "4", "5", "6", "7", "8", "9", "10"}));
    heightSelect->setCurrentIndex(0);

    connect(widthSelect, &QComboBox::currentIndexChanged, this, &LevelAreaWidget::onWidthSelectChanged);
    connect(heightSelect, &QComboBox::currentIndexChanged, this, &LevelAreaWidget::onHeightSelectChanged);

    QBoxLayout* layout = new QVBoxLayout(this);

    QBoxLayout* statsLayout = new QHBoxLayout;
    statsLayout->addWidget(widthSelect, 1);
    statsLayout->addWidget(heightSelect, 1);

    QBoxLayout* levelAreaLayout = new QHBoxLayout;
    levelAreaLayout->addLayout(levelArea);

    layout->addLayout(levelAreaLayout, 1);
    layout->addLayout(statsLayout, 1);

    resize();

    setLayout(layout);
}

void LevelAreaWidget::onWidthSelectChanged(int index)
{
    resize();
}

void LevelAreaWidget::onHeightSelectChanged(int index)
{
    resize();
}

void LevelAreaWidget::resize()
{
    if (levelArea->rowCount() > 1 || levelArea->columnCount() > 1) { // TODO remove this check
        for (int i = 0; i < levelArea->rowCount(); i++) {
            for (int j = 0; j < levelArea->columnCount(); j++) {
                QLayoutItem* item = levelArea->itemAtPosition(i, j);
                QWidget* widget = item->widget();
                levelArea->removeItem(item);
                delete widget;
            }
        }
    }
    for (int i = 0; i < widthSelect->currentText().toInt(); i++) {
        for (int j = 0; j < heightSelect->currentText().toInt(); j++) {
            QComboBox* cell = new QComboBox(this);
            cell->addItems(QStringList({"test1", "test2"}));
            levelArea->addWidget(cell, i, j);
        }
    }
}
