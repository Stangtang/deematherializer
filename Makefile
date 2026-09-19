CXX := g++
CXXFLAGS := -Wall -Wextra

BUILD_DIR := build
# OBJECTS := $(BUILD_DIR)/main.o $(BUILD_DIR)/input.o
OBJECTS := $(BUILD_DIR)/main.o

ifeq ($(OS),Windows_NT)
	TARGET := $(BUILD_DIR)/main.exe
else
	TARGET := $(BUILD_DIR)/main
endif

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJECTS)
	@echo "Linking modules..."
	$(CXX) $(OBJECTS) -o "$@"

$(BUILD_DIR)/%.o: %.cpp | $(BUILD_DIR)
	@echo "Compiling $<..."
	$(CXX) $(CXXFLAGS) -c "$<" -o "$@"

$(BUILD_DIR):
	mkdir -p "$@"

clean:
	@echo "Removing compiled files..."
	rm -rf "$(BUILD_DIR)"
