#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "GLObjLoader.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
	GLObjLoader * openglWgt = new GLObjLoader(this);
	this->setCentralWidget(openglWgt);
}

MainWindow::~MainWindow()
{
    delete ui;
}

