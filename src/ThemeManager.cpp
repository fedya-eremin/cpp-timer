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
    
    // Set default text color to black
    qApp->setStyleSheet("QLabel { color: black; }");
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
    darkPalette.setColor(QPalette::ToolTipBase, QColor(0, 0, 0));
    darkPalette.setColor(QPalette::ToolTipText, QColor(255, 255, 255));
    darkPalette.setColor(QPalette::Text, QColor(230, 230, 230));
    darkPalette.setColor(QPalette::Button, QColor(53, 53, 53));
    darkPalette.setColor(QPalette::ButtonText, QColor(255, 255, 255));
    darkPalette.setColor(QPalette::BrightText, QColor(255, 0, 0));
    darkPalette.setColor(QPalette::Link, QColor(42, 130, 218));
    darkPalette.setColor(QPalette::Highlight, QColor(42, 130, 218));
    darkPalette.setColor(QPalette::HighlightedText, QColor(0, 0, 0));
    
    qApp->setPalette(darkPalette);
    
    // Set default text color to white for dark theme
    qApp->setStyleSheet("QLabel { color: white; }");
}