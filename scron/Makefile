CFLAGS += -std=c99 -Wall -Wextra -pedantic -D_DEFAULT_SOURCE -D_POSIX_C_SOURCE=200809L -D_BSD_SOURCE
PREFIX = /usr/local
MANPREFIX = $(PREFIX)/share/man

BIN = crond
MAN = scron.1

all: $(BIN)

install: clean all
	mkdir -p $(DESTDIR)$(PREFIX)/bin
	cp -f $(BIN) $(DESTDIR)$(PREFIX)/bin
	mkdir -p $(DESTDIR)$(MANPREFIX)/man1
	cp -f $(MAN) $(DESTDIR)$(MANPREFIX)/man1
	rm -f $(BIN) *.orig *.rej *.diff

uninstall:
	rm -f $(DESTDIR)$(PREFIX)/bin/$(BIN)
	rm -f $(DESTDIR)$(MANPREFIX)/man1/$(MAN)

clean:
	rm -f $(BIN)

.PHONY:
	all install uninstall clean
