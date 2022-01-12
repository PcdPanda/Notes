#include <future>
#include <thread>
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <chrono>

int no(int N){
    return 0;
}
int main(int argc, char*argv[]){
    //promise and future
    std::promise<int> p;
    std::future<int> f = p.get_future();
    //async
    std::future<int> g = std::async(std::launch::async, no, 2);
    //package task

    std::packaged_task<int()> t(no,2);

    std::future<int> h = t.get_future();
    h.get();//get会自动调用wait
    h.wait();//等到h的函数有return了再继续
    h.wait_for(chrono::milliseconds(2));
    h.wait_until(tp);//最多等到tp  

    return 0;
}