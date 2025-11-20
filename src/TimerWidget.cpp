#include <QApplication>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QSpinBox>
#include <QTime>

#include "TimerWidget.h"

TimerWidget::TimerWidget(QWidget *parent)
    : QWidget(parent)
    , m_timer(new QTimer(this))
    , m_isRunning(false)
{
    // Set up the layout
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    // Title
    QLabel *titleLabel = new QLabel("Timer");
    titleLabel->setAlignment(Qt::AlignCenter);
    titleLabel->setStyleSheet("QLabel { font-size: 24px; font-weight: bold; margin: 10px; }"); // Keep font styling but let theme handle colors

    // Time display
    m_timeLabel = new QLabel("00:00:00");
    m_timeLabel->setAlignment(Qt::AlignCenter);
    m_timeLabel->setStyleSheet("QLabel { font-size: 48px; font-weight: bold; margin: 20px; }"); // Keep font styling but let theme handle colors

    // Input controls for setting time
    QHBoxLayout *inputLayout = new QHBoxLayout();
    m_hourSpinBox = new QSpinBox();
    m_hourSpinBox->setRange(0, 23);
    m_hourSpinBox->setValue(0);
    m_hourSpinBox->setPrefix("H: ");

    m_minuteSpinBox = new QSpinBox();
    m_minuteSpinBox->setRange(0, 59);
    m_minuteSpinBox->setValue(0);
    m_minuteSpinBox->setPrefix("M: ");

    m_secondSpinBox = new QSpinBox();
    m_secondSpinBox->setRange(0, 59);
    m_secondSpinBox->setValue(0);
    m_secondSpinBox->setPrefix("S: ");

    inputLayout->addWidget(m_hourSpinBox);
    inputLayout->addWidget(m_minuteSpinBox);
    inputLayout->addWidget(m_secondSpinBox);
    inputLayout->addStretch(); // Add stretch to center the spin boxes

    // Control buttons
    QHBoxLayout *buttonLayout = new QHBoxLayout();
    m_startButton = new QPushButton("Start");
    m_pauseButton = new QPushButton("Pause");
    m_resetButton = new QPushButton("Reset");

    buttonLayout->addStretch(); // Add stretch to center the buttons
    buttonLayout->addWidget(m_startButton);
    buttonLayout->addWidget(m_pauseButton);
    buttonLayout->addWidget(m_resetButton);
    buttonLayout->addStretch();

    // Add all widgets to main layout
    mainLayout->addWidget(titleLabel);
    mainLayout->addWidget(m_timeLabel);
    mainLayout->addSpacing(10);
    mainLayout->addLayout(inputLayout);
    mainLayout->addSpacing(20);
    mainLayout->addLayout(buttonLayout);
    mainLayout->addStretch(); // Add stretch to center content vertically

    // Connect signals and slots
    connect(m_timer, &QTimer::timeout, this, &TimerWidget::updateTimer);
    connect(m_startButton, &QPushButton::clicked, this, &TimerWidget::startTimer);
    connect(m_pauseButton, &QPushButton::clicked, this, &TimerWidget::pauseTimer);
    connect(m_resetButton, &QPushButton::clicked, this, &TimerWidget::resetTimer);

    // Initialize the time
    int hours = m_hourSpinBox->value();
    int minutes = m_minuteSpinBox->value();
    int seconds = m_secondSpinBox->value();
    m_currentTime = QTime(hours, minutes, seconds);
    updateTimeDisplay();
}

void TimerWidget::startTimer()
{
    if (!m_isRunning) {
        // Check if timer is at 00:00:00, then set from spin boxes
        if (m_currentTime == QTime(0, 0, 0)) {
            int hours = m_hourSpinBox->value();
            int minutes = m_minuteSpinBox->value();
            int seconds = m_secondSpinBox->value();
            m_currentTime = QTime(hours, minutes, seconds);

            // If still 0, don't start
            if (m_currentTime == QTime(0, 0, 0)) {
                return;
            }
        }

        m_timer->start(1000); // Update every second
        m_isRunning = true;
        m_startButton->setEnabled(false);
        m_pauseButton->setEnabled(true);
    }
}

void TimerWidget::pauseTimer()
{
    if (m_isRunning) {
        m_timer->stop();
        m_isRunning = false;
        m_startButton->setEnabled(true);
        m_pauseButton->setEnabled(false);
    }
}

void TimerWidget::resetTimer()
{
    m_timer->stop();
    m_isRunning = false;

    // Reset to the values in the spin boxes
    int hours = m_hourSpinBox->value();
    int minutes = m_minuteSpinBox->value();
    int seconds = m_secondSpinBox->value();
    m_currentTime = QTime(hours, minutes, seconds);

    updateTimeDisplay();
    m_startButton->setEnabled(true);
    m_pauseButton->setEnabled(false);
}

void TimerWidget::updateTimer()
{
    // Subtract one second
    m_currentTime = m_currentTime.addSecs(-1);

    // Check if timer has reached 0
    if (m_currentTime <= QTime(0, 0, 0)) {
        m_timer->stop();
        m_isRunning = false;
        m_currentTime = QTime(0, 0, 0);
        m_startButton->setEnabled(true);
        m_pauseButton->setEnabled(false);
    }

    updateTimeDisplay();
}

void TimerWidget::updateTimeDisplay()
{
    QString timeText = m_currentTime.toString("hh:mm:ss");
    m_timeLabel->setText(timeText);
}