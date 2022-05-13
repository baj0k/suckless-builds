My personalized build of pass - the simple password store by Jason Donenfeld

## Upstream repository
Clone: git clone git://git.zx2c4.com/password-store  
Browse online: [https://git.zx2c4.com/password-store/](https://git.zx2c4.com/password-store/)

This build is based on the following commit:  
*emacs: Fix an infloop on Windows enviroments	Tino Calancha	2022-03-06*

## Dependencies
- tree
- git
- qrencode
- xclip
- GnuPG2
- GNU getopt

## Customizations
Basically everything was moved to root directory. Unit tests as well as contrib and platform/shell dependent compatibility changes were removed. This build assumes that one is using zsh shell in a linux environment. Additionally, the system extensions support was removed. The --dirsfirst flag was added to the *show* command which is pretty much self explanatory.

## Installation
Use GNU make inside the suckless-builds/pass directory to install executables to your system.
```
$ sudo make install
```
