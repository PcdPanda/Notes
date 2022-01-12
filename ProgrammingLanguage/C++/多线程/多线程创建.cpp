#include <iostream>
#include <thread>

void producer(){

}

std::string modify(const std::string& str){
    return str + "abc";
}

int main(int argc, char* argv[]){
    std::thread p1(producer);
    p1.join(); // main会等到p1运行完接着运行
    p1.detach(); //main会和p1同步运行
    // join和detach必须取其一
    // 如果main运行完了，其他线程即使detach了也会直接结束（没运行完）
    std::string str = "abc";

    std::thread p2(modify,str); // 即使传递引用也不会修改str
    std::thread p3(modify, std::ref(str));// 必须用std::ref传递引用
    std::cout << str << std::endl;

    std::thread p4 = p3; //不行，线程不能copy
    std::thread p5 = std::move(p3); //可以，转移p3线程的所有权，p3变成空线程
    return 0;
}