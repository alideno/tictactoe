CC = g++
TARGET = xox

$(TARGET): $(TARGET).cpp
	$(CC) $(CFLAGS) $^ -o $@

.PHONY: clean run
clean:
	del $(TARGET).exe

run: clean $(TARGET)
	./$(TARGET)