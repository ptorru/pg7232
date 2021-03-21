---
title: Theory Week 8 - Memory Layout of a C Program
created: '2021-03-17T17:35:24.039Z'
modified: '2021-03-17T19:45:49.848Z'
---

# Theory Week 8 - Memory Layout of a C Program

## Introduction
In this session we aim to:
* Remember where things are located in memory.
   * Types of data storage.
* What happens when a function is called.
* Getting some (non-dynamic) Memory
  * Interesting things in 8-Bit Pics.


## Memory Layout of a C Program

```
High Addresses ---> .----------------------.
                    |      Environment     |
                    |----------------------|
                    |                      |   Functions and variable are declared
                    |         STACK        |   on the stack.
base pointer ->     | - - - - - - - - - - -|
                    |           |          |
                    |           v          |
                    :                      :
                    .                      .   The stack grows down into unused space
                    .         Empty        .   while the heap grows up. 
                    .                      .
                    .                      .   (other memory maps do occur here, such 
                    .                      .    as dynamic libraries, and different memory
                    :                      :    allocate)
                    |           ^          |
                    |           |          |
 brk point ->       | - - - - - - - - - - -|   Dynamic memory is declared on the heap
                    |          HEAP        |
                    |                      |
                    |----------------------|
                    |          BSS         |   Uninitialized data (BSS)
                    |----------------------|   
                    |          Data        |   Initialized data (DS)
                    |----------------------|
                    |          Text        |   Binary code
Low Addresses ----> '----------------------'

taken from:
https://aticleworld.com/memory-layout-of-c-program/
```

In general terms:
* You need space to hold your program (Text).
* You need space to hold variables (stack).
* You need space to hold dynamic variables (heap).

## What happens when a function is called

This should be a relatively easy topic to discuss, thinking about previous Computer Architecture courses.

Remember we have a stack, a separate stack is kept for every function.

On a function call we need to...
* Save the current environment.
  * Save the address of the next instruction to run when returning from a function.
* Set your function up.
* Execute code.
* Clean Up and return.
* Reload previous context.
* Continue execution.

## Getting some (non-dynamic) Memory

**IMPORTANT:** Please remember this:
* A variable has two characteristics:
  * Scope: what things can access it.
  * Persistence: do we get the data for ever?.

C has got the concept of Automatic and Non-Automatic Variables
* Automatic variables are allocated at function initialization.
* Their lifetime is only the scope of the function.

Automatic vs Non-Automatic may be hard to visualize. Important though is:
* We affect scope by moving the position of the variable in the code.
* We affect persistence by using *static*.

```C
//Automatic Variables
void func1(){
  int myVariable = 2; // allocated in .data
  int myVariable2;    // allocated in .bss
...
}
```

Non-Automatic variables persist in time.
```C
//Non-Automatic Variables
// This is a global variable
int global_var;       // allocated in .bss can be seen by anything/everything.
```

```C
static int semi_global_var; // allocated in .bss, only available to local functions.

void func1(){
  // top-tip: Static variables in functs get initialized only once!
  //          at least when using XC8
  static int myVariable = 2;  // allocated in .data
  const int myVariable2 = 9;  // allocated in .text
...
}
```

Other interesting keywords
* *volatile*: tells the compiler to always update, eg, not rely on cache.
* *const*: makes variable read only.


### Compiler/Architecture Specifics

* Remember C is a "high-level" language. 
  * The compiler will interpret your instructions in different ways depending on the underlying architecture.

* You should consult the XC-8 Compiler Manual.
  * Specially *5.5 MEMORY ALLOCATION AND ACCESS*

Some gems from 8-Bit pics:

```
5.3.4 Stacks
Stacks are used for two different purposes by programs running on 8-bit devices: one
stack is for storing function return addresses, and one or two other stacks are used for
data allocation.

...
The 8-bit PIC devices use what is referred to in this user’s guide as a hardware stack.
This stack is limited in depth and cannot be manipulated directly. It is only used for
function return addresses and cannot be used for program data.

You must ensure that the maximum hardware stack depth is not exceeded; otherwise,
code can fail. Nesting function calls too deeply will overflow the stack.
```

```
5.3.4.2 DATA STACKS
The compiler can implement two types of data stack: a compiled stack and a software
stack. Both these stacks are for storing stack-based variables, such as a function’s
auto, parameter, and temporary variables.

Either one or both of these types of stacks may be used by a program. Compiler
options, specifiers, and how the functions are called will dictate which stacks are used.
```

```
5.5.2.2.3 Size Limits of Auto Variables

...
Unlike with non-auto variables, it is not efficient to access auto variables within the
compiled stack using the linear memory of enhanced mid-range devices. For all
devices, including PIC18 and Enhanced mid-range PIC MCUs, each component of the
compiled stack must fit entirely within one bank of data memory on the target device
(however, you can have more than one component, each allocated to a different bank).

This limits the size of objects within the stack to the maximum free space of the bank
in which it is allocated. The more auto variables in the stack; the more restrictive the
space is to large objects.
```

## References
* [Computer Systems: A Programmer's Perspective. Chapter 7](http://csapp.cs.cmu.edu/2e/ch7-preview.pdf)
* [GCC and Make Compiling, Linking and Building C/C++ Applications](https://www3.ntu.edu.sg/home/ehchua/programming/cpp/gcc_make.html)
* [MPLAB ® XC8 C Compiler User’s Guide](http://ww1.microchip.com/downloads/en/DeviceDoc/50002053G.pdf)
* [Zeyuan Hu's: Understanding how a function call works](https://zhu45.org/posts/2017/Jul/30/understanding-how-function-call-works/)
* [Aticleworld: Memory Layout of a C Program](https://aticleworld.com/memory-layout-of-c-program/)

