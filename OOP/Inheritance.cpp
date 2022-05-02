#include<iostream>
#include<string>
using namespace std;

class Parent
{
    public:
    string Hair ;
    string color ;
    string skin ;

    void print()
    {
        cout<<this->Hair<<endl ;
        cout<<this->color<<endl ;
        cout<<this->skin<<endl ;
    }
};

class child : public Parent // Access modifier then parent class
{
    public:
    int intelligence ;
    void print()
    {
        cout<<this->intelligence<<endl ;
    }
};

int main(){
    
    child human ;
    // Not in the class but in parent class
    human.Hair="Black" ;
    human.color="Brown" ;
    human.skin="Dry" ;

    // in child class
    human.intelligence= 100 ;

    human.Parent::print() ;
    human.child::print() ;
    return 0 ;
}