#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <fstream>
using namespace std;

class trade{
    int timestamp, quantity, price;
    string symbol;
    public:
        trade(string input){
            int start = 0, end = -1;
            string str[4];
            for(auto i=0;i<4;i++){
                start = end + 1;
                end = input.find(',', start);
                str[i] = input.substr(start, end - start);
            }
            timestamp = atoi(str[0].c_str());
            symbol = str[1];
            quantity = atoi(str[2].c_str());
            price = atoi(str[3].c_str());
        }
        string get_symbol(){return symbol;}
        int get_timestamp(){return timestamp;}
        int get_quantity(){return quantity;}
        int get_price(){return price;}
};
int main() { 
    string input;
    ifstream csvinput;
    ofstream csvoutput;
    csvinput.open("input.csv");
    csvoutput.open("output.csv");
    if(csvinput.fail()){
        csvoutput << "File not found";
        return 0;
    }
    map<string, vector<trade*>> m;
    while(csvinput >> input){
        if(input.size()<4)continue;
        auto tmp = new trade(input);
        auto symbol = tmp -> get_symbol();
        auto i = m.find(symbol); 
        if(i!=m.end())i -> second.push_back(tmp);
        else {
            vector<trade*> in ;
            in.push_back(tmp);
            m.insert(make_pair(symbol,in));
        }
    }
    for(auto i:m){
        csvoutput << i.first << ','; 
        auto in = i.second;
        int mtp = 0, s = in.size();
        if(s > 1)mtp = in[s-1]->get_timestamp() - in[0] -> get_timestamp();
        csvoutput<< mtp << ',';
        int v = 0, price = 0, max = 0 ;
        if(s>=1)for(auto j=0;j<in.size();j++){
            if(in[j] -> get_price() > max) max = in[j] -> get_price();
            v+=in[j] -> get_quantity();
            price += in[j] -> get_quantity() * in[j] -> get_price();
            delete in[j];
        } 
        if(s>=1)csvoutput << v << ',' << price/v << ',' << max << endl;
        else csvoutput << 0 << ',' << 0 << ',' << 0 << endl;
    }
    return 0;
}
