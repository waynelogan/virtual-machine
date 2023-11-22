# A virtual machine written in C

## About
This project is an implementation of a low level virtual machine. It is part of a languagee interpreter.

## How it works
The virtual machine implements stack memory and stack methods. From these stack methods, other functions such as arithmetic operators are implemented using the stack and stack methods.

## Project Organization
**Folder Structure**
```
|-build
    |-vm
|-src
    |-vm.c
|-build.sh
|-README.md
```
The entry point is `/src/vm.c`
Compiled object code is stored in `/build`