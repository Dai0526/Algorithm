// singletonAcquireRelease.cpp

#include <atomic>
#include <iostream>
#include <future>
#include <mutex>
#include <thread>

constexpr auto tenMill = 10000000;

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


std::atomic<SingletonAcqRel*> SingletonAcqRel::instance;
std::mutex SingletonAcqRel::myMutex;

int main(){
    
  constexpr auto fourtyMill = 4 * tenMill;
  
  const auto begin= std::chrono::system_clock::now();
  
  for ( size_t i = 0; i <= fourtyMill; ++i){
    SingletonAcqRel::getInstance();
  }
  
  const auto end = std::chrono::system_clock::now() - begin;
  
  std::cout << std::chrono::duration<double>(end).count() << std::endl;
}