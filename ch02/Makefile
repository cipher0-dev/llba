.PHONY: all clean

PROG_BINS := $(patsubst %.c,build/%,$(wildcard *.c))

all: $(PROG_BINS) build/test_addend.o

clean:
	-rm -rf build 2>/dev/null

# programs binaries

build/%: %.c
	mkdir -p $(@D)
	gcc -nostdlib -static -std=c23 -g -Og -o $@ $^

build/test_addend:
	mkdir -p $(@D)
	touch build/test_addend

build/test_addend.o: test_addend.c
	mkdir -p $(@D)
	gcc -nostdlib -static -std=c23 -g -Og -c -o $@ $^
