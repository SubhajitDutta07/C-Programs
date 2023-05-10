#include<iostream>
#include<list>
using namespace std;



class Youtube{
    public:
        string Name;
        int Subscribers;
    
        Youtube(string name, int subscribers){
            Name=name;
            Subscribers=subscribers;
        }
        bool operator==(const Youtube& ytchannel)const{
            return this->Name == ytchannel.Name ;
        }
};

class MyCollection{
    public:
        list<Youtube> myChannels;

        void operator+=(Youtube ytChannel){
            myChannels.push_back(ytChannel);
            
        }
        void operator-=(Youtube ytChannel){
            myChannels.remove(ytChannel);
        }
        
};

ostream& operator<<(ostream& COUT , Youtube&  ytChannel){   
    
    COUT<< "Name: "<< ytChannel.Name << endl ;
    COUT<< "Subscriber Count : "<< ytChannel.Subscribers << endl ;

    return COUT ;

}

ostream& operator<<(ostream& COUT, MyCollection& myCollection){
    for(Youtube ytChannel : myCollection.myChannels){
        COUT<< ytChannel<< endl ;
    }
    return COUT ;
}

class Point{
    int x;
    int y;
    public :
        Point(int a=0, int b=0){
            x=a;
            y=b;
        }
        Point operator+(Point& rhs){
            Point p;
            p.x=x+rhs.y;
            p.y=y+rhs.x;
            return p;
        }
        Point operator-(Point& rhs){
            Point p(0,0);
            p.x=x-rhs.x;
            p.y=y-rhs.y;
            return p;
        }
        void print(){
            cout << "x : " << x << " y : " << y <<endl ;
        }
};

int main(){
    Youtube yt("Sencer07", 40958);
    Youtube yt2("BearBug", 79754);
    cout << yt << yt2<<endl ;  // did overload the operator << to print the objects of a class
    MyCollection myCollection;
    myCollection += yt;
    myCollection += yt2;

    cout << myCollection ;

    myCollection -= yt2;

    cout << "------------------------------------------- \n";

    cout << myCollection ;


    Point a(7,9), b(2,3);
    Point c=a+b;
    
    c.print();
    c=a-b;
    c.print();

    return 0;
}