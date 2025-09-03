# Simple Shell in C

This project is about building a simple shell from scratch in C.  
I will start with a minimal shell that runs basic commands without arguments,  
and progressively add features like argument parsing, redirection, and piping.  

# Usage Interactive shell
vagrant@ubuntu-focal:~/ALX_REVISION/C_LANG/shell/simple_shell$ gcc shell.c -o shell
vagrant@ubuntu-focal:~/ALX_REVISION/C_LANG/shell/simple_shell$ ./shell
#cisfun$ /bin/ls
shell  shell.c
#cisfun$ /ls
./shell: No such file or directory
#cisfun$ pwd
./shell: No such file or directory
#cisfun$ /pwd
./shell: No such file or directory
#cisfun$ /bin/pwd
/home/vagrant/ALX_REVISION/C_LANG/shell/simple_shell
#cisfun$ uname
./shell: No such file or directory
#cisfun$ /bin/uname
Linux
#cisfun$ ^C

# Usage Non-interactive shell
vagrant@ubuntu-focal:~/ALX_REVISION/C_LANG/shell/simple_shell$ echo /bin/ls | ./shell
shell  shell.c
vagrant@ubuntu-focal:~/ALX_REVISION/C_LANG/shell/simple_shell$ echo ls | ./shell
./shell: No such file or directory
vagrant@ubuntu-focal:~/ALX_REVISION/C_LANG/shell/simple_shell$ echo pwd | ./shell
./shell: No such file or directory
vagrant@ubuntu-focal:~/ALX_REVISION/C_LANG/shell/simple_shell$ echo /bin/pwd | ./shell
/home/vagrant/ALX_REVISION/C_LANG/shell/simple_shell
vagrant@ubuntu-focal:~/ALX_REVISION/C_LANG/shell/simple_shell$ echo uname | ./shell
./shell: No such file or directory
vagrant@ubuntu-focal:~/ALX_REVISION/C_LANG/shell/simple_shell$ echo /bin/uname | ./shell
Linux

Commands' arguments and options
vagrant@ubuntu-focal:~/ALX_REVISION/C_LANG/shell/simple_shell$ ./shell
#cisfun$ /bin/ls
README.md  shell  shell.c
#cisfun$ /bin/ls -l
total 28
-rw-rw-r-- 1 vagrant vagrant  1487 Sep  2 11:11 README.md
-rwxrwxr-x 1 vagrant vagrant 17264 Sep  2 11:31 shell
-rw-rw-r-- 1 vagrant vagrant  1392 Sep  2 11:31 shell.c
#cisfun$ /bin/ls -la
total 40
drwxrwxr-x 3 vagrant vagrant  4096 Sep  2 11:31 .
drwxrwxr-x 4 vagrant vagrant  4096 Sep  2 10:45 ..
drwxrwxr-x 8 vagrant vagrant  4096 Sep  2 11:33 .git
-rw-rw-r-- 1 vagrant vagrant  1487 Sep  2 11:11 README.md
-rwxrwxr-x 1 vagrant vagrant 17264 Sep  2 11:31 shell
-rw-rw-r-- 1 vagrant vagrant  1392 Sep  2 11:31 shell.c
#cisfun$ /bin/ls etc
/bin/ls: cannot access 'etc': No such file or directory
#cisfun$
./shell: Bad address
#cisfun$ /bin/ls -la /etc
total 844
drwxr-xr-x 96 root root       4096 Aug 29 09:42 .
drwxr-xr-x 20 root root       4096 Sep  2 10:42 ..
-rw-------  1 root root          0 Apr  3 01:04 .pwd.lock
drwxr-xr-x  3 root root       4096 Apr  3 01:06 ModemManager
drwxr-xr-x  2 root root       4096 Apr  3 01:07 PackageKit
drwxr-xr-x  6 root root       4096 Aug 24 08:25 X11
-rw-r--r--  1 root root       3028 Apr  3 01:04 adduser.conf
drwxr-xr-x  2 root root       4096 Aug 24 08:25 alternatives
drwxr-xr-x  3 root root       4096 Apr  3 01:06 apparmor
drwxr-xr-x  8 root root       4096 Apr  3 01:07 apparmor.d
drwxr-xr-x  3 root root       4096 Aug 22 07:54 apport
drwxr-xr-x  7 root root       4096 Jun 19 10:07 apt
-rw-r-----  1 root daemon      144 Nov 12  2018 at.deny
-rw-r--r--  1 root root       2319 Feb 25  2020 bash.bashrc
-rw-r--r--  1 root root         45 Jan 26  2020 bash_completion
drwxr-xr-x  2 root root       4096 Aug 22 07:54 bash_completion.d
-rw-r--r--  1 root root        367 Apr 14  2020 bindresvport.blacklist
drwxr-xr-x  2 root root       4096 Apr 22  2020 binfmt.d
drwxr-xr-x  2 root root       4096 Apr  3 01:06 byobu
drwxr-xr-x  3 root root       4096 Apr  3 01:04 ca-certificates
-rw-r--r--  1 root root       8023 Apr  3 01:05 ca-certificates.conf
-rw-r--r--  1 root root       5713 Apr  3 01:05 ca-certificates.conf.dpkg-old
drwxr-xr-x  2 root root       4096 Apr  3 01:06 calendar
drwxr-xr-x  5 root root       4096 Apr  3 01:08 cloud
drwxr-xr-x  2 root root       4096 Apr  3 01:07 console-setup
drwxr-xr-x  2 root root       4096 Apr  3 01:06 cron.d
drwxr-xr-x  2 root root       4096 Aug 22 07:54 cron.daily
drwxr-xr-x  2 root root       4096 Apr  3 01:04 cron.hourly
drwxr-xr-x  2 root root       4096 Apr  3 01:04 cron.monthly
drwxr-xr-x  2 root root       4096 Apr  3 01:07 cron.weekly
-rw-r--r--  1 root root       1042 Feb 13  2020 crontab
drwxr-xr-x  2 root root       4096 Apr  3 01:07 cryptsetup-initramfs
-rw-r--r--  1 root root         54 Apr  3 01:06 crypttab
drwxr-xr-x  4 root root       4096 Apr  3 01:04 dbus-1
drwxr-xr-x  3 root root       4096 Apr  3 01:06 dconf
-rw-r--r--  1 root root       2969 Aug  3  2019 debconf.conf
-rw-r--r--  1 root root         13 Dec  5  2019 debian_version
drwxr-xr-x  3 root root       4096 Aug 22 07:54 default
-rw-r--r--  1 root root        604 Sep 15  2018 deluser.conf
drwxr-xr-x  2 root root       4096 Apr  3 01:05 depmod.d
drwxr-xr-x  4 root root       4096 Apr  3 01:05 dhcp
drwxr-xr-x  4 root root       4096 Apr  3 01:05 dpkg
-rw-r--r--  1 root root        685 Feb 14  2020 e2scrub.conf
