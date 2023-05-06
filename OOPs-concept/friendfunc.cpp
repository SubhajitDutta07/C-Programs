#include<iostream>
using namespace std;

class Student
{
    string name ;
    int id;
    public:
    void Set(string Name, int ID)
    {
        name=Name;
        id=ID;
    }
    friend void display(Student);
    friend void add(Student,Student);

};

void display(Student s)
{
    cout<<"name "<<s.name<<endl;
    cout<<"id "<<s.id<<endl;
}
void add(Student s1,Student s2)
{
    int a=s1.id+s2.id;
    cout<<"total "<<a<<endl;
}

int main()
{
    Student s1;
    Student s2;
    s1.Set("subhajit",4000);
    s2.Set("Soumik", 2000);
    add(s1,s2);
    display(s1);
    display(s2);
   
   
    return 0;
}

