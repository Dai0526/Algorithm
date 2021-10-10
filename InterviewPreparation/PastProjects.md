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
The architecture itself utlize the computing resources. It makes sure as less idel agent as possible

#### Agent, Thread, Pipe(Multi-Threading)
* Agent 
    * Agent is the unit owns resources
    * Agent is connected through pipes

* Thread
    * Thread is the worker in agents
        * run the execution function
    * SyncGetInput and SyncGetOutput to obtain buffer one thread at a time
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
#### Remote Procedure Call(RPC)
1. Interface defination language
    1. MIDL in windows
    2. PIDL in linux https://linux.die.net/man/1/pidl

#### Checkstall to monitor CPU usages


## High Performance Data Computing
HPC for image and signal processing
1. Although 2d matrix is more intuitive, I prefer 1D vectors since it is memory aligned and it is faster.

#### CUDA
* Cuda library wrapper
* Cuda FFT

#### IPP


#### AVX


## Data Acquistion 
### Jungo Driver and WDK  


### Montion Control and Scan Control
#### State Machine Framework