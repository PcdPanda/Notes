#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <map>
#include <memory>
std::mutex m;
std::mutex m1;
std::once_flag flag;
//once_flag和call_once(once_flag, lambda函数)搭配可以保证只运行一次
void basic(){
    m.lock();
    std::cout << "hello" << std::endl;
    m.unlock();
    //基本的mutex操作，但如果basic线程崩溃,m则永远不会解锁

    std::lock_guard<std::mutex> locker(m, std::adopt_lock);
    //当函数结束或者崩溃,locker会自动解锁m,定义的时候会直接锁住m
    //adopt_lock告诉locker m已经被锁住了，不用管, 配合std::lock运行

    std::lock(m,m1);
    //可以不分先后顺序地同时锁住所有输入的锁,可以防止死锁

    std::unique_lock<std::mutex> ulocker(m, std::defer_lock);
    //有了defer_lock可以不用在定义的时候锁住m
    //unique_lock可以确保在想要的时候突然解锁,之后再上锁,当运行结束也会自动解锁
    ulocker.lock();
    ulocker.unlock();

    ulocker.try_lock();
    //如果无法lock就直接return

    ulocker.try_lock_for(chrono::nanoseconds(500));
    //持续5纳秒无法lock的话就return

    ulocker.try_lock_until(tp);
    //持续trylock一直到tp如果不行就return 

    std::unique_lock<std::mutex> ulocker2 = (std::move(ulocker));
    //unique_lock可以move, lock_guard不行

    //unique_lock占用资源比lock_guard多

    // std::call_once(once_flag, [](){std::cout <<" once program " << std::endl;});
}

int main(int argc, char* argv[]){
    int a = 0;
    return 0;
}