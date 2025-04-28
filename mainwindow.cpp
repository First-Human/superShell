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
    connect(terminalSessionAction, &QAction::triggered, this, &MainWindow::createTerminalLogin);
    connect(fileSessionAction, &QAction::triggered, this, &MainWindow::createFileLogin);
    connect(terminalSessionToolAction, &QAction::triggered, this, &MainWindow::createTerminalLogin);
    connect(fileSessionToolAction, &QAction::triggered, this, &MainWindow::createFileLogin);
    connect(terminalSessionBtn, &QPushButton::clicked, this, &MainWindow::createTerminalLogin);
    connect(fileSessionBtn, &QPushButton::clicked, this, &MainWindow::createFileLogin);
    connect(this, &MainWindow::terminalLogin, this, &MainWindow::createLoginDiglog);
    connect(this, &MainWindow::fileLogin, this, &MainWindow::createLoginDiglog);
    connect(rightTabWidget, &QTabWidget::tabCloseRequested, this, [=](int index){
        // 获取要关闭的标签页内容
        QWidget* tabContent = rightTabWidget->widget(index);
        // 删除标签页内容对象，防止内存泄漏
        tabContent->deleteLater();
        // 从tabWidget中移除标签页
        rightTabWidget->removeTab(index);

    });

}

MainWindow::~MainWindow()
{
    delete ui;
}

/******************创建菜单栏******************************/
void MainWindow::createMainMenu(){
    mainMenuBar = new QMenuBar();
    sessionMenu = new QMenu("会话");
    keyMenu = new QMenu("生成密钥");
    viewMenu = new QMenu("视图");
    X11Menu = new QMenu("X11");
    setingMenu = new QMenu("系统设置");
    terminalSessionAction = new QAction("命令界面");
    fileSessionAction = new QAction("文件界面");

    this->setMenuBar(mainMenuBar);
    mainMenuBar->addMenu(sessionMenu);
    mainMenuBar->addMenu(keyMenu);
    mainMenuBar->addMenu(viewMenu);
    mainMenuBar->addMenu(X11Menu);
    mainMenuBar->addMenu(setingMenu);
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
    rightTabWidget->setTabsClosable(true);
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
    leftTabWidget->addTab(sessionItem, "会话");
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

void MainWindow::createTerminalLogin(){
    emit terminalLogin(0);

}
void MainWindow::createFileLogin(){
    emit fileLogin(1);
}
/*********************登录弹窗************************************/
void MainWindow::createLoginDiglog(int sessionType){
    sshLoginDialog = new QsshLoginDialog(&sessionType, this);
    if(sshLoginDialog->exec() == QDialog::Accepted){
        if(sessionType == 0){//命令行显示
            QWidget *terminalSessionWd = new QWidget();
            QVBoxLayout *terminalLayout = new QVBoxLayout();
            terminalSessionWd->setLayout(terminalLayout);
            QTextEdit *textWind = new QTextEdit();
            terminalLayout->addWidget(textWind);
            int count = rightTabWidget->count();
            int index = rightTabWidget->addTab(terminalSessionWd, "命令界面"+QString::number(count+1));
            rightTabWidget->setCurrentIndex(index);

        }
        else{//文件显示
            QWidget *fileSessionWd = new QWidget();
            QVBoxLayout *fileLayout = new QVBoxLayout();
            fileSessionWd->setLayout(fileLayout);
            QTextEdit *textWind = new QTextEdit();
            fileLayout->addWidget(textWind);
            int count = rightTabWidget->count();
            int index = rightTabWidget->addTab(fileSessionWd, "文件界面"+QString::number(count+1));
            rightTabWidget->setCurrentIndex(index);
        }

    }

}


