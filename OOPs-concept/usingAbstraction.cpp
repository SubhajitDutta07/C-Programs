#include<iostream>
using namespace std ;

class SmartPhone{

    public:
        virtual void ClickPhotos()=0;
        virtual void MakeCall()=0;
};

class Android : public SmartPhone{

    public:
        void ClickPhotos(){
            cout << "Android clicking a photo \n";
        }

        void MakeCall(){
            cout<< "Android making a call \n";
        }

};

class Iphone : public SmartPhone{

    public:
        void ClickPhotos(){
            cout << "Iphone is clicking a photo \n";
        }

        void MakeCall(){
            cout<< "Ihone is making a call \n" ;
        }
};


int main(){

    Iphone i;
    Android a;

    i.ClickPhotos();
    i.MakeCall();

    a.ClickPhotos();
    a.MakeCall();

    return 0;
}