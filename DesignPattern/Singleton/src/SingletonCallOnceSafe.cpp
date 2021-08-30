// singletonCallOnce.cpp

#include <chrono>
#include <iostream>
#include <future>
#include <mutex>
#include <thread>

constexpr auto tenMill = 10000000;

class SingletonCallOnceSafe{
public:
  static SingletonCallOnceSafe& getInstance(){
    std::call_once(initInstanceFlag, &SingletonCallOnceSafe::initSingleton);
    volatile int dummy{};
    return *instance;
  }
private:
  SingletonCallOnceSafe() = default;
  ~SingletonCallOnceSafe() = default;
  SingletonCallOnceSafe(const SingletonCallOnceSafe&) = delete;
  SingletonCallOnceSafe& operator=(const SingletonCallOnceSafe&) = delete;

  static SingletonCallOnceSafe* instance;
  static std::once_flag initInstanceFlag;

  static void initSingleton(){
    instance= new SingletonCallOnceSafe;
  }
};

SingletonCallOnceSafe* SingletonCallOnceSafe::instance = nullptr;
std::once_flag SingletonCallOnceSafe::initInstanceFlag;

int main(){
    
  constexpr auto fourtyMill = 4 * tenMill;
  
  const auto begin= std::chrono::system_clock::now();
  
  for ( size_t i = 0; i <= fourtyMill; ++i){
    SingletonCallOnceSafe::getInstance();
  }
  
  const auto end = std::chrono::system_clock::now() - begin;
  
  std::cout << std::chrono::duration<double>(end).count() << std::endl;

}
