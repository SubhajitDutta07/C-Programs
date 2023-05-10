// using virtual we can make the the same function name in the parent class and as well as the derived class
// if virtual keyword wouldn't have been there then parent class's funtion will be implented
// if it is there than if there is func in the derived class, then that will be executed or else the 
// parent class function will be executed

#include <iostream>
using namespace std;

class Instrument{

    public:
        virtual void MakeSound(){   
            cout << "An Instrument is being played" << endl ;
        }

};

class Piano : public Instrument{

    public:
        void MakeSound(){
            cout << "Piano is being player "<< endl ;
        }

};

int main (){

    Instrument* i = new Piano ;     // using pointer to access the class 
    i->MakeSound(); 

    return 0;
}