# 0x16. C - Simple Shell
By Spencer Cheng, featuring Julien Barbier


## Overview

This is a basic command line interface (CLI) that allow users to interact with a UNIX-like operating systems (Linux) just by entering commands consisting of text


## Compilation
You can compile all the .c files using this command on your terminal

```
gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
```


## Run
You can run the executable file using this command on your terminal

```
./hsh
```


## Files

##### README.md
This briefly describe what this simple shell project does
>
##### AUTHORS
This is an auto-generated file listing names of contributors to this project.

Click [here](hack/generate-authors.sh) for more info
>
#### main.h
This header file consist of all standard libraries used, macros, and prototype of functions used in this project
>
#### main.c
This C file starts the program
>
#### process.c
This C file uses the fork() system call to create a new process (child process) and the process that call the fork() is called parent process
>
#### prompt.c
This C file displays a prompt message to the standard output (terminal)

#### get_tokens.c
This C file breaks down a string into smaller pieces called tokens

#### env.c
This C file displays environment variables to the standard output (terminal)

#### path.c
This C file searches for an executable command in the system's directories, uses the PATH environment variable to locate the command and construct a full path to the command by concatenating each directory path with the command name

#### strings.c
This C file perform basic string manipulation on strings

#### free_memory.c
This C file frees memory allocated for an array of strings, then frees the memory alocated for the array

#### exit.c
This C file frees allocated memory and terminates the shell program

