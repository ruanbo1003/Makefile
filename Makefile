
.PHONY: clean

CC = gcc

BUILD_DIR := ./build
TARGET_BIN = bin/main

SRC_DIRS := ./src
SRC_FILES := $(shell find $(SRC_DIRS) -name '*.cpp' -or -name '*.c')
OBJS := $(SRC_FILES:%=$(BUILD_DIR)/%.o)

INC_DIRS := $(shell find $(SRC_DIRS) -type d)
INC_FLAGS := $(addprefix -I, $(INC_DIRS))
CPPFLAGS := $(INC_FLAGS)

# sanitize: https://github.com/google/sanitizers
CPPFLAGS += -fsanitize=address
PLATFORM_OS := $(shell uname)
ifneq ($(PLATFORM_OS), Darwin)
	# -fsanitize=leak not support on MacOS
	CPPFLAGS += -fsanitize=leak -static-libasan
endif


$(TARGET_BIN): $(OBJS)
	@echo "start compiling...", $(IS_DEBUG)
	echo $(SRC_FILES)

	${CC} $(OBJS) -o $@ $(CPPFLAGS)

	@echo "compile done..."


# build .c source file, from file.c to file.c.o
$(BUILD_DIR)/%.c.o : %.c
	mkdir -p $(dir $@)
	$(CC) $(CPPFLAGS) -c $< -o $@


clean:
	rm -rf $(TARGET_BIN) $(BUILD_DIR)/*

