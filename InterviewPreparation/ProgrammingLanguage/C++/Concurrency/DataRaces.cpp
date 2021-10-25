// addMoney.cpp

#include <functional>
#include <iostream>
#include <thread>
#include <vector>

struct Account{
  int balance{100};                             
};

void addMoney(Account& to, int amount){
  to.balance += amount;                         
}

void Add5000(){
      

    Account account;
    std::vector<std::thread> vecThreads(100);
  
                                                 
    for (auto& thr: vecThreads) thr = std::thread(addMoney, std::ref(account), 50);
  
    for (auto& thr: vecThreads) thr.join();
  
                                                 
    std::cout << "accou nt.balance: " << account.balance << std::endl;
}

int main(){
    for(int i = 0; i < 10; ++i){
        Add5000();
    }


}