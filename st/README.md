My personalized build of st - the simple terminal by suckless.org.

## Upstream repository
Clone: git clone git://git.suckless.org/st  
Browse online: [https://git.suckless.org/st/](https://git.suckless.org/st/)

This build is based on the following commit:  
*2022-05-01 16:38	Makefile: add manual path for OpenBSD	Hiltjo Posthuma*

## Dependencies
- libxcb
- Xlib-libxcb

## Patches applied
- [alpha](https://st.suckless.org/patches/alpha/st-alpha-osc11-20220222-0.8.5.diff)
- [bold is not bright](https://st.suckless.org/patches/bold-is-not-bright/st-bold-is-not-bright-20190127-3be4cf1.diff)
- [font2](https://st.suckless.org/patches/font2/st-font2-20190416-ba72400.diff)
- [glyph wide support](https://st.suckless.org/patches/glyph_wide_support/st-glyph-wide-support-20220411-ef05519.diff)
- [newterm](https://st.suckless.org/patches/newterm/st-newterm-20220221-0.8.5.diff)
- [selectioncolors](https://st.suckless.org/patches/selectioncolors/st-selectioncolors-0.8.4.diff)
- [selectionbgalpha](https://st.suckless.org/patches/selectionbg-alpha/st-selectionbg-alpha-0.8.2.diff)
- [scrollback](https://st.suckless.org/patches/scrollback/st-scrollback-0.8.5.diff)
- [scrollback-reflow](https://st.suckless.org/patches/scrollback/st-scrollback-reflow-0.8.5.diff)
- [scrollback-mouse](https://st.suckless.org/patches/scrollback/st-scrollback-mouse-20220127-2c5edf2.diff)
- [scrollback-mouse-altscreen](https://st.suckless.org/patches/scrollback/st-scrollback-mouse-altscreen-20220127-2c5edf2.diff)
- [snap line delimeter](https://st.suckless.org/patches/line_snap_delimiter/st-line_snap_delimiter-3bd7e43.diff)
- [workingdir](https://st.suckless.org/patches/workingdir/st-workingdir-20200317-51e19ea.diff)

## Patch customizations
Some functionalities of the above-mentioned patches were changed or removed either due to conflicts with other patches or simply because the features were of no use in my workflow. Listed below are changes made to the original patches. Links lead to relevant commits in which the changes were made.

## Installation
Use GNU make inside the suckless-builds/dwm directory to build and install binary.
```
$ sudo make install
```
