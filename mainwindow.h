#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QtWebKit>
#include <QLabel>
#include <QProgressBar>
#include <QTabWidget>
#include <QLineEdit>
#include <QMenuBar>
#include <QToolBar>
#include <QStatusBar>
#include <QLayout>
#include <QWebView>
#include <QMessageBox>

class MainWindoW : public QMainWindow
{
    Q_OBJECT
public:
    MainWindoW();
public slots:
    void addTab();
    void removeTab();
    void previousPage();
    void goAddress();
    void forwardPage();
    void adjustTitle();
    void aboutDialog();
    void aboutDialogQt();
    void setTabTitle();
    void updatepBar(int);
private:
    void createMenus();
    void createToolBar();
    void createActions();
    void createProgressBar();
    QMenu *file ;
    QMenu *navigation ;
    QMenu *questionMark ;
    QToolBar *fileToolBar ;
    QToolBar *navigationToolBar ;
    QAction * closeTab ;
    QAction * newTab ;
    QAction *quit ;
    QAction *next ;
    QAction *prev ;
    QAction *reload ;
    QAction *stop ;
    QAction *startPage ;
    QAction *go ;
    QAction *about ;
    QAction *aboutQt ;
    QProgressBar *progressBar ;
    QLineEdit *barAddress ;
    QTabWidget *tabs ;
};

#endif // MAINWINDOW_H
