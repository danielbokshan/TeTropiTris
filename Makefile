CC := gcc
CFLAGS := -Wall
LDFLAGS := -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

SRCS := main.c spawnshapes.c
TARGET := game.exe

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET)
