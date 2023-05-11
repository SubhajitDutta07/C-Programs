#include <iostream>
#include <list>

using namespace std;

class cars{
    public:
        string Name;
        string Model;
        int ModelNo ;
        list<string> Features;

        // default constructor but has initialized on ur needs
        cars(){
            Name="Something";
            Model="Something";
            ModelNo=0;
        }

        //parametarized constructor 
        cars(string name, string model, int modelNo){
            Name = name;
            Model = model ; 
            ModelNo = modelNo ;
        }

        void GetInfo(){
            cout << "Name : " << Name << endl ;
            cout << "Model : " << Model << endl;
            cout << "Model No : " << ModelNo << endl;
            cout << "Features : " << endl ;
            for(string feature : Features){
                cout << feature << endl ;
            }
        }
};

int main (){

    cars c("Lamborgini" , "Aventador SVJ", 891);
    c.Features.push_back("Engine : V12") ;
    c.Features.push_front("HP: 700");
    c.Features.push_back("Four wheel drive");

    cars c2("Keoniggsegg" , " Agera RS", 13934);
    c2.Features.push_back("Engine : v12");
    c2.Features.push_back("HP: 1110");
    c2.Features.push_back("Four wheel drive");
    c2.Features.push_back("Full exposed carbon fiber");

    c.GetInfo();
    cout << "---------------------------------------------" << endl ;
    c2.GetInfo();

    return 0;
}