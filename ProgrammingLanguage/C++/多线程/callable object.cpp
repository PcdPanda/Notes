#include <iostream>
#include <thread>
std::once_flag flag;
class A{
    public:
        void f(int x, char c){}
        double g(double x){return 0;}
        int operator()(int N){return 0;}
};

int main(int argc, char* argv[]){
    A a;
    std::thread p(a, 6); // 复制a并在p进程中运行
    std::thread p1(std::ref(a), 6); // 直接用a运行
    std::thread p2(A(),6); //用一个之后会消失的a放在p里运行
    std::thread p3([](int x){return x*x;}, 6); //运行lambda函数
    std::thread p4(A::g, std::move(a), 2);//可以运行其他函数,std::move的对象必须以后不会再用


    std::async(std::launch::async, a, 6);


    std::bind(a,6);
    std::call_once(flag, a, 6);
    return 0;
}