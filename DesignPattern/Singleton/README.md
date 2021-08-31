# Singleton Benchmark
## PC Setup
* Windows 10 Build 19042
* AMD 3700X 8-Core Processor, 3593 Mhz, 8 Core(s), 16 Logical Processor(s)

* RAM 32 GB

Create Singleton Instance for 40,000,000 times.

| Singleton Type   | win10 cl <sup id="fn1">[1](#f1)</sup>       | Ubuntu gcc <sup id="fn2">[2](#f2)</sup>     |
|:---              |---:            |---:            |
| [Lock Init](https://github.com/Dai0526/Algorithm/blob/master/DesignPattern/Singleton/src/SingletonLock.h)              |    1.72336 sec| 0.581528 sec|
| [Lock Double Check](https://github.com/Dai0526/Algorithm/blob/master/DesignPattern/Singleton/src/SingletonDoubleLock.h)|  0.0887732 sec| 0.0908317 sec|
| [Classical 1](https://github.com/Dai0526/Algorithm/blob/master/DesignPattern/Singleton/src/SingletonClassical.h)       |  0.0777613 sec| 0.0714579 sec|
| [LockGuard](https://github.com/Dai0526/Algorithm/blob/master/DesignPattern/Singleton/src/SingletonLockGuard.h)         |    1.63736 sec| 0.58448 sec|
| [CallOnce](https://github.com/Dai0526/Algorithm/blob/master/DesignPattern/Singleton/src/SingletonCallOnceSafe.h)       |   0.324206 sec| 0.389989 sec|
| [Seq Consistency](https://github.com/Dai0526/Algorithm/blob/master/DesignPattern/Singleton/src/SingletonSeqConsistency.h)  |   0.201078 sec| 0.180449 sec|
| [Release Acquire](https://github.com/Dai0526/Algorithm/blob/master/DesignPattern/Singleton/src/SingletonAcqRel.h)       |   0.307426 sec|0.17178 sec|




<b id="f1">1</b> cl r19.29.30038.1 x64[↩](#fn1)  
<b id="f2">2</b> gcc r9.3 [↩](#fn2)

