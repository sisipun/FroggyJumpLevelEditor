#include "leveleditor.h"
#include "./ui_leveleditor.h"

#include "levelareawidget.h"


LevelEditor::LevelEditor(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LevelEditor)
{
    ui->setupUi(this);

    levelArea = new LevelAreaWidget(this);

    ui->gridLayout->addWidget(levelArea);
}

LevelEditor::~LevelEditor()
{
    delete ui;
}


