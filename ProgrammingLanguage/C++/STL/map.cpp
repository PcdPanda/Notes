#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int N;
    string name;
    int p, grade;
    cin >> N;
    map<string, int> m;
    for (auto i = 0;i < N;i++){
        cin >> p >> name;
        if(p == 1) cin >> grade;
        auto j = m.find(name);
        switch (p){
            case 1 :
                if(j == m.end())m.insert(make_pair(name, grade));
                else j -> second += grade;
                break;
            case 2 : m.erase(name);
                break;
            default : cout << m[name] << endl;
        }
    } 

    return 0;
}


