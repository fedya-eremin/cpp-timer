#ifndef STOPWATCHWIDGET_H
#define STOPWATCHWIDGET_H

#include <QWidget>
#include <QTimer>
#include <QTime>
#include <QList>

class QLabel;
class QPushButton;
class QListWidget;

class StopwatchWidget : public QWidget
{
    Q_OBJECT

public:
    explicit StopwatchWidget(QWidget *parent = nullptr);

private slots:
    void startStopwatch();
    void pauseStopwatch();
    void resetStopwatch();
    void recordLap();
    void updateStopwatch();

private:
    void updateTimeDisplay();

    QTime m_startTime; // The time when the current session started
    QTime m_elapsedTime; // For display purposes only
    QTimer *m_timer;
    bool m_isRunning;
    int m_totalElapsedMs; // Total accumulated milliseconds from all sessions
    
    QLabel *m_timeLabel;
    QPushButton *m_startButton;
    QPushButton *m_pauseButton;
    QPushButton *m_resetButton;
    QPushButton *m_lapButton;
    QListWidget *m_lapsList;
};

#endif // STOPWATCHWIDGET_H