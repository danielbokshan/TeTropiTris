CC := gcc
CFLAGS := -Wall
LDFLAGS := -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

SRCS := main.c
OBJS := $(SRCS:.c=.o)
TARGET := game

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
