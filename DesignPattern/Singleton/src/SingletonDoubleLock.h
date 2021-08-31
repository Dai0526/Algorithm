/*
Thread Safe singleton with double lock
Better performance than single check
*/

#include <mutex>

static std::mutex mtxDL;

class SingletonDoubleLock{
public:  
  static SingletonDoubleLock* getInstance(){    
      if (!sdlInstance){                                           // check
        std::lock_guard<std::mutex> myLock(mtxDL);              // lock
        if(!sdlInstance) sdlInstance = new SingletonDoubleLock();     // check
      } 
      return sdlInstance; 
  }

private:  
    SingletonDoubleLock() = default; 
    ~SingletonDoubleLock() = default;
    SingletonDoubleLock(const SingletonDoubleLock&) = delete;  
    SingletonDoubleLock& operator= (const SingletonDoubleLock&) = delete;
    static SingletonDoubleLock* sdlInstance;

};
