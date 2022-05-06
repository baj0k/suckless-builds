My personalized build of scron - the simple cron daemon that follows the suckless principles.
Upstream repository: [git clone git://git.2f30.org/scron](git clone git://git.2f30.org/scron)
Browse online: [https://git.2f30.org/scron/](https://git.2f30.org/scron/)

## Features
- Schedule commands to be run at specified dates and times.
- Single daemon and configiguration file.
- Run job as different user: 'su -c 'command' user'.
- Log job output: 'command &>> /var/log/cron.log'.
- Log to stdout or syslog.

## Installation
Use GNU make inside the suckless-builds/st directory to build and install binary.
```
$ sudo make install
```
## Usage
Columns:
 minute, hour, day of month, month, day of week, command

Values:
 30 (number), * (wildcard), */5 (repeat), 1-5 (range), or 1,3,6 (list)

Separator:
 Any number of tabs or spaces.

## Examples
### Run updatedb at 6:00 every day
0   6    *    *    *    updatedb

### Run at 5:30 every business day. Log output to /var/log/backup.log.
30  5    *    *    1-5  syncbackup &>> /var/log/backup.log

### Run as user postmaster at 5:00 every third day of month.
0   5    */3  *    *    su -c 'mail -s "Hello world" a@b.com' postmaster
