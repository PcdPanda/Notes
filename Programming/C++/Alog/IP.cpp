#include <cmath>
#include <cstdio>
#include <deque>
#include <iostream>
#include <algorithm>
using namespace std;
deque<deque<int>> decide(int n, int choice){
    int max = n - (choice -1);
    int min = n - 3*(choice - 1);
    deque<deque<int>> output;
    if(!choice)return output;
    if(max > 3)max = 3;
    if(min < 1 || choice == 1)min = 1;
    for(auto i = min;i<=max;i++){
        deque<deque<int>> tmp = decide(n - i, choice - 1);
        if(choice == 1){
            deque<int> j;
            j.push_back(i);
            output.push_back(j);
        }
        for(auto j = tmp.begin(); j != tmp.end();j++){
            (*j).push_front(i);
            auto t = *j;
            output.push_back(t);
        }
    }
    return output;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int N,a;
    cin >> N;
    deque<int> in;
    
    //A:
    // for(auto i=0;i<N;i++){
    //     cin >> a;
    //     in.push_back(a);
    // }

    //B:
    a=N;
    while(a!=0){
        int j = a%10;
        in.push_front(j);
        a=a/10;
    }

    auto n = in.size() - 1;
    for(auto i = in.begin();i!=in.end();i++)cout<<*i;
    cout<<endl<<"n="<<n<<endl;
    auto out = decide(n,3);
    for(auto i = out.begin();i!=out.end();i++){
        auto x = *i;
        for(auto j = x.begin()+1;j!=x.end();j++)*j+=*(j-1);
        int y = 0;
        for(auto j = 0;j < N;j++){
            if(j==x[y]){
                y++;
                cout << ",";
            }
            cout << in[j];
        }
        cout << endl;
    }
    return 0;
}
