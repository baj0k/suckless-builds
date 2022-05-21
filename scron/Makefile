CFLAGS += -std=c99 -Wall -Wextra -pedantic -D_DEFAULT_SOURCE -D_POSIX_C_SOURCE=200809L -D_BSD_SOURCE
PREFIX = /usr/local
MANPREFIX = $(PREFIX)/share/man

all: crond

clean:
	rm -f crond

install: clean all
	mkdir -p $(PREFIX)/bin
	cp -f crond $(PREFIX)/bin
	mkdir -p $(MANPREFIX)/man1
	cp -f crond.1 $(MANPREFIX)/man1
	rm -f crond *.orig *.rej *.diff

uninstall:
	rm -f $(PREFIX)/bin/crond
	rm -f $(MANPREFIX)/man1/crond.1

.PHONY:
	all install uninstall clean
