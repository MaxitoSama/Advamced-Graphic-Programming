#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_inspector.h" // 2
//#include "inspector.h" 1

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),uiMainWindow(new Ui::MainWindow),uiInspector(new Ui::Inspector)
{
    uiMainWindow->setupUi(this);

//  1- Using a widget Class:
//  Inspector* inspector = new Inspector();
//  ui->Dock_1->setWidget(inspector);

//  2- Without using a widget Class:
//  Create an empty widget:
    QWidget* widget = new QWidget();
//  execute setupUI
    uiInspector->setupUi(widget);
//  set the widget into the dock
    uiMainWindow->Dock_1->setWidget(widget);


    //Button Connection
    connect(uiMainWindow->LoadProject,SIGNAL(triggered()),this,SLOT(LoadFile()));
    connect(uiMainWindow->SaveProject,SIGNAL(triggered()),this,SLOT(SaveFile()));
}

MainWindow::~MainWindow()
{
    delete uiMainWindow;
    delete uiInspector;
}

void MainWindow::LoadFile()
{
    close();
}

void MainWindow::SaveFile()
{
    close();
}
