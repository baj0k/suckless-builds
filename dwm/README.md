My personalized build of dwm - the dynamic window manager for X by suckless.org

## Patches applied
- [alwaysontop](https://dwm.suckless.org/patches/alwaysontop/alwaysontop-6.2.diff)
- [attachaside](https://dwm.suckless.org/patches/attachaside/dwm-attachaside-6.3.diff)
- [canfocusfloating](https://dwm.suckless.org/patches/canfocusfloating/dwm-canfocusfloating-20210724-b914109.diff)
- [floatrules](https://dwm.suckless.org/patches/floatrules/dwm-floatrules-20210801-138b405.diff)
- [fullgaps](https://dwm.suckless.org/patches/fullgaps/dwm-fullgaps-6.2.diff) - But without the setgaps function. In result the gap size cannot be changed dynamically.
- [hide vacant tags](https://dwm.suckless.org/patches/hide_vacant_tags/dwm-hide_vacant_tags-6.3.diff)
- [shiftview] - tbd <!-- TODO: upload diff to suckless.org -->
- [pertag](https://dwm.suckless.org/patches/pertag/dwm-pertag-20200914-61bb8b2.diff) <!-- TODO: check if any of the previous patches had a version that works with pertag -->
- [resetnmaster](https://dwm.suckless.org/patches/resetnmaster/dwm-resetnmaster-pertag-6.3.diff)
- [resizecorners](https://dwm.suckless.org/patches/resizecorners/dwm-resizecorners-6.2.diff)

## Installation
Use GNU make inside the suckless-builds/dwm directory to build and install binary.
```
$ sudo make cleaninstall
```
