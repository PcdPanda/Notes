#include <iostream>
#include <pthread.h>
using namespace std;
#define MAX 100
pthread_mutex_t m;
pthread_cond_t pp, pc;
int buf = 0;
void *prod(){
    for(auto i=0;i<MAX;i++){
        pthread_mutex_lock(&m); //锁住m,表示要进入critical region
        while(buf!=0)pthread_cond_wait(&pp,&m);//如果buf!=0说明现在没轮到producer工作，所以交出锁并等待信号
        buf=0;
        pthread_cond_signal(&pc);//修改完成,给等待pc的线程发送信号
        pthread_mutex_unlock(&m);//释放锁
    }
    pthread_exit(0);//表示退出
    
}
void *cons(){
    for(auto i=0;i<MAX;i++){
        pthread_mutex_lock(&m);
        while(buf==0)pthread_cond_wait(&pc,&m);
        buf=1;
        pthread_cond_signal(&pp);//修改完成,给等待pp的线程发送信号
        pthread_mutex_unlock(&m);//释放锁
    }
    pthread_exit(0);//表示退出，输入必须和对应的join的第二个参数一致
}

int max(int a, int b){
    cout << "comp" << endl;
    return a;
}


int main() {
    int (*x)(int, int); // 定义函数指针,定义和调用的时候要括号起来
    x = max;
    cout << (*x)(5,6);

    pthread_t p,c;
    pthread_mutex_init(&m,0); 
    pthread_cond_init(&pp,0);
    pthread_cond_init(&pc,0);//初始化的输入是锁和条件的地址
    pthread_create(&p,0,&prod,0);
    pthread_create(&p,0,&cons,0);//创建线程都是用地址的
    pthread_join(p,0);
    pthread_join(c,0);//两个join指p和c都运行完了才往下
    pthread_mutex_destroy(&m);
    pthread_cond_destroy(&pp);
    pthread_cond_destroy(&pc);//运行完了记得都删除
	return 0;

}