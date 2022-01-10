#include <iostream>
#include <deque> 
using namespace std;

void printKMax(int arr[], int n, int k){
	//Write your code here.
    deque<int> q;
    int max = arr[0]; 
    auto index = q.begin();//index记录最大坐标
    for(auto i = 0; i < k - 1 ;i++){
        q.push_back(arr[i]); // q初始化
        if (arr[i] >= max){
            max = arr[i];
            index = q.end() -1;//找到最大坐标前 k-1中的最大值
        }
    }
    for(auto i = 0; i < n - k + 1;i++){
        q.push_back(arr[i + k -1]); //插入下一个元素
        if(q.back() > *index){
            max = q.back(); 
            index = q.end() -1;
        }
        else max = *index;
        if(k == 1) max = arr[i + k -1];
        cout << max << " ";
        if(index == q.begin()){//如果本来第一个元素是最大，则重新找最大
            max = q[1];
            for(auto j = q.begin() + 1;j != q.end();j++){
                if(*j >= max){
                    max = *j;
                    index = j;
                }
            }
        }
        q.pop_front(); //删除第1个元素
    }
    cout << endl;
}

int main(){
  
	int t;
	cin >> t;
	while(t>0) {
		int n,k;
    	cin >> n >> k;
    	int i;
    	int arr[n];
    	for(i=0;i<n;i++)
      		cin >> arr[i];
    	printKMax(arr, n, k);
    	t--;
  	}
  	return 0;
}