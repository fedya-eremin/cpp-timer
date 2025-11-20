#ifndef TIMERWIDGET_H
#define TIMERWIDGET_H

#include <QWidget>
#include <QTimer>
#include <QTime>

class QLabel;
class QPushButton;
class QSpinBox;

class TimerWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TimerWidget(QWidget *parent = nullptr);

private slots:
    void startTimer();
    void pauseTimer();
    void resetTimer();
    void updateTimer();

private:
    void updateTimeDisplay();

    QTime m_initialTime;
    QTime m_currentTime;
    QTimer *m_timer;
    bool m_isRunning;
    
    QLabel *m_timeLabel;
    QPushButton *m_startButton;
    QPushButton *m_pauseButton;
    QPushButton *m_resetButton;
    QSpinBox *m_hourSpinBox;
    QSpinBox *m_minuteSpinBox;
    QSpinBox *m_secondSpinBox;
};

#endif // TIMERWIDGET_H