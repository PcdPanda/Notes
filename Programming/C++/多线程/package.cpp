#include <iostream>
#include <thread>
#include <future>
#include <deque>
int factorial(int n){
    if(n<=1) return 1;
    else{
        int out = 1;
        while(n>=1){
            out *= n;
            n--;
        }
        return out;
    }
}

int main(int argc, char*argv[]){
    std::packaged_task<int(int)> t(factorial);

    std::packaged_task<int()> t1(std::bind(factorial, 6)); 
    // 传入n=6,无法在接受输入，所以定义也要修改

    auto x = std::bind(factorial, 6); // package object
    std::deque<std::packaged_task<int()>> d;
    d.emplace_back(std::move(x));//任务队列
    //做很多事

    std::future<int> fu = t1.get_future();

    t(6); //task可以被传送到其他线程或者函数或者类进行操作，把函数包装成package
    //!t只会返回void value
    int x = t.get_future().get();//获得factorial(6)的值

    std::cout << fu.get() << std::endl;
}