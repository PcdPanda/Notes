#include<bits/stdc++.h>

using namespace std;
//Implement the class Box  
//l,b,h are integers representing the dimensions of the box

// The class should have the following functions : 
class shape{
    public:
        virtual int getLength()=0;

};
class Box: public shape{
    private :
        int l, b, h;
    public :
        Box(int len = 0, int breadth = 0, int height = 0){
            l = len;
            b = breadth;
            h = height;
        };
        Box(Box &i){
            l = i.l;
            b = i.b;
            h = i.h;
        }
    int getLength(){ // Return box's length
        return l;
    }
    int getBreadth (){ // Return box's breadth
        return b;
    }
    int getHeight (){  //Return box's height
        return h;
    }
    long long CalculateVolume(){ // Return the volume of the box
        return ((long long)l * b * h);
    }
    friend bool operator<(Box& x,Box& y){
        if(x.l < y.l) return true;
        else if (x.b < y.b && x.l == y.l) return true;
        else if(x.h < y.h && x.b == y.b && x.l == y.l) return true;
        else return false;
    }
    friend ostream& operator<<(ostream& out, Box &x){
        out << x.l << " " << x.b << " " << x.h;
        return out;
    }
};
// Constructors: 
// Box();
// Box(int,int,int);
// Box(Box);


// int getLength(); // Return box's length
// int getBreadth (); // Return box's breadth
// int getHeight ();  //Return box's height
// long long CalculateVolume(); // Return the volume of the box

//Overload operator < as specified
//bool operator<(Box& b)

//Overload operator << as specified
//ostream& operator<<(ostream& out, Box& B)


void check2()
{
	int n;
	cin>>n;
	Box temp;
	for(int i=0;i<n;i++)
	{
		int type;
		cin>>type;
		if(type ==1)
		{
			cout<<temp<<endl;
		}
		if(type == 2)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			temp=NewBox;
			cout<<temp<<endl;
		}
		if(type==3)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			if(NewBox<temp)
			{
				cout<<"Lesser\n";
			}
			else
			{
				cout<<"Greater\n";
			}
		}
		if(type==4)
		{
			cout<<temp.CalculateVolume()<<endl;
		}
		if(type==5)
		{
			Box NewBox(temp);
			cout<<NewBox<<endl;
		}

	}
}

int main()
{
    // shape * s= new Box;
    // cout << s->getLength()<<endl;
	// check2();
    int a[5];
    a[4]=2;
    realloc(a,100*sizeof(int));
    a[90]=5;
    cout << a[90];
    return 0;
}