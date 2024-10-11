GXX = g++
SOURCES = decay-visualizer.cpp src/*.cpp
TARGET = decay-visualizer
FLAGS = -o $(TARGET) -Iinclude -lncurses

$(TARGET): $(SOURCES)
	$(GXX) $(FLAGS) $(SOURCES)
