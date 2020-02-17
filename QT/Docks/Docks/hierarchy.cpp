#include "hierarchy.h"
#include "ui_hierarchy.h"
#include <iostream>

Hierarchy::Hierarchy(QWidget *parent) : QWidget(parent), ui(new Ui::Hierarchy)
{
    ui->setupUi(this);

    connect(ui->AddEntity,SIGNAL(clicked()),this,SLOT(onAddEntity()));
    connect(ui->RemoveEntity,SIGNAL(clicked()),this,SLOT(onRemoveEntity()));
    connect(ui->listWidget,SIGNAL(currentRowChanged(int)),this,SLOT(onEntitySelected(int)));
}

Hierarchy::~Hierarchy()
{
    delete ui;
}

void Hierarchy::onAddEntity()
{
    std::string test= "Entity" + std::to_string(numEntities);
    numEntities++;
    ui->listWidget->addItem(test.c_str());
}

void Hierarchy::onRemoveEntity()
{
    int row=ui->listWidget->currentRow();
    ui->listWidget->takeItem(row);
    numEntities--;
}

void Hierarchy::onEntitySelected(int row)
{
    emit entityChanged(row);
}
