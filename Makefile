INC_DIR = core/include
SRC_DIR = core/src

CC     = gcc
CFLAGS = -g -O0 -Wall -Wextra -I$(INC_DIR) -std=c11
SRCS   = $(wildcard $(SRC_DIR)/*.c)

TARGET = build/test

all: $(TARGET)
$(TARGET):
	@mkdir -p build
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET)
clean:
	rm -rf build

.PHONY: all clean