/*
 Scott Meyers. 
 Single Thread

*/

#include <chrono>
#include <iostream>

constexpr auto tenMill = 10000000;

class SingletonMeyerClassical{
public:
  static SingletonMeyerClassical& getInstance(){
    static SingletonMeyerClassical instance;
    volatile int dummy{};
    return instance;
  }

private:
  SingletonMeyerClassical() = default;
  ~SingletonMeyerClassical() = default;
  SingletonMeyerClassical(const SingletonMeyerClassical&) = delete;
  SingletonMeyerClassical& operator=(const SingletonMeyerClassical&) = delete;
};

int main(){
    
  constexpr auto fourtyMill = 4 * tenMill;
  
  const auto begin= std::chrono::system_clock::now();
  
  for ( size_t i = 0; i <= fourtyMill; ++i){
    SingletonMeyerClassical::getInstance();
  }
  
  const auto end = std::chrono::system_clock::now() - begin;
  
  std::cout << std::chrono::duration<double>(end).count() << std::endl;

}