#include<iostream>
using namespace std;
const double ESP=0.01;
double sol(double x)
{
    return (x*x*x -x*x +2);
}
void bisec(double a, double b)
{
    if(sol(a)*sol(b)>=0){
    cout<<"Not possible"<<endl;
    }
    double mid;
    while((b-a)>=ESP)
    {
        mid=((a+b)/2);
    
    if(sol(mid)==0.0)
    break;
    
    else if(sol(mid)*sol(a)<0)
    b=a;
    else
    a=mid;
    }
    cout<<"the value of root is "<<mid<<endl;
}
int main()
{
    double a,b;
    cout<<"enter the values of a and b"<<endl;
    cin>>a>>b;
    bisec(a,b);
    return 0;
}
