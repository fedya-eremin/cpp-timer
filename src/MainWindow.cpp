#include <QTabWidget>
#include <QVBoxLayout>
#include <QMenuBar>
#include <QStyleFactory>
#include <QApplication>

#include "MainWindow.h"
#include "TimerWidget.h"
#include "StopwatchWidget.h"
#include "ThemeManager.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , m_tabWidget(new QTabWidget(this))
{
    // Initialize with light theme
    ThemeManager::setTheme(ThemeManager::Light);

    // Create the widgets
    m_timerWidget = std::make_unique<TimerWidget>();
    m_stopwatchWidget = std::make_unique<StopwatchWidget>();

    // Add widgets to tab widget
    m_tabWidget->addTab(m_timerWidget.get(), "Timer");
    m_tabWidget->addTab(m_stopwatchWidget.get(), "Stopwatch");

    // Don't set specific tab widget stylesheet since theme handles it
    // The tab widget will inherit styles from the application theme

    // Set the central widget
    setCentralWidget(m_tabWidget);

    // Setup menu bar
    setupMenuBar();
}

MainWindow::~MainWindow()
{
}

void MainWindow::setupMenuBar()
{
    QMenu *viewMenu = menuBar()->addMenu("View");

    m_themeAction = new QAction("Toggle Theme", this);
    m_themeAction->setShortcut(QKeySequence("Ctrl+T"));
    connect(m_themeAction, &QAction::triggered, this, &MainWindow::toggleTheme);
    viewMenu->addAction(m_themeAction);
}

void MainWindow::toggleTheme()
{
    ThemeManager::toggleTheme();

    // Update action text based on current theme
    if (ThemeManager::currentTheme() == ThemeManager::Dark) {
        m_themeAction->setText("Switch to Light Theme");
    } else {
        m_themeAction->setText("Switch to Dark Theme");
    }
}