# Time App - Timer & Stopwatch

A Qt6-based GUI application for timing and stopwatch functionality with dark/light theme support.

## Features

- **Timer**: Set custom countdown time with hours, minutes, seconds
  - Start, pause, and reset controls
- **Stopwatch**: Precision timing with centisecond accuracy
  - Start, pause, and reset controls
  - Lap functionality to record lap times
- **Theme Support**: Toggle between light and dark themes
  - Accessible via View -> Toggle Theme or Ctrl+T

## Build Requirements

- C++17 compiler (g++ or clang++)
- Qt6 development libraries (Core, Gui, Widgets)
- Make

## Building

```bash
make
```

The executable will be created in `bin/timeapp`.

## Running

```bash
./bin/timeapp
```

## Usage

### Timer
1. Set your desired time using the hour, minute, and second spin boxes
2. Click "Start" to begin the countdown
3. Use "Pause" to temporarily stop the timer
4. Use "Reset" to return to the set time

### Stopwatch
1. Click "Start" to begin timing
2. Click "Lap" to record the current lap time
3. Use "Pause" to temporarily stop the stopwatch
4. Use "Reset" to clear the time and lap records

### Theme Toggle
- Switch between light and dark themes using the View menu or Ctrl+T shortcut

## Project Structure

```
.
├── Makefile          # Build configuration
├── README.md         # This file
├── src/              # Source code
│   ├── main.cpp      # Application entry point
│   ├── MainWindow.h  # Main window header
│   ├── MainWindow.cpp # Main window implementation
│   ├── TimerWidget.h # Timer functionality header
│   ├── TimerWidget.cpp # Timer functionality implementation
│   ├── StopwatchWidget.h # Stopwatch functionality header
│   ├── StopwatchWidget.cpp # Stopwatch functionality implementation
│   ├── ThemeManager.h # Theme management header
│   └── ThemeManager.cpp # Theme management implementation
└── bin/              # Output directory for executable
```