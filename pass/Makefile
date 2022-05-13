# password-store - simple password manager
# See LICENSE file for copyright and license details

PREFIX = /usr/local
MANPREFIX = ${PREFIX}/share/man

all:
	@echo "Password store is a shell script. Use \"make install\" instead."

install:
	@install -v -d "$(MANPREFIX)/man1"
	@install -m 0644 -v pass.1 "$(MANPREFIX)/man1/pass.1"
	@install -v -d "$(PREFIX)/share/zsh/site-functions"
	@install -m 0644 -v pass.zsh-completion "$(PREFIX)/share/zsh/site-functions/_pass"
	@install -v -d "$(PREFIX)/bin/"
	@install -m 0755 -v password-store.sh "$(PREFIX)/bin/pass"

uninstall:
	@rm -rvf \
		"$(PREFIX)/bin/pass" \
		"$(MANPREFIX)/man1/pass.1" \
		"$(PREFIX)/share/zsh/site-functions/_pass" \

.PHONY: install uninstall
