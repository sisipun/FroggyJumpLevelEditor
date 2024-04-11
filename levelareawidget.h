#ifndef LEVELAREAWIDGET_H
#define LEVELAREAWIDGET_H

#include "platformtype.h"
#include "jumpertype.h"

#include <QWidget>

QT_BEGIN_NAMESPACE
class QComboBox;
class QGridLayout;
class QListWidgetItem;
QT_END_NAMESPACE

class LevelAreaWidget : public QWidget
{
    Q_OBJECT
public:
    explicit LevelAreaWidget(QWidget *parent = nullptr);

private:
    void resize();

private slots:
    void onWidthSelectChanged(int index);
    void onHeightSelectChanged(int index);
    void onDefaultPlatformSelectChanged(int index);
    void onDefaultJumperSelectChanged(int index);

private:
    QGridLayout* levelArea = nullptr;
    QComboBox* widthSelect = nullptr;
    QComboBox* heightSelect = nullptr;
    QComboBox* defaultPlatformSelect = nullptr;
    QComboBox* defaultJumperSelect = nullptr;

    int width;
    int height;
    PlatformType defaultPlatformType;
    JumperType defaultJumperType;
};

#endif // LEVELAREAWIDGET_H
