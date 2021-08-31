# Singleton Benchmark
Create Singleton Instance for 40,000,000 times.
## Singleton C++ performance in Windows 10


|Singleton Type    |  Time Spent   |
|:---              |---:           |
| [Lock Init](https://github.com/Dai0526/Algorithm/blob/master/DesignPattern/Singleton/src/SingletonLock.h)        |    1.72336 sec|
| [Lock Double Check](https://github.com/Dai0526/Algorithm/blob/master/DesignPattern/Singleton/src/SingletonDoubleLock.h)|  0.0887732 sec|
| [Classical 1](https://github.com/Dai0526/Algorithm/blob/master/DesignPattern/Singleton/src/SingletonClassical.h)      |  0.0777613 sec|
| [LockGuard](https://github.com/Dai0526/Algorithm/blob/master/DesignPattern/Singleton/src/SingletonLockGuard.h)       |    1.63736 sec|
| [CallOnce](https://github.com/Dai0526/Algorithm/blob/master/DesignPattern/Singleton/src/SingletonCallOnceSafe.h)        |   0.324206 sec|
| [Seq Consistency](https://github.com/Dai0526/Algorithm/blob/master/DesignPattern/Singleton/src/SingletonSeqConsistency.h)  |   0.201078 sec|
| [Release Acquire](https://github.com/Dai0526/Algorithm/blob/master/DesignPattern/Singleton/src/SingletonAcqRel.h)  |   0.307426 sec|


## Windows 10 Ubuntu gcc

|Singleton Type    |  Time Spent   |
|:---              |---:           |
| [Lock Init](https://github.com/Dai0526/Algorithm/blob/master/DesignPattern/Singleton/src/SingletonLock.h)        |    0.581528 sec|
| [Lock Double Check](https://github.com/Dai0526/Algorithm/blob/master/DesignPattern/Singleton/src/SingletonDoubleLock.h)|  0.0908317 sec|
| [Classical 1](https://github.com/Dai0526/Algorithm/blob/master/DesignPattern/Singleton/src/SingletonClassical.h)      |  0.0714579 sec|
| [LockGuard](https://github.com/Dai0526/Algorithm/blob/master/DesignPattern/Singleton/src/SingletonLockGuard.h)       |    0.58448 sec|
| [CallOnce](https://github.com/Dai0526/Algorithm/blob/master/DesignPattern/Singleton/src/SingletonCallOnceSafe.h)        |   0.389989 sec|
| [Seq Consistency](https://github.com/Dai0526/Algorithm/blob/master/DesignPattern/Singleton/src/SingletonSeqConsistency.h)  |   0.180449 sec|
| [Release Acquire](https://github.com/Dai0526/Algorithm/blob/master/DesignPattern/Singleton/src/SingletonAcqRel.h)  |   0.17178 sec|