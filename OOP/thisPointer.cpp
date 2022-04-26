#include<iostream>
using namespace std;
class Hero
{
    private:
    int Health ;

    public :
    Hero(int Health)
    {
        // Health=Health  You are putting the same value of a variable health in health
        // use "this pointer" : this stores the address of the closest var in class
        this->Health = Health ; 
        cout<<"\nAddress of this in class : "<<this ;
    }

    int level ;

    void getHealth()
    {
        cout<<"Health is : "<<Health ;
    }
};


int main(){
    Hero Paul(79) ;
    // Paul.getHealth() ;

    cout<<"\nAddress of Paul in class : "<<&Paul ;
    
    // once your define a custom constructor, the default constructor dies
    // Hero pp ; will not work
    // because the constructor we have defines requires a argument

    return 0 ;
}