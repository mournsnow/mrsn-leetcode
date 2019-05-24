CC := g++

CFLAGS := -g -Wall

BINARY := answer
OBJECTS := main.o

TEST_INPUTS := $(wildcard *.in)
TEST_ANSWERS := $(subst .in,.ans,$(TEST_INPUTS))

MAKEFILE_PATH := $(abspath $(lastword $(MAKEFILE_LIST)))
MAKEFILE_DIR := $(shell dirname $(MAKEFILE_PATH))

CPP_UTIL_DIR := $(MAKEFILE_DIR)
CPP_UTIL_OBJ := $(CPP_UTIL_DIR)/cpp_util.o
LEETCODE_STRUCT_DIR := $(MAKEFILE_DIR)
LEETCODE_STRUCT_OBJ := $(CPP_UTIL_DIR)/leetcode_structs.o

all: $(BINARY)

%.o: %.cpp
	$(CC) $(CFLAGS) -I $(MAKEFILE_DIR) -o $@ -c $<

answer: $(OBJECTS) $(CPP_UTIL_OBJ) $(LEETCODE_STRUCT_OBJ)
	$(CC) $(CFLAGS) -o $(BINARY) $(OBJECTS) $(CPP_UTIL_OBJ) $(LEETCODE_STRUCT_OBJ)

test:
	$(foreach input, $(TEST_INPUTS), cat $(input) | ./answer > $(subst .in,.ans,$(input)); diff -q $(subst .in,.out,$(input)) $(subst .in,.ans,$(input));)

clean:
	rm -f $(BINARY) $(OBJECTS) $(CPP_UTIL_OBJ) $(LEETCODE_STRUCT_OBJ) $(TEST_ANSWERS)

