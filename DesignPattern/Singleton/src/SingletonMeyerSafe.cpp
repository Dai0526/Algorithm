// singletonMeyers.cpp

#include <chrono>
#include <iostream>
#include <future>

constexpr auto tenMill = 10000000;

class SingletonMeyerSafe{
public:
  static SingletonMeyerSafe& getInstance(){
    static SingletonMeyerSafe instance;
    volatile int dummy{};
    return instance;
  }
private:
  SingletonMeyerSafe() = default;
  ~SingletonMeyerSafe() = default;
  SingletonMeyerSafe(const SingletonMeyerSafe&) = delete;
  SingletonMeyerSafe& operator=(const SingletonMeyerSafe&) = delete;

};

std::chrono::duration<double> getTime(){

  auto begin = std::chrono::system_clock::now();
  for (size_t i = 0; i <= tenMill; ++i){
      SingletonMeyerSafe::getInstance();
  }
  return std::chrono::system_clock::now() - begin;
  
};

int main(){
 
    auto fut1= std::async(std::launch::async, getTime);
    auto fut2= std::async(std::launch::async, getTime);
    auto fut3= std::async(std::launch::async, getTime);
    auto fut4= std::async(std::launch::async, getTime);
    
    const auto total= fut1.get() + fut2.get() + fut3.get() + fut4.get();
    
    std::cout << total.count() << std::endl;

}