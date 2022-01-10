#include <future>
#include <iostream>



void factorial(int N, int& x){
    if(N<1)x=0;
    else{
        int res = 1;
        for(auto i=N;N>=1;N--)res*=N;
        x = res;
    }
}

int Factorial(int N){
    if(N<1) return 0;
    else{
        int res = 1;
        for(auto i=N;N>=1;N--)res*=N;
        return res;
    }
}

int ff(std::future<int> fu){
    int N = fu.get();//当未来得到fu的值了才会继续运行
    if(N<1) return 0;
    else{
        int res = 1;
        for(auto i=N;N>=1;N--)res*=N;
        return res;
    }
}

int main(int argc, char*argv[]){
    int x = 0;
    std::thread p(factorial, 4, std::ref(x)) 
    p.join();
    //通过引用方式来获得线程的返回值
    std::cout << x << std::endl;


    std::future<int> fu = std::async(Factorial, 4);
    std::future<int> fu = std::async(std::launch::async|std::launch::deferred, Factorial, 4); // async不一定启动新线程,上下两行一样
     
    std::future<int> fu = std::async(std::launch::deferred, Factorial, 4); 
    // 不启动新线程, 等到fu.get()的时候调用Factorial函数
     
    std::future<int> fu = std::async(std::launch::async, Factorial, 4); 
    // 创建新线程

    x = fu.get(); // future只能get一次
    //直接获得factorial的返回值
    std::cout << x << std::endl;

    
    //承诺在未来传送value给ff thread
    std::promise<int> p;
    std::future<int> f = p.get_future();
    //future和promise都不能copy, 只能std::move()
    std::future<int> fu = std::async(std::launch::async, ff, std::ref(f)); 

    p.set_value(4);//如果不传送值给p,违背了promise,则会得到exception
    x = fu.get();

    std::shared_future<int> sf = f.share();
    //shared_future可以被copy
    //可以get多次
    return 0;
}