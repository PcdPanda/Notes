#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node{
   Node* next;
   Node* prev;
   int value;
   int key;
   Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
   Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{
   
   protected: 
   map<int,Node*> mp; //map the key to the node in the linked list
   int cp;  //capacity
   Node* tail; // double linked list tail pointer
   Node* head; // double linked list head pointer
   virtual void set(int, int) = 0; //set function
   virtual int get(int) = 0; //get function

};
class LRUCache : public Cache{
    private:
    int room;
    public:
    LRUCache(int capacity){
        cp = capacity;
        room = 0;
        tail = NULL;
        head = NULL;
    }
    int get(int key){
        auto i = mp.find(key);
        if(i==mp.end())return -1;
        else return i->second->value;
    }
    void set(int key, int value){
        //cout<< endl<<"set value=" << value <<" with key="<<key<<endl;
        auto i = mp.find(key);
        if(i==mp.end()){//not find
            //cout<<"not find"<<endl;
            if(room==cp){//we need to delete the last one first
                //cout<<"full, start deleting"<<endl;
                if(tail->prev!=NULL){//tail has a previous one
                    // cout<<"tail has a previous"<<endl;
                    mp.erase(tail->key);
                    auto t=tail->prev;
                    delete tail;
                    tail=t;
                    tail->next=NULL;
                }
                else {
                    // cout<<"Delete the tail"<<endl;
                    delete tail;
                }
                room--;
            }
            //insert
            //cout<<"inserting"<<endl;
            Node* x = new Node(head,NULL,key,value);
            if(head!=NULL){
                //cout<<"The link already has a node"<<endl;
                x->next=head;
                head->prev=x;
            }
            else tail = x;
            head = x;
            mp.insert(pair<int,Node*>(key,x));
            room++;
        }
        else{//find so we just need to change the position and set the value
            //cout<<"find"<<endl;
            auto tmp=i->second;
            tmp->value = value;
            if(tmp->prev!=NULL){//tmp is not the first
                //cout<<"in the middle"<<endl;
                if(tmp->next)tmp->prev->next=tmp->next;//tmp is not the last
                else {//tmp is the last
                    tail=tmp->prev;
                    tail->next=NULL;
                }
                if(head){
                    //cout<<"at fisrt, easy"<<endl;
                    tmp->next=head;
                    head->prev=tmp;
                }
                head = tmp;
            }
            else tmp->value=value;//tmp is the first, and we just set the value
        }
    }
};
int main() {
   int n, capacity,i;
   cin >> n >> capacity;
   LRUCache l(capacity);
   for(i=0;i<n;i++) {
      string command;
      cin >> command;
      if(command == "get") {
         int key;
         cin >> key;
         cout << l.get(key) << endl;
      } 
      else if(command == "set") {
         int key, value;
         cin >> key >> value;
         l.set(key,value);
      }
   }
   return 0;
}
