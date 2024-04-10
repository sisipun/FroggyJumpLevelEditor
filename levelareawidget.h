#ifndef LEVELAREAWIDGET_H
#define LEVELAREAWIDGET_H


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

private:
    QGridLayout* levelArea = nullptr;
    QComboBox* widthSelect = nullptr;
    QComboBox* heightSelect = nullptr;
};

#endif // LEVELAREAWIDGET_H
