#ifndef LEVELAREAWIDGET_H
#define LEVELAREAWIDGET_H


#include <QWidget>

QT_BEGIN_NAMESPACE
class QComboBox;
QT_END_NAMESPACE

class LevelAreaWidget : public QWidget
{
    Q_OBJECT
public:
    explicit LevelAreaWidget(QWidget *parent = nullptr);

private:
    QComboBox* widthSelect = nullptr;
    QComboBox* heightSelect = nullptr;
};

#endif // LEVELAREAWIDGET_H
