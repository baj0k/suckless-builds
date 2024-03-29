My personalized build of dmenu - the dynamic menu for X by suckless.org

## Upstream repository
Clone: git clone git://git.suckless.org/dmenu  
Browse online: [https://git.suckless.org/dmenu/](https://git.suckless.org/dmenu/)

This build is based on the following commit:  
*2022-10-26 07:43	dmenu: small XmbLookupString code improvements	Hiltjo Posthuma*

## Patches applied

- [alpha](https://tools.suckless.org/dmenu/patches/alpha/dmenu-alpha-20210605-1a13d04.diff)
- [border](https://tools.suckless.org/dmenu/patches/border/dmenu-border-4.9.diff)
- [center](https://tools.suckless.org/dmenu/patches/center/dmenu-center-20200111-8cd37e1.diff)
- [highlight](https://tools.suckless.org/dmenu/patches/highlight/dmenu-highlight-20201211-fcdc159.diff)
- [initial text](https://tools.suckless.org/dmenu/patches/initialtext/dmenu-initialtext-4.7.diff)
- [numbers](https://tools.suckless.org/dmenu/patches/numbers/dmenu-numbers-4.9.diff)
- [password](https://tools.suckless.org/dmenu/patches/password/dmenu-password-5.0.diff)
- [prefix completion](https://tools.suckless.org/dmenu/patches/prefix-completion/dmenu-prefixcompletion-4.9.diff)

## Patch customizations
Some functionalities of the above-mentioned patches were changed or removed either due to conflicts with other patches or simply because the features were of no use in my workflow. Listed below are changes made to the original patches. Links lead to relevant commits in which the changes were made.
- alpha - Fixed compiler warnings and unused parameters from another patches.
- center - Changed so that the centered behaviour is default.
- password - Changed so that characters are replaced with asterisks instead of dots.
- prefix completion - Changed to reference changes in the following upstream commit: 2022-09-01 17:51	tab-complete: figure out the size before copying commit in the upstream.

## Installation
Use GNU make inside the suckless-builds/dmenu directory to build and install binary.
```
$ sudo make install
```
