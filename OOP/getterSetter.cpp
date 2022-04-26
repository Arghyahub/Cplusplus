#include<iostream>
using namespace std;

class Hero
{
    private:
    int Health ; // we cannot directly print Health in main() function

    public :
    int level ;
    // make a function to do so, 
    int getHealth()
    {
        return Health ;
    }

    void setHealth(int n)
    {
        Health=n ;
    }
};


int main(){
    // static
    Hero a ;
    a.setHealth(60) ;
    cout<<"Health of a : "<<a.getHealth()<<endl ;

    //dynamic
    Hero *b = new Hero ; // in a pointer we have allocated the adress of a dynamic Hero
    (*b).setHealth(70) ;
    cout<<"Health of b :"<<(*b).getHealth()<<endl ; // b is just a adress, (*b) is the pointing toward the variable
    cout<<"Health of b :"<<b->getHealth()<<endl ;  // another way of representation

    
    // cout<<"Health is : "<<a.getHealth()<<endl ;

    return 0 ;
}