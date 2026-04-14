.PHONY: all clean

PROG_BINS := $(patsubst %.c,build/%,$(wildcard *.c))

all: build/test_addend build/test_addend.o build/test_foo.o

clean:
	-rm -rf build 2>/dev/null

build/%: build/%.o build/test_foo.o
	mkdir -p $(@D)
	gcc -nostdlib -static -std=c23 -fno-pic -fno-omit-frame-pointer -m32 -g -Og -o $@ $^

build/%.o: %.c
	mkdir -p $(@D)
	gcc -nostdlib -static -std=c23 -fno-pic -fno-omit-frame-pointer -m32 -g -Og -c -o $@ $^
