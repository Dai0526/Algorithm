// singletonSequentialConsistency.cpp

#include <atomic>
#include <future>
#include <mutex>

class SingletonSeqConsistency{
public:
    static SingletonSeqConsistency* getInstance(){
      SingletonSeqConsistency* sin = instance.load();
      if (!sin){
        std::lock_guard<std::mutex> myLock(myMutex);
        sin = instance.load(std::memory_order_relaxed);
        if(!sin){
          sin= new SingletonSeqConsistency();
          instance.store(sin);
        }
      }
      volatile int dummy{};
      return sin;
  }

private:

    SingletonSeqConsistency() = default;
    ~SingletonSeqConsistency() = default;
    SingletonSeqConsistency(const SingletonSeqConsistency&) = delete;
    SingletonSeqConsistency& operator=(const SingletonSeqConsistency&) = delete;

    static std::atomic<SingletonSeqConsistency*> instance;
    static std::mutex myMutex;
};
