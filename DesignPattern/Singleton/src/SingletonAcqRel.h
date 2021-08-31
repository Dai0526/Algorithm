// singletonAcquireRelease.cpp
#include <atomic>
#include <future>
#include <mutex>

class SingletonAcqRel{
public:
    static SingletonAcqRel* getInstance(){
    SingletonAcqRel* sin = instance.load(std::memory_order_acquire);
    if (!sin){
        std::lock_guard<std::mutex> myLock(myMutex);
        sin = instance.load(std::memory_order_relaxed);
        if(!sin){
          sin = new SingletonAcqRel();
          instance.store(sin, std::memory_order_release);
        }
    }    
    volatile int dummy{};
    return sin;
  }
private:
  SingletonAcqRel() = default;
  ~SingletonAcqRel() = default;
  SingletonAcqRel(const SingletonAcqRel&) = delete;
  SingletonAcqRel& operator=(const SingletonAcqRel&) = delete;

  static std::atomic<SingletonAcqRel*> instance;
  static std::mutex myMutex;
};
