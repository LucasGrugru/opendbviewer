/*
 * MainWindow.cpp
 *
 *  Created on: 7 juin 2016
 *      Author: echopin
 */

#include "QWindowMain.h"

QWindowMain::QWindowMain(QWidget* parent)
	: QMainWindow(parent)
{
    //Set minimum window size
    setMinimumSize(900, 600);

    //Creation of the menu bar
    createMenu();

    //Creation of the central area
    QWidget *pCentralArea = new QWidget();
    setCentralWidget(pCentralArea);

    //Creation of the main layout
    QVBoxLayout *pMainLayout = new QVBoxLayout();
    pCentralArea->setLayout(pMainLayout);

    //Creation of the first set of tabs for database files
    m_pDatabaseConnectionTab = new QTabWidget(this);
    pMainLayout->addWidget(m_pDatabaseConnectionTab);
}

QWindowMain::~QWindowMain()
{

}

QAction* QWindowMain::getNewConnectionAction() const
{
	return m_pNewConnectionAction;
}

void QWindowMain::addDatabaseConnectionView(QDatabaseConnectionView* pDatabaseConnectionView, const QString& szTitle)
{
	m_pDatabaseConnectionTab->addTab(pDatabaseConnectionView, szTitle);
}

void QWindowMain::createMenu()
{
	QAction *pAction;

    QMenu *pFileMenu = menuBar()->addMenu(tr("&File"));
    m_pNewConnectionAction = new QAction(tr("&New connection"), this);
    pFileMenu->addAction(m_pNewConnectionAction);

    pAction = new QAction(tr("&Quit"), this);
    pFileMenu->addAction(pAction);


    QMenu *pEditMenu = menuBar()->addMenu(tr("&Edit"));
    pAction = new QAction(tr("&Cut"), this);
    pEditMenu->addAction(pAction);
    pAction = new QAction(tr("&Copy"), this);
    pEditMenu->addAction(pAction);
    pAction = new QAction(tr("&Paste"), this);
    pEditMenu->addAction(pAction);
    pAction = new QAction(tr("&Delete"), this);
    pEditMenu->addAction(pAction);

    QMenu *pViewMenu = menuBar()->addMenu(tr("&View"));

    QMenu *pHelpMenu = menuBar()->addMenu(tr("&Help"));
    pAction = new QAction(tr("&About"), this);
    pHelpMenu->addAction(pAction);

}