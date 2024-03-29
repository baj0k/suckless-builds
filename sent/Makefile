# sent - plain text presentation tool
# See LICENSE file for copyright and license details.

include config.mk

SRC = sent.c drw.c util.c
OBJ = ${SRC:.c=.o}

all: options sent

options:
	@echo sent build options:
	@echo "CFLAGS   = ${CFLAGS}"
	@echo "LDFLAGS  = ${LDFLAGS}"
	@echo "CC       = ${CC}"

.c.o:
	@echo CC $<
	@${CC} -c ${CFLAGS} $<

${OBJ}: config.h config.mk

sent: ${OBJ}
	@echo CC -o $@
	@${CC} -o $@ ${OBJ} ${LDFLAGS}

cscope: ${SRC} config.h
	@echo cScope
	@cscope -R -b || echo cScope not installed

clean:
	@echo cleaning
	@rm -f sent ${OBJ} sent-${VERSION}.tar.gz

dist: clean
	@echo creating dist tarball
	@mkdir -p sent-${VERSION}
	@cp -R LICENSE Makefile config.mk ${SRC} sent-${VERSION}
	@tar -cf sent-${VERSION}.tar sent-${VERSION}
	@gzip sent-${VERSION}.tar
	@rm -rf sent-${VERSION}

install: clean all
	@echo installing executable file to ${DESTDIR}${PREFIX}/bin
	@mkdir -p ${DESTDIR}${PREFIX}/bin
	@cp -f sent ${DESTDIR}${PREFIX}/bin
	@chmod 755 ${DESTDIR}${PREFIX}/bin/sent
	@echo installing manual page to ${DESTDIR}${MANPREFIX}/man1
	@mkdir -p ${DESTDIR}${MANPREFIX}/man1
	@cp sent.1 ${DESTDIR}${MANPREFIX}/man1/sent.1
	@chmod 644 ${DESTDIR}${MANPREFIX}/man1/sent.1
	@rm -f sent ${OBJ} sent-${VERSION}.tar.gz *.orig *.rej *.diff

uninstall:
	@echo removing executable file from ${DESTDIR}${PREFIX}/bin
	@rm -f ${DESTDIR}${PREFIX}/bin/sent

.PHONY: all options clean dist install uninstall cscope
