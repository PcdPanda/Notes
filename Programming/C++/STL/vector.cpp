#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int N;
    int n, o = 0, i = 0;
    int dir = 1;
    cin >> N;
    vector<int> input;
    for(auto i = 0;i < N;i++){
        cin >> n;
        input.push_back(n);
    }
    cin >> N; // 定义vector
    for(auto j = 0; j < N; j++){
        cin >> n; //n为寻找的数字
        auto i = lower_bound(input.begin(), input.end(), n);
        cout << (*i == n ? "Yes " : "No ") << distance(input.begin(), i) + 1 << endl;
    }
    return 0;
}
