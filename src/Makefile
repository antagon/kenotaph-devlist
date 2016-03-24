#
# Copyright (c) 2016, CodeWard.org
#

CFLAGS = -std=gnu99 -O2 -pedantic -Wall -ggdb

TARGET = kenotaph-devlist
INSTALL_DIR = /usr/local/sbin

.PHONY: clean install

all: $(TARGET)

install:
	install --mode 755 $(TARGET) $(INSTALL_DIR)

uninstall:
	rm -f $(INSTALL_DIR)/$(TARGET)

clean:
	rm -f *.o $(TARGET)

$(TARGET): main.o
	$(CC) $(CFLAGS) $^ -o $(TARGET) -lpcap

main.o: main.c
	$(CC) $(CFLAGS) -c $<

