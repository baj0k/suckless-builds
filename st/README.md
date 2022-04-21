My personalized build of st - the simple terminal by suckless.org somewhat inspired by Luke's [build](https://github.com/LukeSmithxyz/st)

## Useful bindings
alt-k/j or alt-PgUp/PgDn to scrollback
alt-shift-PgUp/PgDn to increase/decrease font size, alt-home ro reset to default
alt-c to copy, alt-v to paste
alt-l to follow urls
alt-y to copy urls
alt-o to copy the output of commands from stdout
alt-shift-return to spawn new terminal instance with the same CWD as the currently focused one

## Patches applied
- alpha
- font2
- hidecursor
- newterm
- scrollback
- selectioncolors
- vertcenter
- xresources

## Installation
Use GNU make inside the suckless-builds/st directory to build and install binary.
```
$ sudo make clean install
```
