#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QListWidget>
#include <QTime>
#include <QString>
#include <QMessageBox>

#include "StopwatchWidget.h"

StopwatchWidget::StopwatchWidget(QWidget *parent)
    : QWidget(parent)
    , m_timer(new QTimer(this))
    , m_isRunning(false)
    , m_totalElapsedMs(0)
{
    // Set up the layout
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    // Title
    QLabel *titleLabel = new QLabel("Stopwatch");
    titleLabel->setAlignment(Qt::AlignCenter);
    titleLabel->setStyleSheet("QLabel { font-size: 24px; font-weight: bold; margin: 10px; }");

    // Time display
    m_timeLabel = new QLabel("00:00:00.00");
    m_timeLabel->setAlignment(Qt::AlignCenter);
    m_timeLabel->setStyleSheet("QLabel { font-size: 48px; font-weight: bold; margin: 20px; }");

    // Control buttons
    QHBoxLayout *buttonLayout = new QHBoxLayout();
    m_startButton = new QPushButton("Start");
    m_pauseButton = new QPushButton("Pause");
    m_resetButton = new QPushButton("Reset");
    m_lapButton = new QPushButton("Lap");

    buttonLayout->addStretch(); // Add stretch to center the buttons
    buttonLayout->addWidget(m_startButton);
    buttonLayout->addWidget(m_pauseButton);
    buttonLayout->addWidget(m_resetButton);
    buttonLayout->addWidget(m_lapButton);
    buttonLayout->addStretch();

    // Laps list title
    QLabel *lapsTitleLabel = new QLabel("Laps:");
    lapsTitleLabel->setStyleSheet("QLabel { font-size: 16px; font-weight: bold; margin-top: 10px; }");

    // Laps list
    m_lapsList = new QListWidget();
    m_lapsList->setMaximumHeight(150);

    // Add all widgets to main layout
    mainLayout->addWidget(titleLabel);
    mainLayout->addWidget(m_timeLabel);
    mainLayout->addSpacing(10);
    mainLayout->addLayout(buttonLayout);
    mainLayout->addSpacing(10);
    mainLayout->addWidget(lapsTitleLabel);
    mainLayout->addWidget(m_lapsList);
    mainLayout->addStretch(); // Add stretch to center content vertically

    // Connect signals and slots
    connect(m_timer, &QTimer::timeout, this, &StopwatchWidget::updateStopwatch);
    connect(m_startButton, &QPushButton::clicked, this, &StopwatchWidget::startStopwatch);
    connect(m_pauseButton, &QPushButton::clicked, this, &StopwatchWidget::pauseStopwatch);
    connect(m_resetButton, &QPushButton::clicked, this, &StopwatchWidget::resetStopwatch);
    connect(m_lapButton, &QPushButton::clicked, this, &StopwatchWidget::recordLap);

    // Initially disable buttons as needed
    m_pauseButton->setEnabled(false);
    m_lapButton->setEnabled(false);

    // Initialize the time
    m_elapsedTime = QTime(0, 0, 0);
    updateTimeDisplay();
}

void StopwatchWidget::startStopwatch()
{
    if (!m_isRunning) {
        // When starting or resuming, set the start time to current time
        // This begins a new measurement session
        m_startTime = QTime::currentTime();

        m_timer->start(10); // Update every 10ms for centisecond precision
        m_isRunning = true;
        m_startButton->setEnabled(false);
        m_pauseButton->setEnabled(true);
        m_lapButton->setEnabled(true);
    }
}

void StopwatchWidget::pauseStopwatch()
{
    if (m_isRunning) {
        m_timer->stop();
        m_isRunning = false;
        m_startButton->setEnabled(true);
        m_pauseButton->setEnabled(false);
        m_lapButton->setEnabled(false);

        // Calculate the elapsed time of the current session and add to total
        int currentSessionElapsed = m_startTime.msecsTo(QTime::currentTime());
        m_totalElapsedMs += currentSessionElapsed;
        m_elapsedTime = QTime(0, 0, 0).addMSecs(m_totalElapsedMs);
    }
}

void StopwatchWidget::resetStopwatch()
{
    m_timer->stop();
    m_isRunning = false;

    m_totalElapsedMs = 0;
    m_elapsedTime = QTime(0, 0, 0);
    m_lapsList->clear();

    // Reset the start time reference to a default (will be set properly on next start)
    m_startTime = QTime(0, 0, 0);

    updateTimeDisplay();
    m_startButton->setEnabled(true);
    m_pauseButton->setEnabled(false);
    m_lapButton->setEnabled(false);
}

void StopwatchWidget::recordLap()
{
    if (m_isRunning) {
        // Calculate total elapsed time since start
        int currentElapsed = m_startTime.msecsTo(QTime::currentTime());
        int totalElapsed = m_totalElapsedMs + currentElapsed;
        QTime currentTime = QTime(0, 0, 0).addMSecs(totalElapsed);

        // Calculate lap time
        QTime lapTime;
        if (m_lapsList->count() == 0) {
            // First lap - time since start
            lapTime = currentTime;
        } else {
            // Subsequent laps - calculate difference from previous lap
            QString lastLapText = m_lapsList->item(m_lapsList->count() - 1)->text();
            // Extract the time part from "Lap X: time (+lapTime)" format
            QStringList parts = lastLapText.split(" (+");
            QString lastTotalTimeStr = parts[0].split(": ")[1];
            QTime lastTotalTime = QTime::fromString(lastTotalTimeStr, "hh:mm:ss.z");

            int lapDiff = lastTotalTime.msecsTo(currentTime);
            lapTime = QTime(0, 0, 0).addMSecs(lapDiff);
        }

        // Add lap to list
        QString lapText = QString("Lap %1: %2 (+%3)")
                             .arg(m_lapsList->count() + 1)
                             .arg(currentTime.toString("hh:mm:ss.z"))
                             .arg(lapTime.toString("hh:mm:ss.z"));
        m_lapsList->addItem(lapText);
        m_lapsList->scrollToBottom();
    }
}

void StopwatchWidget::updateStopwatch()
{
    int currentSessionElapsed = m_startTime.msecsTo(QTime::currentTime());
    int totalElapsed = m_totalElapsedMs + currentSessionElapsed;
    m_elapsedTime = QTime(0, 0, 0).addMSecs(totalElapsed);
    updateTimeDisplay();
}

void StopwatchWidget::updateTimeDisplay()
{
    QString timeText = m_elapsedTime.toString("hh:mm:ss.z");
    m_timeLabel->setText(timeText);
}