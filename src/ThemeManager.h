#ifndef THEMEMANAGER_H
#define THEMEMANAGER_H

#include <QApplication>
#include <QPalette>
#include <QStyleFactory>

class ThemeManager
{
public:
    enum Theme {
        Light,
        Dark
    };

    static void setTheme(Theme theme);
    static Theme currentTheme() { return m_currentTheme; }
    static void toggleTheme();

private:
    static Theme m_currentTheme;
    static void setDarkTheme();
    static void setLightTheme();
};

#endif // THEMEMANAGER_H