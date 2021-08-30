// singletonLock.cpp

#include <chrono>
#include <iostream>
#include <future>
#include <mutex>

constexpr auto tenMill = 10000000;

std::mutex myMutex;

class SingletonLockGuard{
public:
  static SingletonLockGuard& getInstance(){
    std::lock_guard<std::mutex> myLock(myMutex);
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


SingletonLockGuard* SingletonLockGuard::instance = nullptr;

int main(){
    
  constexpr auto fourtyMill = 4 * tenMill;
  
  const auto begin= std::chrono::system_clock::now();
  
  for ( size_t i = 0; i <= fourtyMill; ++i){
    SingletonLockGuard::getInstance();
  }
  
  const auto end = std::chrono::system_clock::now() - begin;
  
  std::cout << std::chrono::duration<double>(end).count() << std::endl;

}