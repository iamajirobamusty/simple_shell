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

