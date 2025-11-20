#include "ThemeManager.h"

ThemeManager::Theme ThemeManager::m_currentTheme = ThemeManager::Light;

void ThemeManager::setTheme(Theme theme)
{
    m_currentTheme = theme;
    
    if (theme == Dark) {
        setDarkTheme();
    } else {
        setLightTheme();
    }
}

void ThemeManager::toggleTheme()
{
    if (m_currentTheme == Dark) {
        setTheme(Light);
    } else {
        setTheme(Dark);
    }
}

void ThemeManager::setLightTheme()
{
    // Set the Fusion style for consistent look
    QApplication::setStyle(QStyleFactory::create("Fusion"));

    // Create a light palette
    QPalette lightPalette;
    lightPalette.setColor(QPalette::Window, QColor(255, 255, 255));
    lightPalette.setColor(QPalette::WindowText, QColor(0, 0, 0));
    lightPalette.setColor(QPalette::Base, QColor(240, 240, 240));
    lightPalette.setColor(QPalette::AlternateBase, QColor(220, 220, 220));
    lightPalette.setColor(QPalette::ToolTipBase, QColor(255, 255, 220));
    lightPalette.setColor(QPalette::ToolTipText, QColor(0, 0, 0));
    lightPalette.setColor(QPalette::Text, QColor(0, 0, 0));
    lightPalette.setColor(QPalette::Button, QColor(240, 240, 240));
    lightPalette.setColor(QPalette::ButtonText, QColor(0, 0, 0));
    lightPalette.setColor(QPalette::BrightText, QColor(255, 255, 255));
    lightPalette.setColor(QPalette::Link, QColor(0, 0, 255));
    lightPalette.setColor(QPalette::Highlight, QColor(51, 153, 255));
    lightPalette.setColor(QPalette::HighlightedText, QColor(255, 255, 255));

    qApp->setPalette(lightPalette);

    // Set comprehensive light theme stylesheet for consistency
    qApp->setStyleSheet(
        "QLabel { color: black; }"
        "QLineEdit { background-color: white; color: black; border: 1px solid gray; }"
        "QSpinBox { background-color: white; color: black; border: 1px solid gray; }"
        "QPushButton { background-color: rgb(240, 240, 240); color: black; border: 1px solid gray; border-radius: 4px; padding: 5px; }"
        "QPushButton:hover { background-color: rgb(220, 220, 220); }"
        "QPushButton:pressed { background-color: rgb(200, 200, 200); }"
        "QPushButton:disabled { color: rgb(150, 150, 150); }"
        "QListWidget { background-color: white; color: black; border: 1px solid gray; }"
        "QScrollBar:vertical { background: rgb(240, 240, 240); width: 15px; }"
        "QScrollBar::handle:vertical { background: rgb(200, 200, 200); border-radius: 4px; min-height: 20px; }"
        "QScrollBar::handle:vertical:hover { background: rgb(180, 180, 180); }"
        "QTabWidget::pane { border: 1px solid gray; }"
        "QTabBar::tab { background: rgb(240, 240, 240); color: black; border: 1px solid gray; "
        "               border-bottom-color: gray; border-top-left-radius: 4px; border-top-right-radius: 4px; "
        "               min-width: 80px; padding: 8px; margin: 2px; }"
        "QTabBar::tab:selected, QTabBar::tab:hover { background: white; }"
        "QTabBar::tab:selected { background: white; font-weight: bold; }"
    );
}

void ThemeManager::setDarkTheme()
{
    // Set the Fusion style for consistent look
    QApplication::setStyle(QStyleFactory::create("Fusion"));

    // Create a dark palette
    QPalette darkPalette;
    darkPalette.setColor(QPalette::Window, QColor(53, 53, 53));
    darkPalette.setColor(QPalette::WindowText, QColor(255, 255, 255));
    darkPalette.setColor(QPalette::Base, QColor(25, 25, 25, 255));
    darkPalette.setColor(QPalette::AlternateBase, QColor(53, 53, 53));
    darkPalette.setColor(QPalette::ToolTipBase, QColor(40, 40, 40));
    darkPalette.setColor(QPalette::ToolTipText, QColor(255, 255, 255));
    darkPalette.setColor(QPalette::Text, QColor(230, 230, 230));
    darkPalette.setColor(QPalette::Button, QColor(53, 53, 53));
    darkPalette.setColor(QPalette::ButtonText, QColor(255, 255, 255));
    darkPalette.setColor(QPalette::BrightText, QColor(255, 0, 0));
    darkPalette.setColor(QPalette::Link, QColor(42, 130, 218));
    darkPalette.setColor(QPalette::Highlight, QColor(42, 130, 218));
    darkPalette.setColor(QPalette::HighlightedText, QColor(255, 255, 255)); // Fixed: was black, now white for visibility

    qApp->setPalette(darkPalette);

    // Set comprehensive dark theme stylesheet
    qApp->setStyleSheet(
        "QLabel { color: rgb(230, 230, 230); }"
        "QLineEdit { background-color: rgb(40, 40, 40); color: rgb(230, 230, 230); border: 1px solid rgb(70, 70, 70); }"
        "QSpinBox { background-color: rgb(40, 40, 40); color: rgb(230, 230, 230); border: 1px solid rgb(70, 70, 70); }"
        "QPushButton { background-color: rgb(60, 60, 60); color: rgb(230, 230, 230); border: 1px solid rgb(80, 80, 80); border-radius: 4px; padding: 5px; }"
        "QPushButton:hover { background-color: rgb(70, 70, 70); }"
        "QPushButton:pressed { background-color: rgb(50, 50, 50); }"
        "QPushButton:disabled { color: rgb(120, 120, 120); }"
        "QListWidget { background-color: rgb(40, 40, 40); color: rgb(230, 230, 230); border: 1px solid rgb(70, 70, 70); }"
        "QScrollBar:vertical { background: rgb(50, 50, 50); width: 15px; }"
        "QScrollBar::handle:vertical { background: rgb(80, 80, 80); border-radius: 4px; min-height: 20px; }"
        "QScrollBar::handle:vertical:hover { background: rgb(100, 100, 100); }"
        "QTabWidget::pane { border: 1px solid rgb(70, 70, 70); }"
        "QTabBar::tab { background: rgb(60, 60, 60); color: rgb(230, 230, 230); border: 1px solid rgb(70, 70, 70); "
        "               border-bottom-color: rgb(70, 70, 70); border-top-left-radius: 4px; border-top-right-radius: 4px; "
        "               min-width: 80px; padding: 8px; margin: 2px; }"
        "QTabBar::tab:selected, QTabBar::tab:hover { background: rgb(70, 70, 70); }"
        "QTabBar::tab:selected { background: rgb(70, 70, 70); font-weight: bold; }"
    );
}