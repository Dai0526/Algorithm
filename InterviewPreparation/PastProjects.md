# Past Projects

## Software Architecture

### Concurrent Data Pipeline
Overview: Segmenting the data and process them concurrently.
1. each agent process a small piece data a time, such that less IDLE works it has.
2. each agent could have multiple threads to work such that heavy weight processing will not block(bottleneck) the pipeline 

#### Task Scheduler - SyncQueue
Thread safe queue (deque)
* Using Conditional Variable
* Thread wait indefinitely if nothing in the queue
* Thead works immediately after obtaining item in the queue

#### Work Load Balance
The architecture itself utlize the computing resources. It makes sure as less idle agents as possible

#### Agent, Thread, Pipe(Multi-Threading)
* Agent 
    * Agent is the unit owns resources
    * Agent is connected through pipes

* Thread
    * Thread is the worker in agents
        * run the execution function
    * SyncGetInput and SyncGetOutput to obtain buffer one thread at a time
    * CheckStall
        * Outer program monitor each threads processing time
            * a thread to check regularly
        * internal timer to monitor processing time, if last check equal to current processing time, then the thread is stalled.
* Pipe
    * Container class
        * use sync Queue to store meta info
    * Thread Safe
    * Support Multi-Thread write and read
        * Block write if pipe is full
        * Block read if pipe is empty
        * Write size and read size if configurable
    * Token is the data type
* Token
    * Data Segment
        * meta info - data position, data sequence number to ensure data consistency and prevent data corrpution
        * data buffer


### Refactory Recon(worker) and ReconMain(Job coordinator) 
1. ReconMain
    - Job coordinate
        - light weight job scheduling
        - launch process
        - never crush
2. Recon
    - a new process
    - do image processing
    - send output to client

3. Client/GUI
    - Send request to ReconMain with configuration and paremeters
    - Receive data from Recon

#### Remote Procedure Call(RPC)
A common interface for client and server. Data is text based, which is `unsigned char*`. It helps us to divide the respobsibility of Server and Client, and Client doesn't need to know the specific implementation of function call.

1. Interface defination language
    1. MIDL compiler in windows
    2. PIDL compiler in linux https://linux.die.net/man/1/pidl

#### Checkstall to monitor CPU usages


## High Performance Data Computing
HPC for image and signal processing
1. Although 2d matrix is more intuitive, I prefer 1D vectors since it is memory aligned which is faster in perfromance.

#### CUDA
* Cuda library wrapper
* Cuda FFT

#### IPP
Use IPPs verion r2019 update(ipp10).

#### AVX
It is a project to help us understand Ipp and its idea. In order to incoprate IPP into company's HPC library, we implement a class to warp it such that the high level interface is more readble and easier to use.

Then the idea comes to our mind is that how Ipp works and can we develop one by ourselves.

Thus, Assembly language for vector computing, basic calculations for 8 floats(256 bits) a time. 

## Data Acquistion 
### Jungo Driver and WDK  


## Montion Control and Scan Control
### State Machine Framework

Two Classes:
1. State
    - member variable:
        - uid<id, name>: state_name
        - uid<id, name>: prev_state_name
        - map<int, int>: transitions
        - timeout
        - during
        - enterByTimeout
        - enterByException
    - functions:
        - public:
            - int TriggerEvent: tell statemachine to transition
            - void AddTransition
            - GetPreviousState
        - private
            - set timeout
            - start: called when entering the state
            - stop: called leaving the state
            - processing: called periodicity when state is current state

2. State Machine
    - variable
        - map<int, statePtr>: all states
        - statePtr: current state
        - statePtr: prevState
        - int: most recent event id
        - bool: need transition
        - int: next state
        - Thread: state machine thread
        - int: default state
        - set<int>: destination - all event destinations, used to validate transitions.
        - bool: auto call process
        - thread interval
        - bool: isExit
        - mutex, contitionalVariable
    - function:
        - Start(startState, defaultState): first state, if error occur, go to default
        - Stop: Stop thread and build machine
        - AddState: Add StatePtr
        - Add Transition(int oriState, int eventName, int DestState)
        - TriggerEvent(int eventName)
        - void Process: check tmeout and call currentState's processing function
