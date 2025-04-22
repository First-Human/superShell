#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenuBar>
#include <QMenu>
#include <QToolBar>
#include <QAction>

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
    QMenu *viewMenu;
    QAction *terminalSessionAction;
    QAction *fileSessionAction;
    QToolBar *mainTool;
    QAction *terminalSessionToolAction;
    QAction *fileSessionToolAction;

    void createMenu();
    void createTool();

};
#endif // MAINWINDOW_H
