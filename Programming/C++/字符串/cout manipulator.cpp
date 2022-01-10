#include <iostream>
#include <iomanip> 
using namespace std;

int main() {
	int T; cin >> T;
	cout << setiosflags(ios::uppercase);
	cout << setw(0xf) << internal;
	while(T--) {
		double A; cin >> A;
		double B; cin >> B;
		double C; cin >> C;
		/* Enter your code here */
        cout << nouppercase << hex << showbase << left;
        cout << (long int)A << endl;
        cout << dec << setw(15) << setfill('_') << right << showpos << setprecision(2) << fixed;
        cout << B << endl;
        cout << uppercase << noshowpos <<scientific << setprecision(9);
        cout << C << endl ;
	}
	return 0;

}