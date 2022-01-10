#include <iostream>
#include <string.h>
using namespace std;


//仿函数概念
//通过定义一个函数类和重载()可以自定义一个带参数的函数
//在需要传入函数指针的时候特别好用
class short_than{
    public:
    // explicit表示隐式构造无效，不可以通过等号来构造class
    explicit short_than(int m){max = m;}
    bool operator()(int x){
        return x < max;
    }

    private:
        int max;
};

//lambda表达式，用来定义简单的函数 格式如下
//[函数对象参数] (操作符重载函数参数) mutable 或 exception 声明 -> 返回值类型 {函数体}


int main(int argc, char* argv[]){
    const char* s = "hello";
    char ss[20];
    int length = std::strlen(s);
    for(int i=0;i<length;++i)ss[i] = s[length-i];
    printf("%s", ss);
    return 0;
    int a = 0, b = 1, c = 2;
    auto lambda_fun = [](int a, int b) -> int{ // 可以不加返回值类型
        double c = 0;
        c++;
        cout << "in lambda c=" << ++c << "\n";
        return a + (++b);
    }; // 需要加分号,因为lambda本质上是个类
    short_than st(10);
    // cout << st(3) << endl;
    // cout << st(13) << endl;
    cout << lambda_fun(3,13) << endl;
    cout << "a=" << a << "\n";
    cout << "b=" << b << "\n";
    cout << "c=" << c << "\n";
    return 0;
}