#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("superShell");
    this->createMenu();
    this->createTool();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::createMenu(){
    mainMenuBar = new QMenuBar();
    sessionMenu = new QMenu("会话");
    viewMenu = new QMenu("视图");
    terminalSessionAction = new QAction("命令界面");
    fileSessionAction = new QAction("文件界面");

    this->setMenuBar(mainMenuBar);
    mainMenuBar->addMenu(sessionMenu);
    mainMenuBar->addMenu(viewMenu);
    sessionMenu->addAction(terminalSessionAction);
    sessionMenu->addAction(fileSessionAction);
}

void MainWindow::createTool(){
    mainTool = new QToolBar();
    terminalSessionToolAction = new QAction("命令界面");
    fileSessionToolAction = new QAction("文件界面");

    this->addToolBar(mainTool);
    mainTool->addAction(terminalSessionToolAction);
    mainTool->addAction(fileSessionAction);
}
