#include "levelareawidget.h"

#include <QtWidgets>

LevelAreaWidget::LevelAreaWidget(QWidget *parent)
    : QWidget{parent}
{
    levelArea = new QGridLayout;

    widthSelect = new QComboBox(this);
    widthSelect->addItems(QStringList({"3", "4", "5", "6", "7", "8", "9", "10"}));
    widthSelect->setCurrentIndex(0);
    connect(widthSelect, &QComboBox::currentIndexChanged, this, &LevelAreaWidget::onWidthSelectChanged);
    width = widthSelect->currentText().toInt();

    heightSelect = new QComboBox(this);
    heightSelect->addItems(QStringList({"3", "4", "5", "6", "7", "8", "9", "10"}));
    heightSelect->setCurrentIndex(0);
    connect(heightSelect, &QComboBox::currentIndexChanged, this, &LevelAreaWidget::onHeightSelectChanged);
    height = heightSelect->currentText().toInt();

    defaultPlatformSelect = new QComboBox(this);
    defaultPlatformSelect->addItems(QStringList(STRING_TO_PLATFORM_TYPE.keys()));
    defaultPlatformSelect->setCurrentIndex(0);
    connect(defaultPlatformSelect, &QComboBox::currentIndexChanged, this, &LevelAreaWidget::onDefaultPlatformSelectChanged);
    defaultPlatformType = STRING_TO_PLATFORM_TYPE[defaultPlatformSelect->currentText()];

    defaultJumperSelect = new QComboBox(this);
    defaultJumperSelect->addItems(QStringList(STRING_TO_JUMPER_TYPE.keys()));
    defaultJumperSelect->setCurrentIndex(0);
    connect(defaultJumperSelect, &QComboBox::currentIndexChanged, this, &LevelAreaWidget::onDefaultJumperSelectChanged);
    defaultJumperType = STRING_TO_JUMPER_TYPE[defaultJumperSelect->currentText()];

    QBoxLayout* layout = new QVBoxLayout(this);

    QBoxLayout* settingsLayout = new QHBoxLayout;
    settingsLayout->addWidget(widthSelect, 1);
    settingsLayout->addWidget(heightSelect, 1);

    QBoxLayout* defaultsLayout = new QHBoxLayout;
    defaultsLayout->addWidget(defaultPlatformSelect, 1);
    defaultsLayout->addWidget(defaultJumperSelect, 1);

    QBoxLayout* levelAreaLayout = new QHBoxLayout;
    levelAreaLayout->addLayout(levelArea);

    layout->addLayout(levelAreaLayout, 1);
    layout->addLayout(settingsLayout, 1);
    layout->addLayout(defaultsLayout, 1);

    resize();

    setLayout(layout);
}

void LevelAreaWidget::onWidthSelectChanged(int index)
{
    width = widthSelect->currentText().toInt();
    resize();
}

void LevelAreaWidget::onHeightSelectChanged(int index)
{
    height = heightSelect->currentText().toInt();
    resize();
}

void LevelAreaWidget::onDefaultPlatformSelectChanged(int index)
{
    defaultPlatformType = STRING_TO_PLATFORM_TYPE[defaultPlatformSelect->currentText()];
}

void LevelAreaWidget::onDefaultJumperSelectChanged(int index)
{
    defaultJumperType = STRING_TO_JUMPER_TYPE[defaultJumperSelect->currentText()];
}

void LevelAreaWidget::resize()
{
    if (levelArea->rowCount() > 1 || levelArea->columnCount() > 1) { // TODO remove this check
        for (int i = 0; i < levelArea->rowCount(); i++) {
            for (int j = 0; j < levelArea->columnCount(); j++) {
                qDebug() << "rem: (" << i << ":" << j << ")";
                QLayoutItem* item = levelArea->itemAtPosition(i, j);
                QWidget* widget = item->widget();
                levelArea->removeItem(item);
                delete widget; // TODO fix delete after reduce size
            }
        }
    }
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            QBoxLayout* cellLayout = new QVBoxLayout; // todo use custom widget

            QComboBox* platformSelect = new QComboBox(this);
            platformSelect->addItems(QStringList(STRING_TO_PLATFORM_TYPE.keys()));

            QComboBox* jumperSelect = new QComboBox(this);
            jumperSelect->addItems(QStringList(STRING_TO_JUMPER_TYPE.keys()));

            cellLayout->addWidget(platformSelect);
            cellLayout->addWidget(jumperSelect);
            levelArea->addLayout(cellLayout, i, j);
        }
    }
}
