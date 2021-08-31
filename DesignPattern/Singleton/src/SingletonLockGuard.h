// singletonLock.cpp
#include <future>
#include <mutex>

std::mutex mtxLG;
class SingletonLockGuard{

public:

    static SingletonLockGuard& getInstance(){
      std::lock_guard<std::mutex> myLock(mtxLG);
      if (!instance){
          instance= new SingletonLockGuard();
      }
      volatile int dummy{};
      return *instance;
  }

private:
    SingletonLockGuard() = default;
    ~SingletonLockGuard() = default;
    SingletonLockGuard(const SingletonLockGuard&) = delete;
    SingletonLockGuard& operator=(const SingletonLockGuard&) = delete;

    static SingletonLockGuard* instance;

};

