#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    ifstream input("input.txt");
    int n, q, i, x, y, j;
    int len;
    input >> n >> q;  //n为输入的行数， q为输出的行数
    int ** a = (int **) malloc(n * sizeof(int *));//创建行的数组
    for(i = 0;i < n; i++){
        input >> len; //len为每行有多少数字
        // int * c = new int[len * sizeof(int)]; //为每行开空间
        int * c = (int *) malloc(len * sizeof(int));//每行开空间
        for(j = 0;j < len; j++)input >> c[j]; //把len个数字放入c
        a[i] = c;
    }
    for(i = 0;i < q; i++){
        input >> x >> y; //x第几行, y第几列
        cout << a[x][y] << endl;
    }
    for(i = 0;i < n; i++)free(a[i]);
    free(a);
    return 0;
}