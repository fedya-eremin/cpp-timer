#include <QApplication>
#include "MainWindow.h"
#include "ThemeManager.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    app.setApplicationName("Time App");
    app.setApplicationVersion("1.0");

    // Set initial theme (will be light by default in ThemeManager)
    ThemeManager::setTheme(ThemeManager::Light);

    MainWindow window;
    window.setWindowTitle("Time App - Timer & Stopwatch");
    window.resize(500, 400);
    window.show();

    return app.exec();
}