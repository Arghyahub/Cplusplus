#include<iostream>
using namespace std;
class Hero
{
    private:
    int Health ;

    public :
    Hero()
    {
        cout<<"Constructor Called\n" ; //The constructor is called automatically when you define an object under class : eg::Paul
    }

    int level ;

    void setHealth(int n)
    {
        Health=n ;
    }

    // a constructor is initialised with the same name of the class
    // here "HERO"
};


int main(){
    Hero Paul ;
    Paul.level = 3 ;
    Paul.setHealth(79) ;
    return 0 ;
}