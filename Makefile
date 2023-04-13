
CC = gcc

BUILD_DIR := ./build
TARGET_BIN = bin/main

SRC_DIRS := ./src
SRC_FILES := $(shell find $(SRC_DIRS) -name '*.cpp' -or -name '*.c')
OBJS := $(SRC_FILES:%=$(BUILD_DIR)/%.o)

INC_DIRS := $(shell find $(SRC_DIRS) -type d)
INC_FLAGS := $(addprefix -I, $(INC_DIRS))
CPPFLAGS := $(INC_FLAGS)


$(TARGET_BIN): $(OBJS)
	@echo "start compiling..."
	echo $(SRC_FILES)
	echo $(OBJS)

	${CC} $(OBJS) -o $@ $(LDFLAGS)

	@echo "compile done..."


# build .c source file, from file.c to file.c.o
$(BUILD_DIR)/%.c.o : %.c
	mkdir -p $(dir $@)
	$(CC) $(CPPFLAGS) -c $< -o $@


.PHONY: clean
clean:
	rm -rf $(TARGET_BIN) $(BUILD_DIR)/*

