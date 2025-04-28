#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenuBar>
#include <QMenu>
#include <QToolBar>
#include <QAction>
#include <QTabWidget>
#include <QWidget>
#include <QSplitter>
#include <QPushButton>
#include <QVBoxLayout>
#include <QListWidget>
#include <QGroupBox>
#include <qlogindialog.h>
#include <QTextEdit>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QMenuBar *mainMenuBar;
    QMenu *sessionMenu;
    QMenu *keyMenu;
    QMenu *viewMenu;
    QMenu *X11Menu;
    QMenu *setingMenu;
    QAction *terminalSessionAction;
    QAction *fileSessionAction;
    QToolBar *mainTool;
    QAction *terminalSessionToolAction;
    QAction *fileSessionToolAction;
    QTabWidget *leftTabWidget;
    QTabWidget *rightTabWidget;
    QSplitter *mainSplitter;
    QSplitter *leftSplitter;
    QWidget *sessionItem;
    QWidget *mainInterface;
    QGroupBox *terminalSessionGroupBox;
    QGroupBox *fileSessionGroupBox;
    QListWidget *terminalListWidget;//命令行会话项列表
    QListWidget *fileListWidget;//文件会话项列表
    QPushButton *terminalSessionBtn;
    QPushButton *fileSessionBtn;
    QVBoxLayout *mainLayout;
    QVBoxLayout *sessionItemLayout;
    QVBoxLayout *terminalSessionLayout;
    QVBoxLayout *fileSessionLayout;

    QsshLoginDialog *sshLoginDialog;


    void createMainMenu();
    void createMainTool();
    void createMianTabWidget();
public slots:
    void createTerminalLogin();
    void createFileLogin();
    void createLoginDiglog(int sessionType);

signals:
    void terminalLogin(int type);
    void fileLogin(int type);

};
#endif // MAINWINDOW_H
