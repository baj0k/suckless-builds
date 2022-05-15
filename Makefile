# suckless builds - collection of personalized tools that follow the suckless philosophy
# See LICENSE file for copyright and license details.
# Each tool comes with it's own license so please be aware that the original code as well as the changes made are most probably covered by that license.

DIRS = ${sort ${dir ${wildcard ./*/}}}
SOFT = $(patsubst ./%, %, ${DIRS:/=})

all:
		@echo "Use \"make install\" to build and install all programs"
		@echo "Use \"make <program1> <program2>\" to build and install particular programs"

dmenu:
		@make install -C dmenu

dwm:
		@make install -C dwm

dwmblocks:
		@make install -C dwmblocks

pass:
		@make install -C pass

scron:
		@make install -C scron

sent:
		@make install -C sent

slock:
		@make install -C slock

st:
		@make install -C st

tabbed:
		@make install -C tabbed

install:
	    @$(foreach var, $(DIRS), make install -C $(var);)

uninstall:
	    @$(foreach var, $(DIRS), make uninstall -C $(var);)

.PHONY: ${SOFT} install uninstall 
