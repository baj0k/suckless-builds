My personalized build of pass - the simple password store by Jason Donenfeld.  
This build integrates functionalities from pass-otp extension by Tad Fisher.

## Upstream repository
### pass
Clone: git clone git://git.zx2c4.com/password-store  
Browse online: [https://git.zx2c4.com/password-store/](https://git.zx2c4.com/password-store/)

### pass-otp
Clone: git clone git@github.com:tadfisher/pass-otp.git  
Browse online: [https://github.com/tadfisher/pass-otp](https://github.com/tadfisher/pass-otp)

This build is based on the following commits:  
pass:
*emacs: Fix an infloop on Windows enviroments	Tino Calancha	2022-03-06*

pass-otp:
*Add example use of wl-clipboard to get QR from clip ljrk0 and tadfisher 2022-02-13*

## Dependencies
- tree
- git
- qrencode
- xclip
- qrencode
- oath-toolkit
- GnuPG2
- GNU getopt

## Customizations
Source files are now placed in root directory. Unit tests as well as contrib and platform/shell dependent compatibility changes were removed. This build assumes that one is using zsh shell in a linux environment. Additionally, the user extensions support was removed. The --dirsfirst flag was added to the tree command in the *cmd_show* function.

## Installation
Use GNU make inside the suckless-builds/pass directory to install executables to your system.
```
$ sudo make install
```
