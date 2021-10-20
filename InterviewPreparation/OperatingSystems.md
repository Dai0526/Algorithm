
IPC
* Pipe
* Signal
* Message Queue
* Sockets
* Semaphores

MultiThreading
Paging
Process
FileSystem
Kernel

## 32-bit vs 64-bit

## C++ Compiler and Bugging Tool

### C++ Compiler 

* Linux
    * LLVM
    * CLANG
    * GCC
    * PIDL - MIDL equivalent
* Windows
    * CL

* CUDA
    * nvcc

### Compile Tool
* CMake
* Make file
* MSBuild

### C++ Debugger
* Windows
    * visual studio debugger - cl compiles debug version with .PDB file. 
    * cuda - Nvidia NSight
* Linux
    * GDB
        1. Compile and Execute
        ```cpp
            gcc -Wall -g program.c
            gbd a.out arg1 arg2
        ```
    * How to debug
    ```GDB
        // in DGB 
        layout next // type layout to see code layout

        run   // to run or restart program

        // some control instructions
        'control-C' // it will break the execution and it stops where the last execution is. It is good for debug infinte loop

        next // step line by line 
        print parameter_name // print value

        step // step inside the function

        break func_name // add breakpoint to the function

        refresh // clean GUI

        control-x 2 // second window with assembly
        control-x 2 // second window with register

    ```