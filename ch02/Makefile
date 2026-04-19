.PHONY: all clean

PROG_BINS := $(patsubst %.c,build/%,$(wildcard *.c))

all: build/hello_world build/test_addend build/test_addend.o build/test_foo.o build/evil_puts.o

clean:
	-rm -rf build 2>/dev/null

build/hello_world: hello_world.c
	mkdir -p $(@D)
	gcc -static -std=c2x -fno-pic -fno-omit-frame-pointer -m32 -g -Og -o $@ $^

build/test_addend: build/test_addend.o build/test_foo.o
	mkdir -p $(@D)
	gcc -nostdlib -static -std=c2x -fno-pic -fno-omit-frame-pointer -m32 -g -Og -o $@ $^

build/test_addend.o: test_addend.c
	mkdir -p $(@D)
	gcc -nostdlib -static -std=c2x -fno-pic -fno-omit-frame-pointer -m32 -g -Og -c -o $@ $^

build/test_foo.o: test_foo.c
	mkdir -p $(@D)
	gcc -nostdlib -static -std=c2x -fno-pic -fno-omit-frame-pointer -m32 -g -Og -c -o $@ $^

build/evil_puts.o: evil_puts.c
	mkdir -p $(@D)
	gcc -nostdlib -static -std=c2x -fno-pic -fno-omit-frame-pointer -m32 -g -Og -c -o $@ $^
