// singletonSequentialConsistency.cpp

#include <atomic>
#include <iostream>
#include <future>
#include <mutex>
#include <thread>

constexpr auto tenMill = 10000000;

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


std::atomic<SingletonSeqConsistency*> SingletonSeqConsistency::instance;
std::mutex SingletonSeqConsistency::myMutex;

int main(){
    
  constexpr auto fourtyMill = 4 * tenMill;
  
  const auto begin= std::chrono::system_clock::now();
  
  for ( size_t i = 0; i <= fourtyMill; ++i){
    SingletonSeqConsistency::getInstance();
  }
  
  const auto end = std::chrono::system_clock::now() - begin;
  
  std::cout << std::chrono::duration<double>(end).count() << std::endl;

}
