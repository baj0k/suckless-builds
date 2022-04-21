My personalized build of dwm - the dynamic window manager for X by suckless.org
<!-- TODO: Update manual so it shows correct keybinds -->

## Patches applied
- [alwaysontop](https://dwm.suckless.org/patches/alwaysontop/alwaysontop-6.2.diff)
- [attachaside](https://dwm.suckless.org/patches/attachaside/dwm-attachaside-6.3.diff)
- [canfocusfloating](https://dwm.suckless.org/patches/canfocusfloating/dwm-canfocusfloating-20210724-b914109.diff)
- [floatrules](https://dwm.suckless.org/patches/floatrules/dwm-floatrules-20210801-138b405.diff)
- [fullgaps](https://dwm.suckless.org/patches/fullgaps/dwm-fullgaps-6.2.diff)
- [hide vacant tags](https://dwm.suckless.org/patches/hide_vacant_tags/dwm-hide_vacant_tags-6.3.diff)
- [shiftview] - tbd <!-- TODO: upload diff to suckless.org -->
- [pertag](https://dwm.suckless.org/patches/pertag/dwm-pertag-20200914-61bb8b2.diff) <!-- TODO: check if any of the previous patches had a version that works with pertag -->
- [resetnmaster](https://dwm.suckless.org/patches/resetnmaster/dwm-resetnmaster-pertag-6.3.diff)
- [resizecorners](https://dwm.suckless.org/patches/resizecorners/dwm-resizecorners-6.2.diff)
- [restartsig](https://dwm.suckless.org/patches/restartsig/dwm-restartsig-20180523-6.2.diff)
- [rulerefresher](https://dwm.suckless.org/patches/rulerefresher/dwm-rulerefresher-6.2.diff)
- [save floats](https://dwm.suckless.org/patches/save_floats/dwm-savefloats-20181212-b69c870.diff)
- [sticky](https://dwm.suckless.org/patches/sticky/dwm-sticky-6.1.diff)
- [tab](https://dwm.suckless.org/patches/tab/dwm-tab-i3like-20211121-a786211.diff)
- [underlinetags](https://dwm.suckless.org/patches/underlinetags/dwm-underlinetags-6.2.diff)

## Patch customizations
Some functionalities of the above-mentioned patches were changed or removed either due to conflicts with other patches or simply because the features were of no use in my workflow. Listed below are changes made to the original patches. Links lead to relevant commits in which the changes were made.
- [fullgaps](https://github.com/baj0k/suckless-builds/commit/bb92d6fcc7fd2850ed8474a85ad57ddcc9454914)  
The setgaps function was removed to free the bindings for more useful features than changing gap size on runtime.
- [tab](https://github.com/baj0k/suckless-builds/commit/cb4448b3600081358d5fcf05084e03980ac25c77)  
The tabmode function was removed as well as showtab and toptab variables. The patch was changed so that tab bar position and showtab mode are now hardcoded in the source (respectively - top and monocle in the presence of several windows).
<!-- TODO: change tab patch so that it respects gaps. Probably can be done by making monocle layout respect gaps --> 
- [underlinetags](tbd)  
Removed ulineall and ulinevoffset options.

## Installation
Use GNU make inside the suckless-builds/dwm directory to build and install binary.
```
$ sudo make clean install
```
