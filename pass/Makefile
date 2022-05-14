# password-store - simple password manager
# See LICENSE file for copyright and license details

PREFIX ?= /usr/local
MANPREFIX ?= ${PREFIX}/share/man
SYSTEM_EXTENSION_DIR ?= $(PREFIX)/lib/password-store/extensions
BASHCOMPDIR ?= /etc/bash_completion.d

all:
	@echo "Pass is a shell script. Use \"make install\" instead."

install:
	@install -v -d "$(MANPREFIX)/man1"
	@install -m 0644 -v pass.1 "$(MANPREFIX)/man1/pass.1"
	@install -m 0644 -v pass-otp.1 "$(MANPREFIX)/man1/pass-otp.1"
	@install -v -d "$(PREFIX)/share/zsh/site-functions"
	@install -m 0644 -v pass.zsh-completion "$(PREFIX)/share/zsh/site-functions/_pass"
	@install -v -d "$(PREFIX)/bin/"
	@install -m 0755 -v pass.sh "$(PREFIX)/bin/pass"
	@install -v -d "$(SYSTEM_EXTENSION_DIR)/"
	@install -m 0755 -v otp.sh "$(SYSTEM_EXTENSION_DIR)/otp.sh"
#	install -d "$(BASHCOMPDIR)/"
#	install -m 644 pass-otp.bash.completion  "$(BASHCOMPDIR)/pass-otp"

uninstall:
	@rm -rvf \
		"$(PREFIX)/bin/pass" \
		"$(MANPREFIX)/man1/pass.1" \
		"$(PREFIX)/share/zsh/site-functions/_pass" \
		"$(SYSTEM_EXTENSION_DIR)/otp.bash" \
		"$(MANPREFIX)/man1/pass-otp.1" \
		#"$(BASHCOMPDIR)/pass-otp"

.PHONY: install uninstall
