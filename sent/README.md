My personalized build of sent - the simple plaintext presentation tool by suckless.org

## Dependencies
- Xlib
- Xft
- farbfeld

## Patches applied
- progress bar
- toggle cursor

## Installation
Use GNU make inside the suckless-builds/sent directory to build and install binary.
```
$ sudo make clean install
```
## Usage
```
$ sent [FILE]
```
If FILE is omitted or equals `-`, stdin will be read. Each paragraph represents one slide.
Paragraphs starting with `@` in front of the filename produce image slide.
Lines starting with `#` will be ignored. These characters can be escaped `\`.
