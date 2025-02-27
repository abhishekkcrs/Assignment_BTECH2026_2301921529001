#include<bits/stdc++.h>

using namespace std;
//Implement the class Box  
//l,b,h are integers representing the dimensions of the box

// The class should have the following functions : 

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
#include<iostream>

using namespace std;

class Box{
    int length,breadth, height;
public:
    Box(){
        length=breadth=height=0;
    }
    Box(int length, int breadth, int height){
        this->length=length;
        this->breadth=breadth;
        this->height=height;
    }
    Box(Box &b){
        this->length=b.length;
        this->breadth=b.breadth;
        this->height=b.height;
    }
    int getLength(){
        return length;
    }
    int getBreadth(){
        return breadth;
    }
    int getHeight(){
        return height;
    }
    long long CalculateVolume(){
        return length*breadth*height;
    }

    bool operator<(const Box &obj) const {
    if (length < obj.length) return true;
    if (length == obj.length && breadth < obj.breadth) return true;
    if (length == obj.length && breadth == obj.breadth && height < obj.height)
        return true;
    return false;
}

    friend ostream &operator<<(ostream &o, const Box &b) {
    o << b.length << " " << b.breadth << " " << b.height;
    return o;
}
};

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
	check2();
}