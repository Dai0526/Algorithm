/*
Thread Safe singleton with double lock
Better performance than single check
*/

#include <iostream>
#include <mutex>
#include <thread>

std::mutex myMutex;

class SingletonDoubleLock{
public:  
  static SingletonDoubleLock* getInstance(){    
    if (!instance){                                             // check
      std::lock_guard<std::mutex> myLock(myMutex);              // lock
      if(!instance) instance = new SingletonDoubleLock();       // check
    } 
    return instance; 
  }
private:  
  SingletonDoubleLock() = default; 
  ~SingletonDoubleLock() = default;
  SingletonDoubleLock(const SingletonDoubleLock&) = delete;  
  SingletonDoubleLock& operator= (const SingletonDoubleLock&) = delete;
  static SingletonDoubleLock* instance;
};
