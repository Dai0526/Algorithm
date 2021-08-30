/*
 Scott Meyers. 
 Single Thread

*/

class SingletonClassical{
public:
  static SingletonClassical& getInstance(){
    static SingletonClassical instance;
    volatile int dummy{};
    return instance;
  }

private:
  SingletonClassical() = default;
  ~SingletonClassical() = default;
  SingletonClassical(const SingletonClassical&) = delete;
  SingletonClassical& operator=(const SingletonClassical&) = delete;
};
