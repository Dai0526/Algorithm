# C++ Fundmental

## Memoory Model
* Stack
* Heap
* Data Segment

## STL
3 parts in general:
1. Container
2. Iterator
3. Algorithm

### Container and Data Structure
1. Sequential Containers
    * array
    * vector
        * dynamic array
        * resize by 1.5 or 2 times
    * list
        * search is expensive
        * good for delete/insert
    * deque
    * forward list
2. Associative Containers
    key-value bases
    * Sorted by Key - (`Red-Black Tree Based`)
        * set
        * map
        * multiset
        * multimap
    * Unsorted - (`Hash Function`)
        * unordered_map
        * unordered_set
        * unordered_multiset
        * unordered_multimap

Other Data Structure
* stack, queue
Low level design depends on STL version. It could be vector, list, deque

* priority queue
### Smart Pointer
RAII design pattern. Wrap around the raw pointer.

* Weak Pointer
* Unique Pointer
* Shared Pointer

### Iterator
Is to iterate container's element without exposure its internal structure
* forward iterator
* bidirectional iterator
* random access iterator


###

## OOD


## Multi-Threading
* Thread life time
1. Join
    * It can wait until its child is done
2. Detach
    * It can detach itself from its child
    * typically used for long running background services such as server

A mutex only allows you to wait until the lock is available; 
a condition variable allows you to wait until some application-defined condition has changed.

### Thread vs Process
Process:
* Creation of each process requires separate system calls for each process.
* It is an isolated execution entity and does not share data and information.
* Processes use the IPC(Inter-Process Communication) mechanism for communication that significantly increases the number of system calls.
* Process management takes more system calls.
* A process has its stack, heap memory with memory, and data map.

Thread:
* Single system call can create more than one thread
* Threads share data and information.
* Threads shares instruction, global, and heap regions. However, it has its register and stack.
* Thread management consumes very few, or no system calls because of communication between threads that can be achieved using shared memory

| Parameter |	Process |	Thread|
|----|----|----|
|Definition|	Process means a program is in execution. |	Thread means a segment of a process.|
|Lightweight|	The process is not Lightweight.	|Threads are Lightweight.|
|Termination time|	The process takes more time to terminate.|	The thread takes less time to terminate.|
| Creation time|	It takes more time for creation.|	It takes less time for creation.|
|Communication|	Communication between processes needs more time compared to thread.	|Communication between threads requires less time compared to processes.|
|Context switching time	| It takes more time for context switching.	| It takes less time for context switching.
|Resource|	Process consume more resources.	|Thread consume fewer resources.|
|Treatment by OS|	Different process are tread separately by OS.|	All the level peer threads are treated as a single task by OS.|
|Memory	| The process is mostly isolated.	|Threads share memory.|
|Sharing|	It does not share data|	Threads share data with each other.|


### Shared Data
* Mutex
    * Data race
        * mutex.lock
        * mutex.unlock
    * Issues:
        1. Deadlock
        2. Exception handling
            * mutex will not be released if exception occurs in between
        3. Recrusive Lock
            * if the function also work on the same mutex, which lead to unknown behavior
        4. Avoiding calling a function while holding a lock
    * lock_guard
        * shared lock using RAII design idea
            * scoped lock
* Conditional Variable
* Semphore


1. Mutalble Variable and immutable
2. Virtual 
3. Pointer vs reference
4. inline function
5. static function