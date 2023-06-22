#include<bits/stdc++.h>
using namespace std;

class A {
public:
    int x;
  
protected:
    int y;
  
private:
    int z;
};
  
class B : public A {
    // x is public
    // y is protected
    // z is not accessible from B
};
  
class C : protected A {
    // x is protected
    // y is protected
    // z is not accessible from C
};
  
class D : private A // 'private' is default for classes
{
    // x is private
    // y is private
    // z is not accessible from D
};

class Another {
    public:
    int ax , ay;
    Another(int a , int b){
        ax = a;
        ay = b;
    }
};

class One : public Another {
    public:
    int ox;
    One(int a , int b , int c) : Another(b,c)  {
        ox = a;
    }
};


int main() {
    One oo = * new One(1,2,3) ;
    cout<<oo.ax<<" "<<oo.ay<<endl;
    return 0;
}
