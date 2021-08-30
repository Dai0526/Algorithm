# Singleton C++ performance in Windows
|Singleton Type    |  Time Spent   |
|:---              |---:           |
| Lock Init        |    1.72336 sec|
| Lock Double Check|  0.0887732 sec|
| Classical 1      |  0.0777613 sec|
| LockGuard        |    1.63736 sec|
| CallOnce         |   0.324206 sec|
| Seq Consistency  |   0.201078 sec|
| Release Acquire  |   0.307426 sec|