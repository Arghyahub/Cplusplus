#include<iostream>
#include<string>
using namespace std;
bool check(string str,int n,int i)
{
    if (i>n/2)
        return true ;
    else if(str[i]!=str[n-i-1])
        return false ;
    else 
        return check(str,n,i+1) ;
}
int main(){
    string str ;
    cin>>str ;
    int n = str.length();
    bool ans = check(str,n,0) ;

    cout<<ans ;

    return 0 ;
}