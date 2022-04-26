#include<iostream>
using namespace std;
// defining class
/*
class NAME
{
    propeties
};
*/

class Hero
{
    public :
    int Health ;
    int level ;
};


int main(){
    Hero Paul ;
    cout<<"Size of : "<<sizeof(Paul) ; // equal to the size of property defined in the class
    // in case of empty class , 1 byte is allocated for the class's indentification, to keep the track of

    Paul.Health=97 ;
    Paul.level = 3 ;
    

    return 0 ;
}