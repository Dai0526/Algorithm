/* 
This demo show how monitor secures the data in producer and consumer problem.

1. Producer and Consumer Secenario
    a. There is a Queue to manage jobs for distribtued systems
    b. Producer is host applicaitons create job and put it to Queue
    c. Consumer is worker applications take job from Queue and do execution

2. Idea
    * conditional variable and mutex work together as a monitor
        * Use conditional variable to signal worker that there is a job to fetch
        * Use mutex to ensure there is only one producer or one consumer to modify queue
*/
#define _CRT_SECURE_NO_WARNINGS // disable windows system warning

#include <mutex>
#include <condition_variable>
#include <queue>
#include <thread>

#include <sstream>
#include <iostream>
#include <ctime>
#include <iomanip>
#include <chrono>


using namespace std;

/*
Helper function
    - string getTimestamp()
    - void sleep(int ms)

*/
std::string getTimestamp()
{
    auto now = std::chrono::system_clock::now();
    auto nowTime = std::chrono::system_clock::to_time_t(now);

    std::stringstream ss;
    ss << std::put_time(std::localtime(&nowTime), "%Y-%m-%d %X");
    return ss.str();
}

void sleep(int ms){
    this_thread::sleep_for(std::chrono::milliseconds(ms)); // sleep 10 ms to save cpu
}


/*
Just for demo. Not a good practice to use global variable in general.
*/
mutex gMtx;
condition_variable cv;
queue<string> jobQueue;
atomic<bool> isJobsDone = false;


void consumerFunc(const string& name){  

    while(!isJobsDone){
        std::unique_lock ul(gMtx);
        while(jobQueue.empty()){
            cv.wait(ul);
        }

        string job = jobQueue.front();
        cout << name << " is handling job: " << job << endl;
        jobQueue.pop();
        ul.unlock();

        sleep(100);
    }
}

void producerFunc(int jobAmount){
    int count = 0;

    while(!isJobsDone){ // produce 20 jobs
        // dummy exection
        stringstream ss;
        ss << "Hello World " << count << " @ " << getTimestamp() << endl;
        string currJob = ss.str();
        
        mtx.lock(); // not the best practice, better use lock guard for bettern exception handling.
        jobQueue.push(currJob);
        cv.notify_all();
        mtx.unlock();

        ++count;
        isJobsDone = (count == jobAmount ? true : false);
        sleep(100);
    }
}



void runDemo(){

    // demo using 3 consumer thread, 1 producer
    thread prodThread(producerFunc, 20);
    thread consumer1(consumerFunc, "John");
    thread consumer2(consumerFunc, "Tom");
    thread consumer3(consumerFunc, "Jerry");

    prodThread.join();
    consumer1.join();
    consumer2.join();
    consumer3.join();
}

int main(){
    
    try{
        runDemo();
    }catch(exception & ex){
        cerr << ex.what() << endl;
        return 1;
    }catch(...){
        cerr << "Unknow exception" << endl;
        return 1;
    }

    return 0;
}