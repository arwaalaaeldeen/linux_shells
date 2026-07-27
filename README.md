# Linux Shell Projects (Femto & Pico Shells)

A collection of custom, lightweight Unix shell implementations built in C as part of operating systems and systems programming coursework. 

---

## Repository Structure

* **picoshell/** — Contains source code, header files, and Makefile for the picoshell project (supporting system calls like `fork`, `execvp`, and custom functions).
* **femtoshell/** — Contains earlier basic shell iteration files.

---

## Compilation Instructions

To compile any of the shell projects, navigate into its specific directory using your terminal and run the `make` command:

```bash
cd picoshell
make
```

## Here is an example of running the compiled shell and executing basic commands:

arwa@arwa-VirtualBox:~/sesh_practice/project/shells$ ./picoshell 
ZUBA EL-SHAMLULA > ls -l
total 56
-rw-rw-r-- 1 arwa arwa   692 Jul 27 16:55 exec.c
-rw-rw-r-- 1 arwa arwa   821 Jul 27 16:21 femtoshell.c
-rw-rw-r-- 1 arwa arwa   467 Jul 27 16:55 functions.c
-rw-rw-r-- 1 arwa arwa   102 Jul 27 16:27 functions.h
-rwxrwxr-x 1 arwa arwa 16352 Jul 27 16:18 myfemtoshell
-rwxrwxr-x 1 arwa arwa 16912 Jul 27 17:21 picoshell
-rw-rw-r-- 1 arwa arwa  1730 Jul 27 16:55 picoshell.c
ZUBA EL-SHAMLULA > exit
Good Bye ;)

