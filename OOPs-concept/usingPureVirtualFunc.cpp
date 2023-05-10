#include <iostream>
using namespace std;
// forming an abstract class " using at least one virtual func "
class Instrument{

    public:
// forming a pure virtual func so we have to provide a definition for the func in the derived class
        virtual void MakeSound() =0 ;       

};

class Piano : public Instrument{

    public:
        void MakeSound(){
            cout << "Piano is being player "<< endl ;
        }

};

class Synthesizer : public Instrument{

    public:
        void MakeSound(){
            cout << "Synthesizer is being played "<< endl ;
        }

};

int main (){

    Instrument* i = new Piano ;     
    // i->MakeSound(); 

    Instrument* i2 = new Synthesizer ;
    // i2->MakeSound();

    Instrument* instruments[2] = {i,i2};    // using an array of the class type
    for (int i = 0; i < 2; i++)
    {
        instruments[i]->MakeSound();        // calling the func twice
    }
    

    return 0;
}