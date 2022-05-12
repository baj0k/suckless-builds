My personalized build of dmenu - the dynamic menu for X by suckless.org

## Upstream repository
Clone: git clone git://git.suckless.org/dmenu  
Browse online: [https://git.suckless.org/dmenu/](https://git.suckless.org/dmenu/)

This build is based on the following commit:  
*2022-05-01 16:38	Makefile: add manual path for OpenBSD	Hiltjo Posthuma*

## Patches applied

- [numbers](https://tools.suckless.org/dmenu/patches/numbers/dmenu-numbers-4.9.diff)

- [alpha](https://tools.suckless.org/dmenu/patches/alpha/dmenu-alpha-20210605-1a13d04.diff)
//- border
- [center](https://tools.suckless.org/dmenu/patches/center/dmenu-center-20200111-8cd37e1.diff)
//- highlight
- [initial text](https://tools.suckless.org/dmenu/patches/initialtext/dmenu-initialtext-4.7.diff)
- [password](https://tools.suckless.org/dmenu/patches/password/dmenu-password-5.0.diff)
- [prefix completion](https://tools.suckless.org/dmenu/patches/prefix-completion/dmenu-prefixcompletion-4.9.diff)

## Patch customizations
Some functionalities of the above-mentioned patches were changed or removed either due to conflicts with other patches or simply because the features were of no use in my workflow. Listed below are changes made to the original patches. Links lead to relevant commits in which the changes were made.
- alpha - Fixed compiler warnings and unused parameters from another patches.
- center - Changed so that the centered behaviour is default.
- password - Changed so that characters are replaced with asterisks instead of dots.

## Installation
Use GNU make inside the suckless-builds/dmenu directory to build and install binary.
```
$ sudo make install
```
