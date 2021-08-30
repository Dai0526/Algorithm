#include <iostream>
#include <mutex>
#include <thread>

std::mutex myMutex;

class SingletonLock{
public:  
  static SingletonLock* getInstance(){    
    std::lock_guard<std::mutex> myLock(myMutex);      
    if(!instance) instance = new SingletonLock();    
    return instance;  
  }
  
private:  
  SingletonLock() = default; 
  ~SingletonLock() = default;
  SingletonLock(const SingletonLock&) = delete;  
  SingletonLock& operator= (const SingletonLock&) = delete;
  static SingletonLock* instance;
};
