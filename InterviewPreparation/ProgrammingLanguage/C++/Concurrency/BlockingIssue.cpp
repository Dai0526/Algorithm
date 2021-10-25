/*
initialization sequence of threads will cause this issue

Because t2 init before t1
that t2 notify before t1 is wait
and t1 is locked because it misses the t2 notify
*/

#include <iostream>
#include <condition_variable>
#include <mutex>
#include <thread>

std::mutex mutex_;
std::condition_variable condVar;

bool dataReady;


void waitingForWork(){

    std::cout << "Worker: Waiting for work." << std::endl;

    std::unique_lock<std::mutex> lck(mutex_);
    condVar.wait(lck);                          
    // do the work
    std::cout << "Work done." << std::endl;

}

void setDataReady(){

    std::cout << "Sender: Data is ready."  << std::endl;
    condVar.notify_one();                        

}

int main(){

  std::cout << std::endl;

  std::thread t1(setDataReady); // t2 will miss t1's notify for cv
  std::thread t2(waitingForWork); 
   

  t1.join();
  t2.join();

  std::cout << std::endl;
  
}