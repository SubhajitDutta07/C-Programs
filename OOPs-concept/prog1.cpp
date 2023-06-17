#include<iostream>
using namespace std;

class ForPromotion{
    virtual void promotion()=0;
};

class Employee : public ForPromotion { 
    string Job;
    int Age;
    protected:
        string Name;
    public:
        Employee(string name,string job, int age){
            Name=name;
            Job=job;
            Age=age;
        }
        void Introduction(){
            cout<< "Name :"<<Name << endl ;
            cout << "Age : "<< Age << endl;
            cout<< "Job :"<< Job << endl ;
        }
        void promotion(){
            if(Age <= 25)
                cout << Name << " will not get promoted this year" <<endl;
            else    
                cout<< Name << " will get promoted this year"<< endl;
        }
        virtual void work(){
            cout<<Name << " is checking emails, checking backlog tasks" << endl ;
        }
};

class Developer : public Employee{          // with public access modifier we can also access the func of Employee class
    
    string FavLang;
    public:
        Developer(string name,string job,int age, string favLang) : Employee(name,job,age){
            FavLang=favLang;
        }
        void task(){
            cout<< Name << " has been fixing bugs " << endl ;
        }
        // void work(){
        //     cout<<Name << " is programming in C++ and performing tests" << endl ;
        // }
};

class Teacher : public Employee{
    string Subject;
    public:
        Teacher(string name, string job, int age, string subject) : Employee(name,job,age) {
            Subject=subject;
        }
        void lessons(){
            cout << Name << " is preaparing for " << Subject << endl ; 
        }
        void work(){
            cout << Name << " is teaching all about "<< Subject << " and hwo to implement them \n";
        }
};

int main(){

    // Employee e1("Saldina", "YT:CodeBeauty", 24);
    // Employee e2("John", "Teacher", 35);

    // e1.promotion();
    // e2.promotion();
    // e1.Introduction();
    // e2.Introduction();

    Developer d("Saldina", "YT-codeBeauty", 24, "C++");
    d.task();
    d.promotion();
    d.work();

    Teacher t("John", "Hack School", 35 , "Programming");
    t.lessons();
    t.promotion();
    t.work();

    return 0;
}