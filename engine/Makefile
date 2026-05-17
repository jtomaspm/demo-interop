CC := gcc

GLFW := deps/glfw_3.4
GLFW_LIB := $(GLFW)/lib/libglfw3.a 
GLFW_INC := -I$(GLFW)/include

GLAD := deps/glad
GLAD_LIB := $(GLAD)/lib/libglad.a
GLAD_INC := -I$(GLAD)/include

CFLAGS := -g -O0 -Wall -Wextra -Wpedantic -fPIC \
		  $(GLFW_INC) \
		  $(GLAD_INC)
LDFLAGS := -shared
LDLIBS := -lwayland-client -lwayland-cursor -lwayland-egl -lxkbcommon \
          -lGL -ldl -lpthread -lm \
		  $(GLFW_LIB) \
		  $(GLAD_LIB)

SRC_DIR := src
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
