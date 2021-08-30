#include "SingletonLock.h"
#include "SingletonDoubleLock.h"
#include "SingletonClassical.h"
#include "SingletonLockGuard.h"
#include "SingletonCallOnceSafe.h"
#include "SingletonSeqConsistency.h"
#include "SingletonAcqRel.h"

#include <thread>
#include <iostream>
#include <chrono>
#include <iomanip>

const int tenMill = 10000000;
const int fourtyMill = 4 * tenMill;  

SingletonLock* SingletonLock::slInstance = nullptr;
void Case1TestSingletonLock(){

    const auto begin= std::chrono::system_clock::now();
  
    for ( size_t i = 0; i <= fourtyMill; ++i){
        SingletonLock::getInstance();
    }

    const auto end = std::chrono::system_clock::now() - begin;
    std::cout << std::left << std::setw(30) << "\tSingleton Lock Init: " << std::right << std::setw(10) << std::chrono::duration<double>(end).count() << " sec" << std::endl;
}

SingletonDoubleLock* SingletonDoubleLock::sdlInstance = nullptr;
void Case2TestSingletonDoubleLock(){

    const auto begin= std::chrono::system_clock::now();
  
    for ( size_t i = 0; i <= fourtyMill; ++i){
        SingletonDoubleLock::getInstance();
    }

    const auto end = std::chrono::system_clock::now() - begin;
    std::cout << std::left << std::setw(30) << "\tSingleton Lock Double Check: " << std::right << std::setw(10) << std::chrono::duration<double>(end).count() << " sec" << std::endl;
}

void Case3TestSingletonClassical(){
    const auto begin= std::chrono::system_clock::now();
  
    for ( size_t i = 0; i <= fourtyMill; ++i){
        SingletonClassical::getInstance();
    }
  
    const auto end = std::chrono::system_clock::now() - begin;
    std::cout << std::left << std::setw(30) << "\tSingleton Classical1: " << std::right << std::setw(10) << std::chrono::duration<double>(end).count() << " sec" << std::endl;
}


std::chrono::duration<double> getTime(){

  auto begin = std::chrono::system_clock::now();
  for (size_t i = 0; i <= tenMill; ++i){
      SingletonClassical::getInstance();
  }
  return std::chrono::system_clock::now() - begin;
};

void Case4TestSingletonClassicalMultiThread(){
 
    auto fut1= std::async(std::launch::async, getTime);
    auto fut2= std::async(std::launch::async, getTime);
    auto fut3= std::async(std::launch::async, getTime);
    auto fut4= std::async(std::launch::async, getTime);
    
    const auto total= fut1.get() + fut2.get() + fut3.get() + fut4.get();
    std::cout << std::left << std::setw(30) << "\tSingleton Classical 2: " << std::right << std::setw(10) << total.count() << " sec" << std::endl;

}


SingletonLockGuard* SingletonLockGuard::instance = nullptr;
void Case5TestSingletonLockGuard(){
    
    const auto begin= std::chrono::system_clock::now();
  
    for ( size_t i = 0; i <= fourtyMill; ++i){
        SingletonLockGuard::getInstance();
    }
  
    const auto end = std::chrono::system_clock::now() - begin;
    std::cout << std::left << std::setw(30) << "\tSingleton LockGuard: " << std::right << std::setw(10) << std::chrono::duration<double>(end).count() << " sec" << std::endl;
}


SingletonCallOnceSafe* SingletonCallOnceSafe::instance = nullptr;
std::once_flag SingletonCallOnceSafe::initInstanceFlag;
void Case6TestSingletonCallOnce(){
      
  const auto begin= std::chrono::system_clock::now();
  
  for ( size_t i = 0; i <= fourtyMill; ++i){
    SingletonCallOnceSafe::getInstance();
  }
  
  const auto end = std::chrono::system_clock::now() - begin;
  std::cout << std::left << std::setw(30) << "\tSingleton CallOnce: " << std::right << std::setw(10) << std::chrono::duration<double>(end).count() << " sec" << std::endl;

}

// Sequential Consistency
std::atomic<SingletonSeqConsistency*> SingletonSeqConsistency::instance;
std::mutex SingletonSeqConsistency::myMutex;

void Case7TestSingletonSeq(){
  
  const auto begin= std::chrono::system_clock::now();
  
  for ( size_t i = 0; i <= fourtyMill; ++i){
    SingletonSeqConsistency::getInstance();
  }
  
  const auto end = std::chrono::system_clock::now() - begin;
  std::cout << std::left << std::setw(30) << "\tSingleton Seq Consistency: " << std::right << std::setw(10) << std::chrono::duration<double>(end).count() << " sec" << std::endl;
}

// release acquire
std::atomic<SingletonAcqRel*> SingletonAcqRel::instance;
std::mutex SingletonAcqRel::myMutex;

void Case8TestSingletonRelAcq(){
  
  const auto begin= std::chrono::system_clock::now();
  
  for ( size_t i = 0; i <= fourtyMill; ++i){
    SingletonAcqRel::getInstance();
  }
  
  const auto end = std::chrono::system_clock::now() - begin;
  std::cout << std::left << std::setw(30) << "\tSingleton Release Acquire: " << std::right << std::setw(10) << std::chrono::duration<double>(end).count() << " sec" << std::endl;

}

int main(int argc, char* argv[]){

    std::cout << "Singleton Performance Result: std-c++17 cl" << std::endl;
    Case1TestSingletonLock();
    Case2TestSingletonDoubleLock();
    Case3TestSingletonClassical();
    Case4TestSingletonClassicalMultiThread();
    Case5TestSingletonLockGuard();
    Case6TestSingletonCallOnce();
    Case7TestSingletonSeq();
    Case8TestSingletonRelAcq();
    
}