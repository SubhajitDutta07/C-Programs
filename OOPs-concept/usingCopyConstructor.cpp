#include<iostream>
using namespace std ;

class book{

    public:
        string Title;
        string Author;
        int* Rates;
        int RatesCounter;

        book(string title,string author){
            Title=title;
            Author=author;
            RatesCounter=2;
            Rates=new int[RatesCounter];
            Rates[0]=8;
            Rates[1]=3;
        }

        ~book(){
            delete [] Rates;
            Rates = nullptr;
        }

        // copy constructor :
        book( const book& original){
            Title=original.Title;
            Author=original.Author;
            RatesCounter=original.RatesCounter;
            Rates=new int[RatesCounter];
            for (int i = 0; i < RatesCounter; i++)
            {
                Rates[i]=original.Rates[i];
            }
            
        }

};

void PrintBook(book b){
    cout <<"Title :" <<b.Title<<endl;
    cout<<"Author :"<<b.Author<<endl;
    int s=0;
    for (int i = 0; i < b.RatesCounter; i++)
        {
            s+=b.Rates[i];
        }
    cout << "Avg cost :"<<s/b.RatesCounter<<endl;
    return;
}

int main(){

    book b1("Stop giving too much attention ", "Subahjit");
    book b2("Don't feel vulnerable with anyone", "Sencer");
    book b3(b1);        // copying the object b1 to b3
    // book b3=b1  //initialing the b3 object with b1 and this will also use copy constructor
    // further if we o this b3=b2 then assignment operator will be invoked

    PrintBook(b1);      // this func PrintBook() is also using copy constructor for creating a temporary object
    PrintBook(b2);
    PrintBook(b3);

    
    return 0;
}