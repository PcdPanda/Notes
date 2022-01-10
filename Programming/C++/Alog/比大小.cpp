#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
using namespace std;
int v(int a){
    int out = 0;
    while(a!=0){
        if(a%2==1)out++;
        a=a/2;
    }
    return out;
}
bool comp(int a,int b){
    if(v(a)>v(b))return true;
    else if(v(a)==v(b))return a>b;
    return false;
}

int main(){
    int N;
    cin >> N;
    vector<int> input;
    for(auto i = 0;i<N;i++){
        int j;
        cin >> j;
        input.push_back(j);
    }
    sort(input.begin(),input.end(),comp);
    for(auto i=input.begin();i!=input.end();i++){
        cout<<*i;
    }
    return 0;
}