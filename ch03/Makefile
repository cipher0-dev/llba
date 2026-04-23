.PHONY: all clean

CC      ?= zig cc
PIE_CFLAGS  ?= -std=c23
NOPIE_CFLAGS  ?= -std=c23 -no-pie -fno-pie

BUILD := build

all: build/test_pause_pie build/test_pause_nopie build/test_sleep_pie build/test_sleep_nopie

clean:
	rm -rf $(BUILD)

$(BUILD)/test_pause_pie: test_pause.c
	@mkdir -p $(@D)
	$(CC) $(PIE_CFLAGS) -o $@ $<

$(BUILD)/test_pause_nopie: test_pause.c
	@mkdir -p $(@D)
	$(CC) $(NOPIE_CFLAGS) -o $@ $<

$(BUILD)/test_sleep_pie: test_sleep.go
	@mkdir -p $(@D)
	go build -buildmode=pie -o $@ $<

$(BUILD)/test_sleep_nopie: test_sleep.go
	@mkdir -p $(@D)
	go build -o $@ $<
