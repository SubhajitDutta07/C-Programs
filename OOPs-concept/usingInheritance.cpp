#include <iostream>
#include <list>
using namespace std;

class cars{

    private:
        int UnitSold=0 ;
        list<string> Features ;
    protected:
        string Name;
        string Model;
    public:
        cars(string name, string model){
            Name=name;
            Model=model;
        }
        void GetInfo(){
            cout<< "Name : " << Name << endl ;
            cout << "Model : " << Model << endl;
            cout << "UnitSold : " << UnitSold << endl ;
            cout << "Features : "<< endl ;
            for(string feature : Features){
                cout << " "<< feature << endl ;
            }
        }
        void SoldUnits(){
            UnitSold++;
        }
        void Feature(string aat){
            Features.push_back(aat);
        }
        
};

class Company : public cars {  
// we r inheriting the class "cars" and keeping the public sections of the base class as public for the child class as well
    public:
        Company(string name, string model):cars(name,model){

        }

        void modes(){       // we cannot access this funtion from an object created from the base class
            cout<<Name <<" : " << Model << " Modes: Sports , Eco , Adventure" << endl;
            // by turning the Name and Model variable under protected section allows us to access it int derived class as well
        }

};

int main(){
    Company cp("Aston Martin", "Valkarie"), cp2("Pagani", "Hyra");
    cp.modes();

    for (int i = 0; i < 10; i++)
    {
        cp.SoldUnits();
    }
    
    cp.Feature("Engine : V8 ");
    cp.Feature("Body : Full exposed Carbon Fiber");
    cp.Feature("Air suspension");
    cp.Feature("Hp : 1110hp");
    cp.Feature("0-100 in 1.9s");

    cp.GetInfo();

    cout<< "-----------------------------------" << endl ;

    cp2.modes();

    for (int i = 0; i < 16; i++)
    {
        cp2.SoldUnits();
    }
    
    cp2.Feature("Engine : V12 ");
    cp2.Feature("Body : Full exposed Carbon Fiber");
    cp2.Feature("Air suspension");
    cp2.Feature("Hp : 1150hp");
    cp2.Feature("0-100 in 1.2s");

    cp2.GetInfo();

    return 0;
}