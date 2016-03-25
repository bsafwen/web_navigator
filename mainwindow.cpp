#include "mainwindow.h"

MainWindoW::MainWindoW()
{
    this->setWindowIcon(QIcon("/home/bsafwene/compSci/C++/Qt/webNavigator/web.png"));
    tabs = new QTabWidget(this);
    createActions();
    createToolBar();
    createMenus();
    createProgressBar();
    setCentralWidget(tabs);
    addTab();
}

void MainWindoW::createMenus()
{
   file = menuBar()->addMenu("&File");
   file->addAction(newTab);
   file->addAction(closeTab);
   file->addSeparator();
   file->addAction(quit);
   navigation = menuBar()->addMenu("&Navigation");
   navigation->addAction(next);
   navigation->addAction(prev);
   navigation->addAction(reload);
   navigation->addAction(startPage);
   menuBar()->addSeparator();
   questionMark = menuBar()->addMenu("&About");
   questionMark->addAction(about);
   questionMark->addAction(aboutQt);
}

void MainWindoW::createActions()
{
    newTab = new QAction("&New tab", this);
    connect(newTab, SIGNAL(triggered()),this,SLOT(addTab()));
    closeTab = new QAction("&Close tab", this);
    connect(closeTab, SIGNAL(triggered()), this, SLOT(removeTab()));
    quit = new QAction("&Quit",this);
    connect(quit,SIGNAL(triggered()),qApp,SLOT(quit()));
    prev = new QAction(QIcon("/home/bsafwene/compSci/C++/Qt/webNavigator/prec.png"),"&Previous",this);
    connect(prev,SIGNAL(triggered()),this, SLOT(previousPage()));
    next = new QAction(QIcon("/home/bsafwene/compSci/C++/Qt/webNavigator/suiv.png"),"&Next",this);
    connect(next,SIGNAL(triggered()),this , SLOT(forwardPage()));
    reload = new QAction(QIcon("/home/bsafwene/compSci/C++/Qt/webNavigator/actu.png"), "&Reload",this);
    connect(reload, SIGNAL(triggered()), tabs->currentWidget()->findChild<QWebView *>(), SLOT(reload()));
    stop = new QAction(QIcon("/home/bsafwene/compSci/C++/Qt/webNavigator/stop.png"),"&Stop",this);
    connect(stop, SIGNAL(triggered()), tabs->currentWidget()->findChild<QWebView *>(), SLOT(stop()));
    go = new QAction(QIcon("/home/bsafwene/compSci/C++/Qt/webNavigator/go.png"),"&Go",this);
    connect(go, SIGNAL(triggered()), tabs->currentWidget()->findChild<QWebView *>(), SLOT(goAddress()) );
    startPage = new QAction(QIcon("/home/bsafwene/compSci/C++/Qt/webNavigator/home.png"),"&Start page",this);
    about = new QAction("&About", this);
    connect(about, SIGNAL(triggered()), this, SLOT(aboutDialog()));
    aboutQt = new QAction("About &Qt", this);
    connect(aboutQt, SIGNAL(triggered()), this, SLOT(aboutDialogQt()));
}

void MainWindoW::createToolBar()
{
    navigationToolBar = addToolBar("Navigation");
    navigationToolBar->addAction(prev);
    navigationToolBar->addAction(next);
    navigationToolBar->addAction(reload);
    navigationToolBar->addAction(stop);
    barAddress = new QLineEdit ;
    connect(barAddress, SIGNAL(editingFinished()),this, SLOT(goAddress()));
    navigationToolBar->addWidget(barAddress);
    navigationToolBar->addAction(go);

}

void MainWindoW::createProgressBar()
{
    progressBar = new QProgressBar ;
    progressBar->setRange(0,100);
    statusBar()->addWidget(progressBar,1);
}

void MainWindoW::addTab()
{
    QWidget *t = new QWidget ;
    QWebView *tv = new QWebView(this);
    tv->load(QUrl("http://www.google.fr/"));
    tv->show();
    QVBoxLayout *layout = new QVBoxLayout ;
    layout->addWidget(tv);
    t->setLayout(layout);
    tabs->addTab(t,"Google");
    barAddress->setText("http://www.google.fr/");
    connect(tv, SIGNAL(titleChanged(QString)), SLOT(adjustTitle()));
    connect(tv,SIGNAL(urlChanged(QUrl)),this, SLOT(setTabTitle()));
    connect(tv, SIGNAL(loadProgress(int)), this, SLOT(updatepBar(int)));
}

void MainWindoW::removeTab()
{
    tabs->removeTab(tabs->currentIndex());
}

void MainWindoW::previousPage()
{
    QWebView *ptr = tabs->currentWidget()->findChild<QWebView *>() ;
    ptr->history()->back();
}

void MainWindoW::goAddress()
{
    QWebView *ptr = tabs->currentWidget()->findChild<QWebView *>() ;
    QUrl url = QUrl::fromUserInput(barAddress->text());
    ptr->load(url);
}

void MainWindoW::forwardPage()
{
    QWebView *ptr = tabs->currentWidget()->findChild<QWebView *>();
    ptr->history()->forward();
}

void MainWindoW::aboutDialog()
{
    QMessageBox::information(this, "About", "This my homework");
}

void MainWindoW::aboutDialogQt()
{
    QMessageBox::information(this,"About Qt","whatever");
}

void MainWindoW::adjustTitle()
{
    setWindowTitle(tabs->currentWidget()->findChild<QWebView *>()->title());

}

void MainWindoW::setTabTitle()
{
    barAddress->setText(tabs->currentWidget()->findChild<QWebView *>()->url().toDisplayString());
    tabs->setTabText(tabs->currentIndex(),tabs->currentWidget()->findChild<QWebView *>()->url().host());
}

void MainWindoW::updatepBar(int progress)
{
    progressBar->setValue(progress);
}
