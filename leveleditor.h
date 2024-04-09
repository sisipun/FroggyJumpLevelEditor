#ifndef LEVELEDITOR_H
#define LEVELEDITOR_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class LevelEditor;
}
class LevelAreaWidget;
QT_END_NAMESPACE

class LevelEditor : public QMainWindow

{
    Q_OBJECT

public:
    LevelEditor(QWidget *parent = nullptr);
    ~LevelEditor();

private:
    Ui::LevelEditor *ui;
    LevelAreaWidget *levelArea = nullptr;
};

#endif // LEVELEDITOR_H
