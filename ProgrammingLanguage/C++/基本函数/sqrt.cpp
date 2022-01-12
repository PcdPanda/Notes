#include <iostream>
#include <sstream>
using namespace std;
double sqrt(double a){//二分法实现sqrt
    double x=0,y=a,t;
    while(1){
        t=(x+y)/2;
        if(t*t>a)y=t;
        else x=t;
        cout << "t=" << t<<endl;
        auto error = t*t-a;
        if(error*error<0.00001)break;
    }
    return t;
}
int sti(char * a){
    stringstream str;
    str<<a;
    int b;
    str >> b;
    return b;
}
int main(){
    char *a="12345";
    auto b=2*sti(a);
    cout << b;
  	return 0;
}