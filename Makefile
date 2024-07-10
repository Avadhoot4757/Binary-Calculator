CC = gcc
CFLAGS = -Wall -Wextra -std=c99
SRC_DIR = src
SRCS = $(shell find $(SRC_DIR) -name "*.c")
OBJ_DIR = obj
OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))
TARGET = calculator

$(info SRCS = $(SRCS))
$(info OBJS = $(OBJS))

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(TARGET)

.PHONY: clean
