My personalized build of dwm - the dynamic window manager for X by suckless.org
<!-- TODO: Update manual so it shows correct keybinds -->

## Dependencies
- libxcb
- Xlib-libxcb
- xcb-res

## Patches applied
- [alpha](https://dwm.suckless.org/patches/alpha/dwm-alpha-20201019-61bb8b2.diff)
- [alwayscenter](https://dwm.suckless.org/patches/alwayscenter/dwm-alwayscenter-20200625-f04cac6.diff)
- [alwaysontop](https://dwm.suckless.org/patches/alwaysontop/alwaysontop-6.2.diff)
- [attachaside](https://dwm.suckless.org/patches/attachaside/dwm-attachaside-6.3.diff)
- [canfocusfloating](https://dwm.suckless.org/patches/canfocusfloating/dwm-canfocusfloating-20210724-b914109.diff)
- [fadeinactive](https://dwm.suckless.org/patches/fadeinactive/dwm-fadeinactive-20211114-a786211.diff)
- [fakefullscreen](https://dwm.suckless.org/patches/fakefullscreen/dwm-fakefullscreen-20210714-138b405.diff)
- [floatrules](https://dwm.suckless.org/patches/floatrules/dwm-floatrules-20210801-138b405.diff)
- [fullgaps](https://dwm.suckless.org/patches/fullgaps/dwm-fullgaps-6.2.diff)
- [hide vacant tags](https://dwm.suckless.org/patches/hide_vacant_tags/dwm-hide_vacant_tags-6.3.diff)
- [horizgrid](https://dwm.suckless.org/patches/horizgrid/dwm-horizgrid-6.1.diff)
- [shiftview](https://github.com/baj0k/suckless-builds/commit/eedb5ce78ce2a2b87dc1012479d8301ba8482b84)
- [pango](https://dwm.suckless.org/patches/pango/dwm-pango-20201020-519f869.diff)
- [pertag](https://dwm.suckless.org/patches/tab/dwm-tab-v2b-pertab-56a31dc.diff) <!-- TODO: check if any of the previous patches had a version that works with pertag -->
- [resetnmaster](https://dwm.suckless.org/patches/resetnmaster/dwm-resetnmaster-pertag-6.3.diff)
- [resizecorners](https://dwm.suckless.org/patches/resizecorners/dwm-resizecorners-6.2.diff)
- [restartsig](https://dwm.suckless.org/patches/restartsig/dwm-restartsig-20180523-6.2.diff)
- [rulerefresher](https://dwm.suckless.org/patches/rulerefresher/dwm-rulerefresher-6.2.diff)
- [save floats](https://dwm.suckless.org/patches/save_floats/dwm-savefloats-20181212-b69c870.diff)
- [statuscmd](https://dwm.suckless.org/patches/statuscmd/dwm-statuscmd-20210405-67d76bd.diff)
- [sticky](https://dwm.suckless.org/patches/sticky/dwm-sticky-6.1.diff)
- [swallow](https://dwm.suckless.org/patches/swallow/dwm-swallow-20201211-61bb8b2.diff)
- [tab](https://dwm.suckless.org/patches/tab/dwm-tab-v2b-pertab-56a31dc.diff)
- [viewonrulestag](https://dwm.suckless.org/patches/viewonrulestag/dwm-viewonrulestag-20220410-bece862.diff)
- [viewontag](https://dwm.suckless.org/patches/viewontag/dwm-viewontag-20210312-61bb8b2.diff)
- [winview](https://dwm.suckless.org/patches/winview/dwm-6.0-winview.diff)

## Patch customizations
Some functionalities of the above-mentioned patches were changed or removed either due to conflicts with other patches or simply because the features were of no use in my workflow. Listed below are changes made to the original patches. Links lead to relevant commits in which the changes were made.
- floatrules - [diff](https://github.com/baj0k/suckless-builds/commit/8fe82911a5c340dde990d57b0c58fbdf98942ed0)  
Removed floatborderpx rule as border size was already set to 0 for all windows by borderpx variable. 
- fullgaps - [diff](https://github.com/baj0k/suckless-builds/commit/bb92d6fcc7fd2850ed8474a85ad57ddcc9454914)  
The setgaps function was removed to free the bindings for more useful features than changing gap size on runtime.
- horizgrid - [diff](https://github.com/baj0k/suckless-builds/commit/58991f029ff07f8965608234aa80eab27534ac31)
The grid was made to respect the gappx value from the fullgaps patch.
- statuscmd - [diff](https://github.com/baj0k/suckless-builds/commit/241e935a8c17c107c19d7601b4ac058f9516932a)
The original patch was changed similarly to the Luke Smith's [dwmblocks build](https://github.com/LukeSmithxyz/dwmblocks).
- tab - [diff1](https://github.com/baj0k/suckless-builds/commit/cb4448b3600081358d5fcf05084e03980ac25c77), [diff2](https://github.com/baj0k/suckless-builds/commit/351a574484cd6e550985b6990adbc45c671ed98e)  
The tabmode function was removed as well as showtab and toptab variables. The patch was changed so that tab bar position and showtab mode are now hardcoded in the source (respectively - top and monocle in the presence of several windows). In addition this patch wasn't working with the 'alpha' patch. Particularly the updatebars(void) function changed in alpha patch and the m->tabwin initialization had to be changed respectively to the m->barwin changes introduced in the alpha patch.
<!-- TODO: change tab patch so that it respects gaps. Probably can be done by making monocle layout respect gaps --> 

## Installation
Use GNU make inside the suckless-builds/dwm directory to build and install binary.
```
$ sudo make clean install
```
