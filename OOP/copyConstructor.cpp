#include<iostream>
using namespace std;
class Hero
{
    private:
    int Health ;

    public :
    Hero(int Health, int level)
    {
        this->Health=Health ;
        this->level=level ;
    }

    int level ;

    void print()
    {
        cout<<"Health is : "<<Health<<endl ;
        cout<<"Level  is : "<<level<<endl ;
    }
};


int main(){
    Hero Paul(79,3) ;
    Paul.print() ;

    // copy constructor
    Hero Das(Paul) ;
    Das.print() ;


    return 0 ;
}