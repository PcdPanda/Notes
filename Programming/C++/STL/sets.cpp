#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    set<int> s;
    int N;
    cin >> N;
    for(auto i = 0; i < N;i++){
        int p, val;
        cin >> p >> val;
        switch(p){
            case 1: s.insert(val);
                break;
            case 2: s.erase(val);
                break;
            default: cout << (s.find(val) != s.end() ? "Yes" : "No")<< endl;
        }
    }
    return 0;
}



