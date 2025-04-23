#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("superShell");
    this->createMainMenu();
    this->createMainTool();
    this->createMianTabWidget();
}

MainWindow::~MainWindow()
{
    delete ui;
}

/******************创建菜单栏******************************/
void MainWindow::createMainMenu(){
    mainMenuBar = new QMenuBar();
    sessionMenu = new QMenu("会话");
    viewMenu = new QMenu("视图");
    X11Menu = new QMenu("X11");
    terminalSessionAction = new QAction("命令界面");
    fileSessionAction = new QAction("文件界面");

    this->setMenuBar(mainMenuBar);
    mainMenuBar->addMenu(sessionMenu);
    mainMenuBar->addMenu(viewMenu);
    mainMenuBar->addMenu(X11Menu);
    sessionMenu->addAction(terminalSessionAction);
    sessionMenu->addAction(fileSessionAction);
}
/******************创建工具栏******************************/
void MainWindow::createMainTool(){
    mainTool = new QToolBar();
    terminalSessionToolAction = new QAction("命令界面");
    fileSessionToolAction = new QAction("文件界面");

    this->addToolBar(mainTool);
    mainTool->addAction(terminalSessionToolAction);
    mainTool->addAction(fileSessionAction);
}
/******************设置窗口分割******************************/
void MainWindow::createMianTabWidget(){
    leftTabWidget = new QTabWidget();
    rightTabWidget = new QTabWidget();
    mainSplitter = new QSplitter();
    mainSplitter->addWidget(leftTabWidget);
    mainSplitter->addWidget(rightTabWidget);
    /***************右标签页容器主界面布局************************/
    mainInterface = new QWidget();
    terminalSessionBtn = new QPushButton("命令界面");
    fileSessionBtn = new QPushButton("文件界面");
    terminalSessionBtn->setFixedSize(100,40);
    fileSessionBtn->setFixedSize(100,40);
    mainLayout = new QVBoxLayout(mainInterface);
    mainLayout->addWidget(terminalSessionBtn);
    mainLayout->addWidget(fileSessionBtn);
    mainLayout->setAlignment(Qt::AlignCenter);
    mainLayout->setSpacing(10);
    rightTabWidget->addTab(mainInterface, "主界面");
    /****************左标签页容器会话界面布局**********************/
    sessionItem = new QWidget();
    leftTabWidget->addTab(sessionItem, "话会");
    leftTabWidget->setTabPosition(QTabWidget::West);
    leftSplitter = new QSplitter(Qt::Vertical, sessionItem);
    terminalSessionGroupBox = new QGroupBox("命令会话");
    fileSessionGroupBox = new QGroupBox("文件会话");
    terminalSessionLayout = new QVBoxLayout();
    fileSessionLayout = new QVBoxLayout();
    terminalListWidget = new QListWidget();
    fileListWidget = new QListWidget();
    sessionItemLayout = new QVBoxLayout(sessionItem);
    sessionItemLayout->setContentsMargins(0,0,0,0);
    terminalSessionLayout->addWidget(terminalListWidget);
    fileSessionLayout->addWidget(fileListWidget);
    terminalSessionGroupBox->setLayout(terminalSessionLayout);
    fileSessionGroupBox->setLayout(fileSessionLayout);

    sessionItemLayout->addWidget(leftSplitter);
    leftSplitter->addWidget(terminalSessionGroupBox);
    leftSplitter->addWidget(fileSessionGroupBox);
    leftSplitter->setCollapsible(0, false);
    leftSplitter->setCollapsible(1, false);


    /*****************左右标签页容器拉伸比例***********************/
    mainSplitter->setStretchFactor(0,1);
    mainSplitter->setStretchFactor(1,9);
    mainSplitter->setCollapsible(0, false);
    mainSplitter->setCollapsible(1, false);


    setCentralWidget(mainSplitter);


}


