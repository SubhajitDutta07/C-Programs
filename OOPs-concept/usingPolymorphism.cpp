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
        int Sales ;
    public:
        cars(string name, string model){
            Name=name;
            Model=model;
            Sales=0;
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

        void analysis(){
            if(Sales < 3)
                cout << Name << " had bad sales this year"<<endl;
            else
                cout << Name << " had good sales this year"<<endl;
        }
        
};

class Company : public cars {  

    public:
        Company(string name, string model):cars(name,model){

        }

        void modes(){     
            cout<<Name <<" : " << Model << " Modes: Sports , Eco , Adventure" << endl;
            Sales++;
        }

};

class SubCompany : public cars {  

    public:
        SubCompany(string name, string model):cars(name,model){

        }

        void modes(){     
            cout<<Name <<" : " << Model << " Modes: Sports , Eco , Adventure" << endl;
            Sales++;
        }

};

int main(){

    Company c1("Ford", "Fiago"),c2("Tata", "Nexon");
    c1.modes();
    c1.modes();
    
    c2.modes();     // using the same function into different class and also accessing same variable to work on
    c2.modes();
    c2.modes();
    c2.modes();
    c1.analysis();
    c2.analysis();


    return 0;
}

