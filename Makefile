# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2 -fPIC
MOC = /usr/lib/qt6/moc
UIC = /usr/bin/uic
RCC = /usr/bin/rcc
QMAKE = /usr/bin/qmake

# Directories
SRCDIR = src
OBJDIR = obj
BINDIR = bin

# Include and library paths (using pkg-config values)
QT_INCLUDES = -I/usr/include/qt6/QtWidgets -I/usr/include/qt6 -DQT_WIDGETS_LIB -I/usr/include/qt6/QtGui -DQT_GUI_LIB -I/usr/include/qt6/QtCore -DQT_CORE_LIB -I/usr/lib/qt6/mkspecs/linux-g++
QT_LIBS = -lQt6Core -lQt6Gui -lQt6Widgets

# Source files
SOURCES = $(SRCDIR)/main.cpp \
          $(SRCDIR)/MainWindow.cpp \
          $(SRCDIR)/TimerWidget.cpp \
          $(SRCDIR)/StopwatchWidget.cpp \
          $(SRCDIR)/ThemeManager.cpp

# Object files
OBJECTS = $(OBJDIR)/main.o \
          $(OBJDIR)/MainWindow.o \
          $(OBJDIR)/TimerWidget.o \
          $(OBJDIR)/StopwatchWidget.o \
          $(OBJDIR)/ThemeManager.o

# MOC generated files
MOC_SOURCES = $(OBJDIR)/moc_MainWindow.cpp $(OBJDIR)/moc_TimerWidget.cpp $(OBJDIR)/moc_StopwatchWidget.cpp
MOC_OBJECTS = $(OBJDIR)/moc_MainWindow.o $(OBJDIR)/moc_TimerWidget.o $(OBJDIR)/moc_StopwatchWidget.o

# Target executable
TARGET = $(BINDIR)/timeapp

# Default target
all: $(TARGET)

# Create directories if they don't exist
$(OBJDIR):
	mkdir -p $(OBJDIR)

$(BINDIR):
	mkdir -p $(BINDIR)

# Link the executable
$(TARGET): $(OBJECTS) $(MOC_OBJECTS) | $(BINDIR)
	$(CXX) $(OBJECTS) $(MOC_OBJECTS) -o $@ -L/usr/lib/qt6 -lQt6Widgets -lQt6Gui -lQt6Core

# Compile source files
$(OBJDIR)/$(SRCDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(QT_INCLUDES) -c $< -o $@

# Compile MOC source files to objects
$(OBJDIR)/moc_%.o: $(OBJDIR)/moc_%.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) $(QT_INCLUDES) -c $< -o $@

# Generate MOC files for headers that contain Q_OBJECT
$(OBJDIR)/moc_MainWindow.cpp: $(SRCDIR)/MainWindow.h | $(OBJDIR)
	$(MOC) $< -o $@ -I/usr/include/qt6 -I/usr/include/qt6/QtCore -I/usr/include/qt6/QtWidgets -I/usr/include/qt6/QtGui

$(OBJDIR)/moc_TimerWidget.cpp: $(SRCDIR)/TimerWidget.h | $(OBJDIR)
	$(MOC) $< -o $@ -I/usr/include/qt6 -I/usr/include/qt6/QtCore -I/usr/include/qt6/QtWidgets -I/usr/include/qt6/QtGui

$(OBJDIR)/moc_StopwatchWidget.cpp: $(SRCDIR)/StopwatchWidget.h | $(OBJDIR)
	$(MOC) $< -o $@ -I/usr/include/qt6 -I/usr/include/qt6/QtCore -I/usr/include/qt6/QtWidgets -I/usr/include/qt6/QtGui

# Compile regular source files
$(OBJDIR)/main.o: $(SRCDIR)/main.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) $(QT_INCLUDES) -c $< -o $@

$(OBJDIR)/MainWindow.o: $(SRCDIR)/MainWindow.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) $(QT_INCLUDES) -c $< -o $@

$(OBJDIR)/TimerWidget.o: $(SRCDIR)/TimerWidget.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) $(QT_INCLUDES) -c $< -o $@

$(OBJDIR)/StopwatchWidget.o: $(SRCDIR)/StopwatchWidget.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) $(QT_INCLUDES) -c $< -o $@

$(OBJDIR)/ThemeManager.o: $(SRCDIR)/ThemeManager.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) $(QT_INCLUDES) -c $< -o $@

# Clean build files
clean:
	rm -rf $(OBJDIR) $(BINDIR)

# Rebuild
rebuild: clean all

.PHONY: all clean rebuild