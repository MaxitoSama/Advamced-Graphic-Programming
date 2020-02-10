#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Concting the UI with each function
    connect(ui->Button_1,SIGNAL(clicked()),this,SLOT(onText1Pressed()));
    connect(ui->Button_2,SIGNAL(clicked()),this,SLOT(onText2Pressed()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onText1Pressed()
{
    ui->Text_1->setText("Helllo");
}
void MainWindow::onText2Pressed()
{
    ui->Text_1->setText("Adeeuu");
}

