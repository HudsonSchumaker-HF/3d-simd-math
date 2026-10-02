
CC       := gcc
CFLAGS   := -std=c17 -Wall -Wextra -Wpedantic -Wconversion -Wshadow -O3 -msse4.1
CPPFLAGS := -Iinclude -Isrc -Itests
LDLIBS   := -lm

SRC := src/vec4_sse41.c src/mat4_sse41.c
TESTS := test_vec4 test_mat4

.PHONY: all test clean

all: $(TESTS)

test_vec4: tests/test_vec4.c $(SRC)
	$(CC) $(CPPFLAGS) $(CFLAGS) $^ -o $@ $(LDLIBS)

test_mat4: tests/test_mat4.c $(SRC)
	$(CC) $(CPPFLAGS) $(CFLAGS) $^ -o $@ $(LDLIBS)

test: all
	./test_vec4
	./test_mat4

clean:
	rm -f $(TESTS)
