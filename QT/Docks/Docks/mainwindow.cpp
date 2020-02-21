#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include "inspector.h" 1
#include "hierarchy.h"
#include "inspector.h"
#include "sceneview.h"

#include <QMessageBox>
#include <QFileDialog>
#include <iostream>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),uiMainWindow(new Ui::MainWindow)
{
    uiMainWindow->setupUi(this);

//  1- Using a widget Class:
//  Inspector* inspector = new Inspector();
//  ui->Dock_1->setWidget(inspector);

//  2- Without using a widget Class:
//  Create an empty widget:
    //QWidget* widget = new QWidget();
//  execute setupUI
    //uiTransform->setupUi(widget);
//  set the widget into the dock
    //uiMainWindow->Dock_1->setWidget(widget);

    hierarchy = new Hierarchy();
    uiMainWindow->Hierarchy->setWidget(hierarchy);

    inspector = new Inspector();
    uiMainWindow->Dock_1->setWidget(inspector);

    sceneView= new SceneView();
    QVBoxLayout* layout = new QVBoxLayout();
    layout->addWidget(sceneView);
    uiMainWindow->centralWidget->setLayout(layout);

    //Button Connection
    connect(uiMainWindow->LoadProject,SIGNAL(triggered()),this,SLOT(LoadFile()));
    connect(uiMainWindow->SaveProject,SIGNAL(triggered()),this,SLOT(SaveFile()));
    connect(hierarchy,SIGNAL(entityChanged(int)),inspector,SLOT(onEntitySelected(int)));
}

MainWindow::~MainWindow()
{
    delete uiMainWindow;
}

void MainWindow::LoadFile()
{
    QMessageBox::StandardButton button = QMessageBox::question(this,"Load Project","Do you want to Load?");
    if(button==QMessageBox::Yes)
    {
        QString path=QFileDialog::getOpenFileName(this,"Open Project");
        if(!path.isEmpty())
        {
            std::cout<<path.toStdString()<<std::endl;
        }
    }
}

void MainWindow::SaveFile()
{
    close();
}

