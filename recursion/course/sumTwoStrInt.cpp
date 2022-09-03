#include<bits/stdc++.h>
using namespace std;

void sumStr(string &a, string &b, int n, int m, int carry, string &ans)
{
    if (n<0 && m<0 && carry==0)
        return ;
    
    int fsum=0 , ssum = 0 ;
    if (n>=0) fsum = a[n--] - '0' ;
    if (m>=0) ssum = b[m--] - '0' ;

    int sum = fsum+ssum+carry ;
    int quo = sum%10 ;
    carry = sum/10 ;

    ans = (char)(quo+'0') + ans ;

    sumStr(a,b,n,m,carry,ans) ;
}



int main(){
    
    string a = "999" ;
    string b = "11" ;

    int n = a.size()-1 , m = b.size()-1 ;

    string ans = "" ;
    sumStr(a,b,n,m,0,ans) ;

    cout<<ans ;

    return 0 ;
}