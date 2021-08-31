/*
Thread Safe singleton with lock

protect the initialization of the singleon with lock

*/
#include <mutex>

std::mutex mtxSL;

class SingletonLock{
public:  
    static SingletonLock* getInstance(){    
      std::lock_guard<std::mutex> myLock(mtxSL);      
      if(!slInstance) slInstance = new SingletonLock();    
      return slInstance;  
    }
  
private:  

    SingletonLock() = default; 
    ~SingletonLock() = default;
    SingletonLock(const SingletonLock&) = delete;  
    SingletonLock& operator= (const SingletonLock&) = delete;
    static SingletonLock* slInstance;
};
