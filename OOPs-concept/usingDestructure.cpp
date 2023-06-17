#include<iostream>
using namespace std;

class book{
    string Title;
    string Author;
    int* Rates;
    int RateCounter;
    public:
        book(string title, string author){
            Title=title;
            Author=author;

            RateCounter =2;
            Rates = new int[RateCounter];   //creating a dynamic array so always use destructures for deallocate those memory space
            Rates[0]=5;
            Rates[1]=8;

            cout<<"Constructor has been called "<< endl ;
            cout<<"Book title "<<Title<<endl;
        }
        // destructor always uses Stack pop algo
        ~book(){        // only 1 destructor per class
            cout<< "Destructor has been called"<< endl ;
            cout<<"Book title "<<Title<<endl;

            delete []Rates;     //for deleting the whole array not just the pointer value
            Rates=nullptr;
        }
};

int main(){

    book b1("Stop giving too much attention ", "Subahjit");
    book b2("Don't feel vulnerable with anyone", "Sencer");

}