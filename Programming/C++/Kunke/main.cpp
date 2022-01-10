#include <thread>
#include <mutex>
#include <iostream>
#include <deque>
#include <unistd.h>

using namespace std;
// Define the A and B struct
struct A_struct{
    int a;
};
struct B_struct{
    double data[5];
};

// Define the total sum
double sum_b_all = 0;

A_struct A_out; // A a_struct to store the output from thread A
deque<B_struct> B_out; // A deque to store all the outputs from thread B
mutex m; // A mutex lock used when there is an access to critical region

void A(){// Generate a random value in [1,100]
    srand((unsigned int)(time(0)));
    while(1)A_out.a = rand() % 100 + 1;
}

void B(){ // Generate struct_B and put it into the deque
    srand((unsigned int)(time(0)));
    while(1){
        if(B_out.size()>B_out.max_size())continue; // Make sure there is enough memory in deque to keep a struct B
        B_struct out;
        for(auto i=0;i<5;i++){
            out.data[i] = (rand() % 100);
            out.data[i] /= 100; // Generate 5 random data with 2 decimals  
        }
        m.lock(); 
        B_out.push_back(move(out)); // Push the struct_b value to the deque when mutex is locked
        m.unlock();
    }
};
void C(){ // Get the data generated from B and the deque
    while(1){
        bool success = false; // A boolean variable define whether the consumer get valid data
        m.lock();
        double* out;
        if(!B_out.empty()){ // The mutex must be locked before operations on the deque 
            out = B_out.front().data; //Get the first pushed data from the deque
            B_out.pop_front(); // Pop the data
            success = true; 
            m.unlock();
        }
        else {
            m.unlock();
            usleep(2); // To save resources, the thread can sleep for a while
            continue;    
        }
        if(success){ // Get the valid data, so we can compute the sum
            double sum_b = 0;
            for(auto i=0;i<5;i++)sum_b += out[i];
            if(A_out.a % 2==0)sum_b *= -1;
            sum_b_all += sum_b;
        }
    }
}
void D(){ // Print the total sum every second
    while(1){
            cout << sum_b_all << endl;
            sleep(1);
        }
}

int main(int argc, char* argv[]){

    cout << "The maximize size for to store struct B is at an instant is " << B_out.max_size() << endl;
    // Print the max memory for the deque

    thread a(A);
    thread b(B);
    thread c(C);
    thread d(D);

    a.join();
    b.join();
    c.join();
    d.join(); 
    
    return 0;
}
