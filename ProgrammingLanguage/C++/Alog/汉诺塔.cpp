#include <iostream>
using namespace std;
void H(int disk, int start, int end){
    int inter;
    if(start+end==4)inter = 2;
    else if(start+end==5)inter = 1;
    else inter = 3;
    if(disk==1)cout << "move disk 1 from position " << start << " to " << end << endl;
    else {
        H(disk-1,start,inter);
        cout << "move disk "<<disk<<" from position " << start << " to " << end << endl;
        H(disk-1,inter,end);
    }

}
int main(){
    H(3,1,2);
    return 0;
}