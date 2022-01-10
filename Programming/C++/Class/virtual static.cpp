//一共有3个要点
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Person{
    protected:
        string name;
        int age;
    public:
        virtual void getdata(){} //要点1 虚类函数必须有内容，不能只有();
        virtual void putdata(){}
};  

class Professor: public Person{
    private:
        int publications, id;
        static int cur_id;
    public:
        Professor(){
            id = ++cur_id;
        }
        void getdata(){
            cin >> name >> age >> publications;
        }
        void putdata(){
            cout << name << " " << age << " " << publications << " " << id << endl; //要点2 不能直接输出static 变量cur_id
        }
};
class Student: public Person{
    private:
        int marks[6], id;
        static int cur_id;
    public:
        Student(){
            id = ++cur_id;
        }
        void getdata(){
            cin >> name >> age;
            for(auto i = 0;i < 6;i++)cin >> marks[i];
        }
        void putdata(){
            int sum = 0;
            for(auto i = 0;i < 6;i++){
                sum += marks[i];
            }
            cout << name << " " << age << " " << sum << " " << id <<endl;
        }
};
int Professor :: cur_id = 0; //要点3 类的static 变量必须在外面额外声明并初始化
int Student :: cur_id = 0;
int main(){