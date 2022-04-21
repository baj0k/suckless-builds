My personalized build of dwm - the dynamic window manager for X by suckless.org

## Patches applied
- [alwaysontop](https://dwm.suckless.org/patches/alwaysontop/alwaysontop-6.2.diff)
- [attachaside](https://dwm.suckless.org/patches/attachaside/dwm-attachaside-6.3.diff)
- [canfocusfloating](https://dwm.suckless.org/patches/canfocusfloating/dwm-canfocusfloating-20210724-b914109.diff)
- [floatrules](https://dwm.suckless.org/patches/floatrules/dwm-floatrules-20210801-138b405.diff)
- [fullgaps](https://dwm.suckless.org/patches/fullgaps/dwm-fullgaps-6.2.diff) - But the setgaps function and its calls were removed. In result the gaps size can be only changed in config.h.

## Installation
Use GNU make inside the suckless-builds/dwm directory to build and install binary.
```
$ sudo make cleaninstall
```
