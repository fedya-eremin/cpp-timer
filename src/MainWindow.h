#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTabWidget>
#include <QAction>
#include <memory>

class TimerWidget;
class StopwatchWidget;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void toggleTheme();

private:
    void setupMenuBar();

    QTabWidget *m_tabWidget;
    std::unique_ptr<TimerWidget> m_timerWidget;
    std::unique_ptr<StopwatchWidget> m_stopwatchWidget;
    QAction *m_themeAction;
};

#endif // MAINWINDOW_H