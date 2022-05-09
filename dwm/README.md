My personalized build of dwm - the dynamic window manager for X by suckless.org

## Upstream repository
Clone: git clone git://git.suckless.org/dwm  
Browse online: [https://git.suckless.org/dwm/](https://git.suckless.org/dwm/)

## Dependencies
- libxcb
- Xlib-libxcb
- xcb-res

## Patches applied
- [alpha](https://dwm.suckless.org/patches/alpha/dwm-alpha-20201019-61bb8b2.diff)
- [attachaside](https://dwm.suckless.org/patches/attachaside/dwm-attachaside-6.3.diff)
- [bottomstack](https://dwm.suckless.org/patches/bottomstack/dwm-bottomstack-6.1.diff)
- [colorbar](https://dwm.suckless.org/patches/colorbar/dwm-colorbar-6.2.diff)
- [deck](https://dwm.suckless.org/patches/deck/dwm-deck-double-6.2.diff)
- [fadeinactive](https://dwm.suckless.org/patches/fadeinactive/dwm-fadeinactive-20211114-a786211.diff)
- [fakefullscreen](https://dwm.suckless.org/patches/fakefullscreen/dwm-fakefullscreen-20210714-138b405.diff)
- [floatrules](https://dwm.suckless.org/patches/floatrules/dwm-floatrules-20210801-138b405.diff)
- [fullgaps](https://dwm.suckless.org/patches/fullgaps/dwm-fullgaps-6.2.diff)
- [hide vacant tags](https://dwm.suckless.org/patches/hide_vacant_tags/dwm-hide_vacant_tags-6.3.diff)
- [horizgrid](https://dwm.suckless.org/patches/horizgrid/dwm-horizgrid-6.1.diff)
- [notitle](https://dwm.suckless.org/patches/notitle/dwm-notitle-6.2.diff)
- [pertag](https://dwm.suckless.org/patches/pertag/dwm-pertag-20200914-61bb8b2.diff)
- [resetnmaster](https://dwm.suckless.org/patches/resetnmaster/dwm-resetnmaster-pertag-6.3.diff)
- [resizecorners](https://dwm.suckless.org/patches/resizecorners/dwm-resizecorners-6.2.diff)
- [restartsig](https://dwm.suckless.org/patches/restartsig/dwm-restartsig-20180523-6.2.diff)
- [rulerefresher](https://dwm.suckless.org/patches/rulerefresher/dwm-rulerefresher-6.2.diff)
- [save floats](https://dwm.suckless.org/patches/save_floats/dwm-savefloats-20181212-b69c870.diff)
- [shiftview](https://github.com/baj0k/suckless-builds/commit/eedb5ce78ce2a2b87dc1012479d8301ba8482b84)
- [statusallmons](https://dwm.suckless.org/patches/statusallmons/dwm-statusallmons-6.2.diff)
- [statuscmd](https://dwm.suckless.org/patches/statuscmd/dwm-statuscmd-20210405-67d76bd.diff)
- [sticky](https://dwm.suckless.org/patches/sticky/dwm-sticky-6.1.diff)
- [swallow](https://dwm.suckless.org/patches/swallow/dwm-swallow-20201211-61bb8b2.diff)
- [winview](https://dwm.suckless.org/patches/winview/dwm-6.0-winview.diff)

## Patch customizations
Some functionalities of the above-mentioned patches were changed or removed either due to conflicts with other patches or simply because the features were of no use in my workflow. Listed below are changes made to the original patches. Links lead to relevant commits in which the changes were made.
- floatrules - [diff](https://github.com/baj0k/suckless-builds/commit/8fe82911a5c340dde990d57b0c58fbdf98942ed0)  
Removed floatborderpx rule as border size was already set to 0 for all windows by borderpx variable. 
- fullgaps - [diff](https://github.com/baj0k/suckless-builds/commit/bb92d6fcc7fd2850ed8474a85ad57ddcc9454914)  
The setgaps function was removed to free the bindings for more useful features than changing gap size on runtime.
- horizgrid - [diff](https://github.com/baj0k/suckless-builds/commit/58991f029ff07f8965608234aa80eab27534ac31)
The grid was made to respect the gappx value from the fullgaps patch.
- pertag - [diff](tbd)
The setlayout function was changed so that the default layout can be set for each tag in config.h.
- statuscmd - [diff](https://github.com/baj0k/suckless-builds/commit/241e935a8c17c107c19d7601b4ac058f9516932a)
The original patch was changed similarly to the Luke Smith's [dwmblocks build](https://github.com/LukeSmithxyz/dwmblocks).

## Installation
Use GNU make inside the suckless-builds/dwm directory to build and install binary.
```
$ sudo make install
```
