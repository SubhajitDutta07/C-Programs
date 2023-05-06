#include <iostream>
#include <list>
using namespace std;

class YouTube{
    private:
        string Name;
        string Owner;
        int Subcribers;
        list<string> VideosUploaded;

    public:
        YouTube(string name, string owner){
            Name = name ;
            Owner = owner ;
            Subcribers = 0;
        }

        void GetInfo(){
            cout<< "Name :" << Name << endl ;
            cout << "Owner Name : "<< Owner << endl ;
            cout<< "No. of subscribers : " << Subcribers << endl ;
            cout << "Videos uploaded : " << endl ;
            for( string videos : VideosUploaded){
                cout << videos << endl;
            }
        }
        void Subscribe(){
            Subcribers++ ;
        }

        void Unsubscribe(){
            if(Subcribers <= 0)
                return ;
            Subcribers-- ;
        }
        void PublishVideos(string video){   // we r accessing the private variables through an in-class function, 
                                            // thus not exposing the varible to public 
            VideosUploaded.push_back(video);
        }
};

int main(){
    YouTube yt("sencer07", "Subhajit");
    yt.PublishVideos("CS GO day1");
    yt.PublishVideos("CS GO day2");
    yt.PublishVideos("CS GO day3");
    yt.PublishVideos("CS GO day4");

    for (int i = 0; i < 7; i++)
    {
        yt.Subscribe();
        yt.Subscribe();
        yt.Subscribe();
        yt.Unsubscribe();
    }

    yt.GetInfo();
    

    return 0;
}