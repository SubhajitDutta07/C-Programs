#include <iostream>
#include <list>
using namespace std ;

class cars{

    public:
        string name;
        string model;
        int hp;
        list<string> features ;
};

int main(){
    cars c;
    c.name = "Volvo";
    c.model = "XC90";
    c.hp = 1110;
    c.features = {"Luxurious","Stylish", "Safety rated 5 star"};

    cout<< "name :"<< c.name << endl;
    cout<< "model :"<<c.model << endl;
    cout<< "hp :"<<c.hp << endl;
    cout << "Features : " <<endl;
    for(string feature: c.features){
        cout<< feature << endl ;
    }
    return 0;
}