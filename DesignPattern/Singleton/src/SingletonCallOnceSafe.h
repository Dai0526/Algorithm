// singletonCallOnce.cpp

#include <future>
#include <mutex>
#include <thread>

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