CC := gcc

CFLAGS := -Wall -Wextra -Wpedantic -fPIC -I.
LDFLAGS := -shared
LDLIBS :=

SRC_DIR := impl
OBJ_DIR := obj
BIN_DIR := bin

SRC := $(shell find $(SRC_DIR) -type f -name '*.c')
OBJ := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))

TARGET := $(BIN_DIR)/engine.so

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJ)
	@mkdir -p $(BIN_DIR)
	$(CC) $(LDFLAGS) -o $@ $^ $(LDLIBS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)