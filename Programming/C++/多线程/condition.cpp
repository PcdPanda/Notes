#include <iostream>
#include <deque>
#include <mutex>
#include <condition_variable>

std::deque<int> q;
std::mutex m;
std::condition_variable cond1;

void producer(){
    int count = 10;
    while(count>0){
        std::unique_lock<std::mutex> locker(m);
        locker.lock();
        cond1.notify_one(); //唤醒一个正在等cond1的thread
        cond1.nofity_all(); //唤醒所有正在等cond1的thread
        q.emplace_back(count);
        sleep(1);
        count--;
    }
}

void consumer(){
    while(1){
        std::unique_lock<std::mutex> locker(m);
        cond1.wait(locker, [](){return !q.empty()}); 
        //sleep等到有了cond1的notify, sleep前会释放locker,醒来时锁住locker
        //为了防止spurious wake自己醒来, wait1后面加入了lambda函数
        //这个时候如果q是empty返回false则继续sleep
        int x = q.pop_front();
        std::cout << x << std::endl;
    }
}

int main(int argc, char* argv[]){

}